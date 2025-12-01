// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from uv_msgs:msg/ServoSet.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__SERVO_SET__BUILDER_HPP_
#define UV_MSGS__MSG__DETAIL__SERVO_SET__BUILDER_HPP_

#include "uv_msgs/msg/detail/servo_set__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace uv_msgs
{

namespace msg
{

namespace builder
{

class Init_ServoSet_angle
{
public:
  explicit Init_ServoSet_angle(::uv_msgs::msg::ServoSet & msg)
  : msg_(msg)
  {}
  ::uv_msgs::msg::ServoSet angle(::uv_msgs::msg::ServoSet::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uv_msgs::msg::ServoSet msg_;
};

class Init_ServoSet_num
{
public:
  Init_ServoSet_num()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ServoSet_angle num(::uv_msgs::msg::ServoSet::_num_type arg)
  {
    msg_.num = std::move(arg);
    return Init_ServoSet_angle(msg_);
  }

private:
  ::uv_msgs::msg::ServoSet msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::uv_msgs::msg::ServoSet>()
{
  return uv_msgs::msg::builder::Init_ServoSet_num();
}

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__SERVO_SET__BUILDER_HPP_
