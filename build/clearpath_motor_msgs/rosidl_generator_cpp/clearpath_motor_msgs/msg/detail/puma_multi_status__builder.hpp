// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from clearpath_motor_msgs:msg/PumaMultiStatus.idl
// generated code does not contain a copyright notice

#ifndef CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_MULTI_STATUS__BUILDER_HPP_
#define CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_MULTI_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "clearpath_motor_msgs/msg/detail/puma_multi_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace clearpath_motor_msgs
{

namespace msg
{

namespace builder
{

class Init_PumaMultiStatus_drivers
{
public:
  explicit Init_PumaMultiStatus_drivers(::clearpath_motor_msgs::msg::PumaMultiStatus & msg)
  : msg_(msg)
  {}
  ::clearpath_motor_msgs::msg::PumaMultiStatus drivers(::clearpath_motor_msgs::msg::PumaMultiStatus::_drivers_type arg)
  {
    msg_.drivers = std::move(arg);
    return std::move(msg_);
  }

private:
  ::clearpath_motor_msgs::msg::PumaMultiStatus msg_;
};

class Init_PumaMultiStatus_header
{
public:
  Init_PumaMultiStatus_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PumaMultiStatus_drivers header(::clearpath_motor_msgs::msg::PumaMultiStatus::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_PumaMultiStatus_drivers(msg_);
  }

private:
  ::clearpath_motor_msgs::msg::PumaMultiStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::clearpath_motor_msgs::msg::PumaMultiStatus>()
{
  return clearpath_motor_msgs::msg::builder::Init_PumaMultiStatus_header();
}

}  // namespace clearpath_motor_msgs

#endif  // CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_MULTI_STATUS__BUILDER_HPP_
