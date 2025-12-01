// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from uv_msgs:msg/PidControllers.idl
// generated code does not contain a copyright notice
#include "uv_msgs/msg/detail/pid_controllers__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "uv_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "uv_msgs/msg/detail/pid_controllers__struct.h"
#include "uv_msgs/msg/detail/pid_controllers__functions.h"
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

#include "uv_msgs/msg/detail/pid_params__functions.h"  // rx, ry, rz, vx, vy, x, y, z

// forward declare type support functions
size_t get_serialized_size_uv_msgs__msg__PidParams(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_uv_msgs__msg__PidParams(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, uv_msgs, msg, PidParams)();


using _PidControllers__ros_msg_type = uv_msgs__msg__PidControllers;

static bool _PidControllers__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _PidControllers__ros_msg_type * ros_message = static_cast<const _PidControllers__ros_msg_type *>(untyped_ros_message);
  // Field name: x
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, PidParams
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->x, cdr))
    {
      return false;
    }
  }

  // Field name: y
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, PidParams
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->y, cdr))
    {
      return false;
    }
  }

  // Field name: z
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, PidParams
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->z, cdr))
    {
      return false;
    }
  }

  // Field name: rx
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, PidParams
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->rx, cdr))
    {
      return false;
    }
  }

  // Field name: ry
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, PidParams
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->ry, cdr))
    {
      return false;
    }
  }

  // Field name: rz
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, PidParams
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->rz, cdr))
    {
      return false;
    }
  }

  // Field name: vx
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, PidParams
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->vx, cdr))
    {
      return false;
    }
  }

  // Field name: vy
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, PidParams
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->vy, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _PidControllers__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _PidControllers__ros_msg_type * ros_message = static_cast<_PidControllers__ros_msg_type *>(untyped_ros_message);
  // Field name: x
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, PidParams
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->x))
    {
      return false;
    }
  }

  // Field name: y
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, PidParams
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->y))
    {
      return false;
    }
  }

  // Field name: z
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, PidParams
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->z))
    {
      return false;
    }
  }

  // Field name: rx
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, PidParams
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->rx))
    {
      return false;
    }
  }

  // Field name: ry
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, PidParams
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->ry))
    {
      return false;
    }
  }

  // Field name: rz
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, PidParams
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->rz))
    {
      return false;
    }
  }

  // Field name: vx
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, PidParams
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->vx))
    {
      return false;
    }
  }

  // Field name: vy
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, PidParams
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->vy))
    {
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_uv_msgs
size_t get_serialized_size_uv_msgs__msg__PidControllers(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PidControllers__ros_msg_type * ros_message = static_cast<const _PidControllers__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name x

  current_alignment += get_serialized_size_uv_msgs__msg__PidParams(
    &(ros_message->x), current_alignment);
  // field.name y

  current_alignment += get_serialized_size_uv_msgs__msg__PidParams(
    &(ros_message->y), current_alignment);
  // field.name z

  current_alignment += get_serialized_size_uv_msgs__msg__PidParams(
    &(ros_message->z), current_alignment);
  // field.name rx

  current_alignment += get_serialized_size_uv_msgs__msg__PidParams(
    &(ros_message->rx), current_alignment);
  // field.name ry

  current_alignment += get_serialized_size_uv_msgs__msg__PidParams(
    &(ros_message->ry), current_alignment);
  // field.name rz

  current_alignment += get_serialized_size_uv_msgs__msg__PidParams(
    &(ros_message->rz), current_alignment);
  // field.name vx

  current_alignment += get_serialized_size_uv_msgs__msg__PidParams(
    &(ros_message->vx), current_alignment);
  // field.name vy

  current_alignment += get_serialized_size_uv_msgs__msg__PidParams(
    &(ros_message->vy), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _PidControllers__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_uv_msgs__msg__PidControllers(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_uv_msgs
size_t max_serialized_size_uv_msgs__msg__PidControllers(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: x
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_uv_msgs__msg__PidParams(
        full_bounded, current_alignment);
    }
  }
  // member: y
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_uv_msgs__msg__PidParams(
        full_bounded, current_alignment);
    }
  }
  // member: z
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_uv_msgs__msg__PidParams(
        full_bounded, current_alignment);
    }
  }
  // member: rx
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_uv_msgs__msg__PidParams(
        full_bounded, current_alignment);
    }
  }
  // member: ry
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_uv_msgs__msg__PidParams(
        full_bounded, current_alignment);
    }
  }
  // member: rz
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_uv_msgs__msg__PidParams(
        full_bounded, current_alignment);
    }
  }
  // member: vx
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_uv_msgs__msg__PidParams(
        full_bounded, current_alignment);
    }
  }
  // member: vy
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_uv_msgs__msg__PidParams(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _PidControllers__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_uv_msgs__msg__PidControllers(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_PidControllers = {
  "uv_msgs::msg",
  "PidControllers",
  _PidControllers__cdr_serialize,
  _PidControllers__cdr_deserialize,
  _PidControllers__get_serialized_size,
  _PidControllers__max_serialized_size
};

static rosidl_message_type_support_t _PidControllers__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PidControllers,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, uv_msgs, msg, PidControllers)() {
  return &_PidControllers__type_support;
}

#if defined(__cplusplus)
}
#endif
