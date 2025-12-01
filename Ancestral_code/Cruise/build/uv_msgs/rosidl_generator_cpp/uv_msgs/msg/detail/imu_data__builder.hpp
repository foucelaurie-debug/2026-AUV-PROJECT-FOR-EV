// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from uv_msgs:msg/ImuData.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__IMU_DATA__BUILDER_HPP_
#define UV_MSGS__MSG__DETAIL__IMU_DATA__BUILDER_HPP_

#include "uv_msgs/msg/detail/imu_data__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace uv_msgs
{

namespace msg
{

namespace builder
{

class Init_ImuData_spd
{
public:
  explicit Init_ImuData_spd(::uv_msgs::msg::ImuData & msg)
  : msg_(msg)
  {}
  ::uv_msgs::msg::ImuData spd(::uv_msgs::msg::ImuData::_spd_type arg)
  {
    msg_.spd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::uv_msgs::msg::ImuData msg_;
};

class Init_ImuData_pos
{
public:
  explicit Init_ImuData_pos(::uv_msgs::msg::ImuData & msg)
  : msg_(msg)
  {}
  Init_ImuData_spd pos(::uv_msgs::msg::ImuData::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return Init_ImuData_spd(msg_);
  }

private:
  ::uv_msgs::msg::ImuData msg_;
};

class Init_ImuData_dvl
{
public:
  explicit Init_ImuData_dvl(::uv_msgs::msg::ImuData & msg)
  : msg_(msg)
  {}
  Init_ImuData_pos dvl(::uv_msgs::msg::ImuData::_dvl_type arg)
  {
    msg_.dvl = std::move(arg);
    return Init_ImuData_pos(msg_);
  }

private:
  ::uv_msgs::msg::ImuData msg_;
};

class Init_ImuData_mode
{
public:
  Init_ImuData_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ImuData_dvl mode(::uv_msgs::msg::ImuData::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_ImuData_dvl(msg_);
  }

private:
  ::uv_msgs::msg::ImuData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::uv_msgs::msg::ImuData>()
{
  return uv_msgs::msg::builder::Init_ImuData_mode();
}

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__IMU_DATA__BUILDER_HPP_
