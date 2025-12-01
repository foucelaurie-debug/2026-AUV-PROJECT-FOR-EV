// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from uv_msgs:msg/TargetPosDown.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__TARGET_POS_DOWN__STRUCT_HPP_
#define UV_MSGS__MSG__DETAIL__TARGET_POS_DOWN__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'pos'
#include "uv_msgs/msg/detail/robot_axis__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__uv_msgs__msg__TargetPosDown __attribute__((deprecated))
#else
# define DEPRECATED__uv_msgs__msg__TargetPosDown __declspec(deprecated)
#endif

namespace uv_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TargetPosDown_
{
  using Type = TargetPosDown_<ContainerAllocator>;

  explicit TargetPosDown_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pos(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cs = 0;
    }
  }

  explicit TargetPosDown_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pos(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cs = 0;
    }
  }

  // field types and members
  using _cs_type =
    uint8_t;
  _cs_type cs;
  using _pos_type =
    uv_msgs::msg::RobotAxis_<ContainerAllocator>;
  _pos_type pos;

  // setters for named parameter idiom
  Type & set__cs(
    const uint8_t & _arg)
  {
    this->cs = _arg;
    return *this;
  }
  Type & set__pos(
    const uv_msgs::msg::RobotAxis_<ContainerAllocator> & _arg)
  {
    this->pos = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    uv_msgs::msg::TargetPosDown_<ContainerAllocator> *;
  using ConstRawPtr =
    const uv_msgs::msg::TargetPosDown_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<uv_msgs::msg::TargetPosDown_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<uv_msgs::msg::TargetPosDown_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::TargetPosDown_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::TargetPosDown_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::TargetPosDown_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::TargetPosDown_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<uv_msgs::msg::TargetPosDown_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<uv_msgs::msg::TargetPosDown_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__uv_msgs__msg__TargetPosDown
    std::shared_ptr<uv_msgs::msg::TargetPosDown_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__uv_msgs__msg__TargetPosDown
    std::shared_ptr<uv_msgs::msg::TargetPosDown_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TargetPosDown_ & other) const
  {
    if (this->cs != other.cs) {
      return false;
    }
    if (this->pos != other.pos) {
      return false;
    }
    return true;
  }
  bool operator!=(const TargetPosDown_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TargetPosDown_

// alias to use template instance with default allocator
using TargetPosDown =
  uv_msgs::msg::TargetPosDown_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__TARGET_POS_DOWN__STRUCT_HPP_
