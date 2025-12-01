// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from uv_msgs:msg/PropellerThrust.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "uv_msgs/msg/detail/propeller_thrust__struct.hpp"
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

void PropellerThrust_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) uv_msgs::msg::PropellerThrust(_init);
}

void PropellerThrust_fini_function(void * message_memory)
{
  auto typed_message = static_cast<uv_msgs::msg::PropellerThrust *>(message_memory);
  typed_message->~PropellerThrust();
}

size_t size_function__PropellerThrust__thrust(const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * get_const_function__PropellerThrust__thrust(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 6> *>(untyped_member);
  return &member[index];
}

void * get_function__PropellerThrust__thrust(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 6> *>(untyped_member);
  return &member[index];
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember PropellerThrust_message_member_array[1] = {
  {
    "thrust",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(uv_msgs::msg::PropellerThrust, thrust),  // bytes offset in struct
    nullptr,  // default value
    size_function__PropellerThrust__thrust,  // size() function pointer
    get_const_function__PropellerThrust__thrust,  // get_const(index) function pointer
    get_function__PropellerThrust__thrust,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers PropellerThrust_message_members = {
  "uv_msgs::msg",  // message namespace
  "PropellerThrust",  // message name
  1,  // number of fields
  sizeof(uv_msgs::msg::PropellerThrust),
  PropellerThrust_message_member_array,  // message members
  PropellerThrust_init_function,  // function to initialize message memory (memory has to be allocated)
  PropellerThrust_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t PropellerThrust_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PropellerThrust_message_members,
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
get_message_type_support_handle<uv_msgs::msg::PropellerThrust>()
{
  return &::uv_msgs::msg::rosidl_typesupport_introspection_cpp::PropellerThrust_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, uv_msgs, msg, PropellerThrust)() {
  return &::uv_msgs::msg::rosidl_typesupport_introspection_cpp::PropellerThrust_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
