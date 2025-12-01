// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from uv_msgs:msg/ThrustCurves.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__THRUST_CURVES__STRUCT_H_
#define UV_MSGS__MSG__DETAIL__THRUST_CURVES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'm0'
// Member 'm1'
// Member 'm2'
// Member 'm3'
// Member 'm4'
// Member 'm5'
#include "uv_msgs/msg/detail/thrust_curve__struct.h"

// Struct defined in msg/ThrustCurves in the package uv_msgs.
typedef struct uv_msgs__msg__ThrustCurves
{
  uv_msgs__msg__ThrustCurve m0;
  uv_msgs__msg__ThrustCurve m1;
  uv_msgs__msg__ThrustCurve m2;
  uv_msgs__msg__ThrustCurve m3;
  uv_msgs__msg__ThrustCurve m4;
  uv_msgs__msg__ThrustCurve m5;
} uv_msgs__msg__ThrustCurves;

// Struct for a sequence of uv_msgs__msg__ThrustCurves.
typedef struct uv_msgs__msg__ThrustCurves__Sequence
{
  uv_msgs__msg__ThrustCurves * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} uv_msgs__msg__ThrustCurves__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UV_MSGS__MSG__DETAIL__THRUST_CURVES__STRUCT_H_
