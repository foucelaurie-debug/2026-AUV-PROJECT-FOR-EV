// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from uv_msgs:msg/TargetParams.idl
// generated code does not contain a copyright notice
#include "uv_msgs/msg/detail/target_params__rosidl_typesupport_fastrtps_cpp.hpp"
#include "uv_msgs/msg/detail/target_params__struct.hpp"

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
bool cdr_serialize(
  const uv_msgs::msg::PixelAxis &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  uv_msgs::msg::PixelAxis &);
size_t get_serialized_size(
  const uv_msgs::msg::PixelAxis &,
  size_t current_alignment);
size_t
max_serialized_size_PixelAxis(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace uv_msgs

namespace uv_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const uv_msgs::msg::TargetAxis &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  uv_msgs::msg::TargetAxis &);
size_t get_serialized_size(
  const uv_msgs::msg::TargetAxis &,
  size_t current_alignment);
size_t
max_serialized_size_TargetAxis(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace uv_msgs


namespace uv_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_uv_msgs
cdr_serialize(
  const uv_msgs::msg::TargetParams & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: tpos_inpic
  uv_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.tpos_inpic,
    cdr);
  // Member: tpos_inworld
  uv_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.tpos_inworld,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_uv_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  uv_msgs::msg::TargetParams & ros_message)
{
  // Member: tpos_inpic
  uv_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.tpos_inpic);

  // Member: tpos_inworld
  uv_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.tpos_inworld);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_uv_msgs
get_serialized_size(
  const uv_msgs::msg::TargetParams & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: tpos_inpic

  current_alignment +=
    uv_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.tpos_inpic, current_alignment);
  // Member: tpos_inworld

  current_alignment +=
    uv_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.tpos_inworld, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_uv_msgs
max_serialized_size_TargetParams(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: tpos_inpic
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        uv_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_PixelAxis(
        full_bounded, current_alignment);
    }
  }

  // Member: tpos_inworld
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        uv_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_TargetAxis(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static bool _TargetParams__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const uv_msgs::msg::TargetParams *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _TargetParams__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<uv_msgs::msg::TargetParams *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _TargetParams__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const uv_msgs::msg::TargetParams *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _TargetParams__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_TargetParams(full_bounded, 0);
}

static message_type_support_callbacks_t _TargetParams__callbacks = {
  "uv_msgs::msg",
  "TargetParams",
  _TargetParams__cdr_serialize,
  _TargetParams__cdr_deserialize,
  _TargetParams__get_serialized_size,
  _TargetParams__max_serialized_size
};

static rosidl_message_type_support_t _TargetParams__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_TargetParams__callbacks,
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
get_message_type_support_handle<uv_msgs::msg::TargetParams>()
{
  return &uv_msgs::msg::typesupport_fastrtps_cpp::_TargetParams__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, uv_msgs, msg, TargetParams)() {
  return &uv_msgs::msg::typesupport_fastrtps_cpp::_TargetParams__handle;
}

#ifdef __cplusplus
}
#endif
