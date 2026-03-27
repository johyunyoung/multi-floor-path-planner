"""
Go2 + TRG-Planner + Local Planner navigation launcher.

Usage:
  ros2 launch /home/jo/clearpath_ws/go2/trg_navigation.launch.py
  ros2 launch /home/jo/clearpath_ws/go2/trg_navigation.launch.py world:=warehouse
"""

import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


SIM_LAUNCH = '/home/jo/clearpath_ws/go2/simulation.launch.py'

ARGUMENTS = [
    DeclareLaunchArgument('world', default_value='warehouse'),
    DeclareLaunchArgument('x',   default_value='0.0'),
    DeclareLaunchArgument('y',   default_value='0.0'),
    DeclareLaunchArgument('z',   default_value='0.5'),
    DeclareLaunchArgument('yaw', default_value='0.0'),
]


def generate_launch_description():
    # ── Simulation (Gazebo + Go2 spawn + RViz) ────────────────────────
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

    # ── TRG-Planner ─────────────────────────────────────────────────────
    trg_pkg = get_package_share_directory('trg_planner_ros')
    go2_params = os.path.join(trg_pkg, 'config', 'go2_params.yaml')

    trg_node = Node(
        package='trg_planner_ros',
        executable='trg_ros2_node',
        name='trg_ros2_node',
        parameters=[
            go2_params,
            {'mapConfig': 'go2_warehouse', 'use_sim_time': True},
        ],
        remappings=[
            ('/tf', '/go2_0000/tf'),
            ('/tf_static', '/go2_0000/tf_static'),
        ],
        output='screen',
    )

    # ── Local Planner ───────────────────────────────────────────────────
    local_planner_pkg = get_package_share_directory('local_planner')
    local_planner_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(local_planner_pkg, 'launch', 'local_planner_go2.launch.py')
        ),
    )

    ld = LaunchDescription(ARGUMENTS)
    ld.add_action(sim)
    ld.add_action(trg_node)
    ld.add_action(local_planner_launch)
    return ld
