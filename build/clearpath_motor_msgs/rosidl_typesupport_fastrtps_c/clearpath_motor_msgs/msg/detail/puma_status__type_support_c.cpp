// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from clearpath_motor_msgs:msg/PumaStatus.idl
// generated code does not contain a copyright notice
#include "clearpath_motor_msgs/msg/detail/puma_status__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "clearpath_motor_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "clearpath_motor_msgs/msg/detail/puma_status__struct.h"
#include "clearpath_motor_msgs/msg/detail/puma_status__functions.h"
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


using _PumaStatus__ros_msg_type = clearpath_motor_msgs__msg__PumaStatus;

static bool _PumaStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _PumaStatus__ros_msg_type * ros_message = static_cast<const _PumaStatus__ros_msg_type *>(untyped_ros_message);
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

  // Field name: bus_voltage
  {
    cdr << ros_message->bus_voltage;
  }

  // Field name: temperature
  {
    cdr << ros_message->temperature;
  }

  // Field name: output_voltage
  {
    cdr << ros_message->output_voltage;
  }

  // Field name: analog_input
  {
    cdr << ros_message->analog_input;
  }

  // Field name: mode
  {
    cdr << ros_message->mode;
  }

  // Field name: fault
  {
    cdr << ros_message->fault;
  }

  return true;
}

static bool _PumaStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _PumaStatus__ros_msg_type * ros_message = static_cast<_PumaStatus__ros_msg_type *>(untyped_ros_message);
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

  // Field name: bus_voltage
  {
    cdr >> ros_message->bus_voltage;
  }

  // Field name: temperature
  {
    cdr >> ros_message->temperature;
  }

  // Field name: output_voltage
  {
    cdr >> ros_message->output_voltage;
  }

  // Field name: analog_input
  {
    cdr >> ros_message->analog_input;
  }

  // Field name: mode
  {
    cdr >> ros_message->mode;
  }

  // Field name: fault
  {
    cdr >> ros_message->fault;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_clearpath_motor_msgs
size_t get_serialized_size_clearpath_motor_msgs__msg__PumaStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PumaStatus__ros_msg_type * ros_message = static_cast<const _PumaStatus__ros_msg_type *>(untyped_ros_message);
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
  // field.name bus_voltage
  {
    size_t item_size = sizeof(ros_message->bus_voltage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name temperature
  {
    size_t item_size = sizeof(ros_message->temperature);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name output_voltage
  {
    size_t item_size = sizeof(ros_message->output_voltage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name analog_input
  {
    size_t item_size = sizeof(ros_message->analog_input);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name mode
  {
    size_t item_size = sizeof(ros_message->mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name fault
  {
    size_t item_size = sizeof(ros_message->fault);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _PumaStatus__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_clearpath_motor_msgs__msg__PumaStatus(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_clearpath_motor_msgs
size_t max_serialized_size_clearpath_motor_msgs__msg__PumaStatus(
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
  // member: bus_voltage
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: temperature
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: output_voltage
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: analog_input
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: mode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: fault
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = clearpath_motor_msgs__msg__PumaStatus;
    is_plain =
      (
      offsetof(DataType, fault) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _PumaStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_clearpath_motor_msgs__msg__PumaStatus(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_PumaStatus = {
  "clearpath_motor_msgs::msg",
  "PumaStatus",
  _PumaStatus__cdr_serialize,
  _PumaStatus__cdr_deserialize,
  _PumaStatus__get_serialized_size,
  _PumaStatus__max_serialized_size
};

static rosidl_message_type_support_t _PumaStatus__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PumaStatus,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, clearpath_motor_msgs, msg, PumaStatus)() {
  return &_PumaStatus__type_support;
}

#if defined(__cplusplus)
}
#endif
