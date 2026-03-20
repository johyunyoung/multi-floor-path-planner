"""
Clearpath Husky simulation launcher.

World resolution order:
  1. /home/jo/clearpath_ws/clearpath/worlds/<world>.sdf  (custom worlds)
  2. clearpath_gz/worlds/<world>.sdf         (built-in worlds: warehouse, ...)

Usage:
  ros2 launch /home/jo/clearpath_ws/clearpath/simulation.launch.py
  ros2 launch /home/jo/clearpath_ws/clearpath/simulation.launch.py world:=simple_multi_floor
  ros2 launch /home/jo/clearpath_ws/clearpath/simulation.launch.py world:=warehouse x:=1.0
"""

import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import (
    DeclareLaunchArgument,
    IncludeLaunchDescription,
    OpaqueFunction,
    SetEnvironmentVariable,
)
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


CUSTOM_WORLDS_DIR = '/home/jo/clearpath_ws/clearpath/worlds'
SETUP_PATH = '/home/jo/clearpath_ws/clearpath/'

ARGUMENTS = [
    DeclareLaunchArgument(
        'world', default_value='warehouse',
        description='World name. Custom worlds in ~/clearpath/worlds/ take priority.'),
    DeclareLaunchArgument('x',   default_value='0.0'),
    DeclareLaunchArgument('y',   default_value='0.0'),
    DeclareLaunchArgument('z',   default_value='0.3'),
    DeclareLaunchArgument('yaw', default_value='0.0'),
]


def launch_setup(context, *args, **kwargs):
    world = LaunchConfiguration('world').perform(context)

    pkg_clearpath_gz = get_package_share_directory('clearpath_gz')
    pkg_ros_gz_sim   = get_package_share_directory('ros_gz_sim')
    pkg_clearpath_viz = get_package_share_directory('clearpath_viz')

    # ── Resource path ────────────────────────────────────────────────────────
    # Custom worlds dir is prepended so it takes priority over built-in worlds.
    ros_share_dirs = [
        os.path.join(p, 'share')
        for p in os.getenv('AMENT_PREFIX_PATH', '').split(':') if p
    ]
    resource_path = ':'.join([
        CUSTOM_WORLDS_DIR,
        os.path.join(pkg_clearpath_gz, 'worlds'),
    ] + ros_share_dirs)

    set_resource_path = SetEnvironmentVariable(
        name='IGN_GAZEBO_RESOURCE_PATH',
        value=resource_path,
    )

    # ── Gazebo ───────────────────────────────────────────────────────────────
    gui_config = os.path.join(pkg_clearpath_gz, 'config', 'gui.config')

    gz_sim = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_ros_gz_sim, 'launch', 'gz_sim.launch.py')
        ),
        launch_arguments=[
            ('gz_args', f'{world}.sdf -r -v 4 --gui-config {gui_config}'),
        ],
    )

    # Clock bridge (normally provided by clearpath_gz/gz_sim.launch.py)
    clock_bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        name='clock_bridge',
        output='screen',
        arguments=['/clock@rosgraph_msgs/msg/Clock[ignition.msgs.Clock'],
    )

    # ── Robot spawn ──────────────────────────────────────────────────────────
    robot_spawn = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_clearpath_gz, 'launch', 'robot_spawn.launch.py')
        ),
        launch_arguments=[
            ('generate',   'false'),
            ('use_sim_time', 'true'),
            ('setup_path', SETUP_PATH),
            ('world',      world),
            ('rviz',       'false'),
            ('x',   LaunchConfiguration('x')),
            ('y',   LaunchConfiguration('y')),
            ('z',   LaunchConfiguration('z')),
            ('yaw', LaunchConfiguration('yaw')),
        ],
    )

    # ── RViz ─────────────────────────────────────────────────────────────────
    rviz = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([pkg_clearpath_viz, 'launch', 'view_robot.launch.py'])
        ),
        launch_arguments=[
            ('namespace',    'a200_0000'),
            ('use_sim_time', 'true'),
        ],
    )

    return [set_resource_path, gz_sim, clock_bridge, robot_spawn, rviz]


def generate_launch_description():
    ld = LaunchDescription(ARGUMENTS)
    ld.add_action(OpaqueFunction(function=launch_setup))
    return ld
