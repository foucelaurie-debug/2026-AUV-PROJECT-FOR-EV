// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from uv_msgs:msg/PidParams.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__PID_PARAMS__TRAITS_HPP_
#define UV_MSGS__MSG__DETAIL__PID_PARAMS__TRAITS_HPP_

#include "uv_msgs/msg/detail/pid_params__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<uv_msgs::msg::PidParams>()
{
  return "uv_msgs::msg::PidParams";
}

template<>
inline const char * name<uv_msgs::msg::PidParams>()
{
  return "uv_msgs/msg/PidParams";
}

template<>
struct has_fixed_size<uv_msgs::msg::PidParams>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<uv_msgs::msg::PidParams>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<uv_msgs::msg::PidParams>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UV_MSGS__MSG__DETAIL__PID_PARAMS__TRAITS_HPP_
