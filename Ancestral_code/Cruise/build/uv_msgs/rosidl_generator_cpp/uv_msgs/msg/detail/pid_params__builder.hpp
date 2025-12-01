// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from uv_msgs:msg/PidParams.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__PID_PARAMS__BUILDER_HPP_
#define UV_MSGS__MSG__DETAIL__PID_PARAMS__BUILDER_HPP_

#include "uv_msgs/msg/detail/pid_params__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace uv_msgs
{

namespace msg
{

namespace builder
{

class Init_PidParams_output_limit
{
public:
  explicit Init_PidParams_output_limit(::uv_msgs::msg::PidParams & msg)
  : msg_(msg)
  {}
  ::uv_msgs::msg::PidParams output_limit(::uv_msgs::msg::PidParams::_output_limit_type arg)
  {
    msg_.output_limit = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uv_msgs::msg::PidParams msg_;
};

class Init_PidParams_i_limit
{
public:
  explicit Init_PidParams_i_limit(::uv_msgs::msg::PidParams & msg)
  : msg_(msg)
  {}
  Init_PidParams_output_limit i_limit(::uv_msgs::msg::PidParams::_i_limit_type arg)
  {
    msg_.i_limit = std::move(arg);
    return Init_PidParams_output_limit(msg_);
  }

private:
  ::uv_msgs::msg::PidParams msg_;
};

class Init_PidParams_d
{
public:
  explicit Init_PidParams_d(::uv_msgs::msg::PidParams & msg)
  : msg_(msg)
  {}
  Init_PidParams_i_limit d(::uv_msgs::msg::PidParams::_d_type arg)
  {
    msg_.d = std::move(arg);
    return Init_PidParams_i_limit(msg_);
  }

private:
  ::uv_msgs::msg::PidParams msg_;
};

class Init_PidParams_i
{
public:
  explicit Init_PidParams_i(::uv_msgs::msg::PidParams & msg)
  : msg_(msg)
  {}
  Init_PidParams_d i(::uv_msgs::msg::PidParams::_i_type arg)
  {
    msg_.i = std::move(arg);
    return Init_PidParams_d(msg_);
  }

private:
  ::uv_msgs::msg::PidParams msg_;
};

class Init_PidParams_p
{
public:
  explicit Init_PidParams_p(::uv_msgs::msg::PidParams & msg)
  : msg_(msg)
  {}
  Init_PidParams_i p(::uv_msgs::msg::PidParams::_p_type arg)
  {
    msg_.p = std::move(arg);
    return Init_PidParams_i(msg_);
  }

private:
  ::uv_msgs::msg::PidParams msg_;
};

class Init_PidParams_name
{
public:
  Init_PidParams_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PidParams_p name(::uv_msgs::msg::PidParams::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_PidParams_p(msg_);
  }

private:
  ::uv_msgs::msg::PidParams msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::uv_msgs::msg::PidParams>()
{
  return uv_msgs::msg::builder::Init_PidParams_name();
}

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__PID_PARAMS__BUILDER_HPP_
