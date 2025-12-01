// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from uv_msgs:msg/LedControllers.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__LED_CONTROLLERS__BUILDER_HPP_
#define UV_MSGS__MSG__DETAIL__LED_CONTROLLERS__BUILDER_HPP_

#include "uv_msgs/msg/detail/led_controllers__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace uv_msgs
{

namespace msg
{

namespace builder
{

class Init_LedControllers_led1
{
public:
  explicit Init_LedControllers_led1(::uv_msgs::msg::LedControllers & msg)
  : msg_(msg)
  {}
  ::uv_msgs::msg::LedControllers led1(::uv_msgs::msg::LedControllers::_led1_type arg)
  {
    msg_.led1 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uv_msgs::msg::LedControllers msg_;
};

class Init_LedControllers_led0
{
public:
  Init_LedControllers_led0()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LedControllers_led1 led0(::uv_msgs::msg::LedControllers::_led0_type arg)
  {
    msg_.led0 = std::move(arg);
    return Init_LedControllers_led1(msg_);
  }

private:
  ::uv_msgs::msg::LedControllers msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::uv_msgs::msg::LedControllers>()
{
  return uv_msgs::msg::builder::Init_LedControllers_led0();
}

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__LED_CONTROLLERS__BUILDER_HPP_
