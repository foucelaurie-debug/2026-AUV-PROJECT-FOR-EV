// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from uv_msgs:msg/Yolov8.idl
// generated code does not contain a copyright notice
#include "uv_msgs/msg/detail/yolov8__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "uv_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "uv_msgs/msg/detail/yolov8__struct.h"
#include "uv_msgs/msg/detail/yolov8__functions.h"
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

#include "uv_msgs/msg/detail/target_params__functions.h"  // targets

// forward declare type support functions
size_t get_serialized_size_uv_msgs__msg__TargetParams(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_uv_msgs__msg__TargetParams(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, uv_msgs, msg, TargetParams)();


using _Yolov8__ros_msg_type = uv_msgs__msg__Yolov8;

static bool _Yolov8__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Yolov8__ros_msg_type * ros_message = static_cast<const _Yolov8__ros_msg_type *>(untyped_ros_message);
  // Field name: state
  {
    size_t size = 11;
    auto array_ptr = ros_message->state;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: targets
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, TargetParams
      )()->data);
    size_t size = 11;
    auto array_ptr = ros_message->targets;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  return true;
}

static bool _Yolov8__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Yolov8__ros_msg_type * ros_message = static_cast<_Yolov8__ros_msg_type *>(untyped_ros_message);
  // Field name: state
  {
    size_t size = 11;
    auto array_ptr = ros_message->state;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: targets
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, TargetParams
      )()->data);
    size_t size = 11;
    auto array_ptr = ros_message->targets;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_uv_msgs
size_t get_serialized_size_uv_msgs__msg__Yolov8(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Yolov8__ros_msg_type * ros_message = static_cast<const _Yolov8__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name state
  {
    size_t array_size = 11;
    auto array_ptr = ros_message->state;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name targets
  {
    size_t array_size = 11;
    auto array_ptr = ros_message->targets;

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_uv_msgs__msg__TargetParams(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Yolov8__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_uv_msgs__msg__Yolov8(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_uv_msgs
size_t max_serialized_size_uv_msgs__msg__Yolov8(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: state
  {
    size_t array_size = 11;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: targets
  {
    size_t array_size = 11;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_uv_msgs__msg__TargetParams(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _Yolov8__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_uv_msgs__msg__Yolov8(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_Yolov8 = {
  "uv_msgs::msg",
  "Yolov8",
  _Yolov8__cdr_serialize,
  _Yolov8__cdr_deserialize,
  _Yolov8__get_serialized_size,
  _Yolov8__max_serialized_size
};

static rosidl_message_type_support_t _Yolov8__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Yolov8,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, uv_msgs, msg, Yolov8)() {
  return &_Yolov8__type_support;
}

#if defined(__cplusplus)
}
#endif
