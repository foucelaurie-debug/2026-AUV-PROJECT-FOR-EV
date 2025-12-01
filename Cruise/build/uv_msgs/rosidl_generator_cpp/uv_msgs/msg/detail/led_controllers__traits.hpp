// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from uv_msgs:msg/LedControllers.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__LED_CONTROLLERS__TRAITS_HPP_
#define UV_MSGS__MSG__DETAIL__LED_CONTROLLERS__TRAITS_HPP_

#include "uv_msgs/msg/detail/led_controllers__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<uv_msgs::msg::LedControllers>()
{
  return "uv_msgs::msg::LedControllers";
}

template<>
inline const char * name<uv_msgs::msg::LedControllers>()
{
  return "uv_msgs/msg/LedControllers";
}

template<>
struct has_fixed_size<uv_msgs::msg::LedControllers>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<uv_msgs::msg::LedControllers>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<uv_msgs::msg::LedControllers>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UV_MSGS__MSG__DETAIL__LED_CONTROLLERS__TRAITS_HPP_
