// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from uv_msgs:msg/ThrustCurve.idl
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
#include "uv_msgs/msg/detail/thrust_curve__struct.h"
#include "uv_msgs/msg/detail/thrust_curve__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool uv_msgs__msg__thrust_curve__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[38];
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
    assert(strncmp("uv_msgs.msg._thrust_curve.ThrustCurve", full_classname_dest, 37) == 0);
  }
  uv_msgs__msg__ThrustCurve * ros_message = _ros_message;
  {  // num
    PyObject * field = PyObject_GetAttrString(_pymsg, "num");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->num = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // np_mid
    PyObject * field = PyObject_GetAttrString(_pymsg, "np_mid");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->np_mid = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // np_ini
    PyObject * field = PyObject_GetAttrString(_pymsg, "np_ini");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->np_ini = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pp_ini
    PyObject * field = PyObject_GetAttrString(_pymsg, "pp_ini");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pp_ini = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pp_mid
    PyObject * field = PyObject_GetAttrString(_pymsg, "pp_mid");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pp_mid = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // nt_end
    PyObject * field = PyObject_GetAttrString(_pymsg, "nt_end");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->nt_end = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // nt_mid
    PyObject * field = PyObject_GetAttrString(_pymsg, "nt_mid");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->nt_mid = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pt_mid
    PyObject * field = PyObject_GetAttrString(_pymsg, "pt_mid");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pt_mid = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pt_end
    PyObject * field = PyObject_GetAttrString(_pymsg, "pt_end");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pt_end = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * uv_msgs__msg__thrust_curve__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ThrustCurve */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("uv_msgs.msg._thrust_curve");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ThrustCurve");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  uv_msgs__msg__ThrustCurve * ros_message = (uv_msgs__msg__ThrustCurve *)raw_ros_message;
  {  // num
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->num);
    {
      int rc = PyObject_SetAttrString(_pymessage, "num", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // np_mid
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->np_mid);
    {
      int rc = PyObject_SetAttrString(_pymessage, "np_mid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // np_ini
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->np_ini);
    {
      int rc = PyObject_SetAttrString(_pymessage, "np_ini", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pp_ini
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pp_ini);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pp_ini", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pp_mid
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pp_mid);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pp_mid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // nt_end
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->nt_end);
    {
      int rc = PyObject_SetAttrString(_pymessage, "nt_end", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // nt_mid
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->nt_mid);
    {
      int rc = PyObject_SetAttrString(_pymessage, "nt_mid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pt_mid
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pt_mid);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pt_mid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pt_end
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pt_end);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pt_end", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
