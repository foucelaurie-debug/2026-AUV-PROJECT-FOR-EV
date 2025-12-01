// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from uv_msgs:msg/Yolov8.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__YOLOV8__STRUCT_H_
#define UV_MSGS__MSG__DETAIL__YOLOV8__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'targets'
#include "uv_msgs/msg/detail/target_params__struct.h"

// Struct defined in msg/Yolov8 in the package uv_msgs.
typedef struct uv_msgs__msg__Yolov8
{
  float state[11];
  uv_msgs__msg__TargetParams targets[11];
} uv_msgs__msg__Yolov8;

// Struct for a sequence of uv_msgs__msg__Yolov8.
typedef struct uv_msgs__msg__Yolov8__Sequence
{
  uv_msgs__msg__Yolov8 * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} uv_msgs__msg__Yolov8__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UV_MSGS__MSG__DETAIL__YOLOV8__STRUCT_H_
