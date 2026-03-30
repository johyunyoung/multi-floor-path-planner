"""
Walk-these-ways RL inference node for Unitree Go2 in ROS 2 / Ignition Fortress.

Observation (70-dim, from lcm_agent.py):
  [0:3]   projected gravity  (from IMU quaternion)
  [3:18]  commands × commands_scale  (15 dims)
  [18:30] dof_pos - default_dof_pos  (policy order [FL,FR,RL,RR])
  [30:42] dof_vel × dof_vel_scale    (policy order)
  [42:54] prev_actions (clipped)
  [54:66] last_actions  (observe_two_prev_actions=True)
  [66:70] clock_inputs sin(2π × foot_indices)  (observe_clock_inputs=True)

History: rolling buffer of 30 × 70 = 2100 floats (oldest → newest).

Joint ordering:
  ROS control.yaml : [FR, FL, RR, RL]  (indices 0..11)
  Policy (URDF/training) : [FL, FR, RL, RR]
  Remapping idx JOINT_IDXS = [3,4,5,0,1,2,9,10,11,6,7,8]
    ros→policy  : policy_dof = ros_dof[JOINT_IDXS]
    policy→ros  : ros_target = policy_target[JOINT_IDXS]
"""

import os
import numpy as np
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy

from sensor_msgs.msg import JointState, Imu
from geometry_msgs.msg import Twist
from std_msgs.msg import Float64MultiArray

from .policy_wrapper import PolicyWrapper


# ── Constants derived from parameters.pkl ─────────────────────────────────────

# Joint remapping: ros_order[FR,FL,RR,RL] → policy_order[FL,FR,RL,RR]
JOINT_IDXS = np.array([3, 4, 5, 0, 1, 2, 9, 10, 11, 6, 7, 8], dtype=np.int32)

# Joint names in ROS (control.yaml) order
ROS_JOINT_NAMES = [
    'FR_hip_joint', 'FR_thigh_joint', 'FR_calf_joint',
    'FL_hip_joint', 'FL_thigh_joint', 'FL_calf_joint',
    'RR_hip_joint', 'RR_thigh_joint', 'RR_calf_joint',
    'RL_hip_joint', 'RL_thigh_joint', 'RL_calf_joint',
]

# Default joint angles in policy order [FL, FR, RL, RR]
DEFAULT_DOF_POS = np.array([
    0.1, 0.8, -1.5,   # FL_hip, FL_thigh, FL_calf
   -0.1, 0.8, -1.5,   # FR_hip, FR_thigh, FR_calf
    0.1, 1.0, -1.5,   # RL_hip, RL_thigh, RL_calf
   -0.1, 1.0, -1.5,   # RR_hip, RR_thigh, RR_calf
], dtype=np.float32)

# Observation scaling
DOF_POS_SCALE = 1.0
DOF_VEL_SCALE = 0.05
LIN_VEL_SCALE = 2.0
ANG_VEL_SCALE = 0.25

# 15-dim commands_scale (from lcm_agent.py)
CMD_SCALE = np.array([
    LIN_VEL_SCALE,   # vx
    LIN_VEL_SCALE,   # vy
    ANG_VEL_SCALE,   # yaw_rate
    2.0,             # body_height_cmd
    1.0,             # gait_frequency
    1.0,             # gait_phase
    1.0,             # gait_offset
    1.0,             # gait_bound
    1.0,             # gait_duration
    0.15,            # footswing_height
    0.3,             # body_pitch
    0.3,             # body_roll
    1.0,             # stance_width
    1.0,             # stance_length
    1.0,             # aux_reward_coef
], dtype=np.float32)

# Default fixed gait command values (trot gait)
# cmd[0]=vx, [1]=vy, [2]=yaw from cmd_vel; rest are fixed
DEFAULT_CMD = np.array([
    0.0,   # vx         (from cmd_vel)
    0.0,   # vy         (from cmd_vel)
    0.0,   # yaw_rate   (from cmd_vel)
    0.0,   # body_height_cmd
    0.0,   # gait_frequency (Hz) – 0=stand; set to GAIT_FREQUENCY by cmd_vel when moving
    0.5,   # gait_phase  – trot phase offset (0.5 = diagonal pairs antiphase)
    0.0,   # gait_offset
    0.0,   # gait_bound
    0.5,   # gait_duration
    0.09,  # footswing_height (m)
    0.0,   # body_pitch
    0.0,   # body_roll
    0.27,  # stance_width  (middle of [0.1, 0.45])
    0.40,  # stance_length (middle of [0.35, 0.45])
    0.0,   # aux_reward_coef
], dtype=np.float32)

# PD gains — exact training values (stiffness=20, damping=0.5 from parameters.pkl)
# The policy is trained knowing the resulting ~0.25 rad static sag under gravity,
# and compensates via its action offsets. Do NOT change these for hardware deployment.
KP = 20.0
KD = 0.5
MAX_TORQUE = 33.0  # N·m — conservative Go2 joint torque limit

# Action processing
ACTION_SCALE = 0.25
HIP_SCALE_REDUCTION = 0.5   # applied to hip indices [0,3,6,9] in policy order
CLIP_ACTIONS = 10.0

# Control
CONTROL_HZ = 50.0
SIM_DT = 4 * 0.005  # decimation × sim_dt = 0.02 s
STARTUP_HOLD_SECS = 2.0  # hold default pose before engaging RL (lets robot settle + warms obs_history)

# Velocity-gated gait: below this magnitude the robot stands still (gait_freq=0)
VEL_DEADBAND  = 0.05   # m/s or rad/s
GAIT_FREQUENCY = 3.0   # Hz when walking

# Obs / history dims
NUM_OBS = 70
NUM_HISTORY = 30


class RLInferenceNode(Node):

    def __init__(self):
        super().__init__('rl_inference_node')

        # ── Parameters ───────────────────────────────────────────────────────
        self.declare_parameter('body_model_path', '')
        self.declare_parameter('adaptation_model_path', '')

        body_path = self.get_parameter('body_model_path').get_parameter_value().string_value
        adapt_path = self.get_parameter('adaptation_model_path').get_parameter_value().string_value

        if not body_path or not adapt_path:
            raise RuntimeError('body_model_path and adaptation_model_path parameters are required')

        self.get_logger().info(f'Loading policy from:\n  body:    {body_path}\n  adapt:   {adapt_path}')
        self.policy = PolicyWrapper(body_path, adapt_path)
        self.get_logger().info('Policy loaded successfully')

        # ── State buffers ─────────────────────────────────────────────────────
        self.obs_history = np.zeros(NUM_OBS * NUM_HISTORY, dtype=np.float32)  # (2100,)
        self.prev_actions = np.zeros(12, dtype=np.float32)
        self.last_actions = np.zeros(12, dtype=np.float32)

        # Sensor data (latest)
        self.dof_pos_ros = np.zeros(12, dtype=np.float32)   # ROS order [FR,FL,RR,RL]
        self.dof_vel_ros = np.zeros(12, dtype=np.float32)
        self.gravity_vec = np.array([0.0, 0.0, -1.0], dtype=np.float32)
        self.commands = DEFAULT_CMD.copy()

        # Gait phase tracker (50 Hz update)
        self.gait_index = np.float32(0.0)
        self.clock_inputs = np.zeros(4, dtype=np.float32)

        # Readiness flags
        self._joint_ready = False
        self._imu_ready = False

        # Startup hold: timestamp of first valid sensor reading
        self._startup_t0 = None

        # Dynamic joint index mapping: ROS msg index → 0..11 position in ROS_JOINT_NAMES
        self._joint_name_to_idx: dict = {}

        # ── ROS interfaces ────────────────────────────────────────────────────
        sensor_qos = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            history=HistoryPolicy.KEEP_LAST,
            depth=1,
        )

        self.sub_joint = self.create_subscription(
            JointState, '/joint_states', self._cb_joint, 10)
        self.sub_imu = self.create_subscription(
            Imu, '/go2_0000/imu/data', self._cb_imu, sensor_qos)
        self.sub_cmd = self.create_subscription(
            Twist, '/go2_0000/cmd_vel', self._cb_cmd, 10)

        self.pub_effort = self.create_publisher(
            Float64MultiArray, '/forward_effort_controller/commands', 10)

        self.timer = self.create_timer(1.0 / CONTROL_HZ, self._control_loop)

        self.get_logger().info('RL inference node started (50 Hz)')

    # ── Callbacks ─────────────────────────────────────────────────────────────

    def _cb_joint(self, msg: JointState):
        # Build name→index map once
        if not self._joint_name_to_idx:
            for i, name in enumerate(msg.name):
                if name in ROS_JOINT_NAMES:
                    self._joint_name_to_idx[name] = i

        if len(self._joint_name_to_idx) < 12:
            return

        for ros_idx, name in enumerate(ROS_JOINT_NAMES):
            msg_idx = self._joint_name_to_idx.get(name)
            if msg_idx is not None and msg_idx < len(msg.position):
                self.dof_pos_ros[ros_idx] = msg.position[msg_idx]
                self.dof_vel_ros[ros_idx] = msg.velocity[msg_idx]

        self._joint_ready = True

    def _cb_imu(self, msg: Imu):
        # ROS Imu quaternion: x, y, z, w
        qx = msg.orientation.x
        qy = msg.orientation.y
        qz = msg.orientation.z
        qw = msg.orientation.w
        # Rotate world gravity [0,0,-1] into body frame: grav = R^T @ [0,0,-1]
        # Derived from rotation matrix for ROS quaternion (x,y,z,w):
        #   gx = -R[2][0] = 2*(-qx*qz + qw*qy)
        #   gy = -R[2][1] = -2*(qy*qz + qw*qx)
        #   gz = -R[2][2] = -(1-2*(qx^2+qy^2)) = 1 - 2*(qw^2+qz^2)
        # Upright (identity q): gz = 1-2*(1+0) = -1 ✓
        self.gravity_vec[0] = 2.0 * (-qz * qx + qw * qy)
        self.gravity_vec[1] = -2.0 * (qz * qy + qw * qx)
        self.gravity_vec[2] = 1.0 - 2.0 * (qw * qw + qz * qz)
        self._imu_ready = True

    def _cb_cmd(self, msg: Twist):
        vx  = msg.linear.x
        vy  = msg.linear.y
        yaw = msg.angular.z
        self.commands[0] = vx
        self.commands[1] = vy
        self.commands[2] = yaw
        # Gate gait: stand still (gait_freq=0) when no meaningful velocity is commanded
        moving = (abs(vx) > VEL_DEADBAND or abs(vy) > VEL_DEADBAND or abs(yaw) > VEL_DEADBAND)
        self.commands[4] = GAIT_FREQUENCY if moving else 0.0

    # ── Control loop ──────────────────────────────────────────────────────────

    def _control_loop(self):
        if not (self._joint_ready and self._imu_ready):
            return

        # ── Startup hold timer ────────────────────────────────────────────────
        if self._startup_t0 is None:
            self._startup_t0 = self.get_clock().now()
            self.get_logger().info(
                f'Startup hold begun: holding default pose for {STARTUP_HOLD_SECS:.1f}s '
                f'to let robot settle and warm obs_history')

        elapsed = (self.get_clock().now() - self._startup_t0).nanoseconds * 1e-9

        # 1. Update clock (gait phase) — always, so history has realistic clock inputs
        gait_freq = self.commands[4]
        self.gait_index = float(np.fmod(self.gait_index + SIM_DT * gait_freq, 1.0))

        phase  = self.commands[5]
        offset = self.commands[6]
        bound  = self.commands[7]

        foot_indices = [
            self.gait_index + phase + offset + bound,
            self.gait_index + offset,
            self.gait_index + bound,
            self.gait_index + phase,
        ]
        for i in range(4):
            self.clock_inputs[i] = np.sin(2.0 * np.pi * foot_indices[i])

        # 2. Build observation (70-dim) — always, even during startup
        obs = self._build_obs()

        # 3. Update rolling history — always (warms the buffer during hold phase)
        self.obs_history = np.roll(self.obs_history, -NUM_OBS)
        self.obs_history[-NUM_OBS:] = obs

        # ── Startup hold: command default pose, skip RL inference ─────────────
        if elapsed < STARTUP_HOLD_SECS:
            self._publish_targets(DEFAULT_DOF_POS[JOINT_IDXS])
            return

        if elapsed < STARTUP_HOLD_SECS + SIM_DT:
            self.get_logger().info('Startup hold done — engaging RL policy')

        # 4. Policy inference
        raw_action = self.policy.infer(self.obs_history)  # (12,)

        # 5. Action processing (lcm_agent.py: publish_action)
        self.last_actions = self.prev_actions.copy()
        clipped = np.clip(raw_action, -CLIP_ACTIONS, CLIP_ACTIONS)
        self.prev_actions = clipped.copy()

        target = clipped * ACTION_SCALE
        target[[0, 3, 6, 9]] *= HIP_SCALE_REDUCTION  # hip scale (policy order indices)
        target += DEFAULT_DOF_POS                      # policy order [FL,FR,RL,RR]

        # 6. Reorder policy→ROS: policy[FL,FR,RL,RR] → ros[FR,FL,RR,RL]
        target_ros = target[JOINT_IDXS]

        # 7. Publish JointTrajectory
        self._publish_targets(target_ros)

    def _build_obs(self) -> np.ndarray:
        # dof_pos in policy order [FL,FR,RL,RR]
        dof_pos = self.dof_pos_ros[JOINT_IDXS]
        dof_vel = self.dof_vel_ros[JOINT_IDXS]

        obs = np.concatenate([
            self.gravity_vec,                                        # [0:3]
            self.commands * CMD_SCALE,                               # [3:18]
            (dof_pos - DEFAULT_DOF_POS) * DOF_POS_SCALE,            # [18:30]
            dof_vel * DOF_VEL_SCALE,                                 # [30:42]
            np.clip(self.prev_actions, -CLIP_ACTIONS, CLIP_ACTIONS), # [42:54]
            self.last_actions,                                       # [54:66]
            self.clock_inputs,                                       # [66:70]
        ]).astype(np.float32)

        return obs

    def _publish_targets(self, target_ros: np.ndarray):
        """Compute PD effort and publish to forward_effort_controller.

        Matches Isaac Gym training formula exactly:
            τ = Kp * (target - q) + Kd * (0 - dq)
        The policy learned implicit gravity compensation assuming these gains.
        """
        effort = (KP * (target_ros - self.dof_pos_ros)
                  + KD * (-self.dof_vel_ros))
        effort = np.clip(effort, -MAX_TORQUE, MAX_TORQUE)
        self.pub_effort.publish(Float64MultiArray(data=effort.tolist()))


def main(args=None):
    rclpy.init(args=args)
    node = RLInferenceNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
