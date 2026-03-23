# Clearpath Husky A200 Simulation Workspace

## Overview

ROS 2 Humble + Ignition Fortress 환경의 Clearpath Husky A200 시뮬레이션 워크스페이스.
TRG-Planner (global path planner) 통합 포함.

## Workspace Structure

```
clearpath_ws/
├── CLAUDE.md               # 이 파일
├── README.md
├── .gitignore
├── clearpath/              # 로봇 설정 (핵심 작업 디렉토리)
│   ├── simulation.launch.py        # 시뮬레이션 launch (Gazebo + spawn + RViz)
│   ├── trg_navigation.launch.py    # TRG-Planner 통합 launch
│   ├── robot.yaml                  # Clearpath 로봇 설정
│   ├── robot.urdf.xacro            # URDF (OdometryPublisher 3D 플러그인 포함)
│   ├── rviz/navigation.rviz        # RViz config (Path, LiDAR, 2D Nav Goal)
│   ├── platform/                   # 플랫폼 설정 + launch
│   ├── sensors/                    # 센서 설정 + launch (lidar bridge 포함)
│   ├── manipulators/               # 매니퓰레이터 설정
│   └── worlds/                     # 커스텀 월드 SDF + 메시
├── src/
│   ├── clearpath_common/           # Clearpath 공식 패키지 (git submodule)
│   ├── clearpath_config/           # Clearpath 공식 패키지
│   ├── clearpath_msgs/             # Clearpath 공식 패키지
│   └── TRG-planner-main/          # TRG global path planner
└── build/ install/ log/            # colcon 빌드 산출물 (.gitignore 처리)
```

## Key Commands

```bash
# 시뮬레이션만 실행 (Gazebo + RViz)
source install/setup.bash
ros2 launch /home/jo/clearpath_ws/clearpath/simulation.launch.py

# TRG-Planner 포함 실행 (시뮬레이션 + path planning)
ros2 launch /home/jo/clearpath_ws/clearpath/trg_navigation.launch.py world:=warehouse

# 커스텀 월드로 실행
ros2 launch /home/jo/clearpath_ws/clearpath/trg_navigation.launch.py world:=simple_multi_floor

# TRG-Planner만 리빌드
colcon build --packages-select trg_planner_ros --cmake-args -DCMAKE_BUILD_TYPE=Release
```

## Robot Configuration

- **Platform**: Husky A200 (`a200-0000`)
- **Namespace**: `a200_0000`
- **Sensors**: Velodyne VLP-16 LiDAR (`lidar3d_0`), Microstrain IMU (`imu_0`)
- **Controller**: PS4 gamepad

## Architecture

### Odometry Pipeline (Ground Truth)

```
Ignition Gazebo WorldPose
  → OdometryPublisher (3D, <dimensions>3</dimensions>)
    → ros_gz_bridge → /a200_0000/ground_truth/odom
      → EKF (robot_localization) → odom→base_link TF
```

- `control.yaml`: `enable_odom_tf: False` (diff drive는 TF 미발행)
- `localization.yaml`: `odom0: ground_truth/odom`, `two_d_mode: False`, 6DOF 활성화
- `robot.urdf.xacro`: `OdometryPublisher` 플러그인 (`<dimensions>3</dimensions>`)

### TRG-Planner Integration

```
/a200_0000/lidar3d_0/points (PointCloud2) → TRG obsCloud input
/a200_0000/ground_truth/odom (Odometry)   → TRG egoOdom input
/goal_pose (PoseStamped, RViz 2D Nav Goal) → TRG goal input
                                            → /trg/output/path (Path) → RViz
```

- **Config**: `src/TRG-planner-main/config/husky_warehouse.yaml` (live cloud, robotSize=0.5)
- **Params**: `src/TRG-planner-main/pipelines/ros2/config/husky_params.yaml` (토픽 매핑)
- **TF remap**: TRG 노드는 `/tf` → `/a200_0000/tf` 리매핑 (네임스페이스 TF 접근)

### Sensor Bridge

- `sensors-service.launch.py`: Velodyne PointCloud2 bridge (Gazebo → ROS)
- `platform-service.launch.py`: cmd_vel bridge + ground truth odom bridge

## Important Notes

### generate:=false 필수
`platform-service.launch.py`와 `robot.urdf.xacro`는 수동 수정 파일.
`clearpath_generator_gz`가 덮어쓰지 않도록 `simulation.launch.py`에서 `generate:=false` 설정됨.

### TRG-Planner 빌드 주의사항
- C++ core 라이브러리는 `/usr/local/lib/libtrg_planner_core.a`에 사전 설치 필요 (`sudo make cppinstall`)
- `pipelines/ros1/COLCON_IGNORE`, `pipelines/ros2/COLCON_IGNORE` 존재해야 중복 package.xml 방지
- `TRG_ROS_DIR`은 컴파일 타임 경로 → config 파일은 반드시 소스 트리 `config/`에 위치

### 커스텀 월드 추가
1. 메시를 `clearpath/worlds/meshes/`에 저장
2. `clearpath/worlds/<name>.sdf` 생성 (world name = 파일명)
3. 메시 URI는 절대 경로: `file:///home/jo/clearpath_ws/clearpath/worlds/meshes/<file>`
4. `world:=<name>` 인자로 실행

### QoS 이슈
`ros_gz_bridge`는 `BEST_EFFORT`로 퍼블리시. TRG-Planner의 `obs_cloud_` 구독이 `RELIABLE`이면 데이터를 못 받을 수 있음.
→ `ros2_node.h` 46행: `rclcpp::SensorDataQoS()`로 변경 필요할 수 있음.
