#!/usr/bin/env python3
"""
Converts Gazebo ground truth world pose into ROS odom->base_link TF.

This node replaces the wheel-odometry-based TF bridge so that RViz reflects
the robot's actual physical position in Gazebo even when wheels slip or the
robot is blocked by a wall.

Topic flow:
  Ignition /world/<world>/dynamic_pose/info (Pose_V)
      → ros_gz_bridge → /gz_world_poses (TFMessage)
          → this node → /tf  (odom -> base_link, ground truth)
                       → /tf_static (world -> odom, identity)
"""

import rclpy
from rclpy.node import Node
from tf2_msgs.msg import TFMessage
from geometry_msgs.msg import TransformStamped
from tf2_ros import StaticTransformBroadcaster


class GzGroundTruthTF(Node):
    def __init__(self):
        super().__init__('gz_ground_truth_tf')

        self.declare_parameter('world_frame', 'warehouse')
        self.declare_parameter('robot_frame', 'a200_0000/robot')
        self.declare_parameter('odom_frame', 'odom')
        self.declare_parameter('base_frame', 'base_link')

        self.world_frame = self.get_parameter('world_frame').value
        self.robot_frame = self.get_parameter('robot_frame').value
        self.odom_frame = self.get_parameter('odom_frame').value
        self.base_frame = self.get_parameter('base_frame').value

        self.get_logger().info(
            f'Ground truth TF: [{self.world_frame} -> {self.robot_frame}] '
            f'republished as [{self.odom_frame} -> {self.base_frame}]'
        )

        # Publish world -> odom as a static identity transform so that
        # the TF chain world->odom->base_link is complete.
        static_tf = TransformStamped()
        static_tf.header.frame_id = self.world_frame
        static_tf.child_frame_id = self.odom_frame
        static_tf.transform.rotation.w = 1.0  # identity quaternion

        self._static_broadcaster = StaticTransformBroadcaster(self)
        self._static_broadcaster.sendTransform(static_tf)

        self._pub = self.create_publisher(TFMessage, '/tf', 100)
        self._sub = self.create_subscription(
            TFMessage,
            '/gz_world_poses',
            self._on_gz_poses,
            10,
        )

        self._found = False

    def _on_gz_poses(self, msg: TFMessage):
        for tf in msg.transforms:
            if tf.child_frame_id != self.robot_frame:
                continue

            if not self._found:
                self.get_logger().info(
                    f'Ground truth frame found: {self.world_frame} -> {self.robot_frame}'
                )
                self._found = True

            out = TransformStamped()
            out.header.stamp = tf.header.stamp
            out.header.frame_id = self.odom_frame
            out.child_frame_id = self.base_frame
            out.transform = tf.transform

            self._pub.publish(TFMessage(transforms=[out]))
            return

        if not self._found:
            available = [t.child_frame_id for t in msg.transforms[:8]]
            self.get_logger().warn(
                f'Frame "{self.robot_frame}" not found yet. '
                f'Available (first 8): {available}',
                throttle_duration_sec=5.0,
            )


def main():
    rclpy.init()
    node = GzGroundTruthTF()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
