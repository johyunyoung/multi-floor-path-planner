// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from clearpath_motor_msgs:msg/PumaFeedback.idl
// generated code does not contain a copyright notice

#ifndef CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_FEEDBACK__STRUCT_HPP_
#define CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_FEEDBACK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__clearpath_motor_msgs__msg__PumaFeedback __attribute__((deprecated))
#else
# define DEPRECATED__clearpath_motor_msgs__msg__PumaFeedback __declspec(deprecated)
#endif

namespace clearpath_motor_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PumaFeedback_
{
  using Type = PumaFeedback_<ContainerAllocator>;

  explicit PumaFeedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->device_number = 0;
      this->device_name = "";
      this->duty_cycle = 0.0f;
      this->current = 0.0f;
      this->travel = 0.0;
      this->speed = 0.0;
      this->setpoint = 0.0;
    }
  }

  explicit PumaFeedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : device_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->device_number = 0;
      this->device_name = "";
      this->duty_cycle = 0.0f;
      this->current = 0.0f;
      this->travel = 0.0;
      this->speed = 0.0;
      this->setpoint = 0.0;
    }
  }

  // field types and members
  using _device_number_type =
    uint8_t;
  _device_number_type device_number;
  using _device_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _device_name_type device_name;
  using _duty_cycle_type =
    float;
  _duty_cycle_type duty_cycle;
  using _current_type =
    float;
  _current_type current;
  using _travel_type =
    double;
  _travel_type travel;
  using _speed_type =
    double;
  _speed_type speed;
  using _setpoint_type =
    double;
  _setpoint_type setpoint;

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
  Type & set__duty_cycle(
    const float & _arg)
  {
    this->duty_cycle = _arg;
    return *this;
  }
  Type & set__current(
    const float & _arg)
  {
    this->current = _arg;
    return *this;
  }
  Type & set__travel(
    const double & _arg)
  {
    this->travel = _arg;
    return *this;
  }
  Type & set__speed(
    const double & _arg)
  {
    this->speed = _arg;
    return *this;
  }
  Type & set__setpoint(
    const double & _arg)
  {
    this->setpoint = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    clearpath_motor_msgs::msg::PumaFeedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const clearpath_motor_msgs::msg::PumaFeedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<clearpath_motor_msgs::msg::PumaFeedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<clearpath_motor_msgs::msg::PumaFeedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      clearpath_motor_msgs::msg::PumaFeedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<clearpath_motor_msgs::msg::PumaFeedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      clearpath_motor_msgs::msg::PumaFeedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<clearpath_motor_msgs::msg::PumaFeedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<clearpath_motor_msgs::msg::PumaFeedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<clearpath_motor_msgs::msg::PumaFeedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__clearpath_motor_msgs__msg__PumaFeedback
    std::shared_ptr<clearpath_motor_msgs::msg::PumaFeedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__clearpath_motor_msgs__msg__PumaFeedback
    std::shared_ptr<clearpath_motor_msgs::msg::PumaFeedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PumaFeedback_ & other) const
  {
    if (this->device_number != other.device_number) {
      return false;
    }
    if (this->device_name != other.device_name) {
      return false;
    }
    if (this->duty_cycle != other.duty_cycle) {
      return false;
    }
    if (this->current != other.current) {
      return false;
    }
    if (this->travel != other.travel) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    if (this->setpoint != other.setpoint) {
      return false;
    }
    return true;
  }
  bool operator!=(const PumaFeedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PumaFeedback_

// alias to use template instance with default allocator
using PumaFeedback =
  clearpath_motor_msgs::msg::PumaFeedback_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace clearpath_motor_msgs

#endif  // CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_FEEDBACK__STRUCT_HPP_
