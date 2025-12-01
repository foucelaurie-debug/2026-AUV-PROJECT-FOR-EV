// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from uv_msgs:msg/PropellerThrust.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__PROPELLER_THRUST__TRAITS_HPP_
#define UV_MSGS__MSG__DETAIL__PROPELLER_THRUST__TRAITS_HPP_

#include "uv_msgs/msg/detail/propeller_thrust__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<uv_msgs::msg::PropellerThrust>()
{
  return "uv_msgs::msg::PropellerThrust";
}

template<>
inline const char * name<uv_msgs::msg::PropellerThrust>()
{
  return "uv_msgs/msg/PropellerThrust";
}

template<>
struct has_fixed_size<uv_msgs::msg::PropellerThrust>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<uv_msgs::msg::PropellerThrust>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<uv_msgs::msg::PropellerThrust>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UV_MSGS__MSG__DETAIL__PROPELLER_THRUST__TRAITS_HPP_
