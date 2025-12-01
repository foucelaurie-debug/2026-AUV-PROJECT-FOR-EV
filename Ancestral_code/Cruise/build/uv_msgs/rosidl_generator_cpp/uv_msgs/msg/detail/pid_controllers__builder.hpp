// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from uv_msgs:msg/PidControllers.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__PID_CONTROLLERS__BUILDER_HPP_
#define UV_MSGS__MSG__DETAIL__PID_CONTROLLERS__BUILDER_HPP_

#include "uv_msgs/msg/detail/pid_controllers__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace uv_msgs
{

namespace msg
{

namespace builder
{

class Init_PidControllers_vy
{
public:
  explicit Init_PidControllers_vy(::uv_msgs::msg::PidControllers & msg)
  : msg_(msg)
  {}
  ::uv_msgs::msg::PidControllers vy(::uv_msgs::msg::PidControllers::_vy_type arg)
  {
    msg_.vy = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uv_msgs::msg::PidControllers msg_;
};

class Init_PidControllers_vx
{
public:
  explicit Init_PidControllers_vx(::uv_msgs::msg::PidControllers & msg)
  : msg_(msg)
  {}
  Init_PidControllers_vy vx(::uv_msgs::msg::PidControllers::_vx_type arg)
  {
    msg_.vx = std::move(arg);
    return Init_PidControllers_vy(msg_);
  }

private:
  ::uv_msgs::msg::PidControllers msg_;
};

class Init_PidControllers_rz
{
public:
  explicit Init_PidControllers_rz(::uv_msgs::msg::PidControllers & msg)
  : msg_(msg)
  {}
  Init_PidControllers_vx rz(::uv_msgs::msg::PidControllers::_rz_type arg)
  {
    msg_.rz = std::move(arg);
    return Init_PidControllers_vx(msg_);
  }

private:
  ::uv_msgs::msg::PidControllers msg_;
};

class Init_PidControllers_ry
{
public:
  explicit Init_PidControllers_ry(::uv_msgs::msg::PidControllers & msg)
  : msg_(msg)
  {}
  Init_PidControllers_rz ry(::uv_msgs::msg::PidControllers::_ry_type arg)
  {
    msg_.ry = std::move(arg);
    return Init_PidControllers_rz(msg_);
  }

private:
  ::uv_msgs::msg::PidControllers msg_;
};

class Init_PidControllers_rx
{
public:
  explicit Init_PidControllers_rx(::uv_msgs::msg::PidControllers & msg)
  : msg_(msg)
  {}
  Init_PidControllers_ry rx(::uv_msgs::msg::PidControllers::_rx_type arg)
  {
    msg_.rx = std::move(arg);
    return Init_PidControllers_ry(msg_);
  }

private:
  ::uv_msgs::msg::PidControllers msg_;
};

class Init_PidControllers_z
{
public:
  explicit Init_PidControllers_z(::uv_msgs::msg::PidControllers & msg)
  : msg_(msg)
  {}
  Init_PidControllers_rx z(::uv_msgs::msg::PidControllers::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_PidControllers_rx(msg_);
  }

private:
  ::uv_msgs::msg::PidControllers msg_;
};

class Init_PidControllers_y
{
public:
  explicit Init_PidControllers_y(::uv_msgs::msg::PidControllers & msg)
  : msg_(msg)
  {}
  Init_PidControllers_z y(::uv_msgs::msg::PidControllers::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_PidControllers_z(msg_);
  }

private:
  ::uv_msgs::msg::PidControllers msg_;
};

class Init_PidControllers_x
{
public:
  Init_PidControllers_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PidControllers_y x(::uv_msgs::msg::PidControllers::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_PidControllers_y(msg_);
  }

private:
  ::uv_msgs::msg::PidControllers msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::uv_msgs::msg::PidControllers>()
{
  return uv_msgs::msg::builder::Init_PidControllers_x();
}

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__PID_CONTROLLERS__BUILDER_HPP_
