// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from uv_msgs:msg/PidControllersState.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__PID_CONTROLLERS_STATE__STRUCT_H_
#define UV_MSGS__MSG__DETAIL__PID_CONTROLLERS_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/PidControllersState in the package uv_msgs.
typedef struct uv_msgs__msg__PidControllersState
{
  uint8_t x;
  uint8_t y;
  uint8_t z;
  uint8_t rx;
  uint8_t ry;
  uint8_t rz;
  uint8_t vy;
  uint8_t vx;
} uv_msgs__msg__PidControllersState;

// Struct for a sequence of uv_msgs__msg__PidControllersState.
typedef struct uv_msgs__msg__PidControllersState__Sequence
{
  uv_msgs__msg__PidControllersState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} uv_msgs__msg__PidControllersState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UV_MSGS__MSG__DETAIL__PID_CONTROLLERS_STATE__STRUCT_H_
