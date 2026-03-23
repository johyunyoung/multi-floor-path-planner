# Clearpath Husky A200 — Simulation + TRG-Planner

ROS 2 Humble + Ignition Fortress 환경에서 Clearpath Husky A200 시뮬레이션 및 TRG-Planner (global path planner) 통합 워크스페이스입니다.

## 환경

| 항목 | 버전 |
|------|------|
| ROS | ROS 2 Humble |
| Simulator | Ignition Gazebo (Fortress, `libignition-gazebo6` 6.17.1) |
| Robot | Clearpath Husky A200 (`a200-0000`) |
| Planner | TRG-Planner (Traversal Risk Graph) |

## 주요 특징

- **Ground-truth odometry**: Ignition `OdometryPublisher` (P3D 등가)로 wheel slip·벽 충돌과 무관한 월드 절대 pose를 EKF 입력으로 사용
- **Full 3D pose 추적**: x·y·z 위치 및 roll·pitch·yaw 회전 모두 RViz에 반영
- **TRG-Planner 통합**: 라이다 기반 global path planning, RViz에서 경로 시각화
- **멀티 월드 지원**: `world:=<name>` 인자로 커스텀/내장 월드 즉시 전환
- **단일 커맨드 실행**: Gazebo + 로봇 스폰 + TRG-Planner + RViz 통합

## 디렉토리 구조

```
clearpath_ws/
├── clearpath/                          # 로봇 설정 (핵심 디렉토리)
│   ├── simulation.launch.py            # 시뮬레이션 launch (Gazebo + spawn + RViz)
│   ├── trg_navigation.launch.py        # TRG-Planner 통합 launch
│   ├── robot.yaml                      # Clearpath 로봇 설정
│   ├── robot.urdf.xacro                # URDF (OdometryPublisher 3D 포함)
│   ├── rviz/navigation.rviz            # RViz config (Path, LiDAR, 2D Nav Goal)
│   ├── platform/
│   │   ├── config/localization.yaml    # EKF (ground truth 3D)
│   │   ├── config/control.yaml         # diff_drive 컨트롤러
│   │   └── launch/platform-service.launch.py
│   ├── sensors/
│   │   ├── config/lidar3d_0.yaml
│   │   └── launch/sensors-service.launch.py  # 라이다 브리지
│   └── worlds/
│       ├── simple_multi_floor.sdf
│       └── meshes/floor.dae
│
└── src/
    ├── clearpath_common/               # Clearpath 공식 패키지
    ├── clearpath_config/
    ├── clearpath_msgs/
    └── TRG-planner-main/              # TRG global path planner
        ├── config/husky_warehouse.yaml  # Husky 전용 TRG 설정
        └── pipelines/ros2/config/husky_params.yaml  # 토픽 매핑
```

## 실행 방법

```bash
source /home/jo/clearpath_ws/install/setup.bash

# 시뮬레이션 + TRG-Planner (권장)
ros2 launch /home/jo/clearpath_ws/clearpath/trg_navigation.launch.py world:=warehouse

# 시뮬레이션만 (planner 없이)
ros2 launch /home/jo/clearpath_ws/clearpath/simulation.launch.py

# 커스텀 월드 + 스폰 위치 지정
ros2 launch /home/jo/clearpath_ws/clearpath/trg_navigation.launch.py world:=simple_multi_floor x:=1.0 y:=2.0
```

## RViz에서 경로 생성

1. 실행 후 RViz 상단 툴바에서 **2D Nav Goal** 클릭
2. 맵에 목표점을 드래그하여 지정
3. 녹색 경로(`/trg/output/path`)가 자동 표시됨

## 아키텍처

### Ground-truth Odometry

```
Ignition Gazebo (WorldPose ECS)
  └─ OdometryPublisher (3D)
       └─ ros_gz_bridge → /a200_0000/ground_truth/odom
            └─ EKF (robot_localization) → odom→base_link TF → RViz
```

### TRG-Planner 파이프라인

```
/a200_0000/lidar3d_0/points (PointCloud2) ──→ TRG obsCloud
/a200_0000/ground_truth/odom (Odometry)   ──→ TRG egoOdom
/goal_pose (RViz 2D Nav Goal)             ──→ TRG goal
                                               └─→ /trg/output/path → RViz
```

## 커스텀 월드 추가

1. 메시 파일을 `clearpath/worlds/meshes/`에 저장
2. `clearpath/worlds/<world_name>.sdf` 생성 (world name = 파일명)
3. 메시 URI는 절대 경로: `file:///home/jo/clearpath_ws/clearpath/worlds/meshes/<file>`
4. 실행: `world:=<world_name>`

## 주의 사항

- `platform-service.launch.py`와 `robot.urdf.xacro`는 수동 수정 파일 — `generate:=false` 필수 (이미 설정됨)
- TRG C++ core는 사전 설치 필요: `cd src/TRG-planner-main && sudo make cppinstall`
- `worlds/meshes/floor.dae`는 바이너리 — Git LFS 권장
