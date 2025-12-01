// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from uv_msgs:msg/PidControllersState.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__PID_CONTROLLERS_STATE__BUILDER_HPP_
#define UV_MSGS__MSG__DETAIL__PID_CONTROLLERS_STATE__BUILDER_HPP_

#include "uv_msgs/msg/detail/pid_controllers_state__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace uv_msgs
{

namespace msg
{

namespace builder
{

class Init_PidControllersState_vx
{
public:
  explicit Init_PidControllersState_vx(::uv_msgs::msg::PidControllersState & msg)
  : msg_(msg)
  {}
  ::uv_msgs::msg::PidControllersState vx(::uv_msgs::msg::PidControllersState::_vx_type arg)
  {
    msg_.vx = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uv_msgs::msg::PidControllersState msg_;
};

class Init_PidControllersState_vy
{
public:
  explicit Init_PidControllersState_vy(::uv_msgs::msg::PidControllersState & msg)
  : msg_(msg)
  {}
  Init_PidControllersState_vx vy(::uv_msgs::msg::PidControllersState::_vy_type arg)
  {
    msg_.vy = std::move(arg);
    return Init_PidControllersState_vx(msg_);
  }

private:
  ::uv_msgs::msg::PidControllersState msg_;
};

class Init_PidControllersState_rz
{
public:
  explicit Init_PidControllersState_rz(::uv_msgs::msg::PidControllersState & msg)
  : msg_(msg)
  {}
  Init_PidControllersState_vy rz(::uv_msgs::msg::PidControllersState::_rz_type arg)
  {
    msg_.rz = std::move(arg);
    return Init_PidControllersState_vy(msg_);
  }

private:
  ::uv_msgs::msg::PidControllersState msg_;
};

class Init_PidControllersState_ry
{
public:
  explicit Init_PidControllersState_ry(::uv_msgs::msg::PidControllersState & msg)
  : msg_(msg)
  {}
  Init_PidControllersState_rz ry(::uv_msgs::msg::PidControllersState::_ry_type arg)
  {
    msg_.ry = std::move(arg);
    return Init_PidControllersState_rz(msg_);
  }

private:
  ::uv_msgs::msg::PidControllersState msg_;
};

class Init_PidControllersState_rx
{
public:
  explicit Init_PidControllersState_rx(::uv_msgs::msg::PidControllersState & msg)
  : msg_(msg)
  {}
  Init_PidControllersState_ry rx(::uv_msgs::msg::PidControllersState::_rx_type arg)
  {
    msg_.rx = std::move(arg);
    return Init_PidControllersState_ry(msg_);
  }

private:
  ::uv_msgs::msg::PidControllersState msg_;
};

class Init_PidControllersState_z
{
public:
  explicit Init_PidControllersState_z(::uv_msgs::msg::PidControllersState & msg)
  : msg_(msg)
  {}
  Init_PidControllersState_rx z(::uv_msgs::msg::PidControllersState::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_PidControllersState_rx(msg_);
  }

private:
  ::uv_msgs::msg::PidControllersState msg_;
};

class Init_PidControllersState_y
{
public:
  explicit Init_PidControllersState_y(::uv_msgs::msg::PidControllersState & msg)
  : msg_(msg)
  {}
  Init_PidControllersState_z y(::uv_msgs::msg::PidControllersState::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_PidControllersState_z(msg_);
  }

private:
  ::uv_msgs::msg::PidControllersState msg_;
};

class Init_PidControllersState_x
{
public:
  Init_PidControllersState_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PidControllersState_y x(::uv_msgs::msg::PidControllersState::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_PidControllersState_y(msg_);
  }

private:
  ::uv_msgs::msg::PidControllersState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::uv_msgs::msg::PidControllersState>()
{
  return uv_msgs::msg::builder::Init_PidControllersState_x();
}

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__PID_CONTROLLERS_STATE__BUILDER_HPP_
