// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from uv_msgs:msg/ThrustCurves.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__THRUST_CURVES__TRAITS_HPP_
#define UV_MSGS__MSG__DETAIL__THRUST_CURVES__TRAITS_HPP_

#include "uv_msgs/msg/detail/thrust_curves__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'm0'
// Member 'm1'
// Member 'm2'
// Member 'm3'
// Member 'm4'
// Member 'm5'
#include "uv_msgs/msg/detail/thrust_curve__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<uv_msgs::msg::ThrustCurves>()
{
  return "uv_msgs::msg::ThrustCurves";
}

template<>
inline const char * name<uv_msgs::msg::ThrustCurves>()
{
  return "uv_msgs/msg/ThrustCurves";
}

template<>
struct has_fixed_size<uv_msgs::msg::ThrustCurves>
  : std::integral_constant<bool, has_fixed_size<uv_msgs::msg::ThrustCurve>::value> {};

template<>
struct has_bounded_size<uv_msgs::msg::ThrustCurves>
  : std::integral_constant<bool, has_bounded_size<uv_msgs::msg::ThrustCurve>::value> {};

template<>
struct is_message<uv_msgs::msg::ThrustCurves>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UV_MSGS__MSG__DETAIL__THRUST_CURVES__TRAITS_HPP_
