// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from clearpath_motor_msgs:msg/PumaMultiStatus.idl
// generated code does not contain a copyright notice

#ifndef CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_MULTI_STATUS__TRAITS_HPP_
#define CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_MULTI_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "clearpath_motor_msgs/msg/detail/puma_multi_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'drivers'
#include "clearpath_motor_msgs/msg/detail/puma_status__traits.hpp"

namespace clearpath_motor_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const PumaMultiStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: drivers
  {
    if (msg.drivers.size() == 0) {
      out << "drivers: []";
    } else {
      out << "drivers: [";
      size_t pending_items = msg.drivers.size();
      for (auto item : msg.drivers) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PumaMultiStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: drivers
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.drivers.size() == 0) {
      out << "drivers: []\n";
    } else {
      out << "drivers:\n";
      for (auto item : msg.drivers) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PumaMultiStatus & msg, bool use_flow_style = false)
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
  const clearpath_motor_msgs::msg::PumaMultiStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  clearpath_motor_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use clearpath_motor_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const clearpath_motor_msgs::msg::PumaMultiStatus & msg)
{
  return clearpath_motor_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<clearpath_motor_msgs::msg::PumaMultiStatus>()
{
  return "clearpath_motor_msgs::msg::PumaMultiStatus";
}

template<>
inline const char * name<clearpath_motor_msgs::msg::PumaMultiStatus>()
{
  return "clearpath_motor_msgs/msg/PumaMultiStatus";
}

template<>
struct has_fixed_size<clearpath_motor_msgs::msg::PumaMultiStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<clearpath_motor_msgs::msg::PumaMultiStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<clearpath_motor_msgs::msg::PumaMultiStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_MULTI_STATUS__TRAITS_HPP_
