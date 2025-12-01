// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from uv_msgs:msg/RobotMotionController.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__ROBOT_MOTION_CONTROLLER__BUILDER_HPP_
#define UV_MSGS__MSG__DETAIL__ROBOT_MOTION_CONTROLLER__BUILDER_HPP_

#include "uv_msgs/msg/detail/robot_motion_controller__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace uv_msgs
{

namespace msg
{

namespace builder
{

class Init_RobotMotionController_pidstate
{
public:
  explicit Init_RobotMotionController_pidstate(::uv_msgs::msg::RobotMotionController & msg)
  : msg_(msg)
  {}
  ::uv_msgs::msg::RobotMotionController pidstate(::uv_msgs::msg::RobotMotionController::_pidstate_type arg)
  {
    msg_.pidstate = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uv_msgs::msg::RobotMotionController msg_;
};

class Init_RobotMotionController_thrust
{
public:
  explicit Init_RobotMotionController_thrust(::uv_msgs::msg::RobotMotionController & msg)
  : msg_(msg)
  {}
  Init_RobotMotionController_pidstate thrust(::uv_msgs::msg::RobotMotionController::_thrust_type arg)
  {
    msg_.thrust = std::move(arg);
    return Init_RobotMotionController_pidstate(msg_);
  }

private:
  ::uv_msgs::msg::RobotMotionController msg_;
};

class Init_RobotMotionController_imu
{
public:
  explicit Init_RobotMotionController_imu(::uv_msgs::msg::RobotMotionController & msg)
  : msg_(msg)
  {}
  Init_RobotMotionController_thrust imu(::uv_msgs::msg::RobotMotionController::_imu_type arg)
  {
    msg_.imu = std::move(arg);
    return Init_RobotMotionController_thrust(msg_);
  }

private:
  ::uv_msgs::msg::RobotMotionController msg_;
};

class Init_RobotMotionController_tpos_inworld
{
public:
  explicit Init_RobotMotionController_tpos_inworld(::uv_msgs::msg::RobotMotionController & msg)
  : msg_(msg)
  {}
  Init_RobotMotionController_imu tpos_inworld(::uv_msgs::msg::RobotMotionController::_tpos_inworld_type arg)
  {
    msg_.tpos_inworld = std::move(arg);
    return Init_RobotMotionController_imu(msg_);
  }

private:
  ::uv_msgs::msg::RobotMotionController msg_;
};

class Init_RobotMotionController_tpos_inbase
{
public:
  explicit Init_RobotMotionController_tpos_inbase(::uv_msgs::msg::RobotMotionController & msg)
  : msg_(msg)
  {}
  Init_RobotMotionController_tpos_inworld tpos_inbase(::uv_msgs::msg::RobotMotionController::_tpos_inbase_type arg)
  {
    msg_.tpos_inbase = std::move(arg);
    return Init_RobotMotionController_tpos_inworld(msg_);
  }

private:
  ::uv_msgs::msg::RobotMotionController msg_;
};

class Init_RobotMotionController_pos
{
public:
  Init_RobotMotionController_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotMotionController_tpos_inbase pos(::uv_msgs::msg::RobotMotionController::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return Init_RobotMotionController_tpos_inbase(msg_);
  }

private:
  ::uv_msgs::msg::RobotMotionController msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::uv_msgs::msg::RobotMotionController>()
{
  return uv_msgs::msg::builder::Init_RobotMotionController_pos();
}

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__ROBOT_MOTION_CONTROLLER__BUILDER_HPP_
