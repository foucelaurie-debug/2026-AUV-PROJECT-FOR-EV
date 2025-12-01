// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from uv_msgs:msg/ThrustCurve.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__THRUST_CURVE__BUILDER_HPP_
#define UV_MSGS__MSG__DETAIL__THRUST_CURVE__BUILDER_HPP_

#include "uv_msgs/msg/detail/thrust_curve__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace uv_msgs
{

namespace msg
{

namespace builder
{

class Init_ThrustCurve_pt_end
{
public:
  explicit Init_ThrustCurve_pt_end(::uv_msgs::msg::ThrustCurve & msg)
  : msg_(msg)
  {}
  ::uv_msgs::msg::ThrustCurve pt_end(::uv_msgs::msg::ThrustCurve::_pt_end_type arg)
  {
    msg_.pt_end = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uv_msgs::msg::ThrustCurve msg_;
};

class Init_ThrustCurve_pt_mid
{
public:
  explicit Init_ThrustCurve_pt_mid(::uv_msgs::msg::ThrustCurve & msg)
  : msg_(msg)
  {}
  Init_ThrustCurve_pt_end pt_mid(::uv_msgs::msg::ThrustCurve::_pt_mid_type arg)
  {
    msg_.pt_mid = std::move(arg);
    return Init_ThrustCurve_pt_end(msg_);
  }

private:
  ::uv_msgs::msg::ThrustCurve msg_;
};

class Init_ThrustCurve_nt_mid
{
public:
  explicit Init_ThrustCurve_nt_mid(::uv_msgs::msg::ThrustCurve & msg)
  : msg_(msg)
  {}
  Init_ThrustCurve_pt_mid nt_mid(::uv_msgs::msg::ThrustCurve::_nt_mid_type arg)
  {
    msg_.nt_mid = std::move(arg);
    return Init_ThrustCurve_pt_mid(msg_);
  }

private:
  ::uv_msgs::msg::ThrustCurve msg_;
};

class Init_ThrustCurve_nt_end
{
public:
  explicit Init_ThrustCurve_nt_end(::uv_msgs::msg::ThrustCurve & msg)
  : msg_(msg)
  {}
  Init_ThrustCurve_nt_mid nt_end(::uv_msgs::msg::ThrustCurve::_nt_end_type arg)
  {
    msg_.nt_end = std::move(arg);
    return Init_ThrustCurve_nt_mid(msg_);
  }

private:
  ::uv_msgs::msg::ThrustCurve msg_;
};

class Init_ThrustCurve_pp_mid
{
public:
  explicit Init_ThrustCurve_pp_mid(::uv_msgs::msg::ThrustCurve & msg)
  : msg_(msg)
  {}
  Init_ThrustCurve_nt_end pp_mid(::uv_msgs::msg::ThrustCurve::_pp_mid_type arg)
  {
    msg_.pp_mid = std::move(arg);
    return Init_ThrustCurve_nt_end(msg_);
  }

private:
  ::uv_msgs::msg::ThrustCurve msg_;
};

class Init_ThrustCurve_pp_ini
{
public:
  explicit Init_ThrustCurve_pp_ini(::uv_msgs::msg::ThrustCurve & msg)
  : msg_(msg)
  {}
  Init_ThrustCurve_pp_mid pp_ini(::uv_msgs::msg::ThrustCurve::_pp_ini_type arg)
  {
    msg_.pp_ini = std::move(arg);
    return Init_ThrustCurve_pp_mid(msg_);
  }

private:
  ::uv_msgs::msg::ThrustCurve msg_;
};

class Init_ThrustCurve_np_ini
{
public:
  explicit Init_ThrustCurve_np_ini(::uv_msgs::msg::ThrustCurve & msg)
  : msg_(msg)
  {}
  Init_ThrustCurve_pp_ini np_ini(::uv_msgs::msg::ThrustCurve::_np_ini_type arg)
  {
    msg_.np_ini = std::move(arg);
    return Init_ThrustCurve_pp_ini(msg_);
  }

private:
  ::uv_msgs::msg::ThrustCurve msg_;
};

class Init_ThrustCurve_np_mid
{
public:
  explicit Init_ThrustCurve_np_mid(::uv_msgs::msg::ThrustCurve & msg)
  : msg_(msg)
  {}
  Init_ThrustCurve_np_ini np_mid(::uv_msgs::msg::ThrustCurve::_np_mid_type arg)
  {
    msg_.np_mid = std::move(arg);
    return Init_ThrustCurve_np_ini(msg_);
  }

private:
  ::uv_msgs::msg::ThrustCurve msg_;
};

class Init_ThrustCurve_num
{
public:
  Init_ThrustCurve_num()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ThrustCurve_np_mid num(::uv_msgs::msg::ThrustCurve::_num_type arg)
  {
    msg_.num = std::move(arg);
    return Init_ThrustCurve_np_mid(msg_);
  }

private:
  ::uv_msgs::msg::ThrustCurve msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::uv_msgs::msg::ThrustCurve>()
{
  return uv_msgs::msg::builder::Init_ThrustCurve_num();
}

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__THRUST_CURVE__BUILDER_HPP_
