// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from uv_msgs:msg/PidParams.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__PID_PARAMS__STRUCT_HPP_
#define UV_MSGS__MSG__DETAIL__PID_PARAMS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__uv_msgs__msg__PidParams __attribute__((deprecated))
#else
# define DEPRECATED__uv_msgs__msg__PidParams __declspec(deprecated)
#endif

namespace uv_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PidParams_
{
  using Type = PidParams_<ContainerAllocator>;

  explicit PidParams_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->p = 0.0f;
      this->i = 0.0f;
      this->d = 0.0f;
      this->i_limit = 0.0f;
      this->output_limit = 0.0f;
    }
  }

  explicit PidParams_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->p = 0.0f;
      this->i = 0.0f;
      this->d = 0.0f;
      this->i_limit = 0.0f;
      this->output_limit = 0.0f;
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _name_type name;
  using _p_type =
    float;
  _p_type p;
  using _i_type =
    float;
  _i_type i;
  using _d_type =
    float;
  _d_type d;
  using _i_limit_type =
    float;
  _i_limit_type i_limit;
  using _output_limit_type =
    float;
  _output_limit_type output_limit;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__p(
    const float & _arg)
  {
    this->p = _arg;
    return *this;
  }
  Type & set__i(
    const float & _arg)
  {
    this->i = _arg;
    return *this;
  }
  Type & set__d(
    const float & _arg)
  {
    this->d = _arg;
    return *this;
  }
  Type & set__i_limit(
    const float & _arg)
  {
    this->i_limit = _arg;
    return *this;
  }
  Type & set__output_limit(
    const float & _arg)
  {
    this->output_limit = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    uv_msgs::msg::PidParams_<ContainerAllocator> *;
  using ConstRawPtr =
    const uv_msgs::msg::PidParams_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<uv_msgs::msg::PidParams_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<uv_msgs::msg::PidParams_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::PidParams_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::PidParams_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::PidParams_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::PidParams_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<uv_msgs::msg::PidParams_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<uv_msgs::msg::PidParams_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__uv_msgs__msg__PidParams
    std::shared_ptr<uv_msgs::msg::PidParams_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__uv_msgs__msg__PidParams
    std::shared_ptr<uv_msgs::msg::PidParams_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PidParams_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->p != other.p) {
      return false;
    }
    if (this->i != other.i) {
      return false;
    }
    if (this->d != other.d) {
      return false;
    }
    if (this->i_limit != other.i_limit) {
      return false;
    }
    if (this->output_limit != other.output_limit) {
      return false;
    }
    return true;
  }
  bool operator!=(const PidParams_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PidParams_

// alias to use template instance with default allocator
using PidParams =
  uv_msgs::msg::PidParams_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__PID_PARAMS__STRUCT_HPP_
