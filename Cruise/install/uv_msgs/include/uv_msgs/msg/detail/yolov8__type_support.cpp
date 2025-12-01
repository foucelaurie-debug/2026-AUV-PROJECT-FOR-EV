// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from uv_msgs:msg/Yolov8.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "uv_msgs/msg/detail/yolov8__struct.hpp"
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

void Yolov8_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) uv_msgs::msg::Yolov8(_init);
}

void Yolov8_fini_function(void * message_memory)
{
  auto typed_message = static_cast<uv_msgs::msg::Yolov8 *>(message_memory);
  typed_message->~Yolov8();
}

size_t size_function__Yolov8__state(const void * untyped_member)
{
  (void)untyped_member;
  return 11;
}

const void * get_const_function__Yolov8__state(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 11> *>(untyped_member);
  return &member[index];
}

void * get_function__Yolov8__state(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 11> *>(untyped_member);
  return &member[index];
}

size_t size_function__Yolov8__targets(const void * untyped_member)
{
  (void)untyped_member;
  return 11;
}

const void * get_const_function__Yolov8__targets(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<uv_msgs::msg::TargetParams, 11> *>(untyped_member);
  return &member[index];
}

void * get_function__Yolov8__targets(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<uv_msgs::msg::TargetParams, 11> *>(untyped_member);
  return &member[index];
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Yolov8_message_member_array[2] = {
  {
    "state",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    11,  // array size
    false,  // is upper bound
    offsetof(uv_msgs::msg::Yolov8, state),  // bytes offset in struct
    nullptr,  // default value
    size_function__Yolov8__state,  // size() function pointer
    get_const_function__Yolov8__state,  // get_const(index) function pointer
    get_function__Yolov8__state,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "targets",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<uv_msgs::msg::TargetParams>(),  // members of sub message
    true,  // is array
    11,  // array size
    false,  // is upper bound
    offsetof(uv_msgs::msg::Yolov8, targets),  // bytes offset in struct
    nullptr,  // default value
    size_function__Yolov8__targets,  // size() function pointer
    get_const_function__Yolov8__targets,  // get_const(index) function pointer
    get_function__Yolov8__targets,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Yolov8_message_members = {
  "uv_msgs::msg",  // message namespace
  "Yolov8",  // message name
  2,  // number of fields
  sizeof(uv_msgs::msg::Yolov8),
  Yolov8_message_member_array,  // message members
  Yolov8_init_function,  // function to initialize message memory (memory has to be allocated)
  Yolov8_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Yolov8_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Yolov8_message_members,
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
get_message_type_support_handle<uv_msgs::msg::Yolov8>()
{
  return &::uv_msgs::msg::rosidl_typesupport_introspection_cpp::Yolov8_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, uv_msgs, msg, Yolov8)() {
  return &::uv_msgs::msg::rosidl_typesupport_introspection_cpp::Yolov8_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
