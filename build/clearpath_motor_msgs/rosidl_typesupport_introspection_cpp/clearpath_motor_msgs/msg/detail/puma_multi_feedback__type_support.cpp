// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from clearpath_motor_msgs:msg/PumaMultiFeedback.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "clearpath_motor_msgs/msg/detail/puma_multi_feedback__struct.hpp"
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

void PumaMultiFeedback_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) clearpath_motor_msgs::msg::PumaMultiFeedback(_init);
}

void PumaMultiFeedback_fini_function(void * message_memory)
{
  auto typed_message = static_cast<clearpath_motor_msgs::msg::PumaMultiFeedback *>(message_memory);
  typed_message->~PumaMultiFeedback();
}

size_t size_function__PumaMultiFeedback__drivers_feedback(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<clearpath_motor_msgs::msg::PumaFeedback> *>(untyped_member);
  return member->size();
}

const void * get_const_function__PumaMultiFeedback__drivers_feedback(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<clearpath_motor_msgs::msg::PumaFeedback> *>(untyped_member);
  return &member[index];
}

void * get_function__PumaMultiFeedback__drivers_feedback(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<clearpath_motor_msgs::msg::PumaFeedback> *>(untyped_member);
  return &member[index];
}

void fetch_function__PumaMultiFeedback__drivers_feedback(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const clearpath_motor_msgs::msg::PumaFeedback *>(
    get_const_function__PumaMultiFeedback__drivers_feedback(untyped_member, index));
  auto & value = *reinterpret_cast<clearpath_motor_msgs::msg::PumaFeedback *>(untyped_value);
  value = item;
}

void assign_function__PumaMultiFeedback__drivers_feedback(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<clearpath_motor_msgs::msg::PumaFeedback *>(
    get_function__PumaMultiFeedback__drivers_feedback(untyped_member, index));
  const auto & value = *reinterpret_cast<const clearpath_motor_msgs::msg::PumaFeedback *>(untyped_value);
  item = value;
}

void resize_function__PumaMultiFeedback__drivers_feedback(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<clearpath_motor_msgs::msg::PumaFeedback> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember PumaMultiFeedback_message_member_array[2] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(clearpath_motor_msgs::msg::PumaMultiFeedback, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "drivers_feedback",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<clearpath_motor_msgs::msg::PumaFeedback>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(clearpath_motor_msgs::msg::PumaMultiFeedback, drivers_feedback),  // bytes offset in struct
    nullptr,  // default value
    size_function__PumaMultiFeedback__drivers_feedback,  // size() function pointer
    get_const_function__PumaMultiFeedback__drivers_feedback,  // get_const(index) function pointer
    get_function__PumaMultiFeedback__drivers_feedback,  // get(index) function pointer
    fetch_function__PumaMultiFeedback__drivers_feedback,  // fetch(index, &value) function pointer
    assign_function__PumaMultiFeedback__drivers_feedback,  // assign(index, value) function pointer
    resize_function__PumaMultiFeedback__drivers_feedback  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers PumaMultiFeedback_message_members = {
  "clearpath_motor_msgs::msg",  // message namespace
  "PumaMultiFeedback",  // message name
  2,  // number of fields
  sizeof(clearpath_motor_msgs::msg::PumaMultiFeedback),
  PumaMultiFeedback_message_member_array,  // message members
  PumaMultiFeedback_init_function,  // function to initialize message memory (memory has to be allocated)
  PumaMultiFeedback_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t PumaMultiFeedback_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PumaMultiFeedback_message_members,
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
get_message_type_support_handle<clearpath_motor_msgs::msg::PumaMultiFeedback>()
{
  return &::clearpath_motor_msgs::msg::rosidl_typesupport_introspection_cpp::PumaMultiFeedback_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, clearpath_motor_msgs, msg, PumaMultiFeedback)() {
  return &::clearpath_motor_msgs::msg::rosidl_typesupport_introspection_cpp::PumaMultiFeedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
