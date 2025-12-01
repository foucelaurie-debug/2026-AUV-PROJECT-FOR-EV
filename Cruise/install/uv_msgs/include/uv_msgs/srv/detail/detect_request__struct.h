// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from uv_msgs:srv/DetectRequest.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__SRV__DETAIL__DETECT_REQUEST__STRUCT_H_
#define UV_MSGS__SRV__DETAIL__DETECT_REQUEST__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'imagein'
#include "sensor_msgs/msg/detail/image__struct.h"
// Member 'target'
// Member 'stero'
#include "rosidl_runtime_c/string.h"

// Struct defined in srv/DetectRequest in the package uv_msgs.
typedef struct uv_msgs__srv__DetectRequest_Request
{
  sensor_msgs__msg__Image imagein;
  rosidl_runtime_c__String target;
  rosidl_runtime_c__String stero;
} uv_msgs__srv__DetectRequest_Request;

// Struct for a sequence of uv_msgs__srv__DetectRequest_Request.
typedef struct uv_msgs__srv__DetectRequest_Request__Sequence
{
  uv_msgs__srv__DetectRequest_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} uv_msgs__srv__DetectRequest_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/DetectRequest in the package uv_msgs.
typedef struct uv_msgs__srv__DetectRequest_Response
{
  uint8_t s;
  float x;
  float y;
  float z;
} uv_msgs__srv__DetectRequest_Response;

// Struct for a sequence of uv_msgs__srv__DetectRequest_Response.
typedef struct uv_msgs__srv__DetectRequest_Response__Sequence
{
  uv_msgs__srv__DetectRequest_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} uv_msgs__srv__DetectRequest_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UV_MSGS__SRV__DETAIL__DETECT_REQUEST__STRUCT_H_
