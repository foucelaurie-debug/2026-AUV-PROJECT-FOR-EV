// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from uv_msgs:msg/ThrustCurve.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__THRUST_CURVE__STRUCT_HPP_
#define UV_MSGS__MSG__DETAIL__THRUST_CURVE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__uv_msgs__msg__ThrustCurve __attribute__((deprecated))
#else
# define DEPRECATED__uv_msgs__msg__ThrustCurve __declspec(deprecated)
#endif

namespace uv_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ThrustCurve_
{
  using Type = ThrustCurve_<ContainerAllocator>;

  explicit ThrustCurve_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->num = 0;
      this->np_mid = 0.0f;
      this->np_ini = 0.0f;
      this->pp_ini = 0.0f;
      this->pp_mid = 0.0f;
      this->nt_end = 0.0f;
      this->nt_mid = 0.0f;
      this->pt_mid = 0.0f;
      this->pt_end = 0.0f;
    }
  }

  explicit ThrustCurve_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->num = 0;
      this->np_mid = 0.0f;
      this->np_ini = 0.0f;
      this->pp_ini = 0.0f;
      this->pp_mid = 0.0f;
      this->nt_end = 0.0f;
      this->nt_mid = 0.0f;
      this->pt_mid = 0.0f;
      this->pt_end = 0.0f;
    }
  }

  // field types and members
  using _num_type =
    uint8_t;
  _num_type num;
  using _np_mid_type =
    float;
  _np_mid_type np_mid;
  using _np_ini_type =
    float;
  _np_ini_type np_ini;
  using _pp_ini_type =
    float;
  _pp_ini_type pp_ini;
  using _pp_mid_type =
    float;
  _pp_mid_type pp_mid;
  using _nt_end_type =
    float;
  _nt_end_type nt_end;
  using _nt_mid_type =
    float;
  _nt_mid_type nt_mid;
  using _pt_mid_type =
    float;
  _pt_mid_type pt_mid;
  using _pt_end_type =
    float;
  _pt_end_type pt_end;

  // setters for named parameter idiom
  Type & set__num(
    const uint8_t & _arg)
  {
    this->num = _arg;
    return *this;
  }
  Type & set__np_mid(
    const float & _arg)
  {
    this->np_mid = _arg;
    return *this;
  }
  Type & set__np_ini(
    const float & _arg)
  {
    this->np_ini = _arg;
    return *this;
  }
  Type & set__pp_ini(
    const float & _arg)
  {
    this->pp_ini = _arg;
    return *this;
  }
  Type & set__pp_mid(
    const float & _arg)
  {
    this->pp_mid = _arg;
    return *this;
  }
  Type & set__nt_end(
    const float & _arg)
  {
    this->nt_end = _arg;
    return *this;
  }
  Type & set__nt_mid(
    const float & _arg)
  {
    this->nt_mid = _arg;
    return *this;
  }
  Type & set__pt_mid(
    const float & _arg)
  {
    this->pt_mid = _arg;
    return *this;
  }
  Type & set__pt_end(
    const float & _arg)
  {
    this->pt_end = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    uv_msgs::msg::ThrustCurve_<ContainerAllocator> *;
  using ConstRawPtr =
    const uv_msgs::msg::ThrustCurve_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<uv_msgs::msg::ThrustCurve_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<uv_msgs::msg::ThrustCurve_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::ThrustCurve_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::ThrustCurve_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::ThrustCurve_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::ThrustCurve_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<uv_msgs::msg::ThrustCurve_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<uv_msgs::msg::ThrustCurve_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__uv_msgs__msg__ThrustCurve
    std::shared_ptr<uv_msgs::msg::ThrustCurve_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__uv_msgs__msg__ThrustCurve
    std::shared_ptr<uv_msgs::msg::ThrustCurve_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ThrustCurve_ & other) const
  {
    if (this->num != other.num) {
      return false;
    }
    if (this->np_mid != other.np_mid) {
      return false;
    }
    if (this->np_ini != other.np_ini) {
      return false;
    }
    if (this->pp_ini != other.pp_ini) {
      return false;
    }
    if (this->pp_mid != other.pp_mid) {
      return false;
    }
    if (this->nt_end != other.nt_end) {
      return false;
    }
    if (this->nt_mid != other.nt_mid) {
      return false;
    }
    if (this->pt_mid != other.pt_mid) {
      return false;
    }
    if (this->pt_end != other.pt_end) {
      return false;
    }
    return true;
  }
  bool operator!=(const ThrustCurve_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ThrustCurve_

// alias to use template instance with default allocator
using ThrustCurve =
  uv_msgs::msg::ThrustCurve_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__THRUST_CURVE__STRUCT_HPP_
