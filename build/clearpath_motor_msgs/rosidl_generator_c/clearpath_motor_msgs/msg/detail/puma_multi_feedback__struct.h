// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from clearpath_motor_msgs:msg/PumaMultiFeedback.idl
// generated code does not contain a copyright notice

#ifndef CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_MULTI_FEEDBACK__STRUCT_H_
#define CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_MULTI_FEEDBACK__STRUCT_H_

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
// Member 'drivers_feedback'
#include "clearpath_motor_msgs/msg/detail/puma_feedback__struct.h"

/// Struct defined in msg/PumaMultiFeedback in the package clearpath_motor_msgs.
typedef struct clearpath_motor_msgs__msg__PumaMultiFeedback
{
  std_msgs__msg__Header header;
  clearpath_motor_msgs__msg__PumaFeedback__Sequence drivers_feedback;
} clearpath_motor_msgs__msg__PumaMultiFeedback;

// Struct for a sequence of clearpath_motor_msgs__msg__PumaMultiFeedback.
typedef struct clearpath_motor_msgs__msg__PumaMultiFeedback__Sequence
{
  clearpath_motor_msgs__msg__PumaMultiFeedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} clearpath_motor_msgs__msg__PumaMultiFeedback__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_MULTI_FEEDBACK__STRUCT_H_
