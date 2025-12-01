// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from uv_msgs:msg/Yolov8.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__YOLOV8__STRUCT_HPP_
#define UV_MSGS__MSG__DETAIL__YOLOV8__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'targets'
#include "uv_msgs/msg/detail/target_params__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__uv_msgs__msg__Yolov8 __attribute__((deprecated))
#else
# define DEPRECATED__uv_msgs__msg__Yolov8 __declspec(deprecated)
#endif

namespace uv_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Yolov8_
{
  using Type = Yolov8_<ContainerAllocator>;

  explicit Yolov8_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 11>::iterator, float>(this->state.begin(), this->state.end(), 0.0f);
      this->targets.fill(uv_msgs::msg::TargetParams_<ContainerAllocator>{_init});
    }
  }

  explicit Yolov8_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : state(_alloc),
    targets(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 11>::iterator, float>(this->state.begin(), this->state.end(), 0.0f);
      this->targets.fill(uv_msgs::msg::TargetParams_<ContainerAllocator>{_alloc, _init});
    }
  }

  // field types and members
  using _state_type =
    std::array<float, 11>;
  _state_type state;
  using _targets_type =
    std::array<uv_msgs::msg::TargetParams_<ContainerAllocator>, 11>;
  _targets_type targets;

  // setters for named parameter idiom
  Type & set__state(
    const std::array<float, 11> & _arg)
  {
    this->state = _arg;
    return *this;
  }
  Type & set__targets(
    const std::array<uv_msgs::msg::TargetParams_<ContainerAllocator>, 11> & _arg)
  {
    this->targets = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    uv_msgs::msg::Yolov8_<ContainerAllocator> *;
  using ConstRawPtr =
    const uv_msgs::msg::Yolov8_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<uv_msgs::msg::Yolov8_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<uv_msgs::msg::Yolov8_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::Yolov8_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::Yolov8_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::Yolov8_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::Yolov8_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<uv_msgs::msg::Yolov8_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<uv_msgs::msg::Yolov8_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__uv_msgs__msg__Yolov8
    std::shared_ptr<uv_msgs::msg::Yolov8_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__uv_msgs__msg__Yolov8
    std::shared_ptr<uv_msgs::msg::Yolov8_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Yolov8_ & other) const
  {
    if (this->state != other.state) {
      return false;
    }
    if (this->targets != other.targets) {
      return false;
    }
    return true;
  }
  bool operator!=(const Yolov8_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Yolov8_

// alias to use template instance with default allocator
using Yolov8 =
  uv_msgs::msg::Yolov8_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__YOLOV8__STRUCT_HPP_
