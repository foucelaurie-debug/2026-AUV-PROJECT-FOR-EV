// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from uv_msgs:msg/RobotDeviceManager.idl
// generated code does not contain a copyright notice
#include "uv_msgs/msg/detail/robot_device_manager__rosidl_typesupport_fastrtps_cpp.hpp"
#include "uv_msgs/msg/detail/robot_device_manager__struct.hpp"

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
  const uv_msgs::msg::RobotDeviceManager & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: leak
  cdr << ros_message.leak;
  // Member: tem
  cdr << ros_message.tem;
  // Member: hum
  cdr << ros_message.hum;
  // Member: vol
  cdr << ros_message.vol;
  // Member: magnet
  cdr << ros_message.magnet;
  // Member: led
  {
    cdr << ros_message.led;
  }
  // Member: angle
  {
    cdr << ros_message.angle;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_uv_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  uv_msgs::msg::RobotDeviceManager & ros_message)
{
  // Member: leak
  cdr >> ros_message.leak;

  // Member: tem
  cdr >> ros_message.tem;

  // Member: hum
  cdr >> ros_message.hum;

  // Member: vol
  cdr >> ros_message.vol;

  // Member: magnet
  cdr >> ros_message.magnet;

  // Member: led
  {
    cdr >> ros_message.led;
  }

  // Member: angle
  {
    cdr >> ros_message.angle;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_uv_msgs
get_serialized_size(
  const uv_msgs::msg::RobotDeviceManager & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: leak
  {
    size_t item_size = sizeof(ros_message.leak);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: tem
  {
    size_t item_size = sizeof(ros_message.tem);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: hum
  {
    size_t item_size = sizeof(ros_message.hum);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: vol
  {
    size_t item_size = sizeof(ros_message.vol);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: magnet
  {
    size_t item_size = sizeof(ros_message.magnet);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: led
  {
    size_t array_size = 2;
    size_t item_size = sizeof(ros_message.led[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: angle
  {
    size_t array_size = 2;
    size_t item_size = sizeof(ros_message.angle[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_uv_msgs
max_serialized_size_RobotDeviceManager(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: leak
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: tem
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: hum
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: vol
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: magnet
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: led
  {
    size_t array_size = 2;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: angle
  {
    size_t array_size = 2;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _RobotDeviceManager__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const uv_msgs::msg::RobotDeviceManager *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _RobotDeviceManager__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<uv_msgs::msg::RobotDeviceManager *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _RobotDeviceManager__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const uv_msgs::msg::RobotDeviceManager *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _RobotDeviceManager__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_RobotDeviceManager(full_bounded, 0);
}

static message_type_support_callbacks_t _RobotDeviceManager__callbacks = {
  "uv_msgs::msg",
  "RobotDeviceManager",
  _RobotDeviceManager__cdr_serialize,
  _RobotDeviceManager__cdr_deserialize,
  _RobotDeviceManager__get_serialized_size,
  _RobotDeviceManager__max_serialized_size
};

static rosidl_message_type_support_t _RobotDeviceManager__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RobotDeviceManager__callbacks,
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
get_message_type_support_handle<uv_msgs::msg::RobotDeviceManager>()
{
  return &uv_msgs::msg::typesupport_fastrtps_cpp::_RobotDeviceManager__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, uv_msgs, msg, RobotDeviceManager)() {
  return &uv_msgs::msg::typesupport_fastrtps_cpp::_RobotDeviceManager__handle;
}

#ifdef __cplusplus
}
#endif
