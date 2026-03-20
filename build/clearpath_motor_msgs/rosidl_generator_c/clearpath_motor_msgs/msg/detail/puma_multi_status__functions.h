// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from clearpath_motor_msgs:msg/PumaMultiStatus.idl
// generated code does not contain a copyright notice

#ifndef CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_MULTI_STATUS__FUNCTIONS_H_
#define CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_MULTI_STATUS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "clearpath_motor_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "clearpath_motor_msgs/msg/detail/puma_multi_status__struct.h"

/// Initialize msg/PumaMultiStatus message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * clearpath_motor_msgs__msg__PumaMultiStatus
 * )) before or use
 * clearpath_motor_msgs__msg__PumaMultiStatus__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_clearpath_motor_msgs
bool
clearpath_motor_msgs__msg__PumaMultiStatus__init(clearpath_motor_msgs__msg__PumaMultiStatus * msg);

/// Finalize msg/PumaMultiStatus message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_clearpath_motor_msgs
void
clearpath_motor_msgs__msg__PumaMultiStatus__fini(clearpath_motor_msgs__msg__PumaMultiStatus * msg);

/// Create msg/PumaMultiStatus message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * clearpath_motor_msgs__msg__PumaMultiStatus__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_clearpath_motor_msgs
clearpath_motor_msgs__msg__PumaMultiStatus *
clearpath_motor_msgs__msg__PumaMultiStatus__create();

/// Destroy msg/PumaMultiStatus message.
/**
 * It calls
 * clearpath_motor_msgs__msg__PumaMultiStatus__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_clearpath_motor_msgs
void
clearpath_motor_msgs__msg__PumaMultiStatus__destroy(clearpath_motor_msgs__msg__PumaMultiStatus * msg);

/// Check for msg/PumaMultiStatus message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_clearpath_motor_msgs
bool
clearpath_motor_msgs__msg__PumaMultiStatus__are_equal(const clearpath_motor_msgs__msg__PumaMultiStatus * lhs, const clearpath_motor_msgs__msg__PumaMultiStatus * rhs);

/// Copy a msg/PumaMultiStatus message.
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
clearpath_motor_msgs__msg__PumaMultiStatus__copy(
  const clearpath_motor_msgs__msg__PumaMultiStatus * input,
  clearpath_motor_msgs__msg__PumaMultiStatus * output);

/// Initialize array of msg/PumaMultiStatus messages.
/**
 * It allocates the memory for the number of elements and calls
 * clearpath_motor_msgs__msg__PumaMultiStatus__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_clearpath_motor_msgs
bool
clearpath_motor_msgs__msg__PumaMultiStatus__Sequence__init(clearpath_motor_msgs__msg__PumaMultiStatus__Sequence * array, size_t size);

/// Finalize array of msg/PumaMultiStatus messages.
/**
 * It calls
 * clearpath_motor_msgs__msg__PumaMultiStatus__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_clearpath_motor_msgs
void
clearpath_motor_msgs__msg__PumaMultiStatus__Sequence__fini(clearpath_motor_msgs__msg__PumaMultiStatus__Sequence * array);

/// Create array of msg/PumaMultiStatus messages.
/**
 * It allocates the memory for the array and calls
 * clearpath_motor_msgs__msg__PumaMultiStatus__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_clearpath_motor_msgs
clearpath_motor_msgs__msg__PumaMultiStatus__Sequence *
clearpath_motor_msgs__msg__PumaMultiStatus__Sequence__create(size_t size);

/// Destroy array of msg/PumaMultiStatus messages.
/**
 * It calls
 * clearpath_motor_msgs__msg__PumaMultiStatus__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_clearpath_motor_msgs
void
clearpath_motor_msgs__msg__PumaMultiStatus__Sequence__destroy(clearpath_motor_msgs__msg__PumaMultiStatus__Sequence * array);

/// Check for msg/PumaMultiStatus message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_clearpath_motor_msgs
bool
clearpath_motor_msgs__msg__PumaMultiStatus__Sequence__are_equal(const clearpath_motor_msgs__msg__PumaMultiStatus__Sequence * lhs, const clearpath_motor_msgs__msg__PumaMultiStatus__Sequence * rhs);

/// Copy an array of msg/PumaMultiStatus messages.
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
clearpath_motor_msgs__msg__PumaMultiStatus__Sequence__copy(
  const clearpath_motor_msgs__msg__PumaMultiStatus__Sequence * input,
  clearpath_motor_msgs__msg__PumaMultiStatus__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CLEARPATH_MOTOR_MSGS__MSG__DETAIL__PUMA_MULTI_STATUS__FUNCTIONS_H_
