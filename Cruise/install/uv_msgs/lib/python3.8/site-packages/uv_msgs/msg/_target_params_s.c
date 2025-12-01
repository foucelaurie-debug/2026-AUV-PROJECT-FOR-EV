// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from uv_msgs:msg/TargetParams.idl
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
#include "uv_msgs/msg/detail/target_params__struct.h"
#include "uv_msgs/msg/detail/target_params__functions.h"

bool uv_msgs__msg__pixel_axis__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * uv_msgs__msg__pixel_axis__convert_to_py(void * raw_ros_message);
bool uv_msgs__msg__target_axis__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * uv_msgs__msg__target_axis__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool uv_msgs__msg__target_params__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[40];
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
    assert(strncmp("uv_msgs.msg._target_params.TargetParams", full_classname_dest, 39) == 0);
  }
  uv_msgs__msg__TargetParams * ros_message = _ros_message;
  {  // tpos_inpic
    PyObject * field = PyObject_GetAttrString(_pymsg, "tpos_inpic");
    if (!field) {
      return false;
    }
    if (!uv_msgs__msg__pixel_axis__convert_from_py(field, &ros_message->tpos_inpic)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // tpos_inworld
    PyObject * field = PyObject_GetAttrString(_pymsg, "tpos_inworld");
    if (!field) {
      return false;
    }
    if (!uv_msgs__msg__target_axis__convert_from_py(field, &ros_message->tpos_inworld)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * uv_msgs__msg__target_params__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of TargetParams */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("uv_msgs.msg._target_params");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "TargetParams");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  uv_msgs__msg__TargetParams * ros_message = (uv_msgs__msg__TargetParams *)raw_ros_message;
  {  // tpos_inpic
    PyObject * field = NULL;
    field = uv_msgs__msg__pixel_axis__convert_to_py(&ros_message->tpos_inpic);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "tpos_inpic", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tpos_inworld
    PyObject * field = NULL;
    field = uv_msgs__msg__target_axis__convert_to_py(&ros_message->tpos_inworld);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "tpos_inworld", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
