// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from clearpath_motor_msgs:msg/PumaStatus.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "clearpath_motor_msgs/msg/detail/puma_status__struct.h"
#include "clearpath_motor_msgs/msg/detail/puma_status__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool clearpath_motor_msgs__msg__puma_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[49];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("clearpath_motor_msgs.msg._puma_status.PumaStatus", full_classname_dest, 48) == 0);
  }
  clearpath_motor_msgs__msg__PumaStatus * ros_message = _ros_message;
  {  // device_number
    PyObject * field = PyObject_GetAttrString(_pymsg, "device_number");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->device_number = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // device_name
    PyObject * field = PyObject_GetAttrString(_pymsg, "device_name");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->device_name, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // bus_voltage
    PyObject * field = PyObject_GetAttrString(_pymsg, "bus_voltage");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->bus_voltage = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // temperature
    PyObject * field = PyObject_GetAttrString(_pymsg, "temperature");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->temperature = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // output_voltage
    PyObject * field = PyObject_GetAttrString(_pymsg, "output_voltage");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->output_voltage = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // analog_input
    PyObject * field = PyObject_GetAttrString(_pymsg, "analog_input");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->analog_input = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "mode");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->mode = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // fault
    PyObject * field = PyObject_GetAttrString(_pymsg, "fault");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->fault = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * clearpath_motor_msgs__msg__puma_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of PumaStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("clearpath_motor_msgs.msg._puma_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "PumaStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  clearpath_motor_msgs__msg__PumaStatus * ros_message = (clearpath_motor_msgs__msg__PumaStatus *)raw_ros_message;
  {  // device_number
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->device_number);
    {
      int rc = PyObject_SetAttrString(_pymessage, "device_number", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // device_name
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->device_name.data,
      strlen(ros_message->device_name.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "device_name", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bus_voltage
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->bus_voltage);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bus_voltage", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // temperature
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->temperature);
    {
      int rc = PyObject_SetAttrString(_pymessage, "temperature", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // output_voltage
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->output_voltage);
    {
      int rc = PyObject_SetAttrString(_pymessage, "output_voltage", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // analog_input
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->analog_input);
    {
      int rc = PyObject_SetAttrString(_pymessage, "analog_input", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mode
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->mode);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // fault
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->fault);
    {
      int rc = PyObject_SetAttrString(_pymessage, "fault", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
