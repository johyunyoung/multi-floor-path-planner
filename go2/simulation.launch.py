"""
Unitree Go2 simulation launcher for Ignition Fortress.

Usage:
  ros2 launch /home/jo/clearpath_ws/go2/simulation.launch.py
  ros2 launch /home/jo/clearpath_ws/go2/simulation.launch.py world:=warehouse
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
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

import xacro


CUSTOM_WORLDS_DIR = '/home/jo/clearpath_ws/clearpath/worlds'
GO2_DIR = '/home/jo/clearpath_ws/go2'
RVIZ_CONFIG = '/home/jo/clearpath_ws/go2/rviz/navigation.rviz'

ARGUMENTS = [
    DeclareLaunchArgument('world', default_value='warehouse'),
    DeclareLaunchArgument('x',   default_value='0.0'),
    DeclareLaunchArgument('y',   default_value='0.0'),
    DeclareLaunchArgument('z',   default_value='0.5'),
    DeclareLaunchArgument('yaw', default_value='0.0'),
]


def launch_setup(context, *args, **kwargs):
    world = LaunchConfiguration('world').perform(context)

    pkg_clearpath_gz = get_package_share_directory('clearpath_gz')
    pkg_ros_gz_sim   = get_package_share_directory('ros_gz_sim')

    # ── Resource path (same worlds as Husky) ────────────────────────────
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

    # Ensure Gazebo can find ign_ros2_control plugin
    set_plugin_path = SetEnvironmentVariable(
        name='IGN_GAZEBO_SYSTEM_PLUGIN_PATH',
        value='/opt/ros/humble/lib',
    )

    # ── Gazebo ──────────────────────────────────────────────────────────
    gui_config = os.path.join(pkg_clearpath_gz, 'config', 'gui.config')

    gz_sim = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_ros_gz_sim, 'launch', 'gz_sim.launch.py')
        ),
        launch_arguments=[
            ('gz_args', f'{world}.sdf -r -v 4 --gui-config {gui_config}'),
        ],
    )

    # Clock bridge
    clock_bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        name='clock_bridge',
        output='screen',
        arguments=['/clock@rosgraph_msgs/msg/Clock[ignition.msgs.Clock'],
    )

    # ── Go2 URDF processing ────────────────────────────────────────────
    urdf_path = os.path.join(GO2_DIR, 'robot.urdf.xacro')
    robot_description = xacro.process_file(urdf_path, mappings={'is_sim': 'true'}).toxml()

    # Robot state publisher
    # joint_state_broadcaster publishes to root /joint_states (controller_manager
    # is in root namespace), so remap to receive it in the go2_0000 namespace.
    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        namespace='go2_0000',
        parameters=[{
            'robot_description': robot_description,
            'use_sim_time': True,
        }],
        remappings=[
            ('joint_states', '/joint_states'),
            ('/tf', '/go2_0000/tf'),
            ('/tf_static', '/go2_0000/tf_static'),
        ],
        output='screen',
    )

    # Spawn Go2 into Ignition
    spawn_robot = Node(
        package='ros_gz_sim',
        executable='create',
        name='go2_spawn',
        namespace='go2_0000',
        arguments=[
            '-name', 'go2_0000',
            '-topic', 'robot_description',
            '-x', LaunchConfiguration('x'),
            '-y', LaunchConfiguration('y'),
            '-z', LaunchConfiguration('z'),
            '-Y', LaunchConfiguration('yaw'),
        ],
        output='screen',
    )

    # ── Bridges ─────────────────────────────────────────────────────────
    # Ground truth odom bridge (Ignition → ROS)
    odom_bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        name='ground_truth_odom_bridge',
        namespace='go2_0000',
        arguments=[
            '/model/go2_0000/odometry@nav_msgs/msg/Odometry[ignition.msgs.Odometry',
        ],
        remappings=[
            ('/model/go2_0000/odometry', 'ground_truth/odom'),
        ],
        output='screen',
    )

    # LiDAR bridge (Ignition → ROS)
    lidar_bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        name='lidar3d_0_bridge',
        namespace='go2_0000',
        arguments=[
            '/go2_0000/sensors/lidar3d_0/scan/points'
            '@sensor_msgs/msg/PointCloud2'
            '[ignition.msgs.PointCloudPacked',
        ],
        remappings=[
            ('/go2_0000/sensors/lidar3d_0/scan/points', 'lidar3d_0/points'),
        ],
        output='screen',
    )

    # ── Controller spawners ─────────────────────────────────────────────
    joint_state_broadcaster_spawner = Node(
        package='controller_manager',
        executable='spawner',
        arguments=['joint_state_broadcaster'],
        output='screen',
    )

    joint_trajectory_controller_spawner = Node(
        package='controller_manager',
        executable='spawner',
        arguments=['joint_trajectory_controller'],
        output='screen',
    )

    # ── EKF ──────────────────────────────────────────────────────────────
    ekf_node = Node(
        package='robot_localization',
        executable='ekf_node',
        name='ekf_node',
        namespace='go2_0000',
        parameters=[
            os.path.join(GO2_DIR, 'platform', 'config', 'localization.yaml'),
            {'use_sim_time': True},
        ],
        remappings=[
            ('/tf', '/go2_0000/tf'),
        ],
        output='screen',
    )

    # ── CHAMP quadruped controller ──────────────────────────────────────
    champ_controller = Node(
        package='champ_base',
        executable='quadruped_controller_node',
        name='quadruped_controller_node',
        namespace='go2_0000',
        parameters=[
            os.path.join(GO2_DIR, 'platform', 'config', 'champ.yaml'),
            os.path.join(GO2_DIR, 'platform', 'config', 'links.yaml'),
            os.path.join(GO2_DIR, 'platform', 'config', 'joints.yaml'),
            {'use_sim_time': True, 'urdf': robot_description},
        ],
        remappings=[
            ('cmd_vel/smooth', 'cmd_vel'),
            ('joint_trajectory_controller/joint_trajectory',
             '/joint_trajectory_controller/joint_trajectory'),
        ],
        output='screen',
    )

    # ── Static TF: vehicle frame for local planner ───────────────────────
    vehicle_frame_bridge = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='vehicle_frame_bridge',
        namespace='go2_0000',
        arguments=['0', '0', '0', '0', '0', '0',
                   'base_link', 'vehicle'],
        parameters=[{'use_sim_time': True}],
        remappings=[
            ('/tf_static', '/go2_0000/tf_static'),
        ],
        output='screen',
    )

    # ── RViz ─────────────────────────────────────────────────────────────
    rviz = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        namespace='go2_0000',
        arguments=['-d', RVIZ_CONFIG],
        parameters=[{'use_sim_time': True}],
        remappings=[
            ('/tf', '/go2_0000/tf'),
            ('/tf_static', '/go2_0000/tf_static'),
        ],
        output='screen',
    )

    return [
        set_resource_path,
        set_plugin_path,
        gz_sim,
        clock_bridge,
        robot_state_publisher,
        spawn_robot,
        odom_bridge,
        lidar_bridge,
        vehicle_frame_bridge,
        joint_state_broadcaster_spawner,
        joint_trajectory_controller_spawner,
        ekf_node,
        champ_controller,
        rviz,
    ]


def generate_launch_description():
    ld = LaunchDescription(ARGUMENTS)
    ld.add_action(OpaqueFunction(function=launch_setup))
    return ld
