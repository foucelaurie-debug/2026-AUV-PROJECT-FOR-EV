// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from uv_msgs:msg/PidControllers.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__PID_CONTROLLERS__TRAITS_HPP_
#define UV_MSGS__MSG__DETAIL__PID_CONTROLLERS__TRAITS_HPP_

#include "uv_msgs/msg/detail/pid_controllers__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'x'
// Member 'y'
// Member 'z'
// Member 'rx'
// Member 'ry'
// Member 'rz'
// Member 'vx'
// Member 'vy'
#include "uv_msgs/msg/detail/pid_params__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<uv_msgs::msg::PidControllers>()
{
  return "uv_msgs::msg::PidControllers";
}

template<>
inline const char * name<uv_msgs::msg::PidControllers>()
{
  return "uv_msgs/msg/PidControllers";
}

template<>
struct has_fixed_size<uv_msgs::msg::PidControllers>
  : std::integral_constant<bool, has_fixed_size<uv_msgs::msg::PidParams>::value> {};

template<>
struct has_bounded_size<uv_msgs::msg::PidControllers>
  : std::integral_constant<bool, has_bounded_size<uv_msgs::msg::PidParams>::value> {};

template<>
struct is_message<uv_msgs::msg::PidControllers>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UV_MSGS__MSG__DETAIL__PID_CONTROLLERS__TRAITS_HPP_
