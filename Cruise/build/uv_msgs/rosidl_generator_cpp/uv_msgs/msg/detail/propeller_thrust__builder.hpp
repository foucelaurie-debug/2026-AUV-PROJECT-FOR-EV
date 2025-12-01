// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from uv_msgs:msg/PropellerThrust.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__PROPELLER_THRUST__BUILDER_HPP_
#define UV_MSGS__MSG__DETAIL__PROPELLER_THRUST__BUILDER_HPP_

#include "uv_msgs/msg/detail/propeller_thrust__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace uv_msgs
{

namespace msg
{

namespace builder
{

class Init_PropellerThrust_thrust
{
public:
  Init_PropellerThrust_thrust()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::uv_msgs::msg::PropellerThrust thrust(::uv_msgs::msg::PropellerThrust::_thrust_type arg)
  {
    msg_.thrust = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uv_msgs::msg::PropellerThrust msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::uv_msgs::msg::PropellerThrust>()
{
  return uv_msgs::msg::builder::Init_PropellerThrust_thrust();
}

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__PROPELLER_THRUST__BUILDER_HPP_
