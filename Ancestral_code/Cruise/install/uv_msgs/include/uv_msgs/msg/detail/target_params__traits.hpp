// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from uv_msgs:msg/TargetParams.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__TARGET_PARAMS__TRAITS_HPP_
#define UV_MSGS__MSG__DETAIL__TARGET_PARAMS__TRAITS_HPP_

#include "uv_msgs/msg/detail/target_params__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'tpos_inpic'
#include "uv_msgs/msg/detail/pixel_axis__traits.hpp"
// Member 'tpos_inworld'
#include "uv_msgs/msg/detail/target_axis__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<uv_msgs::msg::TargetParams>()
{
  return "uv_msgs::msg::TargetParams";
}

template<>
inline const char * name<uv_msgs::msg::TargetParams>()
{
  return "uv_msgs/msg/TargetParams";
}

template<>
struct has_fixed_size<uv_msgs::msg::TargetParams>
  : std::integral_constant<bool, has_fixed_size<uv_msgs::msg::PixelAxis>::value && has_fixed_size<uv_msgs::msg::TargetAxis>::value> {};

template<>
struct has_bounded_size<uv_msgs::msg::TargetParams>
  : std::integral_constant<bool, has_bounded_size<uv_msgs::msg::PixelAxis>::value && has_bounded_size<uv_msgs::msg::TargetAxis>::value> {};

template<>
struct is_message<uv_msgs::msg::TargetParams>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UV_MSGS__MSG__DETAIL__TARGET_PARAMS__TRAITS_HPP_
