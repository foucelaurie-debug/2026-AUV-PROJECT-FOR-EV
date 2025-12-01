// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from uv_msgs:msg/LedControllers.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__LED_CONTROLLERS__STRUCT_HPP_
#define UV_MSGS__MSG__DETAIL__LED_CONTROLLERS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__uv_msgs__msg__LedControllers __attribute__((deprecated))
#else
# define DEPRECATED__uv_msgs__msg__LedControllers __declspec(deprecated)
#endif

namespace uv_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LedControllers_
{
  using Type = LedControllers_<ContainerAllocator>;

  explicit LedControllers_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->led0 = 0;
      this->led1 = 0;
    }
  }

  explicit LedControllers_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->led0 = 0;
      this->led1 = 0;
    }
  }

  // field types and members
  using _led0_type =
    uint8_t;
  _led0_type led0;
  using _led1_type =
    uint8_t;
  _led1_type led1;

  // setters for named parameter idiom
  Type & set__led0(
    const uint8_t & _arg)
  {
    this->led0 = _arg;
    return *this;
  }
  Type & set__led1(
    const uint8_t & _arg)
  {
    this->led1 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    uv_msgs::msg::LedControllers_<ContainerAllocator> *;
  using ConstRawPtr =
    const uv_msgs::msg::LedControllers_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<uv_msgs::msg::LedControllers_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<uv_msgs::msg::LedControllers_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::LedControllers_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::LedControllers_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::LedControllers_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::LedControllers_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<uv_msgs::msg::LedControllers_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<uv_msgs::msg::LedControllers_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__uv_msgs__msg__LedControllers
    std::shared_ptr<uv_msgs::msg::LedControllers_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__uv_msgs__msg__LedControllers
    std::shared_ptr<uv_msgs::msg::LedControllers_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LedControllers_ & other) const
  {
    if (this->led0 != other.led0) {
      return false;
    }
    if (this->led1 != other.led1) {
      return false;
    }
    return true;
  }
  bool operator!=(const LedControllers_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LedControllers_

// alias to use template instance with default allocator
using LedControllers =
  uv_msgs::msg::LedControllers_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__LED_CONTROLLERS__STRUCT_HPP_
