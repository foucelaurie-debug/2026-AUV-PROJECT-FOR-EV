// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from uv_msgs:msg/PixelAxis.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__PIXEL_AXIS__BUILDER_HPP_
#define UV_MSGS__MSG__DETAIL__PIXEL_AXIS__BUILDER_HPP_

#include "uv_msgs/msg/detail/pixel_axis__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace uv_msgs
{

namespace msg
{

namespace builder
{

class Init_PixelAxis_y
{
public:
  explicit Init_PixelAxis_y(::uv_msgs::msg::PixelAxis & msg)
  : msg_(msg)
  {}
  ::uv_msgs::msg::PixelAxis y(::uv_msgs::msg::PixelAxis::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uv_msgs::msg::PixelAxis msg_;
};

class Init_PixelAxis_x
{
public:
  Init_PixelAxis_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PixelAxis_y x(::uv_msgs::msg::PixelAxis::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_PixelAxis_y(msg_);
  }

private:
  ::uv_msgs::msg::PixelAxis msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::uv_msgs::msg::PixelAxis>()
{
  return uv_msgs::msg::builder::Init_PixelAxis_x();
}

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__PIXEL_AXIS__BUILDER_HPP_
