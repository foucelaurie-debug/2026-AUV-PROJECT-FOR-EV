// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from uv_msgs:msg/MagnetController.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__MAGNET_CONTROLLER__BUILDER_HPP_
#define UV_MSGS__MSG__DETAIL__MAGNET_CONTROLLER__BUILDER_HPP_

#include "uv_msgs/msg/detail/magnet_controller__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace uv_msgs
{

namespace msg
{

namespace builder
{

class Init_MagnetController_state
{
public:
  Init_MagnetController_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::uv_msgs::msg::MagnetController state(::uv_msgs::msg::MagnetController::_state_type arg)
  {
    msg_.state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uv_msgs::msg::MagnetController msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::uv_msgs::msg::MagnetController>()
{
  return uv_msgs::msg::builder::Init_MagnetController_state();
}

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__MAGNET_CONTROLLER__BUILDER_HPP_
