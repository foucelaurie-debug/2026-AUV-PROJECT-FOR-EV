// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from uv_msgs:srv/DetectRequest.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__SRV__DETAIL__DETECT_REQUEST__TRAITS_HPP_
#define UV_MSGS__SRV__DETAIL__DETECT_REQUEST__TRAITS_HPP_

#include "uv_msgs/srv/detail/detect_request__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'imagein'
#include "sensor_msgs/msg/detail/image__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<uv_msgs::srv::DetectRequest_Request>()
{
  return "uv_msgs::srv::DetectRequest_Request";
}

template<>
inline const char * name<uv_msgs::srv::DetectRequest_Request>()
{
  return "uv_msgs/srv/DetectRequest_Request";
}

template<>
struct has_fixed_size<uv_msgs::srv::DetectRequest_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<uv_msgs::srv::DetectRequest_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<uv_msgs::srv::DetectRequest_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<uv_msgs::srv::DetectRequest_Response>()
{
  return "uv_msgs::srv::DetectRequest_Response";
}

template<>
inline const char * name<uv_msgs::srv::DetectRequest_Response>()
{
  return "uv_msgs/srv/DetectRequest_Response";
}

template<>
struct has_fixed_size<uv_msgs::srv::DetectRequest_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<uv_msgs::srv::DetectRequest_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<uv_msgs::srv::DetectRequest_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<uv_msgs::srv::DetectRequest>()
{
  return "uv_msgs::srv::DetectRequest";
}

template<>
inline const char * name<uv_msgs::srv::DetectRequest>()
{
  return "uv_msgs/srv/DetectRequest";
}

template<>
struct has_fixed_size<uv_msgs::srv::DetectRequest>
  : std::integral_constant<
    bool,
    has_fixed_size<uv_msgs::srv::DetectRequest_Request>::value &&
    has_fixed_size<uv_msgs::srv::DetectRequest_Response>::value
  >
{
};

template<>
struct has_bounded_size<uv_msgs::srv::DetectRequest>
  : std::integral_constant<
    bool,
    has_bounded_size<uv_msgs::srv::DetectRequest_Request>::value &&
    has_bounded_size<uv_msgs::srv::DetectRequest_Response>::value
  >
{
};

template<>
struct is_service<uv_msgs::srv::DetectRequest>
  : std::true_type
{
};

template<>
struct is_service_request<uv_msgs::srv::DetectRequest_Request>
  : std::true_type
{
};

template<>
struct is_service_response<uv_msgs::srv::DetectRequest_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // UV_MSGS__SRV__DETAIL__DETECT_REQUEST__TRAITS_HPP_
