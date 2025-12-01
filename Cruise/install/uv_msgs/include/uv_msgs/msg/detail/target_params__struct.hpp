// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from uv_msgs:msg/TargetParams.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__TARGET_PARAMS__STRUCT_HPP_
#define UV_MSGS__MSG__DETAIL__TARGET_PARAMS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'tpos_inpic'
#include "uv_msgs/msg/detail/pixel_axis__struct.hpp"
// Member 'tpos_inworld'
#include "uv_msgs/msg/detail/target_axis__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__uv_msgs__msg__TargetParams __attribute__((deprecated))
#else
# define DEPRECATED__uv_msgs__msg__TargetParams __declspec(deprecated)
#endif

namespace uv_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TargetParams_
{
  using Type = TargetParams_<ContainerAllocator>;

  explicit TargetParams_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : tpos_inpic(_init),
    tpos_inworld(_init)
  {
    (void)_init;
  }

  explicit TargetParams_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : tpos_inpic(_alloc, _init),
    tpos_inworld(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _tpos_inpic_type =
    uv_msgs::msg::PixelAxis_<ContainerAllocator>;
  _tpos_inpic_type tpos_inpic;
  using _tpos_inworld_type =
    uv_msgs::msg::TargetAxis_<ContainerAllocator>;
  _tpos_inworld_type tpos_inworld;

  // setters for named parameter idiom
  Type & set__tpos_inpic(
    const uv_msgs::msg::PixelAxis_<ContainerAllocator> & _arg)
  {
    this->tpos_inpic = _arg;
    return *this;
  }
  Type & set__tpos_inworld(
    const uv_msgs::msg::TargetAxis_<ContainerAllocator> & _arg)
  {
    this->tpos_inworld = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    uv_msgs::msg::TargetParams_<ContainerAllocator> *;
  using ConstRawPtr =
    const uv_msgs::msg::TargetParams_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<uv_msgs::msg::TargetParams_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<uv_msgs::msg::TargetParams_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::TargetParams_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::TargetParams_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::TargetParams_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::TargetParams_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<uv_msgs::msg::TargetParams_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<uv_msgs::msg::TargetParams_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__uv_msgs__msg__TargetParams
    std::shared_ptr<uv_msgs::msg::TargetParams_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__uv_msgs__msg__TargetParams
    std::shared_ptr<uv_msgs::msg::TargetParams_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TargetParams_ & other) const
  {
    if (this->tpos_inpic != other.tpos_inpic) {
      return false;
    }
    if (this->tpos_inworld != other.tpos_inworld) {
      return false;
    }
    return true;
  }
  bool operator!=(const TargetParams_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TargetParams_

// alias to use template instance with default allocator
using TargetParams =
  uv_msgs::msg::TargetParams_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__TARGET_PARAMS__STRUCT_HPP_
