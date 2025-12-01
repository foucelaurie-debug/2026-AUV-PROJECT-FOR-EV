// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from uv_msgs:msg/ThrustCurve.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__THRUST_CURVE__STRUCT_H_
#define UV_MSGS__MSG__DETAIL__THRUST_CURVE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/ThrustCurve in the package uv_msgs.
typedef struct uv_msgs__msg__ThrustCurve
{
  uint8_t num;
  float np_mid;
  float np_ini;
  float pp_ini;
  float pp_mid;
  float nt_end;
  float nt_mid;
  float pt_mid;
  float pt_end;
} uv_msgs__msg__ThrustCurve;

// Struct for a sequence of uv_msgs__msg__ThrustCurve.
typedef struct uv_msgs__msg__ThrustCurve__Sequence
{
  uv_msgs__msg__ThrustCurve * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} uv_msgs__msg__ThrustCurve__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UV_MSGS__MSG__DETAIL__THRUST_CURVE__STRUCT_H_
