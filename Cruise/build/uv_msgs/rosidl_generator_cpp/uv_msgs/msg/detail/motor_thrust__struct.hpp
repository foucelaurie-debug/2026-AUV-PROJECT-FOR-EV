// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from uv_msgs:msg/MotorThrust.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__MOTOR_THRUST__STRUCT_HPP_
#define UV_MSGS__MSG__DETAIL__MOTOR_THRUST__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__uv_msgs__msg__MotorThrust __attribute__((deprecated))
#else
# define DEPRECATED__uv_msgs__msg__MotorThrust __declspec(deprecated)
#endif

namespace uv_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotorThrust_
{
  using Type = MotorThrust_<ContainerAllocator>;

  explicit MotorThrust_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 6>::iterator, float>(this->thrust.begin(), this->thrust.end(), 0.0f);
    }
  }

  explicit MotorThrust_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : thrust(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 6>::iterator, float>(this->thrust.begin(), this->thrust.end(), 0.0f);
    }
  }

  // field types and members
  using _thrust_type =
    std::array<float, 6>;
  _thrust_type thrust;

  // setters for named parameter idiom
  Type & set__thrust(
    const std::array<float, 6> & _arg)
  {
    this->thrust = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    uv_msgs::msg::MotorThrust_<ContainerAllocator> *;
  using ConstRawPtr =
    const uv_msgs::msg::MotorThrust_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<uv_msgs::msg::MotorThrust_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<uv_msgs::msg::MotorThrust_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::MotorThrust_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::MotorThrust_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::MotorThrust_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::MotorThrust_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<uv_msgs::msg::MotorThrust_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<uv_msgs::msg::MotorThrust_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__uv_msgs__msg__MotorThrust
    std::shared_ptr<uv_msgs::msg::MotorThrust_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__uv_msgs__msg__MotorThrust
    std::shared_ptr<uv_msgs::msg::MotorThrust_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotorThrust_ & other) const
  {
    if (this->thrust != other.thrust) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotorThrust_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotorThrust_

// alias to use template instance with default allocator
using MotorThrust =
  uv_msgs::msg::MotorThrust_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__MOTOR_THRUST__STRUCT_HPP_
