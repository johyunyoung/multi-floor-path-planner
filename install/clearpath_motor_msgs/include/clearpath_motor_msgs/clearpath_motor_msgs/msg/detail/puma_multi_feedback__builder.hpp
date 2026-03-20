// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from clearpath_motor_msgs:msg/PumaMultiFeedback.idl
// generated code does not contain a copyright notice

#ifndef CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_MULTI_FEEDBACK__BUILDER_HPP_
#define CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_MULTI_FEEDBACK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "clearpath_motor_msgs/msg/detail/puma_multi_feedback__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace clearpath_motor_msgs
{

namespace msg
{

namespace builder
{

class Init_PumaMultiFeedback_drivers_feedback
{
public:
  explicit Init_PumaMultiFeedback_drivers_feedback(::clearpath_motor_msgs::msg::PumaMultiFeedback & msg)
  : msg_(msg)
  {}
  ::clearpath_motor_msgs::msg::PumaMultiFeedback drivers_feedback(::clearpath_motor_msgs::msg::PumaMultiFeedback::_drivers_feedback_type arg)
  {
    msg_.drivers_feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::clearpath_motor_msgs::msg::PumaMultiFeedback msg_;
};

class Init_PumaMultiFeedback_header
{
public:
  Init_PumaMultiFeedback_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PumaMultiFeedback_drivers_feedback header(::clearpath_motor_msgs::msg::PumaMultiFeedback::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_PumaMultiFeedback_drivers_feedback(msg_);
  }

private:
  ::clearpath_motor_msgs::msg::PumaMultiFeedback msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::clearpath_motor_msgs::msg::PumaMultiFeedback>()
{
  return clearpath_motor_msgs::msg::builder::Init_PumaMultiFeedback_header();
}

}  // namespace clearpath_motor_msgs

#endif  // CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_MULTI_FEEDBACK__BUILDER_HPP_
