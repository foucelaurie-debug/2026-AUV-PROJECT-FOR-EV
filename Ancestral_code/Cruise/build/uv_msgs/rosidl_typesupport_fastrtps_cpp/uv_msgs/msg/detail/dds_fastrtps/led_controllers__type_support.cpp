// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from uv_msgs:msg/LedControllers.idl
// generated code does not contain a copyright notice
#include "uv_msgs/msg/detail/led_controllers__rosidl_typesupport_fastrtps_cpp.hpp"
#include "uv_msgs/msg/detail/led_controllers__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace uv_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_uv_msgs
cdr_serialize(
  const uv_msgs::msg::LedControllers & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: led0
  cdr << ros_message.led0;
  // Member: led1
  cdr << ros_message.led1;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_uv_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  uv_msgs::msg::LedControllers & ros_message)
{
  // Member: led0
  cdr >> ros_message.led0;

  // Member: led1
  cdr >> ros_message.led1;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_uv_msgs
get_serialized_size(
  const uv_msgs::msg::LedControllers & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: led0
  {
    size_t item_size = sizeof(ros_message.led0);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: led1
  {
    size_t item_size = sizeof(ros_message.led1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_uv_msgs
max_serialized_size_LedControllers(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: led0
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: led1
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _LedControllers__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const uv_msgs::msg::LedControllers *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _LedControllers__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<uv_msgs::msg::LedControllers *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _LedControllers__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const uv_msgs::msg::LedControllers *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _LedControllers__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_LedControllers(full_bounded, 0);
}

static message_type_support_callbacks_t _LedControllers__callbacks = {
  "uv_msgs::msg",
  "LedControllers",
  _LedControllers__cdr_serialize,
  _LedControllers__cdr_deserialize,
  _LedControllers__get_serialized_size,
  _LedControllers__max_serialized_size
};

static rosidl_message_type_support_t _LedControllers__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_LedControllers__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace uv_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_uv_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<uv_msgs::msg::LedControllers>()
{
  return &uv_msgs::msg::typesupport_fastrtps_cpp::_LedControllers__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, uv_msgs, msg, LedControllers)() {
  return &uv_msgs::msg::typesupport_fastrtps_cpp::_LedControllers__handle;
}

#ifdef __cplusplus
}
#endif
