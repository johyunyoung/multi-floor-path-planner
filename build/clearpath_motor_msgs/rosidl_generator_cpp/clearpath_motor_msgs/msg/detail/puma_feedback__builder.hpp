// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from clearpath_motor_msgs:msg/PumaFeedback.idl
// generated code does not contain a copyright notice

#ifndef CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_FEEDBACK__BUILDER_HPP_
#define CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_FEEDBACK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "clearpath_motor_msgs/msg/detail/puma_feedback__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace clearpath_motor_msgs
{

namespace msg
{

namespace builder
{

class Init_PumaFeedback_setpoint
{
public:
  explicit Init_PumaFeedback_setpoint(::clearpath_motor_msgs::msg::PumaFeedback & msg)
  : msg_(msg)
  {}
  ::clearpath_motor_msgs::msg::PumaFeedback setpoint(::clearpath_motor_msgs::msg::PumaFeedback::_setpoint_type arg)
  {
    msg_.setpoint = std::move(arg);
    return std::move(msg_);
  }

private:
  ::clearpath_motor_msgs::msg::PumaFeedback msg_;
};

class Init_PumaFeedback_speed
{
public:
  explicit Init_PumaFeedback_speed(::clearpath_motor_msgs::msg::PumaFeedback & msg)
  : msg_(msg)
  {}
  Init_PumaFeedback_setpoint speed(::clearpath_motor_msgs::msg::PumaFeedback::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_PumaFeedback_setpoint(msg_);
  }

private:
  ::clearpath_motor_msgs::msg::PumaFeedback msg_;
};

class Init_PumaFeedback_travel
{
public:
  explicit Init_PumaFeedback_travel(::clearpath_motor_msgs::msg::PumaFeedback & msg)
  : msg_(msg)
  {}
  Init_PumaFeedback_speed travel(::clearpath_motor_msgs::msg::PumaFeedback::_travel_type arg)
  {
    msg_.travel = std::move(arg);
    return Init_PumaFeedback_speed(msg_);
  }

private:
  ::clearpath_motor_msgs::msg::PumaFeedback msg_;
};

class Init_PumaFeedback_current
{
public:
  explicit Init_PumaFeedback_current(::clearpath_motor_msgs::msg::PumaFeedback & msg)
  : msg_(msg)
  {}
  Init_PumaFeedback_travel current(::clearpath_motor_msgs::msg::PumaFeedback::_current_type arg)
  {
    msg_.current = std::move(arg);
    return Init_PumaFeedback_travel(msg_);
  }

private:
  ::clearpath_motor_msgs::msg::PumaFeedback msg_;
};

class Init_PumaFeedback_duty_cycle
{
public:
  explicit Init_PumaFeedback_duty_cycle(::clearpath_motor_msgs::msg::PumaFeedback & msg)
  : msg_(msg)
  {}
  Init_PumaFeedback_current duty_cycle(::clearpath_motor_msgs::msg::PumaFeedback::_duty_cycle_type arg)
  {
    msg_.duty_cycle = std::move(arg);
    return Init_PumaFeedback_current(msg_);
  }

private:
  ::clearpath_motor_msgs::msg::PumaFeedback msg_;
};

class Init_PumaFeedback_device_name
{
public:
  explicit Init_PumaFeedback_device_name(::clearpath_motor_msgs::msg::PumaFeedback & msg)
  : msg_(msg)
  {}
  Init_PumaFeedback_duty_cycle device_name(::clearpath_motor_msgs::msg::PumaFeedback::_device_name_type arg)
  {
    msg_.device_name = std::move(arg);
    return Init_PumaFeedback_duty_cycle(msg_);
  }

private:
  ::clearpath_motor_msgs::msg::PumaFeedback msg_;
};

class Init_PumaFeedback_device_number
{
public:
  Init_PumaFeedback_device_number()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PumaFeedback_device_name device_number(::clearpath_motor_msgs::msg::PumaFeedback::_device_number_type arg)
  {
    msg_.device_number = std::move(arg);
    return Init_PumaFeedback_device_name(msg_);
  }

private:
  ::clearpath_motor_msgs::msg::PumaFeedback msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::clearpath_motor_msgs::msg::PumaFeedback>()
{
  return clearpath_motor_msgs::msg::builder::Init_PumaFeedback_device_number();
}

}  // namespace clearpath_motor_msgs

#endif  // CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_FEEDBACK__BUILDER_HPP_
