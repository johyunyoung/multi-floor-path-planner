// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from clearpath_motor_msgs:msg/PumaMultiFeedback.idl
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
#include "clearpath_motor_msgs/msg/detail/puma_multi_feedback__struct.h"
#include "clearpath_motor_msgs/msg/detail/puma_multi_feedback__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "clearpath_motor_msgs/msg/detail/puma_feedback__functions.h"
// end nested array functions include
ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);
bool clearpath_motor_msgs__msg__puma_feedback__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * clearpath_motor_msgs__msg__puma_feedback__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool clearpath_motor_msgs__msg__puma_multi_feedback__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[64];
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
    assert(strncmp("clearpath_motor_msgs.msg._puma_multi_feedback.PumaMultiFeedback", full_classname_dest, 63) == 0);
  }
  clearpath_motor_msgs__msg__PumaMultiFeedback * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // drivers_feedback
    PyObject * field = PyObject_GetAttrString(_pymsg, "drivers_feedback");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'drivers_feedback'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!clearpath_motor_msgs__msg__PumaFeedback__Sequence__init(&(ros_message->drivers_feedback), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create clearpath_motor_msgs__msg__PumaFeedback__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    clearpath_motor_msgs__msg__PumaFeedback * dest = ros_message->drivers_feedback.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!clearpath_motor_msgs__msg__puma_feedback__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * clearpath_motor_msgs__msg__puma_multi_feedback__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of PumaMultiFeedback */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("clearpath_motor_msgs.msg._puma_multi_feedback");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "PumaMultiFeedback");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  clearpath_motor_msgs__msg__PumaMultiFeedback * ros_message = (clearpath_motor_msgs__msg__PumaMultiFeedback *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // drivers_feedback
    PyObject * field = NULL;
    size_t size = ros_message->drivers_feedback.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    clearpath_motor_msgs__msg__PumaFeedback * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->drivers_feedback.data[i]);
      PyObject * pyitem = clearpath_motor_msgs__msg__puma_feedback__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "drivers_feedback", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
