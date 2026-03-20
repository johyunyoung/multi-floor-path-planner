from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument, ExecuteProcess
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import EnvironmentVariable, FindExecutable, PathJoinSubstitution, LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():

    # Lidar PointCloud2 bridge (Gazebo → ROS)
    node_lidar_bridge = Node(
        name='lidar3d_0_bridge',
        executable='parameter_bridge',
        package='ros_gz_bridge',
        namespace='a200_0000',
        output='screen',
        arguments=[
            '/a200_0000/sensors/lidar3d_0/scan/points'
            '@sensor_msgs/msg/PointCloud2'
            '[ignition.msgs.PointCloudPacked'
        ],
        remappings=[
            ('/a200_0000/sensors/lidar3d_0/scan/points', 'lidar3d_0/points'),
        ],
        parameters=[{'use_sim_time': True}],
    )

    # Create LaunchDescription
    ld = LaunchDescription()
    ld.add_action(node_lidar_bridge)
    return ld
