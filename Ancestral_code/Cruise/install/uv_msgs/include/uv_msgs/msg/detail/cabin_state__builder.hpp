// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from uv_msgs:msg/CabinState.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__CABIN_STATE__BUILDER_HPP_
#define UV_MSGS__MSG__DETAIL__CABIN_STATE__BUILDER_HPP_

#include "uv_msgs/msg/detail/cabin_state__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace uv_msgs
{

namespace msg
{

namespace builder
{

class Init_CabinState_servo
{
public:
  explicit Init_CabinState_servo(::uv_msgs::msg::CabinState & msg)
  : msg_(msg)
  {}
  ::uv_msgs::msg::CabinState servo(::uv_msgs::msg::CabinState::_servo_type arg)
  {
    msg_.servo = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uv_msgs::msg::CabinState msg_;
};

class Init_CabinState_voltage
{
public:
  explicit Init_CabinState_voltage(::uv_msgs::msg::CabinState & msg)
  : msg_(msg)
  {}
  Init_CabinState_servo voltage(::uv_msgs::msg::CabinState::_voltage_type arg)
  {
    msg_.voltage = std::move(arg);
    return Init_CabinState_servo(msg_);
  }

private:
  ::uv_msgs::msg::CabinState msg_;
};

class Init_CabinState_leak
{
public:
  explicit Init_CabinState_leak(::uv_msgs::msg::CabinState & msg)
  : msg_(msg)
  {}
  Init_CabinState_voltage leak(::uv_msgs::msg::CabinState::_leak_type arg)
  {
    msg_.leak = std::move(arg);
    return Init_CabinState_voltage(msg_);
  }

private:
  ::uv_msgs::msg::CabinState msg_;
};

class Init_CabinState_hum
{
public:
  explicit Init_CabinState_hum(::uv_msgs::msg::CabinState & msg)
  : msg_(msg)
  {}
  Init_CabinState_leak hum(::uv_msgs::msg::CabinState::_hum_type arg)
  {
    msg_.hum = std::move(arg);
    return Init_CabinState_leak(msg_);
  }

private:
  ::uv_msgs::msg::CabinState msg_;
};

class Init_CabinState_temp
{
public:
  Init_CabinState_temp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CabinState_hum temp(::uv_msgs::msg::CabinState::_temp_type arg)
  {
    msg_.temp = std::move(arg);
    return Init_CabinState_hum(msg_);
  }

private:
  ::uv_msgs::msg::CabinState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::uv_msgs::msg::CabinState>()
{
  return uv_msgs::msg::builder::Init_CabinState_temp();
}

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__CABIN_STATE__BUILDER_HPP_
