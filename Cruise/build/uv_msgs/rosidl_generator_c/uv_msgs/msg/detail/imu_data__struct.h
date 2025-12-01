// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from uv_msgs:msg/ImuData.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__IMU_DATA__STRUCT_H_
#define UV_MSGS__MSG__DETAIL__IMU_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pos'
// Member 'spd'
#include "uv_msgs/msg/detail/robot_axis__struct.h"

// Struct defined in msg/ImuData in the package uv_msgs.
typedef struct uv_msgs__msg__ImuData
{
  uint8_t mode;
  uint8_t dvl;
  uv_msgs__msg__RobotAxis pos;
  uv_msgs__msg__RobotAxis spd;
} uv_msgs__msg__ImuData;

// Struct for a sequence of uv_msgs__msg__ImuData.
typedef struct uv_msgs__msg__ImuData__Sequence
{
  uv_msgs__msg__ImuData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} uv_msgs__msg__ImuData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UV_MSGS__MSG__DETAIL__IMU_DATA__STRUCT_H_
