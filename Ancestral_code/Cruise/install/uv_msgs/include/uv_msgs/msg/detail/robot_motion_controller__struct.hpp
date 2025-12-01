// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from uv_msgs:msg/RobotMotionController.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__ROBOT_MOTION_CONTROLLER__STRUCT_HPP_
#define UV_MSGS__MSG__DETAIL__ROBOT_MOTION_CONTROLLER__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'pos'
// Member 'tpos_inbase'
// Member 'tpos_inworld'
#include "uv_msgs/msg/detail/robot_axis__struct.hpp"
// Member 'imu'
#include "uv_msgs/msg/detail/imu_data__struct.hpp"
// Member 'thrust'
#include "uv_msgs/msg/detail/motor_thrust__struct.hpp"
// Member 'pidstate'
#include "uv_msgs/msg/detail/pid_controllers_state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__uv_msgs__msg__RobotMotionController __attribute__((deprecated))
#else
# define DEPRECATED__uv_msgs__msg__RobotMotionController __declspec(deprecated)
#endif

namespace uv_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotMotionController_
{
  using Type = RobotMotionController_<ContainerAllocator>;

  explicit RobotMotionController_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pos(_init),
    tpos_inbase(_init),
    tpos_inworld(_init),
    imu(_init),
    thrust(_init),
    pidstate(_init)
  {
    (void)_init;
  }

  explicit RobotMotionController_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pos(_alloc, _init),
    tpos_inbase(_alloc, _init),
    tpos_inworld(_alloc, _init),
    imu(_alloc, _init),
    thrust(_alloc, _init),
    pidstate(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _pos_type =
    uv_msgs::msg::RobotAxis_<ContainerAllocator>;
  _pos_type pos;
  using _tpos_inbase_type =
    uv_msgs::msg::RobotAxis_<ContainerAllocator>;
  _tpos_inbase_type tpos_inbase;
  using _tpos_inworld_type =
    uv_msgs::msg::RobotAxis_<ContainerAllocator>;
  _tpos_inworld_type tpos_inworld;
  using _imu_type =
    uv_msgs::msg::ImuData_<ContainerAllocator>;
  _imu_type imu;
  using _thrust_type =
    uv_msgs::msg::MotorThrust_<ContainerAllocator>;
  _thrust_type thrust;
  using _pidstate_type =
    uv_msgs::msg::PidControllersState_<ContainerAllocator>;
  _pidstate_type pidstate;

  // setters for named parameter idiom
  Type & set__pos(
    const uv_msgs::msg::RobotAxis_<ContainerAllocator> & _arg)
  {
    this->pos = _arg;
    return *this;
  }
  Type & set__tpos_inbase(
    const uv_msgs::msg::RobotAxis_<ContainerAllocator> & _arg)
  {
    this->tpos_inbase = _arg;
    return *this;
  }
  Type & set__tpos_inworld(
    const uv_msgs::msg::RobotAxis_<ContainerAllocator> & _arg)
  {
    this->tpos_inworld = _arg;
    return *this;
  }
  Type & set__imu(
    const uv_msgs::msg::ImuData_<ContainerAllocator> & _arg)
  {
    this->imu = _arg;
    return *this;
  }
  Type & set__thrust(
    const uv_msgs::msg::MotorThrust_<ContainerAllocator> & _arg)
  {
    this->thrust = _arg;
    return *this;
  }
  Type & set__pidstate(
    const uv_msgs::msg::PidControllersState_<ContainerAllocator> & _arg)
  {
    this->pidstate = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    uv_msgs::msg::RobotMotionController_<ContainerAllocator> *;
  using ConstRawPtr =
    const uv_msgs::msg::RobotMotionController_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<uv_msgs::msg::RobotMotionController_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<uv_msgs::msg::RobotMotionController_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::RobotMotionController_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::RobotMotionController_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      uv_msgs::msg::RobotMotionController_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::msg::RobotMotionController_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<uv_msgs::msg::RobotMotionController_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<uv_msgs::msg::RobotMotionController_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__uv_msgs__msg__RobotMotionController
    std::shared_ptr<uv_msgs::msg::RobotMotionController_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__uv_msgs__msg__RobotMotionController
    std::shared_ptr<uv_msgs::msg::RobotMotionController_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotMotionController_ & other) const
  {
    if (this->pos != other.pos) {
      return false;
    }
    if (this->tpos_inbase != other.tpos_inbase) {
      return false;
    }
    if (this->tpos_inworld != other.tpos_inworld) {
      return false;
    }
    if (this->imu != other.imu) {
      return false;
    }
    if (this->thrust != other.thrust) {
      return false;
    }
    if (this->pidstate != other.pidstate) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotMotionController_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotMotionController_

// alias to use template instance with default allocator
using RobotMotionController =
  uv_msgs::msg::RobotMotionController_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace uv_msgs

#endif  // UV_MSGS__MSG__DETAIL__ROBOT_MOTION_CONTROLLER__STRUCT_HPP_
