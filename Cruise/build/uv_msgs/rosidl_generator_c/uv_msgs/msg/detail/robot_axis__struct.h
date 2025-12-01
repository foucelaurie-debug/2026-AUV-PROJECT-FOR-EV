// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from uv_msgs:msg/RobotAxis.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__ROBOT_AXIS__STRUCT_H_
#define UV_MSGS__MSG__DETAIL__ROBOT_AXIS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/RobotAxis in the package uv_msgs.
typedef struct uv_msgs__msg__RobotAxis
{
  float x;
  float y;
  float z;
  float rx;
  float ry;
  float rz;
} uv_msgs__msg__RobotAxis;

// Struct for a sequence of uv_msgs__msg__RobotAxis.
typedef struct uv_msgs__msg__RobotAxis__Sequence
{
  uv_msgs__msg__RobotAxis * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} uv_msgs__msg__RobotAxis__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UV_MSGS__MSG__DETAIL__ROBOT_AXIS__STRUCT_H_
