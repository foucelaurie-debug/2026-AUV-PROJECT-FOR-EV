// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from uv_msgs:msg/RobotDeviceManager.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__ROBOT_DEVICE_MANAGER__STRUCT_HPP_
#define UV_MSGS__MSG__DETAIL__ROBOT_DEVICE_MANAGER__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__uv_msgs__msg__RobotDeviceManager __attribute__((deprecated))
#else
# define DEPRECATED__uv_msgs__msg__RobotDeviceManager __declspec(deprecated)
#endif

namespace uv_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotDeviceManager_
{
  using Type = RobotDeviceManager_<ContainerAllocator>;

  explicit RobotDeviceManager_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->leak = 0;
      this->tem = 0.0f;
      this->hum = 0.0f;
      this->vol = 0.0f;
      this->magnet = 0;
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->led.begin(), this->led.end(), 0);
      std::fill<typename std::array<float, 2>::iterator, float>(this->angle.begin(), this->angle.end(), 0.0f);
    }
  }

  explicit RobotDeviceManager_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : led(_alloc),
    angle(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->leak = 0;
      this->tem = 0.0f;
      this->hum = 0.0f;
      this->vol = 0.0f;
      this->magnet = 0;
      std::fill<typename std::array<uint8_t, 2>::iterator, uint8_t>(this->led.begin(), this->led.end(), 0);
      std::fill<typename std::array<float, 2>::iterator, float>(this->angle.begin(), this->angle.end(), 0.0f);
    }
  }

  // field types and members
  using _leak_type =
    uint8_t;
  _leak_type leak;
  using _tem_type =
    float;
  _tem_type tem;
  using _hum_type =
    float;
  _hum_type hum;
  using _vol_type =
    float;
  _vol_type vol;
  using _magnet_type =
    uint8_t;
  _magnet_type magnet;
  using _led_type =
    std::array<uint8_t, 2>;
  _led_type led;
  using _angle_type =
    std::array<float, 2>;
  _angle_type angle;

  // setters for named parameter idiom
  Type & set__leak(
    const uint8_t & _arg)
  {
    this->leak = _arg;
    return *this;
  }
  Type & set__tem(
    const float & _arg)
  {
    this->tem = _arg;
    return *this;
  }
  Type & set__hum(
    const float & _arg)
  {
    this->hum = _arg;
    return *this;
  }
  Type & set__vol(
    const float & _arg)
  {
    this->vol = _arg;
    return *this;
  }
  Type & set__magnet(
    const uint8_t & _arg)
  {
    this->magnet = _arg;
    return *this;
  }
  Type & set__led(
    const std::array<uint8_t, 2> & _arg)
  {
    this->led = _arg;
    return *this;
  }
  Type & set__angle(
    const std::array<float, 2> & _arg)
  {
    this->angle = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    uv_msgs::msg::RobotDeviceManager_<ContainerAllocator> *;
  using ConstRawPtr =
    const uv_msgs::msg::RobotDeviceManager_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<uv_msgs::msg::RobotDeviceManager_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<uv_msgs::msg::RobotDeviceManager_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::RobotDeviceManager_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::RobotDeviceManager_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::RobotDeviceManager_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::RobotDeviceManager_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<uv_msgs::msg::RobotDeviceManager_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<uv_msgs::msg::RobotDeviceManager_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__uv_msgs__msg__RobotDeviceManager
    std::shared_ptr<uv_msgs::msg::RobotDeviceManager_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__uv_msgs__msg__RobotDeviceManager
    std::shared_ptr<uv_msgs::msg::RobotDeviceManager_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotDeviceManager_ & other) const
  {
    if (this->leak != other.leak) {
      return false;
    }
    if (this->tem != other.tem) {
      return false;
    }
    if (this->hum != other.hum) {
      return false;
    }
    if (this->vol != other.vol) {
      return false;
    }
    if (this->magnet != other.magnet) {
      return false;
    }
    if (this->led != other.led) {
      return false;
    }
    if (this->angle != other.angle) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotDeviceManager_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotDeviceManager_

// alias to use template instance with default allocator
using RobotDeviceManager =
  uv_msgs::msg::RobotDeviceManager_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__ROBOT_DEVICE_MANAGER__STRUCT_HPP_
