// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from uv_msgs:msg/ThrustCurves.idl
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
#include "uv_msgs/msg/detail/thrust_curves__struct.h"
#include "uv_msgs/msg/detail/thrust_curves__functions.h"

bool uv_msgs__msg__thrust_curve__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * uv_msgs__msg__thrust_curve__convert_to_py(void * raw_ros_message);
bool uv_msgs__msg__thrust_curve__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * uv_msgs__msg__thrust_curve__convert_to_py(void * raw_ros_message);
bool uv_msgs__msg__thrust_curve__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * uv_msgs__msg__thrust_curve__convert_to_py(void * raw_ros_message);
bool uv_msgs__msg__thrust_curve__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * uv_msgs__msg__thrust_curve__convert_to_py(void * raw_ros_message);
bool uv_msgs__msg__thrust_curve__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * uv_msgs__msg__thrust_curve__convert_to_py(void * raw_ros_message);
bool uv_msgs__msg__thrust_curve__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * uv_msgs__msg__thrust_curve__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool uv_msgs__msg__thrust_curves__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("uv_msgs.msg._thrust_curves.ThrustCurves", full_classname_dest, 39) == 0);
  }
  uv_msgs__msg__ThrustCurves * ros_message = _ros_message;
  {  // m0
    PyObject * field = PyObject_GetAttrString(_pymsg, "m0");
    if (!field) {
      return false;
    }
    if (!uv_msgs__msg__thrust_curve__convert_from_py(field, &ros_message->m0)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // m1
    PyObject * field = PyObject_GetAttrString(_pymsg, "m1");
    if (!field) {
      return false;
    }
    if (!uv_msgs__msg__thrust_curve__convert_from_py(field, &ros_message->m1)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // m2
    PyObject * field = PyObject_GetAttrString(_pymsg, "m2");
    if (!field) {
      return false;
    }
    if (!uv_msgs__msg__thrust_curve__convert_from_py(field, &ros_message->m2)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // m3
    PyObject * field = PyObject_GetAttrString(_pymsg, "m3");
    if (!field) {
      return false;
    }
    if (!uv_msgs__msg__thrust_curve__convert_from_py(field, &ros_message->m3)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // m4
    PyObject * field = PyObject_GetAttrString(_pymsg, "m4");
    if (!field) {
      return false;
    }
    if (!uv_msgs__msg__thrust_curve__convert_from_py(field, &ros_message->m4)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // m5
    PyObject * field = PyObject_GetAttrString(_pymsg, "m5");
    if (!field) {
      return false;
    }
    if (!uv_msgs__msg__thrust_curve__convert_from_py(field, &ros_message->m5)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * uv_msgs__msg__thrust_curves__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ThrustCurves */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("uv_msgs.msg._thrust_curves");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ThrustCurves");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  uv_msgs__msg__ThrustCurves * ros_message = (uv_msgs__msg__ThrustCurves *)raw_ros_message;
  {  // m0
    PyObject * field = NULL;
    field = uv_msgs__msg__thrust_curve__convert_to_py(&ros_message->m0);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "m0", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // m1
    PyObject * field = NULL;
    field = uv_msgs__msg__thrust_curve__convert_to_py(&ros_message->m1);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "m1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // m2
    PyObject * field = NULL;
    field = uv_msgs__msg__thrust_curve__convert_to_py(&ros_message->m2);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "m2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // m3
    PyObject * field = NULL;
    field = uv_msgs__msg__thrust_curve__convert_to_py(&ros_message->m3);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "m3", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // m4
    PyObject * field = NULL;
    field = uv_msgs__msg__thrust_curve__convert_to_py(&ros_message->m4);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "m4", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // m5
    PyObject * field = NULL;
    field = uv_msgs__msg__thrust_curve__convert_to_py(&ros_message->m5);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "m5", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
