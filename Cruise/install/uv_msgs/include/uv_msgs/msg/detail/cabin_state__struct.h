// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from uv_msgs:msg/CabinState.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__CABIN_STATE__STRUCT_H_
#define UV_MSGS__MSG__DETAIL__CABIN_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/CabinState in the package uv_msgs.
typedef struct uv_msgs__msg__CabinState
{
  float temp;
  float hum;
  uint8_t leak;
  float voltage;
  float servo[2];
} uv_msgs__msg__CabinState;

// Struct for a sequence of uv_msgs__msg__CabinState.
typedef struct uv_msgs__msg__CabinState__Sequence
{
  uv_msgs__msg__CabinState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} uv_msgs__msg__CabinState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UV_MSGS__MSG__DETAIL__CABIN_STATE__STRUCT_H_
