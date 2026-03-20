// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from clearpath_motor_msgs:msg/PumaStatus.idl
// generated code does not contain a copyright notice

#ifndef CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_STATUS__BUILDER_HPP_
#define CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "clearpath_motor_msgs/msg/detail/puma_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace clearpath_motor_msgs
{

namespace msg
{

namespace builder
{

class Init_PumaStatus_fault
{
public:
  explicit Init_PumaStatus_fault(::clearpath_motor_msgs::msg::PumaStatus & msg)
  : msg_(msg)
  {}
  ::clearpath_motor_msgs::msg::PumaStatus fault(::clearpath_motor_msgs::msg::PumaStatus::_fault_type arg)
  {
    msg_.fault = std::move(arg);
    return std::move(msg_);
  }

private:
  ::clearpath_motor_msgs::msg::PumaStatus msg_;
};

class Init_PumaStatus_mode
{
public:
  explicit Init_PumaStatus_mode(::clearpath_motor_msgs::msg::PumaStatus & msg)
  : msg_(msg)
  {}
  Init_PumaStatus_fault mode(::clearpath_motor_msgs::msg::PumaStatus::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_PumaStatus_fault(msg_);
  }

private:
  ::clearpath_motor_msgs::msg::PumaStatus msg_;
};

class Init_PumaStatus_analog_input
{
public:
  explicit Init_PumaStatus_analog_input(::clearpath_motor_msgs::msg::PumaStatus & msg)
  : msg_(msg)
  {}
  Init_PumaStatus_mode analog_input(::clearpath_motor_msgs::msg::PumaStatus::_analog_input_type arg)
  {
    msg_.analog_input = std::move(arg);
    return Init_PumaStatus_mode(msg_);
  }

private:
  ::clearpath_motor_msgs::msg::PumaStatus msg_;
};

class Init_PumaStatus_output_voltage
{
public:
  explicit Init_PumaStatus_output_voltage(::clearpath_motor_msgs::msg::PumaStatus & msg)
  : msg_(msg)
  {}
  Init_PumaStatus_analog_input output_voltage(::clearpath_motor_msgs::msg::PumaStatus::_output_voltage_type arg)
  {
    msg_.output_voltage = std::move(arg);
    return Init_PumaStatus_analog_input(msg_);
  }

private:
  ::clearpath_motor_msgs::msg::PumaStatus msg_;
};

class Init_PumaStatus_temperature
{
public:
  explicit Init_PumaStatus_temperature(::clearpath_motor_msgs::msg::PumaStatus & msg)
  : msg_(msg)
  {}
  Init_PumaStatus_output_voltage temperature(::clearpath_motor_msgs::msg::PumaStatus::_temperature_type arg)
  {
    msg_.temperature = std::move(arg);
    return Init_PumaStatus_output_voltage(msg_);
  }

private:
  ::clearpath_motor_msgs::msg::PumaStatus msg_;
};

class Init_PumaStatus_bus_voltage
{
public:
  explicit Init_PumaStatus_bus_voltage(::clearpath_motor_msgs::msg::PumaStatus & msg)
  : msg_(msg)
  {}
  Init_PumaStatus_temperature bus_voltage(::clearpath_motor_msgs::msg::PumaStatus::_bus_voltage_type arg)
  {
    msg_.bus_voltage = std::move(arg);
    return Init_PumaStatus_temperature(msg_);
  }

private:
  ::clearpath_motor_msgs::msg::PumaStatus msg_;
};

class Init_PumaStatus_device_name
{
public:
  explicit Init_PumaStatus_device_name(::clearpath_motor_msgs::msg::PumaStatus & msg)
  : msg_(msg)
  {}
  Init_PumaStatus_bus_voltage device_name(::clearpath_motor_msgs::msg::PumaStatus::_device_name_type arg)
  {
    msg_.device_name = std::move(arg);
    return Init_PumaStatus_bus_voltage(msg_);
  }

private:
  ::clearpath_motor_msgs::msg::PumaStatus msg_;
};

class Init_PumaStatus_device_number
{
public:
  Init_PumaStatus_device_number()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PumaStatus_device_name device_number(::clearpath_motor_msgs::msg::PumaStatus::_device_number_type arg)
  {
    msg_.device_number = std::move(arg);
    return Init_PumaStatus_device_name(msg_);
  }

private:
  ::clearpath_motor_msgs::msg::PumaStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::clearpath_motor_msgs::msg::PumaStatus>()
{
  return clearpath_motor_msgs::msg::builder::Init_PumaStatus_device_number();
}

}  // namespace clearpath_motor_msgs

#endif  // CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_STATUS__BUILDER_HPP_
