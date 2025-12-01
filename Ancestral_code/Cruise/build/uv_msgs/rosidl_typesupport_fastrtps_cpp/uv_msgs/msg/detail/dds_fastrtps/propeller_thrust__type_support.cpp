// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from uv_msgs:msg/PropellerThrust.idl
// generated code does not contain a copyright notice
#include "uv_msgs/msg/detail/propeller_thrust__rosidl_typesupport_fastrtps_cpp.hpp"
#include "uv_msgs/msg/detail/propeller_thrust__struct.hpp"

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
  const uv_msgs::msg::PropellerThrust & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: thrust
  {
    cdr << ros_message.thrust;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_uv_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  uv_msgs::msg::PropellerThrust & ros_message)
{
  // Member: thrust
  {
    cdr >> ros_message.thrust;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_uv_msgs
get_serialized_size(
  const uv_msgs::msg::PropellerThrust & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: thrust
  {
    size_t array_size = 6;
    size_t item_size = sizeof(ros_message.thrust[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_uv_msgs
max_serialized_size_PropellerThrust(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: thrust
  {
    size_t array_size = 6;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _PropellerThrust__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const uv_msgs::msg::PropellerThrust *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _PropellerThrust__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<uv_msgs::msg::PropellerThrust *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _PropellerThrust__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const uv_msgs::msg::PropellerThrust *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _PropellerThrust__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_PropellerThrust(full_bounded, 0);
}

static message_type_support_callbacks_t _PropellerThrust__callbacks = {
  "uv_msgs::msg",
  "PropellerThrust",
  _PropellerThrust__cdr_serialize,
  _PropellerThrust__cdr_deserialize,
  _PropellerThrust__get_serialized_size,
  _PropellerThrust__max_serialized_size
};

static rosidl_message_type_support_t _PropellerThrust__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_PropellerThrust__callbacks,
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
get_message_type_support_handle<uv_msgs::msg::PropellerThrust>()
{
  return &uv_msgs::msg::typesupport_fastrtps_cpp::_PropellerThrust__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, uv_msgs, msg, PropellerThrust)() {
  return &uv_msgs::msg::typesupport_fastrtps_cpp::_PropellerThrust__handle;
}

#ifdef __cplusplus
}
#endif
