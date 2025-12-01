// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from uv_msgs:msg/ServoSet.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__SERVO_SET__TRAITS_HPP_
#define UV_MSGS__MSG__DETAIL__SERVO_SET__TRAITS_HPP_

#include "uv_msgs/msg/detail/servo_set__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<uv_msgs::msg::ServoSet>()
{
  return "uv_msgs::msg::ServoSet";
}

template<>
inline const char * name<uv_msgs::msg::ServoSet>()
{
  return "uv_msgs/msg/ServoSet";
}

template<>
struct has_fixed_size<uv_msgs::msg::ServoSet>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<uv_msgs::msg::ServoSet>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<uv_msgs::msg::ServoSet>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UV_MSGS__MSG__DETAIL__SERVO_SET__TRAITS_HPP_
