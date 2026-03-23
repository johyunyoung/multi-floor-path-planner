#!/usr/bin/env python3
"""3D Goal Pose Publisher for TRG-Planner.

Interactive mode (default):
    python3 goal_pose_pub.py
    > 5.0 3.0 0.0 90

One-shot mode:
    python3 goal_pose_pub.py --once 5.0 3.0 0.0 90

All coordinates are in the odom frame (robot initial pose = origin).
Yaw is in degrees.
"""

import argparse
import sys
from math import cos, radians, sin

import rclpy
from geometry_msgs.msg import PoseStamped
from rclpy.node import Node


class GoalPosePub(Node):
    def __init__(self, frame_id="odom"):
        super().__init__("goal_pose_pub")
        self.pub = self.create_publisher(PoseStamped, "/goal_pose", 10)
        self.frame_id = frame_id

    def publish_goal(self, x, y, z, yaw_deg):
        msg = PoseStamped()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = self.frame_id
        msg.pose.position.x = x
        msg.pose.position.y = y
        msg.pose.position.z = z
        yaw = radians(yaw_deg)
        msg.pose.orientation.z = sin(yaw / 2.0)
        msg.pose.orientation.w = cos(yaw / 2.0)
        self.pub.publish(msg)
        self.get_logger().info(
            f"Goal: x={x:.2f} y={y:.2f} z={z:.2f} yaw={yaw_deg:.1f}deg"
        )


def parse_xyzw(text):
    """Parse 'x y z yaw' string. Returns (x, y, z, yaw_deg) or None."""
    parts = text.strip().split()
    if len(parts) != 4:
        return None
    try:
        return tuple(float(v) for v in parts)
    except ValueError:
        return None


def main():
    parser = argparse.ArgumentParser(description="Publish 3D goal pose (x y z yaw)")
    parser.add_argument("--frame", default="odom", help="frame_id (default: odom)")
    parser.add_argument(
        "--once",
        nargs=4,
        type=float,
        metavar=("X", "Y", "Z", "YAW"),
        help="One-shot: publish once and exit",
    )
    args = parser.parse_args()

    rclpy.init()
    node = GoalPosePub(frame_id=args.frame)

    if args.once:
        # Allow publisher to be discovered
        import time
        time.sleep(0.3)
        node.publish_goal(*args.once)
        rclpy.spin_once(node, timeout_sec=0.5)
        node.destroy_node()
        rclpy.shutdown()
        return

    # Interactive mode
    print("=== 3D Goal Pose Publisher ===")
    print(f"Frame: {args.frame}")
    print("Enter: x y z yaw(deg)  |  'q' to quit")
    print("Example: 5.0 3.0 0.0 90")
    print()

    try:
        while True:
            try:
                line = input("> ")
            except EOFError:
                break
            if line.strip().lower() in ("q", "quit", "exit"):
                break
            result = parse_xyzw(line)
            if result is None:
                print("  Invalid input. Format: x y z yaw(deg)")
                continue
            node.publish_goal(*result)
            rclpy.spin_once(node, timeout_sec=0.1)
    except KeyboardInterrupt:
        print()

    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
