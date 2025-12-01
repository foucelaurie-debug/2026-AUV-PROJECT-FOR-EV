// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from uv_msgs:srv/DetectRequest.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__SRV__DETAIL__DETECT_REQUEST__STRUCT_HPP_
#define UV_MSGS__SRV__DETAIL__DETECT_REQUEST__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'imagein'
#include "sensor_msgs/msg/detail/image__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__uv_msgs__srv__DetectRequest_Request __attribute__((deprecated))
#else
# define DEPRECATED__uv_msgs__srv__DetectRequest_Request __declspec(deprecated)
#endif

namespace uv_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DetectRequest_Request_
{
  using Type = DetectRequest_Request_<ContainerAllocator>;

  explicit DetectRequest_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : imagein(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target = "";
      this->stero = "";
    }
  }

  explicit DetectRequest_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : imagein(_alloc, _init),
    target(_alloc),
    stero(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->target = "";
      this->stero = "";
    }
  }

  // field types and members
  using _imagein_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _imagein_type imagein;
  using _target_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _target_type target;
  using _stero_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _stero_type stero;

  // setters for named parameter idiom
  Type & set__imagein(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->imagein = _arg;
    return *this;
  }
  Type & set__target(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->target = _arg;
    return *this;
  }
  Type & set__stero(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->stero = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    uv_msgs::srv::DetectRequest_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const uv_msgs::srv::DetectRequest_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<uv_msgs::srv::DetectRequest_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<uv_msgs::srv::DetectRequest_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      uv_msgs::srv::DetectRequest_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::srv::DetectRequest_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      uv_msgs::srv::DetectRequest_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::srv::DetectRequest_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<uv_msgs::srv::DetectRequest_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<uv_msgs::srv::DetectRequest_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__uv_msgs__srv__DetectRequest_Request
    std::shared_ptr<uv_msgs::srv::DetectRequest_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__uv_msgs__srv__DetectRequest_Request
    std::shared_ptr<uv_msgs::srv::DetectRequest_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectRequest_Request_ & other) const
  {
    if (this->imagein != other.imagein) {
      return false;
    }
    if (this->target != other.target) {
      return false;
    }
    if (this->stero != other.stero) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectRequest_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectRequest_Request_

// alias to use template instance with default allocator
using DetectRequest_Request =
  uv_msgs::srv::DetectRequest_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace uv_msgs


#ifndef _WIN32
# define DEPRECATED__uv_msgs__srv__DetectRequest_Response __attribute__((deprecated))
#else
# define DEPRECATED__uv_msgs__srv__DetectRequest_Response __declspec(deprecated)
#endif

namespace uv_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DetectRequest_Response_
{
  using Type = DetectRequest_Response_<ContainerAllocator>;

  explicit DetectRequest_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->s = 0;
      this->x = 0.0f;
      this->y = 0.0f;
      this->z = 0.0f;
    }
  }

  explicit DetectRequest_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->s = 0;
      this->x = 0.0f;
      this->y = 0.0f;
      this->z = 0.0f;
    }
  }

  // field types and members
  using _s_type =
    uint8_t;
  _s_type s;
  using _x_type =
    float;
  _x_type x;
  using _y_type =
    float;
  _y_type y;
  using _z_type =
    float;
  _z_type z;

  // setters for named parameter idiom
  Type & set__s(
    const uint8_t & _arg)
  {
    this->s = _arg;
    return *this;
  }
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const float & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const float & _arg)
  {
    this->z = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    uv_msgs::srv::DetectRequest_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const uv_msgs::srv::DetectRequest_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<uv_msgs::srv::DetectRequest_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<uv_msgs::srv::DetectRequest_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      uv_msgs::srv::DetectRequest_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::srv::DetectRequest_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      uv_msgs::srv::DetectRequest_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<uv_msgs::srv::DetectRequest_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<uv_msgs::srv::DetectRequest_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<uv_msgs::srv::DetectRequest_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__uv_msgs__srv__DetectRequest_Response
    std::shared_ptr<uv_msgs::srv::DetectRequest_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__uv_msgs__srv__DetectRequest_Response
    std::shared_ptr<uv_msgs::srv::DetectRequest_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DetectRequest_Response_ & other) const
  {
    if (this->s != other.s) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    return true;
  }
  bool operator!=(const DetectRequest_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DetectRequest_Response_

// alias to use template instance with default allocator
using DetectRequest_Response =
  uv_msgs::srv::DetectRequest_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace uv_msgs

namespace uv_msgs
{

namespace srv
{

struct DetectRequest
{
  using Request = uv_msgs::srv::DetectRequest_Request;
  using Response = uv_msgs::srv::DetectRequest_Response;
};

}  // namespace srv

}  // namespace uv_msgs

#endif  // UV_MSGS__SRV__DETAIL__DETECT_REQUEST__STRUCT_HPP_
