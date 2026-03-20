# Clearpath Husky A200 — Ignition Gazebo Simulation Config

ROS 2 Humble + Ignition Fortress (Gazebo 6) 환경에서 Clearpath Husky A200를 시뮬레이션하기 위한 설정 파일 모음입니다.

## 환경

| 항목 | 버전 |
|------|------|
| ROS | ROS 2 Humble |
| Simulator | Ignition Gazebo (Fortress, `libignition-gazebo6` 6.17.1) |
| Robot | Clearpath Husky A200 (`a200-0000`) |

## 주요 특징

- **Ground-truth odometry**: Ignition `OdometryPublisher` 플러그인(P3D 등가)으로 wheel slip·벽 충돌과 무관한 월드 절대 pose를 EKF 입력으로 사용
- **Full 3D pose 추적**: `<dimensions>3</dimensions>` 설정으로 x·y·z 위치 및 roll·pitch·yaw 회전 모두 RViz에 반영
- **멀티 월드 지원**: `world:=<name>` 인자로 커스텀 월드(`~/clearpath/worlds/`) 또는 내장 월드 즉시 전환
- **단일 커맨드 실행**: Gazebo + 로봇 스폰 + RViz를 하나의 launch 파일로 실행

## 디렉토리 구조

```
clearpath/
├── simulation.launch.py          # 메인 launch 파일 (Gazebo + spawn + RViz)
├── robot.yaml                    # Clearpath 로봇 설정 (플랫폼·센서·어태치먼트)
├── robot.urdf.xacro              # 생성된 URDF (OdometryPublisher 플러그인 포함)
├── robot.srdf / robot.srdf.xacro # MoveIt SRDF
├── gz_ground_truth_tf.py         # (미사용) 초기 TF 퍼블리셔 시도 — 참고용
│
├── platform/
│   ├── config/
│   │   ├── localization.yaml     # EKF 설정 (ground_truth/odom 입력, 3D 활성화)
│   │   ├── control.yaml          # diff_drive_controller 설정
│   │   ├── imu_filter.yaml
│   │   ├── teleop_joy.yaml
│   │   ├── teleop_interactive_markers.yaml
│   │   └── twist_mux.yaml
│   └── launch/
│       └── platform-service.launch.py  # cmd_vel·ground_truth odom 브리지 포함
│
├── sensors/
│   ├── config/
│   │   ├── imu_0.yaml
│   │   └── lidar3d_0.yaml
│   └── launch/
│       └── sensors-service.launch.py
│
├── manipulators/
│   ├── config/moveit.yaml
│   └── launch/manipulators-service.launch.py
│
└── worlds/
    ├── simple_multi_floor.sdf    # 커스텀 멀티 플로어 월드
    └── meshes/
        └── floor.dae             # 월드 메시 (별도 준비 필요)
```

## 실행 방법

```bash
# 기본 warehouse 월드
ros2 launch /home/jo/clearpath_ws/clearpath/simulation.launch.py

# 커스텀 멀티 플로어 월드
ros2 launch /home/jo/clearpath_ws/clearpath/simulation.launch.py world:=simple_multi_floor

# 스폰 위치 지정
ros2 launch /home/jo/clearpath_ws/clearpath/simulation.launch.py world:=warehouse x:=1.0 y:=2.0 yaw:=1.57
```

> **주의**: `floor.dae` 메시 파일은 저장소에 포함되어 있지 않습니다. 사용 전에 `worlds/meshes/floor.dae`로 직접 복사하세요.

## 아키텍처

### Ground-truth Odometry 파이프라인

```
Ignition Gazebo (WorldPose ECS)
  └─ OdometryPublisher plugin (3D)
       └─ /model/a200_0000/robot/odometry  [Ignition topic]
            └─ ground_truth_odom_bridge (ros_gz_bridge)
                 └─ /a200_0000/ground_truth/odom  [ROS nav_msgs/Odometry]
                      └─ EKF (robot_localization)
                           └─ odom → base_link TF  →  RViz
```

### 핵심 설정 포인트

**`robot.urdf.xacro`** — Ignition OdometryPublisher (시뮬레이션 전용):
```xml
<plugin filename="libignition-gazebo-odometry-publisher-system.so"
        name="ignition::gazebo::systems::OdometryPublisher">
  <odom_frame>odom</odom_frame>
  <robot_base_frame>base_link</robot_base_frame>
  <update_frequency>50</update_frequency>
  <publish_covariance>true</publish_covariance>
  <dimensions>3</dimensions>   <!-- full 3D pose (x,y,z + roll,pitch,yaw) -->
</plugin>
```

**`platform/config/localization.yaml`** — EKF가 ground truth를 전체 6DOF로 사용:
```yaml
odom0: 'ground_truth/odom'
two_d_mode: False
# [x,    y,    z,    roll, pitch, yaw,  vx,   vy,   vz,   ...]
odom0_config: [True, True, True, True, True, True, True, True, True, False, False, True, False, False, False]
```

**`platform/launch/platform-service.launch.py`** — ground truth odom 브리지:
```python
# wheel odometry TF 브리지 대신 ground truth odometry 브리지 사용
node_ground_truth_odom_bridge = Node(
    arguments=['/model/a200_0000/robot/odometry@nav_msgs/msg/Odometry[ignition.msgs.Odometry'],
    remappings=[('/model/a200_0000/robot/odometry', 'ground_truth/odom')],
)
```

## 커스텀 월드 추가

1. `.dae` / `.obj` 등 메시 파일을 `worlds/meshes/`에 저장
2. `worlds/<world_name>.sdf` 파일 생성 (world name = 파일명과 동일)
3. 메시 URI는 절대 경로 사용: `file:///home/jo/clearpath_ws/clearpath/worlds/meshes/<file>`
4. 실행: `ros2 launch /home/jo/clearpath_ws/clearpath/simulation.launch.py world:=<world_name>`

## 주의 사항

- `platform-service.launch.py`는 `clearpath_generator_gz`에 의해 자동 생성됩니다. 수동 수정 사항을 보존하려면 항상 `generate:=false`를 사용하세요 (`simulation.launch.py`에 이미 설정됨).
- `robot.urdf.xacro`도 생성 파일이지만 `OdometryPublisher` 플러그인 추가를 위해 수동 수정되었습니다. `generate:=false` 사용 시 덮어쓰지 않습니다.
- `worlds/meshes/floor.dae`는 `.gitignore`에 추가하거나 Git LFS로 관리하는 것을 권장합니다 (바이너리 파일).
