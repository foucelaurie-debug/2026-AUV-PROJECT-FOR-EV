// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from uv_msgs:msg/RobotDeviceManager.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__ROBOT_DEVICE_MANAGER__STRUCT_H_
#define UV_MSGS__MSG__DETAIL__ROBOT_DEVICE_MANAGER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/RobotDeviceManager in the package uv_msgs.
typedef struct uv_msgs__msg__RobotDeviceManager
{
  uint8_t leak;
  float tem;
  float hum;
  float vol;
  uint8_t magnet;
  uint8_t led[2];
  float angle[2];
} uv_msgs__msg__RobotDeviceManager;

// Struct for a sequence of uv_msgs__msg__RobotDeviceManager.
typedef struct uv_msgs__msg__RobotDeviceManager__Sequence
{
  uv_msgs__msg__RobotDeviceManager * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} uv_msgs__msg__RobotDeviceManager__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UV_MSGS__MSG__DETAIL__ROBOT_DEVICE_MANAGER__STRUCT_H_
