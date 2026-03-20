// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from clearpath_motor_msgs:msg/PumaStatus.idl
// generated code does not contain a copyright notice

#ifndef CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_STATUS__TRAITS_HPP_
#define CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "clearpath_motor_msgs/msg/detail/puma_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace clearpath_motor_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const PumaStatus & msg,
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

  // member: bus_voltage
  {
    out << "bus_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.bus_voltage, out);
    out << ", ";
  }

  // member: temperature
  {
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
    out << ", ";
  }

  // member: output_voltage
  {
    out << "output_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.output_voltage, out);
    out << ", ";
  }

  // member: analog_input
  {
    out << "analog_input: ";
    rosidl_generator_traits::value_to_yaml(msg.analog_input, out);
    out << ", ";
  }

  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << ", ";
  }

  // member: fault
  {
    out << "fault: ";
    rosidl_generator_traits::value_to_yaml(msg.fault, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PumaStatus & msg,
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

  // member: bus_voltage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bus_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.bus_voltage, out);
    out << "\n";
  }

  // member: temperature
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
    out << "\n";
  }

  // member: output_voltage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "output_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.output_voltage, out);
    out << "\n";
  }

  // member: analog_input
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "analog_input: ";
    rosidl_generator_traits::value_to_yaml(msg.analog_input, out);
    out << "\n";
  }

  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }

  // member: fault
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fault: ";
    rosidl_generator_traits::value_to_yaml(msg.fault, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PumaStatus & msg, bool use_flow_style = false)
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
  const clearpath_motor_msgs::msg::PumaStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  clearpath_motor_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use clearpath_motor_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const clearpath_motor_msgs::msg::PumaStatus & msg)
{
  return clearpath_motor_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<clearpath_motor_msgs::msg::PumaStatus>()
{
  return "clearpath_motor_msgs::msg::PumaStatus";
}

template<>
inline const char * name<clearpath_motor_msgs::msg::PumaStatus>()
{
  return "clearpath_motor_msgs/msg/PumaStatus";
}

template<>
struct has_fixed_size<clearpath_motor_msgs::msg::PumaStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<clearpath_motor_msgs::msg::PumaStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<clearpath_motor_msgs::msg::PumaStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_STATUS__TRAITS_HPP_
