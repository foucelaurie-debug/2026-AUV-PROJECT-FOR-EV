// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from uv_msgs:msg/MagnetController.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__MAGNET_CONTROLLER__STRUCT_HPP_
#define UV_MSGS__MSG__DETAIL__MAGNET_CONTROLLER__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__uv_msgs__msg__MagnetController __attribute__((deprecated))
#else
# define DEPRECATED__uv_msgs__msg__MagnetController __declspec(deprecated)
#endif

namespace uv_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MagnetController_
{
  using Type = MagnetController_<ContainerAllocator>;

  explicit MagnetController_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = 0;
    }
  }

  explicit MagnetController_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = 0;
    }
  }

  // field types and members
  using _state_type =
    uint8_t;
  _state_type state;

  // setters for named parameter idiom
  Type & set__state(
    const uint8_t & _arg)
  {
    this->state = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    uv_msgs::msg::MagnetController_<ContainerAllocator> *;
  using ConstRawPtr =
    const uv_msgs::msg::MagnetController_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<uv_msgs::msg::MagnetController_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<uv_msgs::msg::MagnetController_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::MagnetController_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::MagnetController_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::MagnetController_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::MagnetController_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<uv_msgs::msg::MagnetController_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<uv_msgs::msg::MagnetController_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__uv_msgs__msg__MagnetController
    std::shared_ptr<uv_msgs::msg::MagnetController_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__uv_msgs__msg__MagnetController
    std::shared_ptr<uv_msgs::msg::MagnetController_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MagnetController_ & other) const
  {
    if (this->state != other.state) {
      return false;
    }
    return true;
  }
  bool operator!=(const MagnetController_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MagnetController_

// alias to use template instance with default allocator
using MagnetController =
  uv_msgs::msg::MagnetController_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__MAGNET_CONTROLLER__STRUCT_HPP_
