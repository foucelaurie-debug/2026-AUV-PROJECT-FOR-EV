// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from uv_msgs:msg/ThrustCurve.idl
// generated code does not contain a copyright notice
#include "uv_msgs/msg/detail/thrust_curve__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "uv_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "uv_msgs/msg/detail/thrust_curve__struct.h"
#include "uv_msgs/msg/detail/thrust_curve__functions.h"
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


using _ThrustCurve__ros_msg_type = uv_msgs__msg__ThrustCurve;

static bool _ThrustCurve__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ThrustCurve__ros_msg_type * ros_message = static_cast<const _ThrustCurve__ros_msg_type *>(untyped_ros_message);
  // Field name: num
  {
    cdr << ros_message->num;
  }

  // Field name: np_mid
  {
    cdr << ros_message->np_mid;
  }

  // Field name: np_ini
  {
    cdr << ros_message->np_ini;
  }

  // Field name: pp_ini
  {
    cdr << ros_message->pp_ini;
  }

  // Field name: pp_mid
  {
    cdr << ros_message->pp_mid;
  }

  // Field name: nt_end
  {
    cdr << ros_message->nt_end;
  }

  // Field name: nt_mid
  {
    cdr << ros_message->nt_mid;
  }

  // Field name: pt_mid
  {
    cdr << ros_message->pt_mid;
  }

  // Field name: pt_end
  {
    cdr << ros_message->pt_end;
  }

  return true;
}

static bool _ThrustCurve__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ThrustCurve__ros_msg_type * ros_message = static_cast<_ThrustCurve__ros_msg_type *>(untyped_ros_message);
  // Field name: num
  {
    cdr >> ros_message->num;
  }

  // Field name: np_mid
  {
    cdr >> ros_message->np_mid;
  }

  // Field name: np_ini
  {
    cdr >> ros_message->np_ini;
  }

  // Field name: pp_ini
  {
    cdr >> ros_message->pp_ini;
  }

  // Field name: pp_mid
  {
    cdr >> ros_message->pp_mid;
  }

  // Field name: nt_end
  {
    cdr >> ros_message->nt_end;
  }

  // Field name: nt_mid
  {
    cdr >> ros_message->nt_mid;
  }

  // Field name: pt_mid
  {
    cdr >> ros_message->pt_mid;
  }

  // Field name: pt_end
  {
    cdr >> ros_message->pt_end;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_uv_msgs
size_t get_serialized_size_uv_msgs__msg__ThrustCurve(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ThrustCurve__ros_msg_type * ros_message = static_cast<const _ThrustCurve__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name num
  {
    size_t item_size = sizeof(ros_message->num);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name np_mid
  {
    size_t item_size = sizeof(ros_message->np_mid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name np_ini
  {
    size_t item_size = sizeof(ros_message->np_ini);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pp_ini
  {
    size_t item_size = sizeof(ros_message->pp_ini);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pp_mid
  {
    size_t item_size = sizeof(ros_message->pp_mid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name nt_end
  {
    size_t item_size = sizeof(ros_message->nt_end);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name nt_mid
  {
    size_t item_size = sizeof(ros_message->nt_mid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pt_mid
  {
    size_t item_size = sizeof(ros_message->pt_mid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pt_end
  {
    size_t item_size = sizeof(ros_message->pt_end);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ThrustCurve__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_uv_msgs__msg__ThrustCurve(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_uv_msgs
size_t max_serialized_size_uv_msgs__msg__ThrustCurve(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: num
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: np_mid
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: np_ini
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pp_ini
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pp_mid
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: nt_end
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: nt_mid
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pt_mid
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pt_end
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _ThrustCurve__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_uv_msgs__msg__ThrustCurve(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_ThrustCurve = {
  "uv_msgs::msg",
  "ThrustCurve",
  _ThrustCurve__cdr_serialize,
  _ThrustCurve__cdr_deserialize,
  _ThrustCurve__get_serialized_size,
  _ThrustCurve__max_serialized_size
};

static rosidl_message_type_support_t _ThrustCurve__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ThrustCurve,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, uv_msgs, msg, ThrustCurve)() {
  return &_ThrustCurve__type_support;
}

#if defined(__cplusplus)
}
#endif
