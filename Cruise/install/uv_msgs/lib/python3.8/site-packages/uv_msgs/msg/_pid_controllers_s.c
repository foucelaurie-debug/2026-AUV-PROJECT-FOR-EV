// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from uv_msgs:msg/PidControllers.idl
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
#include "uv_msgs/msg/detail/pid_controllers__struct.h"
#include "uv_msgs/msg/detail/pid_controllers__functions.h"

bool uv_msgs__msg__pid_params__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * uv_msgs__msg__pid_params__convert_to_py(void * raw_ros_message);
bool uv_msgs__msg__pid_params__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * uv_msgs__msg__pid_params__convert_to_py(void * raw_ros_message);
bool uv_msgs__msg__pid_params__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * uv_msgs__msg__pid_params__convert_to_py(void * raw_ros_message);
bool uv_msgs__msg__pid_params__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * uv_msgs__msg__pid_params__convert_to_py(void * raw_ros_message);
bool uv_msgs__msg__pid_params__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * uv_msgs__msg__pid_params__convert_to_py(void * raw_ros_message);
bool uv_msgs__msg__pid_params__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * uv_msgs__msg__pid_params__convert_to_py(void * raw_ros_message);
bool uv_msgs__msg__pid_params__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * uv_msgs__msg__pid_params__convert_to_py(void * raw_ros_message);
bool uv_msgs__msg__pid_params__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * uv_msgs__msg__pid_params__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool uv_msgs__msg__pid_controllers__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[44];
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
    assert(strncmp("uv_msgs.msg._pid_controllers.PidControllers", full_classname_dest, 43) == 0);
  }
  uv_msgs__msg__PidControllers * ros_message = _ros_message;
  {  // x
    PyObject * field = PyObject_GetAttrString(_pymsg, "x");
    if (!field) {
      return false;
    }
    if (!uv_msgs__msg__pid_params__convert_from_py(field, &ros_message->x)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // y
    PyObject * field = PyObject_GetAttrString(_pymsg, "y");
    if (!field) {
      return false;
    }
    if (!uv_msgs__msg__pid_params__convert_from_py(field, &ros_message->y)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // z
    PyObject * field = PyObject_GetAttrString(_pymsg, "z");
    if (!field) {
      return false;
    }
    if (!uv_msgs__msg__pid_params__convert_from_py(field, &ros_message->z)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // rx
    PyObject * field = PyObject_GetAttrString(_pymsg, "rx");
    if (!field) {
      return false;
    }
    if (!uv_msgs__msg__pid_params__convert_from_py(field, &ros_message->rx)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // ry
    PyObject * field = PyObject_GetAttrString(_pymsg, "ry");
    if (!field) {
      return false;
    }
    if (!uv_msgs__msg__pid_params__convert_from_py(field, &ros_message->ry)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // rz
    PyObject * field = PyObject_GetAttrString(_pymsg, "rz");
    if (!field) {
      return false;
    }
    if (!uv_msgs__msg__pid_params__convert_from_py(field, &ros_message->rz)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // vx
    PyObject * field = PyObject_GetAttrString(_pymsg, "vx");
    if (!field) {
      return false;
    }
    if (!uv_msgs__msg__pid_params__convert_from_py(field, &ros_message->vx)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // vy
    PyObject * field = PyObject_GetAttrString(_pymsg, "vy");
    if (!field) {
      return false;
    }
    if (!uv_msgs__msg__pid_params__convert_from_py(field, &ros_message->vy)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * uv_msgs__msg__pid_controllers__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of PidControllers */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("uv_msgs.msg._pid_controllers");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "PidControllers");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  uv_msgs__msg__PidControllers * ros_message = (uv_msgs__msg__PidControllers *)raw_ros_message;
  {  // x
    PyObject * field = NULL;
    field = uv_msgs__msg__pid_params__convert_to_py(&ros_message->x);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y
    PyObject * field = NULL;
    field = uv_msgs__msg__pid_params__convert_to_py(&ros_message->y);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // z
    PyObject * field = NULL;
    field = uv_msgs__msg__pid_params__convert_to_py(&ros_message->z);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rx
    PyObject * field = NULL;
    field = uv_msgs__msg__pid_params__convert_to_py(&ros_message->rx);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "rx", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ry
    PyObject * field = NULL;
    field = uv_msgs__msg__pid_params__convert_to_py(&ros_message->ry);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "ry", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rz
    PyObject * field = NULL;
    field = uv_msgs__msg__pid_params__convert_to_py(&ros_message->rz);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "rz", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vx
    PyObject * field = NULL;
    field = uv_msgs__msg__pid_params__convert_to_py(&ros_message->vx);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "vx", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vy
    PyObject * field = NULL;
    field = uv_msgs__msg__pid_params__convert_to_py(&ros_message->vy);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "vy", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
