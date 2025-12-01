// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from uv_msgs:msg/ThrustCurves.idl
// generated code does not contain a copyright notice
#include "uv_msgs/msg/detail/thrust_curves__rosidl_typesupport_fastrtps_cpp.hpp"
#include "uv_msgs/msg/detail/thrust_curves__struct.hpp"

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
  const uv_msgs::msg::ThrustCurve &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  uv_msgs::msg::ThrustCurve &);
size_t get_serialized_size(
  const uv_msgs::msg::ThrustCurve &,
  size_t current_alignment);
size_t
max_serialized_size_ThrustCurve(
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
  const uv_msgs::msg::ThrustCurve &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  uv_msgs::msg::ThrustCurve &);
size_t get_serialized_size(
  const uv_msgs::msg::ThrustCurve &,
  size_t current_alignment);
size_t
max_serialized_size_ThrustCurve(
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
  const uv_msgs::msg::ThrustCurve &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  uv_msgs::msg::ThrustCurve &);
size_t get_serialized_size(
  const uv_msgs::msg::ThrustCurve &,
  size_t current_alignment);
size_t
max_serialized_size_ThrustCurve(
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
  const uv_msgs::msg::ThrustCurve &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  uv_msgs::msg::ThrustCurve &);
size_t get_serialized_size(
  const uv_msgs::msg::ThrustCurve &,
  size_t current_alignment);
size_t
max_serialized_size_ThrustCurve(
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
  const uv_msgs::msg::ThrustCurve &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  uv_msgs::msg::ThrustCurve &);
size_t get_serialized_size(
  const uv_msgs::msg::ThrustCurve &,
  size_t current_alignment);
size_t
max_serialized_size_ThrustCurve(
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
  const uv_msgs::msg::ThrustCurve &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  uv_msgs::msg::ThrustCurve &);
size_t get_serialized_size(
  const uv_msgs::msg::ThrustCurve &,
  size_t current_alignment);
size_t
max_serialized_size_ThrustCurve(
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
  const uv_msgs::msg::ThrustCurves & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: m0
  uv_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.m0,
    cdr);
  // Member: m1
  uv_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.m1,
    cdr);
  // Member: m2
  uv_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.m2,
    cdr);
  // Member: m3
  uv_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.m3,
    cdr);
  // Member: m4
  uv_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.m4,
    cdr);
  // Member: m5
  uv_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.m5,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_uv_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  uv_msgs::msg::ThrustCurves & ros_message)
{
  // Member: m0
  uv_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.m0);

  // Member: m1
  uv_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.m1);

  // Member: m2
  uv_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.m2);

  // Member: m3
  uv_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.m3);

  // Member: m4
  uv_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.m4);

  // Member: m5
  uv_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.m5);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_uv_msgs
get_serialized_size(
  const uv_msgs::msg::ThrustCurves & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: m0

  current_alignment +=
    uv_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.m0, current_alignment);
  // Member: m1

  current_alignment +=
    uv_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.m1, current_alignment);
  // Member: m2

  current_alignment +=
    uv_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.m2, current_alignment);
  // Member: m3

  current_alignment +=
    uv_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.m3, current_alignment);
  // Member: m4

  current_alignment +=
    uv_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.m4, current_alignment);
  // Member: m5

  current_alignment +=
    uv_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.m5, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_uv_msgs
max_serialized_size_ThrustCurves(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: m0
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        uv_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_ThrustCurve(
        full_bounded, current_alignment);
    }
  }

  // Member: m1
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        uv_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_ThrustCurve(
        full_bounded, current_alignment);
    }
  }

  // Member: m2
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        uv_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_ThrustCurve(
        full_bounded, current_alignment);
    }
  }

  // Member: m3
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        uv_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_ThrustCurve(
        full_bounded, current_alignment);
    }
  }

  // Member: m4
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        uv_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_ThrustCurve(
        full_bounded, current_alignment);
    }
  }

  // Member: m5
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        uv_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_ThrustCurve(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static bool _ThrustCurves__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const uv_msgs::msg::ThrustCurves *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ThrustCurves__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<uv_msgs::msg::ThrustCurves *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ThrustCurves__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const uv_msgs::msg::ThrustCurves *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ThrustCurves__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_ThrustCurves(full_bounded, 0);
}

static message_type_support_callbacks_t _ThrustCurves__callbacks = {
  "uv_msgs::msg",
  "ThrustCurves",
  _ThrustCurves__cdr_serialize,
  _ThrustCurves__cdr_deserialize,
  _ThrustCurves__get_serialized_size,
  _ThrustCurves__max_serialized_size
};

static rosidl_message_type_support_t _ThrustCurves__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ThrustCurves__callbacks,
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
get_message_type_support_handle<uv_msgs::msg::ThrustCurves>()
{
  return &uv_msgs::msg::typesupport_fastrtps_cpp::_ThrustCurves__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, uv_msgs, msg, ThrustCurves)() {
  return &uv_msgs::msg::typesupport_fastrtps_cpp::_ThrustCurves__handle;
}

#ifdef __cplusplus
}
#endif
