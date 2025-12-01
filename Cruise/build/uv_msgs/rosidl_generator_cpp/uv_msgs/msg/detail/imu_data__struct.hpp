// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from uv_msgs:msg/ImuData.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__IMU_DATA__STRUCT_HPP_
#define UV_MSGS__MSG__DETAIL__IMU_DATA__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'pos'
// Member 'spd'
#include "uv_msgs/msg/detail/robot_axis__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__uv_msgs__msg__ImuData __attribute__((deprecated))
#else
# define DEPRECATED__uv_msgs__msg__ImuData __declspec(deprecated)
#endif

namespace uv_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ImuData_
{
  using Type = ImuData_<ContainerAllocator>;

  explicit ImuData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pos(_init),
    spd(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
      this->dvl = 0;
    }
  }

  explicit ImuData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pos(_alloc, _init),
    spd(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
      this->dvl = 0;
    }
  }

  // field types and members
  using _mode_type =
    uint8_t;
  _mode_type mode;
  using _dvl_type =
    uint8_t;
  _dvl_type dvl;
  using _pos_type =
    uv_msgs::msg::RobotAxis_<ContainerAllocator>;
  _pos_type pos;
  using _spd_type =
    uv_msgs::msg::RobotAxis_<ContainerAllocator>;
  _spd_type spd;

  // setters for named parameter idiom
  Type & set__mode(
    const uint8_t & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__dvl(
    const uint8_t & _arg)
  {
    this->dvl = _arg;
    return *this;
  }
  Type & set__pos(
    const uv_msgs::msg::RobotAxis_<ContainerAllocator> & _arg)
  {
    this->pos = _arg;
    return *this;
  }
  Type & set__spd(
    const uv_msgs::msg::RobotAxis_<ContainerAllocator> & _arg)
  {
    this->spd = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    uv_msgs::msg::ImuData_<ContainerAllocator> *;
  using ConstRawPtr =
    const uv_msgs::msg::ImuData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<uv_msgs::msg::ImuData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<uv_msgs::msg::ImuData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::ImuData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::ImuData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::ImuData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::ImuData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<uv_msgs::msg::ImuData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<uv_msgs::msg::ImuData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__uv_msgs__msg__ImuData
    std::shared_ptr<uv_msgs::msg::ImuData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__uv_msgs__msg__ImuData
    std::shared_ptr<uv_msgs::msg::ImuData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ImuData_ & other) const
  {
    if (this->mode != other.mode) {
      return false;
    }
    if (this->dvl != other.dvl) {
      return false;
    }
    if (this->pos != other.pos) {
      return false;
    }
    if (this->spd != other.spd) {
      return false;
    }
    return true;
  }
  bool operator!=(const ImuData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ImuData_

// alias to use template instance with default allocator
using ImuData =
  uv_msgs::msg::ImuData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__IMU_DATA__STRUCT_HPP_
