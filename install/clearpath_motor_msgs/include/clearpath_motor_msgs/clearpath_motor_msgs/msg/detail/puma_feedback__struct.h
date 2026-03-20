// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from clearpath_motor_msgs:msg/PumaFeedback.idl
// generated code does not contain a copyright notice

#ifndef CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_FEEDBACK__STRUCT_H_
#define CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_FEEDBACK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'device_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/PumaFeedback in the package clearpath_motor_msgs.
/**
  * Number on the bus (CAN ID).
 */
typedef struct clearpath_motor_msgs__msg__PumaFeedback
{
  uint8_t device_number;
  /// Name of joint controlled, or other identifier.
  rosidl_runtime_c__String device_name;
  /// Duty cycle of the h-bridge driver (-1..1).
  float duty_cycle;
  /// Current consumed (amps).
  float current;
  /// Travel as measured by the encoder (rad).
  double travel;
  /// Angular velocity as measured by the encoder (rad/s).
  double speed;
  /// The reported setpoint value of the on-board controller for the given mode.
  /// In voltage control, duty cycle of the h-bridge driver (-1..1).
  /// In speed control, angular velocity setpoint of the on-board controller (rad/s).
  /// In position control, travel as measured by the encoder (rad).
  /// In current control, the current consumed (amps).
  double setpoint;
} clearpath_motor_msgs__msg__PumaFeedback;

// Struct for a sequence of clearpath_motor_msgs__msg__PumaFeedback.
typedef struct clearpath_motor_msgs__msg__PumaFeedback__Sequence
{
  clearpath_motor_msgs__msg__PumaFeedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} clearpath_motor_msgs__msg__PumaFeedback__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_FEEDBACK__STRUCT_H_
