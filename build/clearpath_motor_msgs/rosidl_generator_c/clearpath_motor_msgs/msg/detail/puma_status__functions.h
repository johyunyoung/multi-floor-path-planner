// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from clearpath_motor_msgs:msg/PumaStatus.idl
// generated code does not contain a copyright notice

#ifndef CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_STATUS__FUNCTIONS_H_
#define CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_STATUS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "clearpath_motor_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "clearpath_motor_msgs/msg/detail/puma_status__struct.h"

/// Initialize msg/PumaStatus message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * clearpath_motor_msgs__msg__PumaStatus
 * )) before or use
 * clearpath_motor_msgs__msg__PumaStatus__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_clearpath_motor_msgs
bool
clearpath_motor_msgs__msg__PumaStatus__init(clearpath_motor_msgs__msg__PumaStatus * msg);

/// Finalize msg/PumaStatus message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_clearpath_motor_msgs
void
clearpath_motor_msgs__msg__PumaStatus__fini(clearpath_motor_msgs__msg__PumaStatus * msg);

/// Create msg/PumaStatus message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * clearpath_motor_msgs__msg__PumaStatus__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_clearpath_motor_msgs
clearpath_motor_msgs__msg__PumaStatus *
clearpath_motor_msgs__msg__PumaStatus__create();

/// Destroy msg/PumaStatus message.
/**
 * It calls
 * clearpath_motor_msgs__msg__PumaStatus__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_clearpath_motor_msgs
void
clearpath_motor_msgs__msg__PumaStatus__destroy(clearpath_motor_msgs__msg__PumaStatus * msg);

/// Check for msg/PumaStatus message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_clearpath_motor_msgs
bool
clearpath_motor_msgs__msg__PumaStatus__are_equal(const clearpath_motor_msgs__msg__PumaStatus * lhs, const clearpath_motor_msgs__msg__PumaStatus * rhs);

/// Copy a msg/PumaStatus message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_clearpath_motor_msgs
bool
clearpath_motor_msgs__msg__PumaStatus__copy(
  const clearpath_motor_msgs__msg__PumaStatus * input,
  clearpath_motor_msgs__msg__PumaStatus * output);

/// Initialize array of msg/PumaStatus messages.
/**
 * It allocates the memory for the number of elements and calls
 * clearpath_motor_msgs__msg__PumaStatus__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_clearpath_motor_msgs
bool
clearpath_motor_msgs__msg__PumaStatus__Sequence__init(clearpath_motor_msgs__msg__PumaStatus__Sequence * array, size_t size);

/// Finalize array of msg/PumaStatus messages.
/**
 * It calls
 * clearpath_motor_msgs__msg__PumaStatus__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_clearpath_motor_msgs
void
clearpath_motor_msgs__msg__PumaStatus__Sequence__fini(clearpath_motor_msgs__msg__PumaStatus__Sequence * array);

/// Create array of msg/PumaStatus messages.
/**
 * It allocates the memory for the array and calls
 * clearpath_motor_msgs__msg__PumaStatus__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_clearpath_motor_msgs
clearpath_motor_msgs__msg__PumaStatus__Sequence *
clearpath_motor_msgs__msg__PumaStatus__Sequence__create(size_t size);

/// Destroy array of msg/PumaStatus messages.
/**
 * It calls
 * clearpath_motor_msgs__msg__PumaStatus__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_clearpath_motor_msgs
void
clearpath_motor_msgs__msg__PumaStatus__Sequence__destroy(clearpath_motor_msgs__msg__PumaStatus__Sequence * array);

/// Check for msg/PumaStatus message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_clearpath_motor_msgs
bool
clearpath_motor_msgs__msg__PumaStatus__Sequence__are_equal(const clearpath_motor_msgs__msg__PumaStatus__Sequence * lhs, const clearpath_motor_msgs__msg__PumaStatus__Sequence * rhs);

/// Copy an array of msg/PumaStatus messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_clearpath_motor_msgs
bool
clearpath_motor_msgs__msg__PumaStatus__Sequence__copy(
  const clearpath_motor_msgs__msg__PumaStatus__Sequence * input,
  clearpath_motor_msgs__msg__PumaStatus__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_STATUS__FUNCTIONS_H_
