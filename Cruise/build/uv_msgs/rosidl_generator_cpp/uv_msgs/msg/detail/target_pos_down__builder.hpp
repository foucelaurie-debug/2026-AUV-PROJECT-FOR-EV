// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from uv_msgs:msg/TargetPosDown.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__TARGET_POS_DOWN__BUILDER_HPP_
#define UV_MSGS__MSG__DETAIL__TARGET_POS_DOWN__BUILDER_HPP_

#include "uv_msgs/msg/detail/target_pos_down__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace uv_msgs
{

namespace msg
{

namespace builder
{

class Init_TargetPosDown_pos
{
public:
  explicit Init_TargetPosDown_pos(::uv_msgs::msg::TargetPosDown & msg)
  : msg_(msg)
  {}
  ::uv_msgs::msg::TargetPosDown pos(::uv_msgs::msg::TargetPosDown::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uv_msgs::msg::TargetPosDown msg_;
};

class Init_TargetPosDown_cs
{
public:
  Init_TargetPosDown_cs()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TargetPosDown_pos cs(::uv_msgs::msg::TargetPosDown::_cs_type arg)
  {
    msg_.cs = std::move(arg);
    return Init_TargetPosDown_pos(msg_);
  }

private:
  ::uv_msgs::msg::TargetPosDown msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::uv_msgs::msg::TargetPosDown>()
{
  return uv_msgs::msg::builder::Init_TargetPosDown_cs();
}

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__TARGET_POS_DOWN__BUILDER_HPP_
