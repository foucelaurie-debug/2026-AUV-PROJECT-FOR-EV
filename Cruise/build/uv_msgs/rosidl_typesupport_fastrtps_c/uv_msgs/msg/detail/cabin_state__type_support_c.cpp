// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from uv_msgs:msg/CabinState.idl
// generated code does not contain a copyright notice
#include "uv_msgs/msg/detail/cabin_state__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "uv_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "uv_msgs/msg/detail/cabin_state__struct.h"
#include "uv_msgs/msg/detail/cabin_state__functions.h"
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


// forward declare type support functions


using _CabinState__ros_msg_type = uv_msgs__msg__CabinState;

static bool _CabinState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _CabinState__ros_msg_type * ros_message = static_cast<const _CabinState__ros_msg_type *>(untyped_ros_message);
  // Field name: temp
  {
    cdr << ros_message->temp;
  }

  // Field name: hum
  {
    cdr << ros_message->hum;
  }

  // Field name: leak
  {
    cdr << ros_message->leak;
  }

  // Field name: voltage
  {
    cdr << ros_message->voltage;
  }

  // Field name: servo
  {
    size_t size = 2;
    auto array_ptr = ros_message->servo;
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _CabinState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _CabinState__ros_msg_type * ros_message = static_cast<_CabinState__ros_msg_type *>(untyped_ros_message);
  // Field name: temp
  {
    cdr >> ros_message->temp;
  }

  // Field name: hum
  {
    cdr >> ros_message->hum;
  }

  // Field name: leak
  {
    cdr >> ros_message->leak;
  }

  // Field name: voltage
  {
    cdr >> ros_message->voltage;
  }

  // Field name: servo
  {
    size_t size = 2;
    auto array_ptr = ros_message->servo;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_uv_msgs
size_t get_serialized_size_uv_msgs__msg__CabinState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CabinState__ros_msg_type * ros_message = static_cast<const _CabinState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name temp
  {
    size_t item_size = sizeof(ros_message->temp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name hum
  {
    size_t item_size = sizeof(ros_message->hum);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name leak
  {
    size_t item_size = sizeof(ros_message->leak);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name voltage
  {
    size_t item_size = sizeof(ros_message->voltage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name servo
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->servo;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _CabinState__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_uv_msgs__msg__CabinState(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_uv_msgs
size_t max_serialized_size_uv_msgs__msg__CabinState(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: temp
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: hum
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: leak
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: voltage
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: servo
  {
    size_t array_size = 2;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _CabinState__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_uv_msgs__msg__CabinState(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_CabinState = {
  "uv_msgs::msg",
  "CabinState",
  _CabinState__cdr_serialize,
  _CabinState__cdr_deserialize,
  _CabinState__get_serialized_size,
  _CabinState__max_serialized_size
};

static rosidl_message_type_support_t _CabinState__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_CabinState,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, uv_msgs, msg, CabinState)() {
  return &_CabinState__type_support;
}

#if defined(__cplusplus)
}
#endif
