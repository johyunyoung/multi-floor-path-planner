// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from clearpath_motor_msgs:msg/PumaStatus.idl
// generated code does not contain a copyright notice

#ifndef CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_STATUS__STRUCT_HPP_
#define CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__clearpath_motor_msgs__msg__PumaStatus __attribute__((deprecated))
#else
# define DEPRECATED__clearpath_motor_msgs__msg__PumaStatus __declspec(deprecated)
#endif

namespace clearpath_motor_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PumaStatus_
{
  using Type = PumaStatus_<ContainerAllocator>;

  explicit PumaStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->device_number = 0;
      this->device_name = "";
      this->bus_voltage = 0.0f;
      this->temperature = 0.0f;
      this->output_voltage = 0.0f;
      this->analog_input = 0.0f;
      this->mode = 0;
      this->fault = 0;
    }
  }

  explicit PumaStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : device_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->device_number = 0;
      this->device_name = "";
      this->bus_voltage = 0.0f;
      this->temperature = 0.0f;
      this->output_voltage = 0.0f;
      this->analog_input = 0.0f;
      this->mode = 0;
      this->fault = 0;
    }
  }

  // field types and members
  using _device_number_type =
    uint8_t;
  _device_number_type device_number;
  using _device_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _device_name_type device_name;
  using _bus_voltage_type =
    float;
  _bus_voltage_type bus_voltage;
  using _temperature_type =
    float;
  _temperature_type temperature;
  using _output_voltage_type =
    float;
  _output_voltage_type output_voltage;
  using _analog_input_type =
    float;
  _analog_input_type analog_input;
  using _mode_type =
    uint8_t;
  _mode_type mode;
  using _fault_type =
    uint8_t;
  _fault_type fault;

  // setters for named parameter idiom
  Type & set__device_number(
    const uint8_t & _arg)
  {
    this->device_number = _arg;
    return *this;
  }
  Type & set__device_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->device_name = _arg;
    return *this;
  }
  Type & set__bus_voltage(
    const float & _arg)
  {
    this->bus_voltage = _arg;
    return *this;
  }
  Type & set__temperature(
    const float & _arg)
  {
    this->temperature = _arg;
    return *this;
  }
  Type & set__output_voltage(
    const float & _arg)
  {
    this->output_voltage = _arg;
    return *this;
  }
  Type & set__analog_input(
    const float & _arg)
  {
    this->analog_input = _arg;
    return *this;
  }
  Type & set__mode(
    const uint8_t & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__fault(
    const uint8_t & _arg)
  {
    this->fault = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t MODE_VOLTAGE =
    0u;
  static constexpr uint8_t MODE_CURRENT =
    1u;
  static constexpr uint8_t MODE_SPEED =
    2u;
  static constexpr uint8_t MODE_POSITION =
    3u;
  static constexpr uint8_t MODE_VCOMP =
    4u;
  static constexpr uint8_t FAULT_CURRENT =
    1u;
  static constexpr uint8_t FAULT_TEMPERATURE =
    2u;
  static constexpr uint8_t FAULT_BUS_VOLTAGE =
    4u;
  static constexpr uint8_t FAULT_BRIDGE_DRIVER =
    8u;

  // pointer types
  using RawPtr =
    clearpath_motor_msgs::msg::PumaStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const clearpath_motor_msgs::msg::PumaStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<clearpath_motor_msgs::msg::PumaStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<clearpath_motor_msgs::msg::PumaStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      clearpath_motor_msgs::msg::PumaStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<clearpath_motor_msgs::msg::PumaStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      clearpath_motor_msgs::msg::PumaStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<clearpath_motor_msgs::msg::PumaStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<clearpath_motor_msgs::msg::PumaStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<clearpath_motor_msgs::msg::PumaStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__clearpath_motor_msgs__msg__PumaStatus
    std::shared_ptr<clearpath_motor_msgs::msg::PumaStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__clearpath_motor_msgs__msg__PumaStatus
    std::shared_ptr<clearpath_motor_msgs::msg::PumaStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PumaStatus_ & other) const
  {
    if (this->device_number != other.device_number) {
      return false;
    }
    if (this->device_name != other.device_name) {
      return false;
    }
    if (this->bus_voltage != other.bus_voltage) {
      return false;
    }
    if (this->temperature != other.temperature) {
      return false;
    }
    if (this->output_voltage != other.output_voltage) {
      return false;
    }
    if (this->analog_input != other.analog_input) {
      return false;
    }
    if (this->mode != other.mode) {
      return false;
    }
    if (this->fault != other.fault) {
      return false;
    }
    return true;
  }
  bool operator!=(const PumaStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PumaStatus_

// alias to use template instance with default allocator
using PumaStatus =
  clearpath_motor_msgs::msg::PumaStatus_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t PumaStatus_<ContainerAllocator>::MODE_VOLTAGE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t PumaStatus_<ContainerAllocator>::MODE_CURRENT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t PumaStatus_<ContainerAllocator>::MODE_SPEED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t PumaStatus_<ContainerAllocator>::MODE_POSITION;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t PumaStatus_<ContainerAllocator>::MODE_VCOMP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t PumaStatus_<ContainerAllocator>::FAULT_CURRENT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t PumaStatus_<ContainerAllocator>::FAULT_TEMPERATURE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t PumaStatus_<ContainerAllocator>::FAULT_BUS_VOLTAGE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t PumaStatus_<ContainerAllocator>::FAULT_BRIDGE_DRIVER;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace clearpath_motor_msgs

#endif  // CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_STATUS__STRUCT_HPP_
