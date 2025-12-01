// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from uv_msgs:msg/CabinState.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__CABIN_STATE__STRUCT_HPP_
#define UV_MSGS__MSG__DETAIL__CABIN_STATE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__uv_msgs__msg__CabinState __attribute__((deprecated))
#else
# define DEPRECATED__uv_msgs__msg__CabinState __declspec(deprecated)
#endif

namespace uv_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CabinState_
{
  using Type = CabinState_<ContainerAllocator>;

  explicit CabinState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->temp = 0.0f;
      this->hum = 0.0f;
      this->leak = 0;
      this->voltage = 0.0f;
      std::fill<typename std::array<float, 2>::iterator, float>(this->servo.begin(), this->servo.end(), 0.0f);
    }
  }

  explicit CabinState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : servo(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->temp = 0.0f;
      this->hum = 0.0f;
      this->leak = 0;
      this->voltage = 0.0f;
      std::fill<typename std::array<float, 2>::iterator, float>(this->servo.begin(), this->servo.end(), 0.0f);
    }
  }

  // field types and members
  using _temp_type =
    float;
  _temp_type temp;
  using _hum_type =
    float;
  _hum_type hum;
  using _leak_type =
    uint8_t;
  _leak_type leak;
  using _voltage_type =
    float;
  _voltage_type voltage;
  using _servo_type =
    std::array<float, 2>;
  _servo_type servo;

  // setters for named parameter idiom
  Type & set__temp(
    const float & _arg)
  {
    this->temp = _arg;
    return *this;
  }
  Type & set__hum(
    const float & _arg)
  {
    this->hum = _arg;
    return *this;
  }
  Type & set__leak(
    const uint8_t & _arg)
  {
    this->leak = _arg;
    return *this;
  }
  Type & set__voltage(
    const float & _arg)
  {
    this->voltage = _arg;
    return *this;
  }
  Type & set__servo(
    const std::array<float, 2> & _arg)
  {
    this->servo = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    uv_msgs::msg::CabinState_<ContainerAllocator> *;
  using ConstRawPtr =
    const uv_msgs::msg::CabinState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<uv_msgs::msg::CabinState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<uv_msgs::msg::CabinState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::CabinState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::CabinState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::CabinState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::CabinState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<uv_msgs::msg::CabinState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<uv_msgs::msg::CabinState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__uv_msgs__msg__CabinState
    std::shared_ptr<uv_msgs::msg::CabinState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__uv_msgs__msg__CabinState
    std::shared_ptr<uv_msgs::msg::CabinState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CabinState_ & other) const
  {
    if (this->temp != other.temp) {
      return false;
    }
    if (this->hum != other.hum) {
      return false;
    }
    if (this->leak != other.leak) {
      return false;
    }
    if (this->voltage != other.voltage) {
      return false;
    }
    if (this->servo != other.servo) {
      return false;
    }
    return true;
  }
  bool operator!=(const CabinState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CabinState_

// alias to use template instance with default allocator
using CabinState =
  uv_msgs::msg::CabinState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__CABIN_STATE__STRUCT_HPP_
