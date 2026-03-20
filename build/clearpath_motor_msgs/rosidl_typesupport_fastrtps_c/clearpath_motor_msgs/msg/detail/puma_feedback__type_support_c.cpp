// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from clearpath_motor_msgs:msg/PumaFeedback.idl
// generated code does not contain a copyright notice
#include "clearpath_motor_msgs/msg/detail/puma_feedback__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "clearpath_motor_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "clearpath_motor_msgs/msg/detail/puma_feedback__struct.h"
#include "clearpath_motor_msgs/msg/detail/puma_feedback__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // device_name
#include "rosidl_runtime_c/string_functions.h"  // device_name

// forward declare type support functions


using _PumaFeedback__ros_msg_type = clearpath_motor_msgs__msg__PumaFeedback;

static bool _PumaFeedback__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _PumaFeedback__ros_msg_type * ros_message = static_cast<const _PumaFeedback__ros_msg_type *>(untyped_ros_message);
  // Field name: device_number
  {
    cdr << ros_message->device_number;
  }

  // Field name: device_name
  {
    const rosidl_runtime_c__String * str = &ros_message->device_name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: duty_cycle
  {
    cdr << ros_message->duty_cycle;
  }

  // Field name: current
  {
    cdr << ros_message->current;
  }

  // Field name: travel
  {
    cdr << ros_message->travel;
  }

  // Field name: speed
  {
    cdr << ros_message->speed;
  }

  // Field name: setpoint
  {
    cdr << ros_message->setpoint;
  }

  return true;
}

static bool _PumaFeedback__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _PumaFeedback__ros_msg_type * ros_message = static_cast<_PumaFeedback__ros_msg_type *>(untyped_ros_message);
  // Field name: device_number
  {
    cdr >> ros_message->device_number;
  }

  // Field name: device_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->device_name.data) {
      rosidl_runtime_c__String__init(&ros_message->device_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->device_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'device_name'\n");
      return false;
    }
  }

  // Field name: duty_cycle
  {
    cdr >> ros_message->duty_cycle;
  }

  // Field name: current
  {
    cdr >> ros_message->current;
  }

  // Field name: travel
  {
    cdr >> ros_message->travel;
  }

  // Field name: speed
  {
    cdr >> ros_message->speed;
  }

  // Field name: setpoint
  {
    cdr >> ros_message->setpoint;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_clearpath_motor_msgs
size_t get_serialized_size_clearpath_motor_msgs__msg__PumaFeedback(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PumaFeedback__ros_msg_type * ros_message = static_cast<const _PumaFeedback__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name device_number
  {
    size_t item_size = sizeof(ros_message->device_number);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name device_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->device_name.size + 1);
  // field.name duty_cycle
  {
    size_t item_size = sizeof(ros_message->duty_cycle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current
  {
    size_t item_size = sizeof(ros_message->current);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name travel
  {
    size_t item_size = sizeof(ros_message->travel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name speed
  {
    size_t item_size = sizeof(ros_message->speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name setpoint
  {
    size_t item_size = sizeof(ros_message->setpoint);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _PumaFeedback__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_clearpath_motor_msgs__msg__PumaFeedback(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_clearpath_motor_msgs
size_t max_serialized_size_clearpath_motor_msgs__msg__PumaFeedback(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: device_number
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: device_name
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: duty_cycle
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: current
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: travel
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: speed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: setpoint
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = clearpath_motor_msgs__msg__PumaFeedback;
    is_plain =
      (
      offsetof(DataType, setpoint) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _PumaFeedback__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_clearpath_motor_msgs__msg__PumaFeedback(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_PumaFeedback = {
  "clearpath_motor_msgs::msg",
  "PumaFeedback",
  _PumaFeedback__cdr_serialize,
  _PumaFeedback__cdr_deserialize,
  _PumaFeedback__get_serialized_size,
  _PumaFeedback__max_serialized_size
};

static rosidl_message_type_support_t _PumaFeedback__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PumaFeedback,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, clearpath_motor_msgs, msg, PumaFeedback)() {
  return &_PumaFeedback__type_support;
}

#if defined(__cplusplus)
}
#endif
