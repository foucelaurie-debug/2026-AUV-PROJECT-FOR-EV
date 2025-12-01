// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from uv_msgs:msg/ServoSet.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__SERVO_SET__STRUCT_HPP_
#define UV_MSGS__MSG__DETAIL__SERVO_SET__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__uv_msgs__msg__ServoSet __attribute__((deprecated))
#else
# define DEPRECATED__uv_msgs__msg__ServoSet __declspec(deprecated)
#endif

namespace uv_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ServoSet_
{
  using Type = ServoSet_<ContainerAllocator>;

  explicit ServoSet_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->num = 0;
      this->angle = 0.0f;
    }
  }

  explicit ServoSet_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->num = 0;
      this->angle = 0.0f;
    }
  }

  // field types and members
  using _num_type =
    uint8_t;
  _num_type num;
  using _angle_type =
    float;
  _angle_type angle;

  // setters for named parameter idiom
  Type & set__num(
    const uint8_t & _arg)
  {
    this->num = _arg;
    return *this;
  }
  Type & set__angle(
    const float & _arg)
  {
    this->angle = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    uv_msgs::msg::ServoSet_<ContainerAllocator> *;
  using ConstRawPtr =
    const uv_msgs::msg::ServoSet_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<uv_msgs::msg::ServoSet_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<uv_msgs::msg::ServoSet_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::ServoSet_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::ServoSet_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::ServoSet_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::ServoSet_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<uv_msgs::msg::ServoSet_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<uv_msgs::msg::ServoSet_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__uv_msgs__msg__ServoSet
    std::shared_ptr<uv_msgs::msg::ServoSet_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__uv_msgs__msg__ServoSet
    std::shared_ptr<uv_msgs::msg::ServoSet_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ServoSet_ & other) const
  {
    if (this->num != other.num) {
      return false;
    }
    if (this->angle != other.angle) {
      return false;
    }
    return true;
  }
  bool operator!=(const ServoSet_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ServoSet_

// alias to use template instance with default allocator
using ServoSet =
  uv_msgs::msg::ServoSet_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__SERVO_SET__STRUCT_HPP_
