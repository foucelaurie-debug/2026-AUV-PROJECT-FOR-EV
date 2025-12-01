// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from uv_msgs:msg/PidControllersState.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__PID_CONTROLLERS_STATE__STRUCT_HPP_
#define UV_MSGS__MSG__DETAIL__PID_CONTROLLERS_STATE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__uv_msgs__msg__PidControllersState __attribute__((deprecated))
#else
# define DEPRECATED__uv_msgs__msg__PidControllersState __declspec(deprecated)
#endif

namespace uv_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PidControllersState_
{
  using Type = PidControllersState_<ContainerAllocator>;

  explicit PidControllersState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0;
      this->y = 0;
      this->z = 0;
      this->rx = 0;
      this->ry = 0;
      this->rz = 0;
      this->vy = 0;
      this->vx = 0;
    }
  }

  explicit PidControllersState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0;
      this->y = 0;
      this->z = 0;
      this->rx = 0;
      this->ry = 0;
      this->rz = 0;
      this->vy = 0;
      this->vx = 0;
    }
  }

  // field types and members
  using _x_type =
    uint8_t;
  _x_type x;
  using _y_type =
    uint8_t;
  _y_type y;
  using _z_type =
    uint8_t;
  _z_type z;
  using _rx_type =
    uint8_t;
  _rx_type rx;
  using _ry_type =
    uint8_t;
  _ry_type ry;
  using _rz_type =
    uint8_t;
  _rz_type rz;
  using _vy_type =
    uint8_t;
  _vy_type vy;
  using _vx_type =
    uint8_t;
  _vx_type vx;

  // setters for named parameter idiom
  Type & set__x(
    const uint8_t & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const uint8_t & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const uint8_t & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__rx(
    const uint8_t & _arg)
  {
    this->rx = _arg;
    return *this;
  }
  Type & set__ry(
    const uint8_t & _arg)
  {
    this->ry = _arg;
    return *this;
  }
  Type & set__rz(
    const uint8_t & _arg)
  {
    this->rz = _arg;
    return *this;
  }
  Type & set__vy(
    const uint8_t & _arg)
  {
    this->vy = _arg;
    return *this;
  }
  Type & set__vx(
    const uint8_t & _arg)
  {
    this->vx = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    uv_msgs::msg::PidControllersState_<ContainerAllocator> *;
  using ConstRawPtr =
    const uv_msgs::msg::PidControllersState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<uv_msgs::msg::PidControllersState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<uv_msgs::msg::PidControllersState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::PidControllersState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::PidControllersState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::PidControllersState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::PidControllersState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<uv_msgs::msg::PidControllersState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<uv_msgs::msg::PidControllersState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__uv_msgs__msg__PidControllersState
    std::shared_ptr<uv_msgs::msg::PidControllersState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__uv_msgs__msg__PidControllersState
    std::shared_ptr<uv_msgs::msg::PidControllersState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PidControllersState_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    if (this->rx != other.rx) {
      return false;
    }
    if (this->ry != other.ry) {
      return false;
    }
    if (this->rz != other.rz) {
      return false;
    }
    if (this->vy != other.vy) {
      return false;
    }
    if (this->vx != other.vx) {
      return false;
    }
    return true;
  }
  bool operator!=(const PidControllersState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PidControllersState_

// alias to use template instance with default allocator
using PidControllersState =
  uv_msgs::msg::PidControllersState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__PID_CONTROLLERS_STATE__STRUCT_HPP_
