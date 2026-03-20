// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from clearpath_motor_msgs:msg/PumaStatus.idl
// generated code does not contain a copyright notice
#include "clearpath_motor_msgs/msg/detail/puma_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `device_name`
#include "rosidl_runtime_c/string_functions.h"

bool
clearpath_motor_msgs__msg__PumaStatus__init(clearpath_motor_msgs__msg__PumaStatus * msg)
{
  if (!msg) {
    return false;
  }
  // device_number
  // device_name
  if (!rosidl_runtime_c__String__init(&msg->device_name)) {
    clearpath_motor_msgs__msg__PumaStatus__fini(msg);
    return false;
  }
  // bus_voltage
  // temperature
  // output_voltage
  // analog_input
  // mode
  // fault
  return true;
}

void
clearpath_motor_msgs__msg__PumaStatus__fini(clearpath_motor_msgs__msg__PumaStatus * msg)
{
  if (!msg) {
    return;
  }
  // device_number
  // device_name
  rosidl_runtime_c__String__fini(&msg->device_name);
  // bus_voltage
  // temperature
  // output_voltage
  // analog_input
  // mode
  // fault
}

bool
clearpath_motor_msgs__msg__PumaStatus__are_equal(const clearpath_motor_msgs__msg__PumaStatus * lhs, const clearpath_motor_msgs__msg__PumaStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // device_number
  if (lhs->device_number != rhs->device_number) {
    return false;
  }
  // device_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->device_name), &(rhs->device_name)))
  {
    return false;
  }
  // bus_voltage
  if (lhs->bus_voltage != rhs->bus_voltage) {
    return false;
  }
  // temperature
  if (lhs->temperature != rhs->temperature) {
    return false;
  }
  // output_voltage
  if (lhs->output_voltage != rhs->output_voltage) {
    return false;
  }
  // analog_input
  if (lhs->analog_input != rhs->analog_input) {
    return false;
  }
  // mode
  if (lhs->mode != rhs->mode) {
    return false;
  }
  // fault
  if (lhs->fault != rhs->fault) {
    return false;
  }
  return true;
}

bool
clearpath_motor_msgs__msg__PumaStatus__copy(
  const clearpath_motor_msgs__msg__PumaStatus * input,
  clearpath_motor_msgs__msg__PumaStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // device_number
  output->device_number = input->device_number;
  // device_name
  if (!rosidl_runtime_c__String__copy(
      &(input->device_name), &(output->device_name)))
  {
    return false;
  }
  // bus_voltage
  output->bus_voltage = input->bus_voltage;
  // temperature
  output->temperature = input->temperature;
  // output_voltage
  output->output_voltage = input->output_voltage;
  // analog_input
  output->analog_input = input->analog_input;
  // mode
  output->mode = input->mode;
  // fault
  output->fault = input->fault;
  return true;
}

clearpath_motor_msgs__msg__PumaStatus *
clearpath_motor_msgs__msg__PumaStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  clearpath_motor_msgs__msg__PumaStatus * msg = (clearpath_motor_msgs__msg__PumaStatus *)allocator.allocate(sizeof(clearpath_motor_msgs__msg__PumaStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(clearpath_motor_msgs__msg__PumaStatus));
  bool success = clearpath_motor_msgs__msg__PumaStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
clearpath_motor_msgs__msg__PumaStatus__destroy(clearpath_motor_msgs__msg__PumaStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    clearpath_motor_msgs__msg__PumaStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
clearpath_motor_msgs__msg__PumaStatus__Sequence__init(clearpath_motor_msgs__msg__PumaStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  clearpath_motor_msgs__msg__PumaStatus * data = NULL;

  if (size) {
    data = (clearpath_motor_msgs__msg__PumaStatus *)allocator.zero_allocate(size, sizeof(clearpath_motor_msgs__msg__PumaStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = clearpath_motor_msgs__msg__PumaStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        clearpath_motor_msgs__msg__PumaStatus__fini(&data[i - 1]);
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
clearpath_motor_msgs__msg__PumaStatus__Sequence__fini(clearpath_motor_msgs__msg__PumaStatus__Sequence * array)
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
      clearpath_motor_msgs__msg__PumaStatus__fini(&array->data[i]);
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

clearpath_motor_msgs__msg__PumaStatus__Sequence *
clearpath_motor_msgs__msg__PumaStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  clearpath_motor_msgs__msg__PumaStatus__Sequence * array = (clearpath_motor_msgs__msg__PumaStatus__Sequence *)allocator.allocate(sizeof(clearpath_motor_msgs__msg__PumaStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = clearpath_motor_msgs__msg__PumaStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
clearpath_motor_msgs__msg__PumaStatus__Sequence__destroy(clearpath_motor_msgs__msg__PumaStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    clearpath_motor_msgs__msg__PumaStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
clearpath_motor_msgs__msg__PumaStatus__Sequence__are_equal(const clearpath_motor_msgs__msg__PumaStatus__Sequence * lhs, const clearpath_motor_msgs__msg__PumaStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!clearpath_motor_msgs__msg__PumaStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
clearpath_motor_msgs__msg__PumaStatus__Sequence__copy(
  const clearpath_motor_msgs__msg__PumaStatus__Sequence * input,
  clearpath_motor_msgs__msg__PumaStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(clearpath_motor_msgs__msg__PumaStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    clearpath_motor_msgs__msg__PumaStatus * data =
      (clearpath_motor_msgs__msg__PumaStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!clearpath_motor_msgs__msg__PumaStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          clearpath_motor_msgs__msg__PumaStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!clearpath_motor_msgs__msg__PumaStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
