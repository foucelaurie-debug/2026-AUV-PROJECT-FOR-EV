// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from uv_msgs:msg/Yolov8.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__YOLOV8__BUILDER_HPP_
#define UV_MSGS__MSG__DETAIL__YOLOV8__BUILDER_HPP_

#include "uv_msgs/msg/detail/yolov8__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace uv_msgs
{

namespace msg
{

namespace builder
{

class Init_Yolov8_targets
{
public:
  explicit Init_Yolov8_targets(::uv_msgs::msg::Yolov8 & msg)
  : msg_(msg)
  {}
  ::uv_msgs::msg::Yolov8 targets(::uv_msgs::msg::Yolov8::_targets_type arg)
  {
    msg_.targets = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uv_msgs::msg::Yolov8 msg_;
};

class Init_Yolov8_state
{
public:
  Init_Yolov8_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Yolov8_targets state(::uv_msgs::msg::Yolov8::_state_type arg)
  {
    msg_.state = std::move(arg);
    return Init_Yolov8_targets(msg_);
  }

private:
  ::uv_msgs::msg::Yolov8 msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::uv_msgs::msg::Yolov8>()
{
  return uv_msgs::msg::builder::Init_Yolov8_state();
}

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__YOLOV8__BUILDER_HPP_
