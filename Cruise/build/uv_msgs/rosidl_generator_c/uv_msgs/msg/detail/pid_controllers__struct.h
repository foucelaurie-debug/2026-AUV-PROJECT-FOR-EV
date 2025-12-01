// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from uv_msgs:msg/PidControllers.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__PID_CONTROLLERS__STRUCT_H_
#define UV_MSGS__MSG__DETAIL__PID_CONTROLLERS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'x'
// Member 'y'
// Member 'z'
// Member 'rx'
// Member 'ry'
// Member 'rz'
// Member 'vx'
// Member 'vy'
#include "uv_msgs/msg/detail/pid_params__struct.h"

// Struct defined in msg/PidControllers in the package uv_msgs.
typedef struct uv_msgs__msg__PidControllers
{
  uv_msgs__msg__PidParams x;
  uv_msgs__msg__PidParams y;
  uv_msgs__msg__PidParams z;
  uv_msgs__msg__PidParams rx;
  uv_msgs__msg__PidParams ry;
  uv_msgs__msg__PidParams rz;
  uv_msgs__msg__PidParams vx;
  uv_msgs__msg__PidParams vy;
} uv_msgs__msg__PidControllers;

// Struct for a sequence of uv_msgs__msg__PidControllers.
typedef struct uv_msgs__msg__PidControllers__Sequence
{
  uv_msgs__msg__PidControllers * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} uv_msgs__msg__PidControllers__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UV_MSGS__MSG__DETAIL__PID_CONTROLLERS__STRUCT_H_
