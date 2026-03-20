// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from clearpath_motor_msgs:msg/PumaMultiStatus.idl
// generated code does not contain a copyright notice
#include "clearpath_motor_msgs/msg/detail/puma_multi_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `drivers`
#include "clearpath_motor_msgs/msg/detail/puma_status__functions.h"

bool
clearpath_motor_msgs__msg__PumaMultiStatus__init(clearpath_motor_msgs__msg__PumaMultiStatus * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    clearpath_motor_msgs__msg__PumaMultiStatus__fini(msg);
    return false;
  }
  // drivers
  if (!clearpath_motor_msgs__msg__PumaStatus__Sequence__init(&msg->drivers, 0)) {
    clearpath_motor_msgs__msg__PumaMultiStatus__fini(msg);
    return false;
  }
  return true;
}

void
clearpath_motor_msgs__msg__PumaMultiStatus__fini(clearpath_motor_msgs__msg__PumaMultiStatus * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // drivers
  clearpath_motor_msgs__msg__PumaStatus__Sequence__fini(&msg->drivers);
}

bool
clearpath_motor_msgs__msg__PumaMultiStatus__are_equal(const clearpath_motor_msgs__msg__PumaMultiStatus * lhs, const clearpath_motor_msgs__msg__PumaMultiStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // drivers
  if (!clearpath_motor_msgs__msg__PumaStatus__Sequence__are_equal(
      &(lhs->drivers), &(rhs->drivers)))
  {
    return false;
  }
  return true;
}

bool
clearpath_motor_msgs__msg__PumaMultiStatus__copy(
  const clearpath_motor_msgs__msg__PumaMultiStatus * input,
  clearpath_motor_msgs__msg__PumaMultiStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // drivers
  if (!clearpath_motor_msgs__msg__PumaStatus__Sequence__copy(
      &(input->drivers), &(output->drivers)))
  {
    return false;
  }
  return true;
}

clearpath_motor_msgs__msg__PumaMultiStatus *
clearpath_motor_msgs__msg__PumaMultiStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  clearpath_motor_msgs__msg__PumaMultiStatus * msg = (clearpath_motor_msgs__msg__PumaMultiStatus *)allocator.allocate(sizeof(clearpath_motor_msgs__msg__PumaMultiStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(clearpath_motor_msgs__msg__PumaMultiStatus));
  bool success = clearpath_motor_msgs__msg__PumaMultiStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
clearpath_motor_msgs__msg__PumaMultiStatus__destroy(clearpath_motor_msgs__msg__PumaMultiStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    clearpath_motor_msgs__msg__PumaMultiStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
clearpath_motor_msgs__msg__PumaMultiStatus__Sequence__init(clearpath_motor_msgs__msg__PumaMultiStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  clearpath_motor_msgs__msg__PumaMultiStatus * data = NULL;

  if (size) {
    data = (clearpath_motor_msgs__msg__PumaMultiStatus *)allocator.zero_allocate(size, sizeof(clearpath_motor_msgs__msg__PumaMultiStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = clearpath_motor_msgs__msg__PumaMultiStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        clearpath_motor_msgs__msg__PumaMultiStatus__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
clearpath_motor_msgs__msg__PumaMultiStatus__Sequence__fini(clearpath_motor_msgs__msg__PumaMultiStatus__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      clearpath_motor_msgs__msg__PumaMultiStatus__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

clearpath_motor_msgs__msg__PumaMultiStatus__Sequence *
clearpath_motor_msgs__msg__PumaMultiStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  clearpath_motor_msgs__msg__PumaMultiStatus__Sequence * array = (clearpath_motor_msgs__msg__PumaMultiStatus__Sequence *)allocator.allocate(sizeof(clearpath_motor_msgs__msg__PumaMultiStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = clearpath_motor_msgs__msg__PumaMultiStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
clearpath_motor_msgs__msg__PumaMultiStatus__Sequence__destroy(clearpath_motor_msgs__msg__PumaMultiStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    clearpath_motor_msgs__msg__PumaMultiStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
clearpath_motor_msgs__msg__PumaMultiStatus__Sequence__are_equal(const clearpath_motor_msgs__msg__PumaMultiStatus__Sequence * lhs, const clearpath_motor_msgs__msg__PumaMultiStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!clearpath_motor_msgs__msg__PumaMultiStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
clearpath_motor_msgs__msg__PumaMultiStatus__Sequence__copy(
  const clearpath_motor_msgs__msg__PumaMultiStatus__Sequence * input,
  clearpath_motor_msgs__msg__PumaMultiStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(clearpath_motor_msgs__msg__PumaMultiStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    clearpath_motor_msgs__msg__PumaMultiStatus * data =
      (clearpath_motor_msgs__msg__PumaMultiStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!clearpath_motor_msgs__msg__PumaMultiStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          clearpath_motor_msgs__msg__PumaMultiStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!clearpath_motor_msgs__msg__PumaMultiStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
