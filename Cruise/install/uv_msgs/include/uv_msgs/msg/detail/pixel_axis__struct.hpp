// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from uv_msgs:msg/PixelAxis.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__PIXEL_AXIS__STRUCT_HPP_
#define UV_MSGS__MSG__DETAIL__PIXEL_AXIS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__uv_msgs__msg__PixelAxis __attribute__((deprecated))
#else
# define DEPRECATED__uv_msgs__msg__PixelAxis __declspec(deprecated)
#endif

namespace uv_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PixelAxis_
{
  using Type = PixelAxis_<ContainerAllocator>;

  explicit PixelAxis_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0ul;
      this->y = 0ul;
    }
  }

  explicit PixelAxis_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0ul;
      this->y = 0ul;
    }
  }

  // field types and members
  using _x_type =
    uint32_t;
  _x_type x;
  using _y_type =
    uint32_t;
  _y_type y;

  // setters for named parameter idiom
  Type & set__x(
    const uint32_t & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const uint32_t & _arg)
  {
    this->y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    uv_msgs::msg::PixelAxis_<ContainerAllocator> *;
  using ConstRawPtr =
    const uv_msgs::msg::PixelAxis_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<uv_msgs::msg::PixelAxis_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<uv_msgs::msg::PixelAxis_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::PixelAxis_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::PixelAxis_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::PixelAxis_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::PixelAxis_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<uv_msgs::msg::PixelAxis_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<uv_msgs::msg::PixelAxis_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__uv_msgs__msg__PixelAxis
    std::shared_ptr<uv_msgs::msg::PixelAxis_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__uv_msgs__msg__PixelAxis
    std::shared_ptr<uv_msgs::msg::PixelAxis_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PixelAxis_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    return true;
  }
  bool operator!=(const PixelAxis_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PixelAxis_

// alias to use template instance with default allocator
using PixelAxis =
  uv_msgs::msg::PixelAxis_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__PIXEL_AXIS__STRUCT_HPP_
