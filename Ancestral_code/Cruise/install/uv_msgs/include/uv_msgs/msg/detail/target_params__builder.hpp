// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from uv_msgs:msg/TargetParams.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__TARGET_PARAMS__BUILDER_HPP_
#define UV_MSGS__MSG__DETAIL__TARGET_PARAMS__BUILDER_HPP_

#include "uv_msgs/msg/detail/target_params__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace uv_msgs
{

namespace msg
{

namespace builder
{

class Init_TargetParams_tpos_inworld
{
public:
  explicit Init_TargetParams_tpos_inworld(::uv_msgs::msg::TargetParams & msg)
  : msg_(msg)
  {}
  ::uv_msgs::msg::TargetParams tpos_inworld(::uv_msgs::msg::TargetParams::_tpos_inworld_type arg)
  {
    msg_.tpos_inworld = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uv_msgs::msg::TargetParams msg_;
};

class Init_TargetParams_tpos_inpic
{
public:
  Init_TargetParams_tpos_inpic()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TargetParams_tpos_inworld tpos_inpic(::uv_msgs::msg::TargetParams::_tpos_inpic_type arg)
  {
    msg_.tpos_inpic = std::move(arg);
    return Init_TargetParams_tpos_inworld(msg_);
  }

private:
  ::uv_msgs::msg::TargetParams msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::uv_msgs::msg::TargetParams>()
{
  return uv_msgs::msg::builder::Init_TargetParams_tpos_inpic();
}

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__TARGET_PARAMS__BUILDER_HPP_
