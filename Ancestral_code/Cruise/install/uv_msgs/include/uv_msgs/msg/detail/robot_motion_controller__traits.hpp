// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from uv_msgs:msg/RobotMotionController.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__ROBOT_MOTION_CONTROLLER__TRAITS_HPP_
#define UV_MSGS__MSG__DETAIL__ROBOT_MOTION_CONTROLLER__TRAITS_HPP_

#include "uv_msgs/msg/detail/robot_motion_controller__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'pos'
// Member 'tpos_inbase'
// Member 'tpos_inworld'
#include "uv_msgs/msg/detail/robot_axis__traits.hpp"
// Member 'imu'
#include "uv_msgs/msg/detail/imu_data__traits.hpp"
// Member 'thrust'
#include "uv_msgs/msg/detail/motor_thrust__traits.hpp"
// Member 'pidstate'
#include "uv_msgs/msg/detail/pid_controllers_state__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<uv_msgs::msg::RobotMotionController>()
{
  return "uv_msgs::msg::RobotMotionController";
}

template<>
inline const char * name<uv_msgs::msg::RobotMotionController>()
{
  return "uv_msgs/msg/RobotMotionController";
}

template<>
struct has_fixed_size<uv_msgs::msg::RobotMotionController>
  : std::integral_constant<bool, has_fixed_size<uv_msgs::msg::ImuData>::value && has_fixed_size<uv_msgs::msg::MotorThrust>::value && has_fixed_size<uv_msgs::msg::PidControllersState>::value && has_fixed_size<uv_msgs::msg::RobotAxis>::value> {};

template<>
struct has_bounded_size<uv_msgs::msg::RobotMotionController>
  : std::integral_constant<bool, has_bounded_size<uv_msgs::msg::ImuData>::value && has_bounded_size<uv_msgs::msg::MotorThrust>::value && has_bounded_size<uv_msgs::msg::PidControllersState>::value && has_bounded_size<uv_msgs::msg::RobotAxis>::value> {};

template<>
struct is_message<uv_msgs::msg::RobotMotionController>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // UV_MSGS__MSG__DETAIL__ROBOT_MOTION_CONTROLLER__TRAITS_HPP_
