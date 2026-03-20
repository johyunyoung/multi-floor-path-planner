// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from clearpath_motor_msgs:msg/PumaMultiFeedback.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "clearpath_motor_msgs/msg/detail/puma_multi_feedback__rosidl_typesupport_introspection_c.h"
#include "clearpath_motor_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "clearpath_motor_msgs/msg/detail/puma_multi_feedback__functions.h"
#include "clearpath_motor_msgs/msg/detail/puma_multi_feedback__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `drivers_feedback`
#include "clearpath_motor_msgs/msg/puma_feedback.h"
// Member `drivers_feedback`
#include "clearpath_motor_msgs/msg/detail/puma_feedback__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void clearpath_motor_msgs__msg__PumaMultiFeedback__rosidl_typesupport_introspection_c__PumaMultiFeedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  clearpath_motor_msgs__msg__PumaMultiFeedback__init(message_memory);
}

void clearpath_motor_msgs__msg__PumaMultiFeedback__rosidl_typesupport_introspection_c__PumaMultiFeedback_fini_function(void * message_memory)
{
  clearpath_motor_msgs__msg__PumaMultiFeedback__fini(message_memory);
}

size_t clearpath_motor_msgs__msg__PumaMultiFeedback__rosidl_typesupport_introspection_c__size_function__PumaMultiFeedback__drivers_feedback(
  const void * untyped_member)
{
  const clearpath_motor_msgs__msg__PumaFeedback__Sequence * member =
    (const clearpath_motor_msgs__msg__PumaFeedback__Sequence *)(untyped_member);
  return member->size;
}

const void * clearpath_motor_msgs__msg__PumaMultiFeedback__rosidl_typesupport_introspection_c__get_const_function__PumaMultiFeedback__drivers_feedback(
  const void * untyped_member, size_t index)
{
  const clearpath_motor_msgs__msg__PumaFeedback__Sequence * member =
    (const clearpath_motor_msgs__msg__PumaFeedback__Sequence *)(untyped_member);
  return &member->data[index];
}

void * clearpath_motor_msgs__msg__PumaMultiFeedback__rosidl_typesupport_introspection_c__get_function__PumaMultiFeedback__drivers_feedback(
  void * untyped_member, size_t index)
{
  clearpath_motor_msgs__msg__PumaFeedback__Sequence * member =
    (clearpath_motor_msgs__msg__PumaFeedback__Sequence *)(untyped_member);
  return &member->data[index];
}

void clearpath_motor_msgs__msg__PumaMultiFeedback__rosidl_typesupport_introspection_c__fetch_function__PumaMultiFeedback__drivers_feedback(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const clearpath_motor_msgs__msg__PumaFeedback * item =
    ((const clearpath_motor_msgs__msg__PumaFeedback *)
    clearpath_motor_msgs__msg__PumaMultiFeedback__rosidl_typesupport_introspection_c__get_const_function__PumaMultiFeedback__drivers_feedback(untyped_member, index));
  clearpath_motor_msgs__msg__PumaFeedback * value =
    (clearpath_motor_msgs__msg__PumaFeedback *)(untyped_value);
  *value = *item;
}

void clearpath_motor_msgs__msg__PumaMultiFeedback__rosidl_typesupport_introspection_c__assign_function__PumaMultiFeedback__drivers_feedback(
  void * untyped_member, size_t index, const void * untyped_value)
{
  clearpath_motor_msgs__msg__PumaFeedback * item =
    ((clearpath_motor_msgs__msg__PumaFeedback *)
    clearpath_motor_msgs__msg__PumaMultiFeedback__rosidl_typesupport_introspection_c__get_function__PumaMultiFeedback__drivers_feedback(untyped_member, index));
  const clearpath_motor_msgs__msg__PumaFeedback * value =
    (const clearpath_motor_msgs__msg__PumaFeedback *)(untyped_value);
  *item = *value;
}

bool clearpath_motor_msgs__msg__PumaMultiFeedback__rosidl_typesupport_introspection_c__resize_function__PumaMultiFeedback__drivers_feedback(
  void * untyped_member, size_t size)
{
  clearpath_motor_msgs__msg__PumaFeedback__Sequence * member =
    (clearpath_motor_msgs__msg__PumaFeedback__Sequence *)(untyped_member);
  clearpath_motor_msgs__msg__PumaFeedback__Sequence__fini(member);
  return clearpath_motor_msgs__msg__PumaFeedback__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember clearpath_motor_msgs__msg__PumaMultiFeedback__rosidl_typesupport_introspection_c__PumaMultiFeedback_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(clearpath_motor_msgs__msg__PumaMultiFeedback, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "drivers_feedback",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(clearpath_motor_msgs__msg__PumaMultiFeedback, drivers_feedback),  // bytes offset in struct
    NULL,  // default value
    clearpath_motor_msgs__msg__PumaMultiFeedback__rosidl_typesupport_introspection_c__size_function__PumaMultiFeedback__drivers_feedback,  // size() function pointer
    clearpath_motor_msgs__msg__PumaMultiFeedback__rosidl_typesupport_introspection_c__get_const_function__PumaMultiFeedback__drivers_feedback,  // get_const(index) function pointer
    clearpath_motor_msgs__msg__PumaMultiFeedback__rosidl_typesupport_introspection_c__get_function__PumaMultiFeedback__drivers_feedback,  // get(index) function pointer
    clearpath_motor_msgs__msg__PumaMultiFeedback__rosidl_typesupport_introspection_c__fetch_function__PumaMultiFeedback__drivers_feedback,  // fetch(index, &value) function pointer
    clearpath_motor_msgs__msg__PumaMultiFeedback__rosidl_typesupport_introspection_c__assign_function__PumaMultiFeedback__drivers_feedback,  // assign(index, value) function pointer
    clearpath_motor_msgs__msg__PumaMultiFeedback__rosidl_typesupport_introspection_c__resize_function__PumaMultiFeedback__drivers_feedback  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers clearpath_motor_msgs__msg__PumaMultiFeedback__rosidl_typesupport_introspection_c__PumaMultiFeedback_message_members = {
  "clearpath_motor_msgs__msg",  // message namespace
  "PumaMultiFeedback",  // message name
  2,  // number of fields
  sizeof(clearpath_motor_msgs__msg__PumaMultiFeedback),
  clearpath_motor_msgs__msg__PumaMultiFeedback__rosidl_typesupport_introspection_c__PumaMultiFeedback_message_member_array,  // message members
  clearpath_motor_msgs__msg__PumaMultiFeedback__rosidl_typesupport_introspection_c__PumaMultiFeedback_init_function,  // function to initialize message memory (memory has to be allocated)
  clearpath_motor_msgs__msg__PumaMultiFeedback__rosidl_typesupport_introspection_c__PumaMultiFeedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t clearpath_motor_msgs__msg__PumaMultiFeedback__rosidl_typesupport_introspection_c__PumaMultiFeedback_message_type_support_handle = {
  0,
  &clearpath_motor_msgs__msg__PumaMultiFeedback__rosidl_typesupport_introspection_c__PumaMultiFeedback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_clearpath_motor_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, clearpath_motor_msgs, msg, PumaMultiFeedback)() {
  clearpath_motor_msgs__msg__PumaMultiFeedback__rosidl_typesupport_introspection_c__PumaMultiFeedback_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  clearpath_motor_msgs__msg__PumaMultiFeedback__rosidl_typesupport_introspection_c__PumaMultiFeedback_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, clearpath_motor_msgs, msg, PumaFeedback)();
  if (!clearpath_motor_msgs__msg__PumaMultiFeedback__rosidl_typesupport_introspection_c__PumaMultiFeedback_message_type_support_handle.typesupport_identifier) {
    clearpath_motor_msgs__msg__PumaMultiFeedback__rosidl_typesupport_introspection_c__PumaMultiFeedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &clearpath_motor_msgs__msg__PumaMultiFeedback__rosidl_typesupport_introspection_c__PumaMultiFeedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
