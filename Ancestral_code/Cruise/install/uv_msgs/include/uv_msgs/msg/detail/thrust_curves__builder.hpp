// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from uv_msgs:msg/ThrustCurves.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__THRUST_CURVES__BUILDER_HPP_
#define UV_MSGS__MSG__DETAIL__THRUST_CURVES__BUILDER_HPP_

#include "uv_msgs/msg/detail/thrust_curves__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace uv_msgs
{

namespace msg
{

namespace builder
{

class Init_ThrustCurves_m5
{
public:
  explicit Init_ThrustCurves_m5(::uv_msgs::msg::ThrustCurves & msg)
  : msg_(msg)
  {}
  ::uv_msgs::msg::ThrustCurves m5(::uv_msgs::msg::ThrustCurves::_m5_type arg)
  {
    msg_.m5 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uv_msgs::msg::ThrustCurves msg_;
};

class Init_ThrustCurves_m4
{
public:
  explicit Init_ThrustCurves_m4(::uv_msgs::msg::ThrustCurves & msg)
  : msg_(msg)
  {}
  Init_ThrustCurves_m5 m4(::uv_msgs::msg::ThrustCurves::_m4_type arg)
  {
    msg_.m4 = std::move(arg);
    return Init_ThrustCurves_m5(msg_);
  }

private:
  ::uv_msgs::msg::ThrustCurves msg_;
};

class Init_ThrustCurves_m3
{
public:
  explicit Init_ThrustCurves_m3(::uv_msgs::msg::ThrustCurves & msg)
  : msg_(msg)
  {}
  Init_ThrustCurves_m4 m3(::uv_msgs::msg::ThrustCurves::_m3_type arg)
  {
    msg_.m3 = std::move(arg);
    return Init_ThrustCurves_m4(msg_);
  }

private:
  ::uv_msgs::msg::ThrustCurves msg_;
};

class Init_ThrustCurves_m2
{
public:
  explicit Init_ThrustCurves_m2(::uv_msgs::msg::ThrustCurves & msg)
  : msg_(msg)
  {}
  Init_ThrustCurves_m3 m2(::uv_msgs::msg::ThrustCurves::_m2_type arg)
  {
    msg_.m2 = std::move(arg);
    return Init_ThrustCurves_m3(msg_);
  }

private:
  ::uv_msgs::msg::ThrustCurves msg_;
};

class Init_ThrustCurves_m1
{
public:
  explicit Init_ThrustCurves_m1(::uv_msgs::msg::ThrustCurves & msg)
  : msg_(msg)
  {}
  Init_ThrustCurves_m2 m1(::uv_msgs::msg::ThrustCurves::_m1_type arg)
  {
    msg_.m1 = std::move(arg);
    return Init_ThrustCurves_m2(msg_);
  }

private:
  ::uv_msgs::msg::ThrustCurves msg_;
};

class Init_ThrustCurves_m0
{
public:
  Init_ThrustCurves_m0()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ThrustCurves_m1 m0(::uv_msgs::msg::ThrustCurves::_m0_type arg)
  {
    msg_.m0 = std::move(arg);
    return Init_ThrustCurves_m1(msg_);
  }

private:
  ::uv_msgs::msg::ThrustCurves msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::uv_msgs::msg::ThrustCurves>()
{
  return uv_msgs::msg::builder::Init_ThrustCurves_m0();
}

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__THRUST_CURVES__BUILDER_HPP_
