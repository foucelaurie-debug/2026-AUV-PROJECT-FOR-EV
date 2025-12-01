// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from uv_msgs:msg/RobotDeviceManager.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "uv_msgs/msg/detail/robot_device_manager__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace uv_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void RobotDeviceManager_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) uv_msgs::msg::RobotDeviceManager(_init);
}

void RobotDeviceManager_fini_function(void * message_memory)
{
  auto typed_message = static_cast<uv_msgs::msg::RobotDeviceManager *>(message_memory);
  typed_message->~RobotDeviceManager();
}

size_t size_function__RobotDeviceManager__led(const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * get_const_function__RobotDeviceManager__led(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<uint8_t, 2> *>(untyped_member);
  return &member[index];
}

void * get_function__RobotDeviceManager__led(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<uint8_t, 2> *>(untyped_member);
  return &member[index];
}

size_t size_function__RobotDeviceManager__angle(const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * get_const_function__RobotDeviceManager__angle(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 2> *>(untyped_member);
  return &member[index];
}

void * get_function__RobotDeviceManager__angle(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 2> *>(untyped_member);
  return &member[index];
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember RobotDeviceManager_message_member_array[7] = {
  {
    "leak",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uv_msgs::msg::RobotDeviceManager, leak),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "tem",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uv_msgs::msg::RobotDeviceManager, tem),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "hum",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uv_msgs::msg::RobotDeviceManager, hum),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "vol",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uv_msgs::msg::RobotDeviceManager, vol),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "magnet",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uv_msgs::msg::RobotDeviceManager, magnet),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "led",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(uv_msgs::msg::RobotDeviceManager, led),  // bytes offset in struct
    nullptr,  // default value
    size_function__RobotDeviceManager__led,  // size() function pointer
    get_const_function__RobotDeviceManager__led,  // get_const(index) function pointer
    get_function__RobotDeviceManager__led,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "angle",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(uv_msgs::msg::RobotDeviceManager, angle),  // bytes offset in struct
    nullptr,  // default value
    size_function__RobotDeviceManager__angle,  // size() function pointer
    get_const_function__RobotDeviceManager__angle,  // get_const(index) function pointer
    get_function__RobotDeviceManager__angle,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers RobotDeviceManager_message_members = {
  "uv_msgs::msg",  // message namespace
  "RobotDeviceManager",  // message name
  7,  // number of fields
  sizeof(uv_msgs::msg::RobotDeviceManager),
  RobotDeviceManager_message_member_array,  // message members
  RobotDeviceManager_init_function,  // function to initialize message memory (memory has to be allocated)
  RobotDeviceManager_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t RobotDeviceManager_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RobotDeviceManager_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace uv_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<uv_msgs::msg::RobotDeviceManager>()
{
  return &::uv_msgs::msg::rosidl_typesupport_introspection_cpp::RobotDeviceManager_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, uv_msgs, msg, RobotDeviceManager)() {
  return &::uv_msgs::msg::rosidl_typesupport_introspection_cpp::RobotDeviceManager_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
