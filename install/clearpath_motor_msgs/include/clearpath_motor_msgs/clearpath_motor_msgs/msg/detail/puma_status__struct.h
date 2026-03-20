// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from clearpath_motor_msgs:msg/PumaStatus.idl
// generated code does not contain a copyright notice

#ifndef CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_STATUS__STRUCT_H_
#define CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'MODE_VOLTAGE'.
/**
  * Available control modes, not all of which are broken out to
  * this ROS driver.
 */
enum
{
  clearpath_motor_msgs__msg__PumaStatus__MODE_VOLTAGE = 0
};

/// Constant 'MODE_CURRENT'.
enum
{
  clearpath_motor_msgs__msg__PumaStatus__MODE_CURRENT = 1
};

/// Constant 'MODE_SPEED'.
enum
{
  clearpath_motor_msgs__msg__PumaStatus__MODE_SPEED = 2
};

/// Constant 'MODE_POSITION'.
enum
{
  clearpath_motor_msgs__msg__PumaStatus__MODE_POSITION = 3
};

/// Constant 'MODE_VCOMP'.
enum
{
  clearpath_motor_msgs__msg__PumaStatus__MODE_VCOMP = 4
};

/// Constant 'FAULT_CURRENT'.
/**
  * Fault states which could cause the driver to be immobilized.
 */
enum
{
  clearpath_motor_msgs__msg__PumaStatus__FAULT_CURRENT = 1
};

/// Constant 'FAULT_TEMPERATURE'.
enum
{
  clearpath_motor_msgs__msg__PumaStatus__FAULT_TEMPERATURE = 2
};

/// Constant 'FAULT_BUS_VOLTAGE'.
enum
{
  clearpath_motor_msgs__msg__PumaStatus__FAULT_BUS_VOLTAGE = 4
};

/// Constant 'FAULT_BRIDGE_DRIVER'.
enum
{
  clearpath_motor_msgs__msg__PumaStatus__FAULT_BRIDGE_DRIVER = 8
};

// Include directives for member types
// Member 'device_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/PumaStatus in the package clearpath_motor_msgs.
/**
  * Number on the bus (CAN ID).
 */
typedef struct clearpath_motor_msgs__msg__PumaStatus
{
  uint8_t device_number;
  /// Name of joint controlled, or other identifier.
  rosidl_runtime_c__String device_name;
  /// Input terminal voltage (volts).
  float bus_voltage;
  /// Internal driver temperature (degC).
  float temperature;
  /// Voltage as output to the motor (volts).
  float output_voltage;
  /// Value of the auxiliary ADC (volts).
  float analog_input;
  uint8_t mode;
  uint8_t fault;
} clearpath_motor_msgs__msg__PumaStatus;

// Struct for a sequence of clearpath_motor_msgs__msg__PumaStatus.
typedef struct clearpath_motor_msgs__msg__PumaStatus__Sequence
{
  clearpath_motor_msgs__msg__PumaStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} clearpath_motor_msgs__msg__PumaStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_STATUS__STRUCT_H_
