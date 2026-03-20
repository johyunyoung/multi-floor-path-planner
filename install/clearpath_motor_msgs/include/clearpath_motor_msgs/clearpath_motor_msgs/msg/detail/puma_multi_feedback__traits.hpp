// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from clearpath_motor_msgs:msg/PumaMultiFeedback.idl
// generated code does not contain a copyright notice

#ifndef CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_MULTI_FEEDBACK__TRAITS_HPP_
#define CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_MULTI_FEEDBACK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "clearpath_motor_msgs/msg/detail/puma_multi_feedback__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'drivers_feedback'
#include "clearpath_motor_msgs/msg/detail/puma_feedback__traits.hpp"

namespace clearpath_motor_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const PumaMultiFeedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: drivers_feedback
  {
    if (msg.drivers_feedback.size() == 0) {
      out << "drivers_feedback: []";
    } else {
      out << "drivers_feedback: [";
      size_t pending_items = msg.drivers_feedback.size();
      for (auto item : msg.drivers_feedback) {
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
  const PumaMultiFeedback & msg,
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

  // member: drivers_feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.drivers_feedback.size() == 0) {
      out << "drivers_feedback: []\n";
    } else {
      out << "drivers_feedback:\n";
      for (auto item : msg.drivers_feedback) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PumaMultiFeedback & msg, bool use_flow_style = false)
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
  const clearpath_motor_msgs::msg::PumaMultiFeedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  clearpath_motor_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use clearpath_motor_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const clearpath_motor_msgs::msg::PumaMultiFeedback & msg)
{
  return clearpath_motor_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<clearpath_motor_msgs::msg::PumaMultiFeedback>()
{
  return "clearpath_motor_msgs::msg::PumaMultiFeedback";
}

template<>
inline const char * name<clearpath_motor_msgs::msg::PumaMultiFeedback>()
{
  return "clearpath_motor_msgs/msg/PumaMultiFeedback";
}

template<>
struct has_fixed_size<clearpath_motor_msgs::msg::PumaMultiFeedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<clearpath_motor_msgs::msg::PumaMultiFeedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<clearpath_motor_msgs::msg::PumaMultiFeedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_MULTI_FEEDBACK__TRAITS_HPP_
