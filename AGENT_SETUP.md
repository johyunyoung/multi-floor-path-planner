# Agent Setup Guide — Multi-Floor Path Planner

This document is written for an LLM agent to reproduce the exact development environment from scratch.
Follow every step in order. Do not skip steps.

---

## Quick Reference: Build Order

| Step | Action | Prerequisite |
|------|--------|-------------|
| 0–2 | System packages + ROS 2 + Ignition install | None |
| 3 | `apt install` ROS packages | ROS apt repo registered |
| 4 | `git clone --recurse-submodules` | None |
| 5 | `vcs import` (Clearpath source packages) | Clone complete |
| 6 | `sudo make cppinstall` (TRG C++ core → `/usr/local`) | PCL, Eigen3, OpenCV installed (Step 0) |
| 7 | Create COLCON_IGNORE files (5 files) | Clone complete |
| 8 | Path remapping (only if not `/home/jo/clearpath_ws`) | Clone complete |
| 9 | `rosdep install` | Step 5 complete |
| 10 | `colcon build` | Steps 6, 7, 9 all complete |
| 11 | Verify | Step 10 complete |
| 12 | Run simulation | Step 11 passed |

> **Critical order:** Step 6 must come before Step 10. `colcon build` links against
> `libtrg_planner_core.a` which is only available after `sudo make cppinstall`.
> Step 7 must also come before Step 10 to avoid duplicate `package.xml` conflicts.

---

## Target Environment

| Item | Version |
|------|---------|
| OS | Ubuntu 22.04 LTS (Jammy) |
| ROS | ROS 2 Humble |
| Simulator | Ignition Gazebo Fortress (`libignition-gazebo6`) |
| Robot | Clearpath Husky A200 (`a200-0000`) |
| Global Planner | TRG-Planner (Traversal Risk Graph) |
| Local Planner | Custom 3-node pipeline (waypoint extraction + local planner + path follower) |
| Shell | bash |

---

## Step 0 — System Prerequisites

```bash
# Verify Ubuntu 22.04
lsb_release -a

# Install build essentials and C++ dependencies required by TRG core
sudo apt update
sudo apt install -y git curl wget build-essential cmake \
    gcc g++ libeigen3-dev python3-pip python3-dev \
    libpcl-dev libopencv-dev libyaml-cpp-dev
```

---

## Step 1 — Install ROS 2 Humble

```bash
# Add ROS 2 apt repository
sudo apt install -y software-properties-common
sudo add-apt-repository universe
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key \
    -o /usr/share/keyrings/ros-archive-keyring.gpg
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] \
    http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" \
    | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null

sudo apt update
sudo apt install -y ros-humble-desktop

# Source ROS 2 in every new shell
echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
source ~/.bashrc
```

---

## Step 2 — Install Ignition Gazebo Fortress

```bash
sudo apt install -y ignition-fortress
```

---

## Step 3 — Install ROS 2 Packages Required by This Workspace

```bash
sudo apt install -y \
    ros-humble-ros-gz \
    ros-humble-ros-gz-bridge \
    ros-humble-ros-gz-sim \
    ros-humble-clearpath-gz \
    ros-humble-robot-localization \
    ros-humble-ros2-control \
    ros-humble-ros2-controllers \
    ros-humble-diff-drive-controller \
    ros-humble-joint-state-broadcaster \
    ros-humble-robot-state-publisher \
    ros-humble-joint-state-publisher \
    ros-humble-rviz2 \
    ros-humble-tf2 \
    ros-humble-tf2-ros \
    ros-humble-tf2-geometry-msgs \
    ros-humble-pcl-ros \
    ros-humble-pcl-conversions \
    ros-humble-nav-msgs \
    ros-humble-sensor-msgs \
    ros-humble-geometry-msgs \
    ros-humble-std-msgs \
    ros-humble-message-filters \
    ros-humble-visualization-msgs \
    ros-humble-xacro \
    ros-humble-ament-cmake \
    python3-colcon-common-extensions \
    python3-vcstool \
    python3-rosdep
```

---

## Step 4 — Clone the Repository

```bash
# Choose your workspace root. All scripts use ABSOLUTE PATHS.
# If you change this, you MUST update all hardcoded paths (see Step 8).
WORKSPACE_ROOT=$HOME/clearpath_ws

git clone --recurse-submodules \
    https://github.com/johyunyoung/multi-floor-path-planner.git \
    "$WORKSPACE_ROOT"

cd "$WORKSPACE_ROOT"
```

> **Important:** The launch files contain hardcoded absolute paths pointing to `/home/jo/clearpath_ws/`.
> If you cloned to a different directory, see **Step 8 — Path Remapping** before proceeding.

---

## Step 5 — Import VCS Dependencies

> **Why this step:** `src/clearpath_common`, `src/clearpath_config`, `src/clearpath_msgs` are
> not in the git repo. They must be cloned from Clearpath's GitHub before rosdep and colcon can
> find them.

```bash
cd "$WORKSPACE_ROOT"
mkdir -p src

# Import repos defined in dependencies.repos
vcs import src < dependencies.repos
```

The following repositories are imported:

| Target | URL | Branch |
|--------|-----|--------|
| `src/clearpath_common` | https://github.com/clearpathrobotics/clearpath_common.git | humble |
| `src/clearpath_config` | https://github.com/clearpathrobotics/clearpath_config.git | humble |
| `src/clearpath_msgs` | https://github.com/clearpathrobotics/clearpath_msgs.git | humble |

Verify:
```bash
ls "$WORKSPACE_ROOT/src/clearpath_common"   # must exist
ls "$WORKSPACE_ROOT/src/clearpath_config"   # must exist
ls "$WORKSPACE_ROOT/src/clearpath_msgs"     # must exist
```

---

## Step 6 — Build and Install the TRG-Planner C++ Core Library

> **Why this step:** `trg_planner_ros` (the ROS2 node) links against the static library
> `libtrg_planner_core.a` at compile time. This library must be installed to `/usr/local/lib/`
> **before** running `colcon build`, or the build will fail with a missing `trg_planner` CMake target.

```bash
cd "$WORKSPACE_ROOT/src/TRG-planner-main"

# Build C++ core and install to /usr/local
sudo make cppinstall
```

What `sudo make cppinstall` does internally:
1. `cmake -B cpp/trg_planner/build cpp/trg_planner -DCMAKE_BUILD_TYPE=Release`
2. `cmake --build cpp/trg_planner/build -j$(nproc)`
3. `sudo cmake --install cpp/trg_planner/build`
   - Installs `libtrg_planner_core.a` → `/usr/local/lib/`
   - Installs headers → `/usr/local/include/trg_planner/`
   - Installs CMake export → `/usr/local/lib/cmake/trg_planner/`

Verify the install succeeded (all three must exist):
```bash
ls /usr/local/lib/libtrg_planner_core.a
ls /usr/local/lib/cmake/trg_planner/trg_plannerConfig.cmake
ls /usr/local/include/trg_planner/
```

---

## Step 7 — Ensure COLCON_IGNORE Files Exist

> **Why this step:** The TRG repository contains multiple `package.xml` files at different levels
> (ros1 pipeline, ros2 pipeline, cpp/examples, python bindings). Without COLCON_IGNORE markers,
> colcon will detect duplicate package names and fail.
>
> colcon builds `trg_planner_ros` from the **parent** `pipelines/` directory
> (i.e., `src/TRG-planner-main/pipelines/package.xml`), NOT from `pipelines/ros2/`.
> The `ros1/` and `ros2/` subdirectory COLCON_IGNORE files prevent double-registration.
>
> Package path as seen by colcon:
> ```
> trg_planner_ros  →  src/TRG-planner-main/pipelines/   (parent package.xml)
>   pipelines/ros1/  →  COLCON_IGNORE  (skipped)
>   pipelines/ros2/  →  COLCON_IGNORE  (skipped)
> ```

```bash
cd "$WORKSPACE_ROOT/src/TRG-planner-main"

touch pipelines/ros1/COLCON_IGNORE
touch pipelines/ros2/COLCON_IGNORE
touch cpp/examples/COLCON_IGNORE
touch python/COLCON_IGNORE
touch cpp/trg_planner/COLCON_IGNORE
```

Also ignore the unitree_ros submodule (ROS1-only packages that conflict with Humble):
```bash
touch "$WORKSPACE_ROOT/src/unitree_ros/COLCON_IGNORE"
```

Verify colcon sees exactly one `trg_planner_ros` entry:
```bash
cd "$WORKSPACE_ROOT"
source /opt/ros/humble/setup.bash
colcon list | grep trg
# Expected: trg_planner_ros    src/TRG-planner-main/pipelines    (ros.ament_cmake)
```

---

## Step 8 — Path Remapping (Only If Not Using `/home/jo/clearpath_ws`)

If your workspace is NOT at `/home/jo/clearpath_ws`, run the following to replace all hardcoded paths:

```bash
OLD_PATH="/home/jo/clearpath_ws"
NEW_PATH="$WORKSPACE_ROOT"   # e.g. /home/yourname/clearpath_ws

# Files that contain hardcoded paths:
FILES=(
    "$NEW_PATH/clearpath/simulation.launch.py"
    "$NEW_PATH/clearpath/trg_navigation.launch.py"
    "$NEW_PATH/clearpath/platform/launch/platform-service.launch.py"
    "$NEW_PATH/clearpath/worlds/simple_multi_floor.sdf"
    "$NEW_PATH/clearpath/goal_pose_pub.py"
    "$NEW_PATH/go2/simulation.launch.py"
    "$NEW_PATH/go2/trg_navigation.launch.py"
    "$NEW_PATH/go2/robot.urdf.xacro"
)

for f in "${FILES[@]}"; do
    sed -i "s|$OLD_PATH|$NEW_PATH|g" "$f"
done
```

Verify no old paths remain:
```bash
grep -r "$OLD_PATH" "$NEW_PATH/clearpath/" "$NEW_PATH/go2/" --include="*.py" --include="*.sdf" --include="*.xacro" -l
# Expected: no output (empty)
```

---

## Step 9 — Initialize rosdep and Install ROS Dependencies

> **Why this step:** resolves ROS package dependencies declared in `package.xml` files
> under `src/` (including the Clearpath packages imported in Step 5).

```bash
sudo rosdep init    # skip if already initialized (error is safe to ignore)
rosdep update

cd "$WORKSPACE_ROOT"
rosdep install --from-paths src --ignore-src -r -y
```

---

## Step 10 — Build the Workspace

```bash
cd "$WORKSPACE_ROOT"
source /opt/ros/humble/setup.bash

colcon build \
    --packages-skip clearpath_generator_gz \
    --cmake-args -DCMAKE_BUILD_TYPE=Release

# Source the install
source install/setup.bash
```

> **Note:** `clearpath_generator_gz` is skipped intentionally. The manual configuration files
> (`platform-service.launch.py`, `robot.urdf.xacro`) must NOT be overwritten by the generator.

To rebuild individual packages:
```bash
# TRG-Planner ROS node only
colcon build --packages-select trg_planner_ros --cmake-args -DCMAKE_BUILD_TYPE=Release

# Local Planner only
colcon build --packages-select local_planner --cmake-args -DCMAKE_BUILD_TYPE=Release

# Clearpath description packages only
colcon build --packages-up-to clearpath_platform_description
```

---

## Step 11 — Verify the Build

```bash
source "$WORKSPACE_ROOT/install/setup.bash"

# 1. TRG node executable
ros2 pkg executables trg_planner_ros
# Expected: trg_planner_ros trg_ros2_node

# 2. Local planner executables
ros2 pkg executables local_planner
# Expected:
#   local_planner localPlanner
#   local_planner pathFollower
#   local_planner waypointExtractor

# 3. Clearpath packages
ros2 pkg list | grep -E "clearpath|trg_planner|local_planner"
# Expected to include: clearpath_control, clearpath_description, clearpath_msgs,
#                      trg_planner_ros, local_planner

# 4. Confirm no stale hardcoded paths (if installed at non-default location)
grep -r "/home/jo/clearpath_ws" "$WORKSPACE_ROOT/clearpath/" "$WORKSPACE_ROOT/go2/" \
    --include="*.py" --include="*.sdf" --include="*.xacro" -l
# Expected: no output if path remapping was done correctly
```

---

## Step 12 — Run the Simulation

```bash
source "$WORKSPACE_ROOT/install/setup.bash"

# Full stack: Gazebo + Robot + TRG-Planner + Local Planner + RViz
ros2 launch "$WORKSPACE_ROOT/clearpath/trg_navigation.launch.py" world:=warehouse

# Simulation only (no planner)
ros2 launch "$WORKSPACE_ROOT/clearpath/simulation.launch.py"

# Custom world with specific spawn position
ros2 launch "$WORKSPACE_ROOT/clearpath/trg_navigation.launch.py" \
    world:=simple_multi_floor x:=1.0 y:=2.0
```

---

## Architecture Reference

### Package Map

```
clearpath_ws/
├── clearpath/                          # Robot config (manually maintained — do NOT regenerate)
│   ├── simulation.launch.py            # Entry point: Gazebo + spawn + RViz
│   ├── trg_navigation.launch.py        # Entry point: simulation + TRG + local planner
│   ├── robot.yaml                      # A200 robot description (sensors, controller)
│   ├── robot.urdf.xacro                # URDF with OdometryPublisher 3D plugin
│   ├── goal_pose_pub.py                # CLI tool for sending 3D goal poses
│   ├── platform/
│   │   ├── config/control.yaml         # DiffDrive controller (enable_odom_tf: false)
│   │   ├── config/localization.yaml    # EKF (6DOF, ground_truth/odom input)
│   │   └── launch/platform-service.launch.py
│   ├── sensors/
│   │   └── launch/sensors-service.launch.py  # Velodyne PointCloud2 bridge
│   ├── rviz/navigation.rviz
│   └── worlds/
│       ├── simple_multi_floor.sdf
│       └── meshes/floor.dae
│
└── src/
    ├── clearpath_common/               # Official Clearpath packages (vcs import, Step 5)
    ├── clearpath_config/               # Official Clearpath config parser (vcs import, Step 5)
    ├── clearpath_msgs/                 # Official Clearpath messages (vcs import, Step 5)
    ├── TRG-planner-main/              # Global path planner
    │   ├── Makefile                    # sudo make cppinstall (Step 6)
    │   ├── cpp/trg_planner/           # C++ static library source (COLCON_IGNORE'd)
    │   ├── config/husky_warehouse.yaml # TRG algorithm parameters for Husky
    │   └── pipelines/                 # colcon package root (trg_planner_ros)
    │       ├── package.xml            # ← colcon reads THIS (not ros2/package.xml)
    │       ├── ros1/  (COLCON_IGNORE) # skipped
    │       └── ros2/  (COLCON_IGNORE) # skipped; source used via parent CMakeLists
    └── local_planner/                 # Waypoint extraction + local planner + path follower
```

### Data Flow

```
Ignition Gazebo (OdometryPublisher plugin, 3D)
  └─ ros_gz_bridge → /a200_0000/ground_truth/odom
       └─ EKF (robot_localization) → odom → base_link TF

/a200_0000/lidar3d_0/points  (PointCloud2, Velodyne VLP-16)
/a200_0000/ground_truth/odom (Odometry, 6DOF)
/goal_pose                   (PoseStamped, from RViz or goal_pose_pub.py)
  └─ TRG-Planner (trg_ros2_node)
       └─ /trg/output/path (nav_msgs/Path) → RViz visualization
            └─ Local Planner (waypoint extractor → local planner → path follower)
                 └─ /a200_0000/cmd_vel (Twist) → DiffDrive Controller → wheels
```

### Key Topic/Frame Names

| Role | Topic / Frame |
|------|--------------|
| Robot namespace | `a200_0000` |
| LiDAR pointcloud | `/a200_0000/lidar3d_0/points` |
| Ground truth odometry | `/a200_0000/ground_truth/odom` |
| Velocity command | `/a200_0000/cmd_vel` |
| Goal pose | `/goal_pose` |
| TRG output path | `/trg/output/path` |
| Base frame | `base_link` |
| Odom frame | `odom` |

---

## Known Issues and Workarounds

### QoS Mismatch (LiDAR data not received by TRG)

`ros_gz_bridge` publishes with `BEST_EFFORT` QoS.
If TRG does not receive point cloud data, check `src/TRG-planner-main/pipelines/ros2/include/ros2_node.h` line ~46 and ensure the subscriber uses `rclcpp::SensorDataQoS()`.

### generate:=false

`platform-service.launch.py` and `robot.urdf.xacro` are manually edited files.
`simulation.launch.py` passes `generate:=false` to prevent `clearpath_generator_gz` from overwriting them.
**Never remove this flag.**

### TF Remapping

The TRG node remaps `/tf` → `/a200_0000/tf` so it can access the namespaced transform tree.
This is already configured in `trg_navigation.launch.py`.

### Custom World Mesh Paths

World SDF files reference mesh files with **absolute paths**:
```
file:///home/jo/clearpath_ws/clearpath/worlds/meshes/floor.dae
```
After cloning to a different path, update these URIs (see Step 8).

---

## Sending a Goal Pose

### Method 1: RViz 2D Nav Goal (x, y only)

1. In RViz toolbar, click **2D Nav Goal**
2. Click and drag on the map to set position and heading
3. A green path (`/trg/output/path`) appears automatically

### Method 2: 3D Goal Pose Script (x, y, z, yaw)

```bash
# Interactive mode
python3 "$WORKSPACE_ROOT/clearpath/goal_pose_pub.py"
# At prompt, enter: x y z yaw_degrees
# Example: 5.0 3.0 0.0 90

# One-shot mode
python3 "$WORKSPACE_ROOT/clearpath/goal_pose_pub.py" --once 5.0 3.0 0.0 90
```

Yaw is in degrees, counter-clockwise positive (ROS right-hand rule).

---

## Adding a Custom World

1. Place mesh file at `clearpath/worlds/meshes/<name>.dae`
2. Create `clearpath/worlds/<name>.sdf` — set world name = filename (without `.sdf`)
3. Mesh URI must be absolute: `file:///home/jo/clearpath_ws/clearpath/worlds/meshes/<name>.dae`
4. Launch with: `world:=<name>`
