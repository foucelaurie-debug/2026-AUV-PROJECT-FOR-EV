// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from uv_msgs:msg/WorkState.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__WORK_STATE__BUILDER_HPP_
#define UV_MSGS__MSG__DETAIL__WORK_STATE__BUILDER_HPP_

#include "uv_msgs/msg/detail/work_state__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace uv_msgs
{

namespace msg
{

namespace builder
{

class Init_WorkState_state
{
public:
  Init_WorkState_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::uv_msgs::msg::WorkState state(::uv_msgs::msg::WorkState::_state_type arg)
  {
    msg_.state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uv_msgs::msg::WorkState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::uv_msgs::msg::WorkState>()
{
  return uv_msgs::msg::builder::Init_WorkState_state();
}

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__WORK_STATE__BUILDER_HPP_
