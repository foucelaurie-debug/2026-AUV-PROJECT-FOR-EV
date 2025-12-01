// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from uv_msgs:msg/ThrustCurves.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__THRUST_CURVES__STRUCT_HPP_
#define UV_MSGS__MSG__DETAIL__THRUST_CURVES__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'm0'
// Member 'm1'
// Member 'm2'
// Member 'm3'
// Member 'm4'
// Member 'm5'
#include "uv_msgs/msg/detail/thrust_curve__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__uv_msgs__msg__ThrustCurves __attribute__((deprecated))
#else
# define DEPRECATED__uv_msgs__msg__ThrustCurves __declspec(deprecated)
#endif

namespace uv_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ThrustCurves_
{
  using Type = ThrustCurves_<ContainerAllocator>;

  explicit ThrustCurves_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : m0(_init),
    m1(_init),
    m2(_init),
    m3(_init),
    m4(_init),
    m5(_init)
  {
    (void)_init;
  }

  explicit ThrustCurves_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : m0(_alloc, _init),
    m1(_alloc, _init),
    m2(_alloc, _init),
    m3(_alloc, _init),
    m4(_alloc, _init),
    m5(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _m0_type =
    uv_msgs::msg::ThrustCurve_<ContainerAllocator>;
  _m0_type m0;
  using _m1_type =
    uv_msgs::msg::ThrustCurve_<ContainerAllocator>;
  _m1_type m1;
  using _m2_type =
    uv_msgs::msg::ThrustCurve_<ContainerAllocator>;
  _m2_type m2;
  using _m3_type =
    uv_msgs::msg::ThrustCurve_<ContainerAllocator>;
  _m3_type m3;
  using _m4_type =
    uv_msgs::msg::ThrustCurve_<ContainerAllocator>;
  _m4_type m4;
  using _m5_type =
    uv_msgs::msg::ThrustCurve_<ContainerAllocator>;
  _m5_type m5;

  // setters for named parameter idiom
  Type & set__m0(
    const uv_msgs::msg::ThrustCurve_<ContainerAllocator> & _arg)
  {
    this->m0 = _arg;
    return *this;
  }
  Type & set__m1(
    const uv_msgs::msg::ThrustCurve_<ContainerAllocator> & _arg)
  {
    this->m1 = _arg;
    return *this;
  }
  Type & set__m2(
    const uv_msgs::msg::ThrustCurve_<ContainerAllocator> & _arg)
  {
    this->m2 = _arg;
    return *this;
  }
  Type & set__m3(
    const uv_msgs::msg::ThrustCurve_<ContainerAllocator> & _arg)
  {
    this->m3 = _arg;
    return *this;
  }
  Type & set__m4(
    const uv_msgs::msg::ThrustCurve_<ContainerAllocator> & _arg)
  {
    this->m4 = _arg;
    return *this;
  }
  Type & set__m5(
    const uv_msgs::msg::ThrustCurve_<ContainerAllocator> & _arg)
  {
    this->m5 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    uv_msgs::msg::ThrustCurves_<ContainerAllocator> *;
  using ConstRawPtr =
    const uv_msgs::msg::ThrustCurves_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<uv_msgs::msg::ThrustCurves_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<uv_msgs::msg::ThrustCurves_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::ThrustCurves_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::ThrustCurves_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::ThrustCurves_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::ThrustCurves_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<uv_msgs::msg::ThrustCurves_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<uv_msgs::msg::ThrustCurves_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__uv_msgs__msg__ThrustCurves
    std::shared_ptr<uv_msgs::msg::ThrustCurves_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__uv_msgs__msg__ThrustCurves
    std::shared_ptr<uv_msgs::msg::ThrustCurves_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ThrustCurves_ & other) const
  {
    if (this->m0 != other.m0) {
      return false;
    }
    if (this->m1 != other.m1) {
      return false;
    }
    if (this->m2 != other.m2) {
      return false;
    }
    if (this->m3 != other.m3) {
      return false;
    }
    if (this->m4 != other.m4) {
      return false;
    }
    if (this->m5 != other.m5) {
      return false;
    }
    return true;
  }
  bool operator!=(const ThrustCurves_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ThrustCurves_

// alias to use template instance with default allocator
using ThrustCurves =
  uv_msgs::msg::ThrustCurves_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__THRUST_CURVES__STRUCT_HPP_
