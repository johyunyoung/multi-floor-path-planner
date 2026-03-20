// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from clearpath_motor_msgs:msg/PumaMultiStatus.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "clearpath_motor_msgs/msg/detail/puma_multi_status__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace clearpath_motor_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void PumaMultiStatus_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) clearpath_motor_msgs::msg::PumaMultiStatus(_init);
}

void PumaMultiStatus_fini_function(void * message_memory)
{
  auto typed_message = static_cast<clearpath_motor_msgs::msg::PumaMultiStatus *>(message_memory);
  typed_message->~PumaMultiStatus();
}

size_t size_function__PumaMultiStatus__drivers(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<clearpath_motor_msgs::msg::PumaStatus> *>(untyped_member);
  return member->size();
}

const void * get_const_function__PumaMultiStatus__drivers(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<clearpath_motor_msgs::msg::PumaStatus> *>(untyped_member);
  return &member[index];
}

void * get_function__PumaMultiStatus__drivers(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<clearpath_motor_msgs::msg::PumaStatus> *>(untyped_member);
  return &member[index];
}

void fetch_function__PumaMultiStatus__drivers(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const clearpath_motor_msgs::msg::PumaStatus *>(
    get_const_function__PumaMultiStatus__drivers(untyped_member, index));
  auto & value = *reinterpret_cast<clearpath_motor_msgs::msg::PumaStatus *>(untyped_value);
  value = item;
}

void assign_function__PumaMultiStatus__drivers(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<clearpath_motor_msgs::msg::PumaStatus *>(
    get_function__PumaMultiStatus__drivers(untyped_member, index));
  const auto & value = *reinterpret_cast<const clearpath_motor_msgs::msg::PumaStatus *>(untyped_value);
  item = value;
}

void resize_function__PumaMultiStatus__drivers(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<clearpath_motor_msgs::msg::PumaStatus> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember PumaMultiStatus_message_member_array[2] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(clearpath_motor_msgs::msg::PumaMultiStatus, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "drivers",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<clearpath_motor_msgs::msg::PumaStatus>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(clearpath_motor_msgs::msg::PumaMultiStatus, drivers),  // bytes offset in struct
    nullptr,  // default value
    size_function__PumaMultiStatus__drivers,  // size() function pointer
    get_const_function__PumaMultiStatus__drivers,  // get_const(index) function pointer
    get_function__PumaMultiStatus__drivers,  // get(index) function pointer
    fetch_function__PumaMultiStatus__drivers,  // fetch(index, &value) function pointer
    assign_function__PumaMultiStatus__drivers,  // assign(index, value) function pointer
    resize_function__PumaMultiStatus__drivers  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers PumaMultiStatus_message_members = {
  "clearpath_motor_msgs::msg",  // message namespace
  "PumaMultiStatus",  // message name
  2,  // number of fields
  sizeof(clearpath_motor_msgs::msg::PumaMultiStatus),
  PumaMultiStatus_message_member_array,  // message members
  PumaMultiStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  PumaMultiStatus_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t PumaMultiStatus_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PumaMultiStatus_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace clearpath_motor_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<clearpath_motor_msgs::msg::PumaMultiStatus>()
{
  return &::clearpath_motor_msgs::msg::rosidl_typesupport_introspection_cpp::PumaMultiStatus_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, clearpath_motor_msgs, msg, PumaMultiStatus)() {
  return &::clearpath_motor_msgs::msg::rosidl_typesupport_introspection_cpp::PumaMultiStatus_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
