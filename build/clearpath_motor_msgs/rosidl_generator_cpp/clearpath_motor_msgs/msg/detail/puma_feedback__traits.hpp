// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from clearpath_motor_msgs:msg/PumaFeedback.idl
// generated code does not contain a copyright notice

#ifndef CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_FEEDBACK__TRAITS_HPP_
#define CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_FEEDBACK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "clearpath_motor_msgs/msg/detail/puma_feedback__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace clearpath_motor_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const PumaFeedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: device_number
  {
    out << "device_number: ";
    rosidl_generator_traits::value_to_yaml(msg.device_number, out);
    out << ", ";
  }

  // member: device_name
  {
    out << "device_name: ";
    rosidl_generator_traits::value_to_yaml(msg.device_name, out);
    out << ", ";
  }

  // member: duty_cycle
  {
    out << "duty_cycle: ";
    rosidl_generator_traits::value_to_yaml(msg.duty_cycle, out);
    out << ", ";
  }

  // member: current
  {
    out << "current: ";
    rosidl_generator_traits::value_to_yaml(msg.current, out);
    out << ", ";
  }

  // member: travel
  {
    out << "travel: ";
    rosidl_generator_traits::value_to_yaml(msg.travel, out);
    out << ", ";
  }

  // member: speed
  {
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << ", ";
  }

  // member: setpoint
  {
    out << "setpoint: ";
    rosidl_generator_traits::value_to_yaml(msg.setpoint, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PumaFeedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: device_number
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "device_number: ";
    rosidl_generator_traits::value_to_yaml(msg.device_number, out);
    out << "\n";
  }

  // member: device_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "device_name: ";
    rosidl_generator_traits::value_to_yaml(msg.device_name, out);
    out << "\n";
  }

  // member: duty_cycle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "duty_cycle: ";
    rosidl_generator_traits::value_to_yaml(msg.duty_cycle, out);
    out << "\n";
  }

  // member: current
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current: ";
    rosidl_generator_traits::value_to_yaml(msg.current, out);
    out << "\n";
  }

  // member: travel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "travel: ";
    rosidl_generator_traits::value_to_yaml(msg.travel, out);
    out << "\n";
  }

  // member: speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << "\n";
  }

  // member: setpoint
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "setpoint: ";
    rosidl_generator_traits::value_to_yaml(msg.setpoint, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PumaFeedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace clearpath_motor_msgs

namespace rosidl_generator_traits
{

[[deprecated("use clearpath_motor_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const clearpath_motor_msgs::msg::PumaFeedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  clearpath_motor_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use clearpath_motor_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const clearpath_motor_msgs::msg::PumaFeedback & msg)
{
  return clearpath_motor_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<clearpath_motor_msgs::msg::PumaFeedback>()
{
  return "clearpath_motor_msgs::msg::PumaFeedback";
}

template<>
inline const char * name<clearpath_motor_msgs::msg::PumaFeedback>()
{
  return "clearpath_motor_msgs/msg/PumaFeedback";
}

template<>
struct has_fixed_size<clearpath_motor_msgs::msg::PumaFeedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<clearpath_motor_msgs::msg::PumaFeedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<clearpath_motor_msgs::msg::PumaFeedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_FEEDBACK__TRAITS_HPP_
