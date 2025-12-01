// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from uv_msgs:msg/TargetParams.idl
// generated code does not contain a copyright notice
#include "uv_msgs/msg/detail/target_params__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "uv_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "uv_msgs/msg/detail/target_params__struct.h"
#include "uv_msgs/msg/detail/target_params__functions.h"
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

#include "uv_msgs/msg/detail/pixel_axis__functions.h"  // tpos_inpic
#include "uv_msgs/msg/detail/target_axis__functions.h"  // tpos_inworld

// forward declare type support functions
size_t get_serialized_size_uv_msgs__msg__PixelAxis(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_uv_msgs__msg__PixelAxis(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, uv_msgs, msg, PixelAxis)();
size_t get_serialized_size_uv_msgs__msg__TargetAxis(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_uv_msgs__msg__TargetAxis(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, uv_msgs, msg, TargetAxis)();


using _TargetParams__ros_msg_type = uv_msgs__msg__TargetParams;

static bool _TargetParams__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _TargetParams__ros_msg_type * ros_message = static_cast<const _TargetParams__ros_msg_type *>(untyped_ros_message);
  // Field name: tpos_inpic
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, PixelAxis
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->tpos_inpic, cdr))
    {
      return false;
    }
  }

  // Field name: tpos_inworld
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, TargetAxis
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->tpos_inworld, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _TargetParams__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _TargetParams__ros_msg_type * ros_message = static_cast<_TargetParams__ros_msg_type *>(untyped_ros_message);
  // Field name: tpos_inpic
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, PixelAxis
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->tpos_inpic))
    {
      return false;
    }
  }

  // Field name: tpos_inworld
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, TargetAxis
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->tpos_inworld))
    {
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_uv_msgs
size_t get_serialized_size_uv_msgs__msg__TargetParams(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TargetParams__ros_msg_type * ros_message = static_cast<const _TargetParams__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name tpos_inpic

  current_alignment += get_serialized_size_uv_msgs__msg__PixelAxis(
    &(ros_message->tpos_inpic), current_alignment);
  // field.name tpos_inworld

  current_alignment += get_serialized_size_uv_msgs__msg__TargetAxis(
    &(ros_message->tpos_inworld), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _TargetParams__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_uv_msgs__msg__TargetParams(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_uv_msgs
size_t max_serialized_size_uv_msgs__msg__TargetParams(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: tpos_inpic
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_uv_msgs__msg__PixelAxis(
        full_bounded, current_alignment);
    }
  }
  // member: tpos_inworld
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_uv_msgs__msg__TargetAxis(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _TargetParams__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_uv_msgs__msg__TargetParams(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_TargetParams = {
  "uv_msgs::msg",
  "TargetParams",
  _TargetParams__cdr_serialize,
  _TargetParams__cdr_deserialize,
  _TargetParams__get_serialized_size,
  _TargetParams__max_serialized_size
};

static rosidl_message_type_support_t _TargetParams__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_TargetParams,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, uv_msgs, msg, TargetParams)() {
  return &_TargetParams__type_support;
}

#if defined(__cplusplus)
}
#endif
