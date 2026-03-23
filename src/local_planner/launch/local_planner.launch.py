"""
Local Planner launch for Clearpath Husky A200 integration.

Three nodes:
  1. waypointExtractor: TRG path -> single waypoint
  2. localPlanner: obstacle-aware local path selection
  3. pathFollower: pure pursuit path tracking -> cmd_vel
"""

import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    pkg_share = get_package_share_directory('local_planner')
    path_folder = os.path.join(pkg_share, 'paths')

    # --- Arguments ---
    args = [
        DeclareLaunchArgument('max_speed', default_value='1.0'),
        DeclareLaunchArgument('autonomy_speed', default_value='1.0'),
    ]

    # --- Waypoint Extractor ---
    waypoint_extractor = Node(
        package='local_planner',
        executable='waypointExtractor',
        name='waypointExtractor',
        parameters=[{'use_sim_time': True, 'lookaheadDistance': 2.0}],
        remappings=[
            ('/trg/output/path', '/trg/output/path'),
            ('/state_estimation', '/a200_0000/ground_truth/odom'),
        ],
        output='screen',
    )

    # --- Local Planner ---
    local_planner = Node(
        package='local_planner',
        executable='localPlanner',
        name='localPlanner',
        parameters=[{
            'use_sim_time': True,
            'pathFolder': path_folder,
            'vehicleLength': 0.6,
            'vehicleWidth': 0.6,
            'sensorOffsetX': 0.0,
            'sensorOffsetY': 0.0,
            'twoWayDrive': True,
            'laserVoxelSize': 0.05,
            'terrainVoxelSize': 0.2,
            'useTerrainAnalysis': False,
            'checkObstacle': False,
            'checkRotObstacle': False,
            'adjacentRange': 4.25,
            'obstacleHeightThre': 0.15,
            'groundHeightThre': 0.1,
            'costHeightThre': 0.1,
            'costScore': 0.02,
            'useCost': False,
            'pointPerPathThre': 2,
            'minRelZ': -0.5,
            'maxRelZ': 0.25,
            'maxSpeed': 1.0,
            'dirWeight': 0.02,
            'dirThre': 90.0,
            'dirToVehicle': False,
            'pathScale': 1.25,
            'minPathScale': 0.75,
            'pathScaleStep': 0.25,
            'pathScaleBySpeed': True,
            'minPathRange': 1.0,
            'pathRangeStep': 0.5,
            'pathRangeBySpeed': True,
            'pathCropByGoal': True,
            'autonomyMode': True,
            'autonomySpeed': 1.0,
            'joyToSpeedDelay': 2.0,
            'joyToCheckObstacleDelay': 5.0,
            'goalClearRange': 0.5,
            'goalX': 0.0,
            'goalY': 0.0,
        }],
        remappings=[
            ('/state_estimation', '/a200_0000/ground_truth/odom'),
            ('/registered_scan', '/a200_0000/lidar3d_0/points'),
            ('/joy', '/a200_0000/joy'),
        ],
        output='screen',
    )

    # --- Path Follower ---
    path_follower = Node(
        package='local_planner',
        executable='pathFollower',
        name='pathFollower',
        parameters=[{
            'use_sim_time': True,
            'sensorOffsetX': 0.0,
            'sensorOffsetY': 0.0,
            'pubSkipNum': 1,
            'twoWayDrive': True,
            'lookAheadDis': 0.5,
            'yawRateGain': 7.5,
            'stopYawRateGain': 7.5,
            'maxYawRate': 90.0,
            'maxSpeed': 1.0,
            'maxAccel': 2.5,
            'switchTimeThre': 1.0,
            'dirDiffThre': 0.1,
            'stopDisThre': 0.2,
            'slowDwnDisThre': 0.85,
            'useInclRateToSlow': False,
            'inclRateThre': 120.0,
            'slowRate1': 0.25,
            'slowRate2': 0.5,
            'slowTime1': 2.0,
            'slowTime2': 2.0,
            'useInclToStop': False,
            'inclThre': 45.0,
            'stopTime': 5.0,
            'noRotAtStop': False,
            'noRotAtGoal': True,
            'autonomyMode': True,
            'autonomySpeed': 1.0,
            'joyToSpeedDelay': 2.0,
        }],
        remappings=[
            ('/state_estimation', '/a200_0000/ground_truth/odom'),
            ('/joy', '/a200_0000/joy'),
            ('/cmd_vel', '/a200_0000/cmd_vel'),
        ],
        output='screen',
    )

    ld = LaunchDescription(args)
    ld.add_action(waypoint_extractor)
    ld.add_action(local_planner)
    ld.add_action(path_follower)
    return ld
