// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from clearpath_motor_msgs:msg/PumaMultiStatus.idl
// generated code does not contain a copyright notice

#ifndef CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_MULTI_STATUS__STRUCT_H_
#define CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_MULTI_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'drivers'
#include "clearpath_motor_msgs/msg/detail/puma_status__struct.h"

/// Struct defined in msg/PumaMultiStatus in the package clearpath_motor_msgs.
typedef struct clearpath_motor_msgs__msg__PumaMultiStatus
{
  std_msgs__msg__Header header;
  clearpath_motor_msgs__msg__PumaStatus__Sequence drivers;
} clearpath_motor_msgs__msg__PumaMultiStatus;

// Struct for a sequence of clearpath_motor_msgs__msg__PumaMultiStatus.
typedef struct clearpath_motor_msgs__msg__PumaMultiStatus__Sequence
{
  clearpath_motor_msgs__msg__PumaMultiStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} clearpath_motor_msgs__msg__PumaMultiStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_MULTI_STATUS__STRUCT_H_
