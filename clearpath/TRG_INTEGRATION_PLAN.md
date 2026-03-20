# TRG-Planner Integration with Husky A200 Gazebo Simulation

## Context

TRG-Planner (Traversal Risk Graph 기반 global path planner)를 기존 Husky A200 Ignition Gazebo 시뮬레이션에 통합하여, 생성된 경로를 RViz에서 시각화한다.

**현재 문제점:**
- TRG-Planner ROS2 패키지 미빌드
- 라이다 센서 브리지 미작동 (`sensors-service.launch.py`가 빈 파일)
- TRG-Planner 토픽/프레임이 시뮬레이션과 매칭되지 않음

**목표:** 단일 launch 명령으로 Gazebo + 로봇 + TRG-Planner + RViz 실행, RViz "2D Nav Goal"로 목표점 지정 시 경로 시각화

---

## Step 1: Lidar 센서 브리지 추가

**파일:** `clearpath/sensors/launch/sensors-service.launch.py` (현재 빈 파일)

라이다 PointCloud2 브리지 노드 추가. 기존 platform bridge 패턴(`parameter_bridge` + 인자 형식) 참조:

```python
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
```

---

## Step 2: Colcon 빌드 충돌 해결

`pipelines/` 하위에 `package.xml`이 3개(pipelines, ros1, ros2) 존재 → colcon 중복 패키지 에러.

**생성할 파일:**
- `src/TRG-planner-main/pipelines/ros1/COLCON_IGNORE` (빈 파일)
- `src/TRG-planner-main/pipelines/ros2/COLCON_IGNORE` (빈 파일)

상위 `pipelines/CMakeLists.txt`가 `add_subdirectory(ros2)`로 포함하므로 빌드에 영향 없음.

---

## Step 3: Husky 전용 TRG 설정 파일 생성

**파일:** `src/TRG-planner-main/config/husky_warehouse.yaml`

`indoor.yaml` 기반, Husky 크기와 live cloud 모드에 맞게 조정:

```yaml
isVerbose: true
timer:
  graphRate: 5.0
  planningRate: 10.0
map:
  isPrebuiltMap: false      # prebuilt PCD 없이 live cloud 사용
  prebuiltMapPath: ""
  isVoxelize: true
  voxelSize: 0.2
trg:
  isPrebuiltTRG: false
  prebuiltTRGPath: ""
  isUpdate: true            # live cloud 환경에서 그래프 갱신
  expandDist: 0.6
  robotSize: 0.5            # Husky inscribed radius (~0.67m 폭)
  sampleNum: 15
  heightThreshold: 0.2
  collisionThreshold: 0.15
  updateCollisionThreshold: 0.15
  safetyFactor: 3.0
  goalTolerance: 0.8
```

`mapConfig` 파라미터로 `husky_warehouse`를 전달하면 TRG 노드가 `TRG_ROS_DIR/../config/husky_warehouse.yaml`을 로드함 (컴파일 타임 경로 `pipelines/` 기준).

---

## Step 4: Husky 전용 ROS2 파라미터 생성

**파일:** `src/TRG-planner-main/pipelines/ros2/config/husky_params.yaml`

토픽 매핑 (TRG 기본 → Husky 시뮬레이션):

| TRG 입력 | 기본값 | 매핑 대상 |
|-----------|--------|-----------|
| `egoOdom` | `/fake_robot_pose` | `/a200_0000/ground_truth/odom` |
| `obsCloud` | `/trip/.../alocal_cloud` | `/a200_0000/lidar3d_0/points` |
| `goal` | `/fake_goal` | `/goal_pose` (RViz 2D Nav Goal) |

`frameId`는 `odom`으로 설정 — TRG 노드의 `state_.frame_id`는 odom 메시지의 `header.frame_id`("odom")에서 동적으로 결정되므로, debug marker의 `param_.frame_id`도 이에 맞춤. 별도 `map` → `odom` TF 불필요.

---

## Step 5: TRG-Planner 빌드

```bash
cd /home/jo/clearpath_ws
colcon build --packages-select trg_planner_ros --cmake-args -DCMAKE_BUILD_TYPE=Release
source install/setup.bash
```

**주의:** `ros2/CMakeLists.txt` 41행에 `${PCL_INCLUDE_DIRS}`가 `target_link_libraries`에 있음 — 링크 에러 시 `${PCL_LIBRARIES}`로 수정 필요.

---

## Step 6: 통합 Launch 파일 생성

**파일:** `clearpath/trg_navigation.launch.py`

```
simulation.launch.py (Gazebo + spawn + RViz)
  └─ trg_ros2_node (husky_params.yaml + mapConfig=husky_warehouse + use_sim_time=true)
```

`world:=` 인자를 simulation.launch.py에 전달. TRG 노드는 네임스페이스 없이 실행 (토픽은 파라미터에서 절대 경로로 지정).

---

## Step 7: 검증

```bash
# 1. 실행
ros2 launch /home/jo/clearpath_ws/clearpath/trg_navigation.launch.py world:=warehouse

# 2. 라이다 데이터 확인
ros2 topic hz /a200_0000/lidar3d_0/points

# 3. TF 체인 확인 (odom → lidar3d_0_laser)
ros2 run tf2_ros tf2_echo odom lidar3d_0_laser

# 4. TRG 초기화 확인 — 콘솔에 "TRG Planner ROS2 initialized" 출력

# 5. RViz에서 Path 디스플레이 추가 (토픽: /trg/output/path)

# 6. RViz "2D Nav Goal" 클릭 → /goal_pose 발행 → 경로 생성 및 시각화 확인
```

---

## 잠재적 이슈

| 이슈 | 원인 | 해결 |
|------|------|------|
| TRG가 point cloud 못 받음 | QoS 불일치 — bridge는 `BEST_EFFORT`, TRG는 `RELIABLE` (`qos.for_reli`) | `ros2_node.h` 46행: `rclcpp::SensorDataQoS()`로 변경 |
| 빌드 링크 에러 | `ros2/CMakeLists.txt` 41행 `PCL_INCLUDE_DIRS` 오타 | `${PCL_LIBRARIES}`로 수정 |
| config 파일 못 찾음 | `TRG_ROS_DIR`이 컴파일 타임 경로 | config는 반드시 소스 트리 `config/`에 위치 |

---

## 수정/생성 파일 요약

| 파일 | 액션 |
|------|------|
| `clearpath/sensors/launch/sensors-service.launch.py` | 수정 — 라이다 브리지 추가 |
| `src/TRG-planner-main/pipelines/ros1/COLCON_IGNORE` | 생성 (빈 파일) |
| `src/TRG-planner-main/pipelines/ros2/COLCON_IGNORE` | 생성 (빈 파일) |
| `src/TRG-planner-main/config/husky_warehouse.yaml` | 생성 — TRG 알고리즘 설정 |
| `src/TRG-planner-main/pipelines/ros2/config/husky_params.yaml` | 생성 — 토픽/프레임 매핑 |
| `clearpath/trg_navigation.launch.py` | 생성 — 통합 launch |
| `src/TRG-planner-main/pipelines/ros2/CMakeLists.txt` | 조건부 수정 (PCL 링크 에러 시) |
| `src/TRG-planner-main/pipelines/ros2/include/ros2_node.h` | 조건부 수정 (QoS 불일치 시) |
