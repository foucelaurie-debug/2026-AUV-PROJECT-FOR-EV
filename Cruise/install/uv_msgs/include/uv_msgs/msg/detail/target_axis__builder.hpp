// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from uv_msgs:msg/TargetAxis.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__TARGET_AXIS__BUILDER_HPP_
#define UV_MSGS__MSG__DETAIL__TARGET_AXIS__BUILDER_HPP_

#include "uv_msgs/msg/detail/target_axis__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace uv_msgs
{

namespace msg
{

namespace builder
{

class Init_TargetAxis_z
{
public:
  explicit Init_TargetAxis_z(::uv_msgs::msg::TargetAxis & msg)
  : msg_(msg)
  {}
  ::uv_msgs::msg::TargetAxis z(::uv_msgs::msg::TargetAxis::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uv_msgs::msg::TargetAxis msg_;
};

class Init_TargetAxis_y
{
public:
  explicit Init_TargetAxis_y(::uv_msgs::msg::TargetAxis & msg)
  : msg_(msg)
  {}
  Init_TargetAxis_z y(::uv_msgs::msg::TargetAxis::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_TargetAxis_z(msg_);
  }

private:
  ::uv_msgs::msg::TargetAxis msg_;
};

class Init_TargetAxis_x
{
public:
  Init_TargetAxis_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TargetAxis_y x(::uv_msgs::msg::TargetAxis::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_TargetAxis_y(msg_);
  }

private:
  ::uv_msgs::msg::TargetAxis msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::uv_msgs::msg::TargetAxis>()
{
  return uv_msgs::msg::builder::Init_TargetAxis_x();
}

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__TARGET_AXIS__BUILDER_HPP_
