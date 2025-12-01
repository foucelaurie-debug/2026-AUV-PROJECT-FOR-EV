// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from uv_msgs:srv/DetectRequest.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__SRV__DETAIL__DETECT_REQUEST__BUILDER_HPP_
#define UV_MSGS__SRV__DETAIL__DETECT_REQUEST__BUILDER_HPP_

#include "uv_msgs/srv/detail/detect_request__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace uv_msgs
{

namespace srv
{

namespace builder
{

class Init_DetectRequest_Request_stero
{
public:
  explicit Init_DetectRequest_Request_stero(::uv_msgs::srv::DetectRequest_Request & msg)
  : msg_(msg)
  {}
  ::uv_msgs::srv::DetectRequest_Request stero(::uv_msgs::srv::DetectRequest_Request::_stero_type arg)
  {
    msg_.stero = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uv_msgs::srv::DetectRequest_Request msg_;
};

class Init_DetectRequest_Request_target
{
public:
  explicit Init_DetectRequest_Request_target(::uv_msgs::srv::DetectRequest_Request & msg)
  : msg_(msg)
  {}
  Init_DetectRequest_Request_stero target(::uv_msgs::srv::DetectRequest_Request::_target_type arg)
  {
    msg_.target = std::move(arg);
    return Init_DetectRequest_Request_stero(msg_);
  }

private:
  ::uv_msgs::srv::DetectRequest_Request msg_;
};

class Init_DetectRequest_Request_imagein
{
public:
  Init_DetectRequest_Request_imagein()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DetectRequest_Request_target imagein(::uv_msgs::srv::DetectRequest_Request::_imagein_type arg)
  {
    msg_.imagein = std::move(arg);
    return Init_DetectRequest_Request_target(msg_);
  }

private:
  ::uv_msgs::srv::DetectRequest_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::uv_msgs::srv::DetectRequest_Request>()
{
  return uv_msgs::srv::builder::Init_DetectRequest_Request_imagein();
}

}  // namespace uv_msgs


namespace uv_msgs
{

namespace srv
{

namespace builder
{

class Init_DetectRequest_Response_z
{
public:
  explicit Init_DetectRequest_Response_z(::uv_msgs::srv::DetectRequest_Response & msg)
  : msg_(msg)
  {}
  ::uv_msgs::srv::DetectRequest_Response z(::uv_msgs::srv::DetectRequest_Response::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uv_msgs::srv::DetectRequest_Response msg_;
};

class Init_DetectRequest_Response_y
{
public:
  explicit Init_DetectRequest_Response_y(::uv_msgs::srv::DetectRequest_Response & msg)
  : msg_(msg)
  {}
  Init_DetectRequest_Response_z y(::uv_msgs::srv::DetectRequest_Response::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_DetectRequest_Response_z(msg_);
  }

private:
  ::uv_msgs::srv::DetectRequest_Response msg_;
};

class Init_DetectRequest_Response_x
{
public:
  explicit Init_DetectRequest_Response_x(::uv_msgs::srv::DetectRequest_Response & msg)
  : msg_(msg)
  {}
  Init_DetectRequest_Response_y x(::uv_msgs::srv::DetectRequest_Response::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_DetectRequest_Response_y(msg_);
  }

private:
  ::uv_msgs::srv::DetectRequest_Response msg_;
};

class Init_DetectRequest_Response_s
{
public:
  Init_DetectRequest_Response_s()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DetectRequest_Response_x s(::uv_msgs::srv::DetectRequest_Response::_s_type arg)
  {
    msg_.s = std::move(arg);
    return Init_DetectRequest_Response_x(msg_);
  }

private:
  ::uv_msgs::srv::DetectRequest_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::uv_msgs::srv::DetectRequest_Response>()
{
  return uv_msgs::srv::builder::Init_DetectRequest_Response_s();
}

}  // namespace uv_msgs

#endif  // UV_MSGS__SRV__DETAIL__DETECT_REQUEST__BUILDER_HPP_
