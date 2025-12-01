// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from uv_msgs:msg/ThrustCurves.idl
// generated code does not contain a copyright notice
#include "uv_msgs/msg/detail/thrust_curves__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "uv_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "uv_msgs/msg/detail/thrust_curves__struct.h"
#include "uv_msgs/msg/detail/thrust_curves__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "uv_msgs/msg/detail/thrust_curve__functions.h"  // m0, m1, m2, m3, m4, m5

// forward declare type support functions
size_t get_serialized_size_uv_msgs__msg__ThrustCurve(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_uv_msgs__msg__ThrustCurve(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, uv_msgs, msg, ThrustCurve)();


using _ThrustCurves__ros_msg_type = uv_msgs__msg__ThrustCurves;

static bool _ThrustCurves__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ThrustCurves__ros_msg_type * ros_message = static_cast<const _ThrustCurves__ros_msg_type *>(untyped_ros_message);
  // Field name: m0
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, ThrustCurve
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->m0, cdr))
    {
      return false;
    }
  }

  // Field name: m1
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, ThrustCurve
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->m1, cdr))
    {
      return false;
    }
  }

  // Field name: m2
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, ThrustCurve
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->m2, cdr))
    {
      return false;
    }
  }

  // Field name: m3
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, ThrustCurve
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->m3, cdr))
    {
      return false;
    }
  }

  // Field name: m4
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, ThrustCurve
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->m4, cdr))
    {
      return false;
    }
  }

  // Field name: m5
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, ThrustCurve
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->m5, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _ThrustCurves__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ThrustCurves__ros_msg_type * ros_message = static_cast<_ThrustCurves__ros_msg_type *>(untyped_ros_message);
  // Field name: m0
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, ThrustCurve
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->m0))
    {
      return false;
    }
  }

  // Field name: m1
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, ThrustCurve
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->m1))
    {
      return false;
    }
  }

  // Field name: m2
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, ThrustCurve
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->m2))
    {
      return false;
    }
  }

  // Field name: m3
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, ThrustCurve
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->m3))
    {
      return false;
    }
  }

  // Field name: m4
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, ThrustCurve
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->m4))
    {
      return false;
    }
  }

  // Field name: m5
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, ThrustCurve
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->m5))
    {
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_uv_msgs
size_t get_serialized_size_uv_msgs__msg__ThrustCurves(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ThrustCurves__ros_msg_type * ros_message = static_cast<const _ThrustCurves__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name m0

  current_alignment += get_serialized_size_uv_msgs__msg__ThrustCurve(
    &(ros_message->m0), current_alignment);
  // field.name m1

  current_alignment += get_serialized_size_uv_msgs__msg__ThrustCurve(
    &(ros_message->m1), current_alignment);
  // field.name m2

  current_alignment += get_serialized_size_uv_msgs__msg__ThrustCurve(
    &(ros_message->m2), current_alignment);
  // field.name m3

  current_alignment += get_serialized_size_uv_msgs__msg__ThrustCurve(
    &(ros_message->m3), current_alignment);
  // field.name m4

  current_alignment += get_serialized_size_uv_msgs__msg__ThrustCurve(
    &(ros_message->m4), current_alignment);
  // field.name m5

  current_alignment += get_serialized_size_uv_msgs__msg__ThrustCurve(
    &(ros_message->m5), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _ThrustCurves__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_uv_msgs__msg__ThrustCurves(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_uv_msgs
size_t max_serialized_size_uv_msgs__msg__ThrustCurves(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: m0
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_uv_msgs__msg__ThrustCurve(
        full_bounded, current_alignment);
    }
  }
  // member: m1
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_uv_msgs__msg__ThrustCurve(
        full_bounded, current_alignment);
    }
  }
  // member: m2
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_uv_msgs__msg__ThrustCurve(
        full_bounded, current_alignment);
    }
  }
  // member: m3
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_uv_msgs__msg__ThrustCurve(
        full_bounded, current_alignment);
    }
  }
  // member: m4
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_uv_msgs__msg__ThrustCurve(
        full_bounded, current_alignment);
    }
  }
  // member: m5
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_uv_msgs__msg__ThrustCurve(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _ThrustCurves__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_uv_msgs__msg__ThrustCurves(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_ThrustCurves = {
  "uv_msgs::msg",
  "ThrustCurves",
  _ThrustCurves__cdr_serialize,
  _ThrustCurves__cdr_deserialize,
  _ThrustCurves__get_serialized_size,
  _ThrustCurves__max_serialized_size
};

static rosidl_message_type_support_t _ThrustCurves__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ThrustCurves,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, uv_msgs, msg, ThrustCurves)() {
  return &_ThrustCurves__type_support;
}

#if defined(__cplusplus)
}
#endif
