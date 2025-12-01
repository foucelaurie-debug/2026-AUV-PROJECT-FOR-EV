// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from uv_msgs:msg/PidControllers.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__PID_CONTROLLERS__STRUCT_HPP_
#define UV_MSGS__MSG__DETAIL__PID_CONTROLLERS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'x'
// Member 'y'
// Member 'z'
// Member 'rx'
// Member 'ry'
// Member 'rz'
// Member 'vx'
// Member 'vy'
#include "uv_msgs/msg/detail/pid_params__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__uv_msgs__msg__PidControllers __attribute__((deprecated))
#else
# define DEPRECATED__uv_msgs__msg__PidControllers __declspec(deprecated)
#endif

namespace uv_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PidControllers_
{
  using Type = PidControllers_<ContainerAllocator>;

  explicit PidControllers_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : x(_init),
    y(_init),
    z(_init),
    rx(_init),
    ry(_init),
    rz(_init),
    vx(_init),
    vy(_init)
  {
    (void)_init;
  }

  explicit PidControllers_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : x(_alloc, _init),
    y(_alloc, _init),
    z(_alloc, _init),
    rx(_alloc, _init),
    ry(_alloc, _init),
    rz(_alloc, _init),
    vx(_alloc, _init),
    vy(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _x_type =
    uv_msgs::msg::PidParams_<ContainerAllocator>;
  _x_type x;
  using _y_type =
    uv_msgs::msg::PidParams_<ContainerAllocator>;
  _y_type y;
  using _z_type =
    uv_msgs::msg::PidParams_<ContainerAllocator>;
  _z_type z;
  using _rx_type =
    uv_msgs::msg::PidParams_<ContainerAllocator>;
  _rx_type rx;
  using _ry_type =
    uv_msgs::msg::PidParams_<ContainerAllocator>;
  _ry_type ry;
  using _rz_type =
    uv_msgs::msg::PidParams_<ContainerAllocator>;
  _rz_type rz;
  using _vx_type =
    uv_msgs::msg::PidParams_<ContainerAllocator>;
  _vx_type vx;
  using _vy_type =
    uv_msgs::msg::PidParams_<ContainerAllocator>;
  _vy_type vy;

  // setters for named parameter idiom
  Type & set__x(
    const uv_msgs::msg::PidParams_<ContainerAllocator> & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const uv_msgs::msg::PidParams_<ContainerAllocator> & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const uv_msgs::msg::PidParams_<ContainerAllocator> & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__rx(
    const uv_msgs::msg::PidParams_<ContainerAllocator> & _arg)
  {
    this->rx = _arg;
    return *this;
  }
  Type & set__ry(
    const uv_msgs::msg::PidParams_<ContainerAllocator> & _arg)
  {
    this->ry = _arg;
    return *this;
  }
  Type & set__rz(
    const uv_msgs::msg::PidParams_<ContainerAllocator> & _arg)
  {
    this->rz = _arg;
    return *this;
  }
  Type & set__vx(
    const uv_msgs::msg::PidParams_<ContainerAllocator> & _arg)
  {
    this->vx = _arg;
    return *this;
  }
  Type & set__vy(
    const uv_msgs::msg::PidParams_<ContainerAllocator> & _arg)
  {
    this->vy = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    uv_msgs::msg::PidControllers_<ContainerAllocator> *;
  using ConstRawPtr =
    const uv_msgs::msg::PidControllers_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<uv_msgs::msg::PidControllers_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<uv_msgs::msg::PidControllers_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::PidControllers_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::PidControllers_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::PidControllers_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::PidControllers_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<uv_msgs::msg::PidControllers_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<uv_msgs::msg::PidControllers_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__uv_msgs__msg__PidControllers
    std::shared_ptr<uv_msgs::msg::PidControllers_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__uv_msgs__msg__PidControllers
    std::shared_ptr<uv_msgs::msg::PidControllers_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PidControllers_ & other) const
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
    if (this->vx != other.vx) {
      return false;
    }
    if (this->vy != other.vy) {
      return false;
    }
    return true;
  }
  bool operator!=(const PidControllers_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PidControllers_

// alias to use template instance with default allocator
using PidControllers =
  uv_msgs::msg::PidControllers_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__PID_CONTROLLERS__STRUCT_HPP_
