// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from uv_msgs:msg/RobotDeviceManager.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__ROBOT_DEVICE_MANAGER__BUILDER_HPP_
#define UV_MSGS__MSG__DETAIL__ROBOT_DEVICE_MANAGER__BUILDER_HPP_

#include "uv_msgs/msg/detail/robot_device_manager__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace uv_msgs
{

namespace msg
{

namespace builder
{

class Init_RobotDeviceManager_angle
{
public:
  explicit Init_RobotDeviceManager_angle(::uv_msgs::msg::RobotDeviceManager & msg)
  : msg_(msg)
  {}
  ::uv_msgs::msg::RobotDeviceManager angle(::uv_msgs::msg::RobotDeviceManager::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uv_msgs::msg::RobotDeviceManager msg_;
};

class Init_RobotDeviceManager_led
{
public:
  explicit Init_RobotDeviceManager_led(::uv_msgs::msg::RobotDeviceManager & msg)
  : msg_(msg)
  {}
  Init_RobotDeviceManager_angle led(::uv_msgs::msg::RobotDeviceManager::_led_type arg)
  {
    msg_.led = std::move(arg);
    return Init_RobotDeviceManager_angle(msg_);
  }

private:
  ::uv_msgs::msg::RobotDeviceManager msg_;
};

class Init_RobotDeviceManager_magnet
{
public:
  explicit Init_RobotDeviceManager_magnet(::uv_msgs::msg::RobotDeviceManager & msg)
  : msg_(msg)
  {}
  Init_RobotDeviceManager_led magnet(::uv_msgs::msg::RobotDeviceManager::_magnet_type arg)
  {
    msg_.magnet = std::move(arg);
    return Init_RobotDeviceManager_led(msg_);
  }

private:
  ::uv_msgs::msg::RobotDeviceManager msg_;
};

class Init_RobotDeviceManager_vol
{
public:
  explicit Init_RobotDeviceManager_vol(::uv_msgs::msg::RobotDeviceManager & msg)
  : msg_(msg)
  {}
  Init_RobotDeviceManager_magnet vol(::uv_msgs::msg::RobotDeviceManager::_vol_type arg)
  {
    msg_.vol = std::move(arg);
    return Init_RobotDeviceManager_magnet(msg_);
  }

private:
  ::uv_msgs::msg::RobotDeviceManager msg_;
};

class Init_RobotDeviceManager_hum
{
public:
  explicit Init_RobotDeviceManager_hum(::uv_msgs::msg::RobotDeviceManager & msg)
  : msg_(msg)
  {}
  Init_RobotDeviceManager_vol hum(::uv_msgs::msg::RobotDeviceManager::_hum_type arg)
  {
    msg_.hum = std::move(arg);
    return Init_RobotDeviceManager_vol(msg_);
  }

private:
  ::uv_msgs::msg::RobotDeviceManager msg_;
};

class Init_RobotDeviceManager_tem
{
public:
  explicit Init_RobotDeviceManager_tem(::uv_msgs::msg::RobotDeviceManager & msg)
  : msg_(msg)
  {}
  Init_RobotDeviceManager_hum tem(::uv_msgs::msg::RobotDeviceManager::_tem_type arg)
  {
    msg_.tem = std::move(arg);
    return Init_RobotDeviceManager_hum(msg_);
  }

private:
  ::uv_msgs::msg::RobotDeviceManager msg_;
};

class Init_RobotDeviceManager_leak
{
public:
  Init_RobotDeviceManager_leak()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotDeviceManager_tem leak(::uv_msgs::msg::RobotDeviceManager::_leak_type arg)
  {
    msg_.leak = std::move(arg);
    return Init_RobotDeviceManager_tem(msg_);
  }

private:
  ::uv_msgs::msg::RobotDeviceManager msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::uv_msgs::msg::RobotDeviceManager>()
{
  return uv_msgs::msg::builder::Init_RobotDeviceManager_leak();
}

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__ROBOT_DEVICE_MANAGER__BUILDER_HPP_
