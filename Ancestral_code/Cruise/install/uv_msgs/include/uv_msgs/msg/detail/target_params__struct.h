// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from uv_msgs:msg/TargetParams.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__TARGET_PARAMS__STRUCT_H_
#define UV_MSGS__MSG__DETAIL__TARGET_PARAMS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'tpos_inpic'
#include "uv_msgs/msg/detail/pixel_axis__struct.h"
// Member 'tpos_inworld'
#include "uv_msgs/msg/detail/target_axis__struct.h"

// Struct defined in msg/TargetParams in the package uv_msgs.
typedef struct uv_msgs__msg__TargetParams
{
  uv_msgs__msg__PixelAxis tpos_inpic;
  uv_msgs__msg__TargetAxis tpos_inworld;
} uv_msgs__msg__TargetParams;

// Struct for a sequence of uv_msgs__msg__TargetParams.
typedef struct uv_msgs__msg__TargetParams__Sequence
{
  uv_msgs__msg__TargetParams * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} uv_msgs__msg__TargetParams__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UV_MSGS__MSG__DETAIL__TARGET_PARAMS__STRUCT_H_
