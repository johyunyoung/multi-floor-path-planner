"""
Clearpath Husky + TRG-Planner navigation launcher.

Usage:
  ros2 launch /home/jo/clearpath_ws/clearpath/trg_navigation.launch.py
  ros2 launch /home/jo/clearpath_ws/clearpath/trg_navigation.launch.py world:=simple_multi_floor
"""

import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


SIM_LAUNCH = '/home/jo/clearpath_ws/clearpath/simulation.launch.py'

ARGUMENTS = [
    DeclareLaunchArgument('world', default_value='warehouse'),
    DeclareLaunchArgument('x',   default_value='0.0'),
    DeclareLaunchArgument('y',   default_value='0.0'),
    DeclareLaunchArgument('z',   default_value='0.3'),
    DeclareLaunchArgument('yaw', default_value='0.0'),
]


def generate_launch_description():
    # ── Simulation (Gazebo + robot spawn + RViz) ──────────────────────────
    sim = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(SIM_LAUNCH),
        launch_arguments=[
            ('world', LaunchConfiguration('world')),
            ('x',     LaunchConfiguration('x')),
            ('y',     LaunchConfiguration('y')),
            ('z',     LaunchConfiguration('z')),
            ('yaw',   LaunchConfiguration('yaw')),
        ],
    )

    # ── TRG-Planner ───────────────────────────────────────────────────────
    trg_pkg = get_package_share_directory('trg_planner_ros')
    husky_params = os.path.join(trg_pkg, 'config', 'husky_params.yaml')

    trg_node = Node(
        package='trg_planner_ros',
        executable='trg_ros2_node',
        name='trg_ros2_node',
        parameters=[
            husky_params,
            {'mapConfig': 'husky_warehouse', 'use_sim_time': True},
        ],
        remappings=[
            ('/tf', '/a200_0000/tf'),
            ('/tf_static', '/a200_0000/tf_static'),
        ],
        output='screen',
    )

    # ── Local Planner (waypoint extractor + local planner + path follower) ─
    local_planner_pkg = get_package_share_directory('local_planner')
    local_planner_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(local_planner_pkg, 'launch', 'local_planner.launch.py')
        ),
    )

    ld = LaunchDescription(ARGUMENTS)
    ld.add_action(sim)
    ld.add_action(trg_node)
    ld.add_action(local_planner_launch)
    return ld
