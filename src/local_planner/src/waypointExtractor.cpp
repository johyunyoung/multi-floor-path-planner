/**
 * Waypoint Extractor Node
 *
 * Bridges TRG-Planner's full path output to localPlanner's single waypoint input.
 * Extracts a lookahead point from the TRG path and publishes it as PointStamped.
 */

#include <rclcpp/rclcpp.hpp>
#include <nav_msgs/msg/path.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <geometry_msgs/msg/point_stamped.hpp>
#include <cmath>

class WaypointExtractor : public rclcpp::Node {
 public:
  WaypointExtractor() : Node("waypointExtractor") {
    this->declare_parameter<double>("lookaheadDistance", 2.0);
    this->get_parameter("lookaheadDistance", lookahead_dist_);

    pub_waypoint_ = this->create_publisher<geometry_msgs::msg::PointStamped>("/way_point", 5);

    sub_path_ = this->create_subscription<nav_msgs::msg::Path>(
        "/trg/output/path", 5,
        std::bind(&WaypointExtractor::pathCallback, this, std::placeholders::_1));

    sub_odom_ = this->create_subscription<nav_msgs::msg::Odometry>(
        "/state_estimation", 5,
        std::bind(&WaypointExtractor::odomCallback, this, std::placeholders::_1));

    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(100),  // 10 Hz
        std::bind(&WaypointExtractor::timerCallback, this));

    RCLCPP_INFO(this->get_logger(), "WaypointExtractor started (lookahead=%.1fm)", lookahead_dist_);
  }

 private:
  void pathCallback(const nav_msgs::msg::Path::ConstSharedPtr msg) {
    path_ = *msg;
    path_received_ = true;
  }

  void odomCallback(const nav_msgs::msg::Odometry::ConstSharedPtr msg) {
    robot_x_ = msg->pose.pose.position.x;
    robot_y_ = msg->pose.pose.position.y;
    robot_z_ = msg->pose.pose.position.z;
    odom_received_ = true;
  }

  void timerCallback() {
    if (!path_received_ || !odom_received_ || path_.poses.empty()) {
      return;
    }

    // 1. Find closest point on TRG path to robot
    int closest_idx = 0;
    float min_dist = std::numeric_limits<float>::max();
    for (size_t i = 0; i < path_.poses.size(); i++) {
      float dx = path_.poses[i].pose.position.x - robot_x_;
      float dy = path_.poses[i].pose.position.y - robot_y_;
      float dist = std::sqrt(dx * dx + dy * dy);
      if (dist < min_dist) {
        min_dist = dist;
        closest_idx = i;
      }
    }

    // 2. Walk forward along path to find lookahead point
    float accum_dist = 0.0;
    int target_idx = closest_idx;
    for (size_t i = closest_idx; i < path_.poses.size() - 1; i++) {
      float dx = path_.poses[i + 1].pose.position.x - path_.poses[i].pose.position.x;
      float dy = path_.poses[i + 1].pose.position.y - path_.poses[i].pose.position.y;
      accum_dist += std::sqrt(dx * dx + dy * dy);
      target_idx = i + 1;
      if (accum_dist >= lookahead_dist_) {
        break;
      }
    }

    // 3. Publish waypoint
    geometry_msgs::msg::PointStamped waypoint;
    waypoint.header.stamp = this->get_clock()->now();
    waypoint.header.frame_id = path_.header.frame_id;
    waypoint.point.x = path_.poses[target_idx].pose.position.x;
    waypoint.point.y = path_.poses[target_idx].pose.position.y;
    waypoint.point.z = path_.poses[target_idx].pose.position.z;
    pub_waypoint_->publish(waypoint);
  }

  rclcpp::Publisher<geometry_msgs::msg::PointStamped>::SharedPtr pub_waypoint_;
  rclcpp::Subscription<nav_msgs::msg::Path>::SharedPtr sub_path_;
  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr sub_odom_;
  rclcpp::TimerBase::SharedPtr timer_;

  nav_msgs::msg::Path path_;
  double robot_x_ = 0.0, robot_y_ = 0.0, robot_z_ = 0.0;
  double lookahead_dist_ = 2.0;
  bool path_received_ = false;
  bool odom_received_ = false;
};

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<WaypointExtractor>());
  rclcpp::shutdown();
  return 0;
}
