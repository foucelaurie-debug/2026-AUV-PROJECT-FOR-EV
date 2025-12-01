// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from uv_msgs:msg/RobotAxis.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__ROBOT_AXIS__BUILDER_HPP_
#define UV_MSGS__MSG__DETAIL__ROBOT_AXIS__BUILDER_HPP_

#include "uv_msgs/msg/detail/robot_axis__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace uv_msgs
{

namespace msg
{

namespace builder
{

class Init_RobotAxis_rz
{
public:
  explicit Init_RobotAxis_rz(::uv_msgs::msg::RobotAxis & msg)
  : msg_(msg)
  {}
  ::uv_msgs::msg::RobotAxis rz(::uv_msgs::msg::RobotAxis::_rz_type arg)
  {
    msg_.rz = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uv_msgs::msg::RobotAxis msg_;
};

class Init_RobotAxis_ry
{
public:
  explicit Init_RobotAxis_ry(::uv_msgs::msg::RobotAxis & msg)
  : msg_(msg)
  {}
  Init_RobotAxis_rz ry(::uv_msgs::msg::RobotAxis::_ry_type arg)
  {
    msg_.ry = std::move(arg);
    return Init_RobotAxis_rz(msg_);
  }

private:
  ::uv_msgs::msg::RobotAxis msg_;
};

class Init_RobotAxis_rx
{
public:
  explicit Init_RobotAxis_rx(::uv_msgs::msg::RobotAxis & msg)
  : msg_(msg)
  {}
  Init_RobotAxis_ry rx(::uv_msgs::msg::RobotAxis::_rx_type arg)
  {
    msg_.rx = std::move(arg);
    return Init_RobotAxis_ry(msg_);
  }

private:
  ::uv_msgs::msg::RobotAxis msg_;
};

class Init_RobotAxis_z
{
public:
  explicit Init_RobotAxis_z(::uv_msgs::msg::RobotAxis & msg)
  : msg_(msg)
  {}
  Init_RobotAxis_rx z(::uv_msgs::msg::RobotAxis::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_RobotAxis_rx(msg_);
  }

private:
  ::uv_msgs::msg::RobotAxis msg_;
};

class Init_RobotAxis_y
{
public:
  explicit Init_RobotAxis_y(::uv_msgs::msg::RobotAxis & msg)
  : msg_(msg)
  {}
  Init_RobotAxis_z y(::uv_msgs::msg::RobotAxis::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_RobotAxis_z(msg_);
  }

private:
  ::uv_msgs::msg::RobotAxis msg_;
};

class Init_RobotAxis_x
{
public:
  Init_RobotAxis_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotAxis_y x(::uv_msgs::msg::RobotAxis::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_RobotAxis_y(msg_);
  }

private:
  ::uv_msgs::msg::RobotAxis msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::uv_msgs::msg::RobotAxis>()
{
  return uv_msgs::msg::builder::Init_RobotAxis_x();
}

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__ROBOT_AXIS__BUILDER_HPP_
