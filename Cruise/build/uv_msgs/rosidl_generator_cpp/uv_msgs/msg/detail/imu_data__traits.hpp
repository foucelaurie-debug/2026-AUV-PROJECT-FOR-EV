// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from uv_msgs:msg/ImuData.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__IMU_DATA__TRAITS_HPP_
#define UV_MSGS__MSG__DETAIL__IMU_DATA__TRAITS_HPP_

#include "uv_msgs/msg/detail/imu_data__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'pos'
// Member 'spd'
#include "uv_msgs/msg/detail/robot_axis__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<uv_msgs::msg::ImuData>()
{
  return "uv_msgs::msg::ImuData";
}

template<>
inline const char * name<uv_msgs::msg::ImuData>()
{
  return "uv_msgs/msg/ImuData";
}

template<>
struct has_fixed_size<uv_msgs::msg::ImuData>
  : std::integral_constant<bool, has_fixed_size<uv_msgs::msg::RobotAxis>::value> {};

template<>
struct has_bounded_size<uv_msgs::msg::ImuData>
  : std::integral_constant<bool, has_bounded_size<uv_msgs::msg::RobotAxis>::value> {};

template<>
struct is_message<uv_msgs::msg::ImuData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UV_MSGS__MSG__DETAIL__IMU_DATA__TRAITS_HPP_
