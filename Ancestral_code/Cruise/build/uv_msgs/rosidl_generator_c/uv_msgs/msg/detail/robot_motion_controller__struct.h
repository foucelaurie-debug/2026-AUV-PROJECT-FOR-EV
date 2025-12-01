// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from uv_msgs:msg/RobotMotionController.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__ROBOT_MOTION_CONTROLLER__STRUCT_H_
#define UV_MSGS__MSG__DETAIL__ROBOT_MOTION_CONTROLLER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pos'
// Member 'tpos_inbase'
// Member 'tpos_inworld'
#include "uv_msgs/msg/detail/robot_axis__struct.h"
// Member 'imu'
#include "uv_msgs/msg/detail/imu_data__struct.h"
// Member 'thrust'
#include "uv_msgs/msg/detail/motor_thrust__struct.h"
// Member 'pidstate'
#include "uv_msgs/msg/detail/pid_controllers_state__struct.h"

// Struct defined in msg/RobotMotionController in the package uv_msgs.
typedef struct uv_msgs__msg__RobotMotionController
{
  uv_msgs__msg__RobotAxis pos;
  uv_msgs__msg__RobotAxis tpos_inbase;
  uv_msgs__msg__RobotAxis tpos_inworld;
  uv_msgs__msg__ImuData imu;
  uv_msgs__msg__MotorThrust thrust;
  uv_msgs__msg__PidControllersState pidstate;
} uv_msgs__msg__RobotMotionController;

// Struct for a sequence of uv_msgs__msg__RobotMotionController.
typedef struct uv_msgs__msg__RobotMotionController__Sequence
{
  uv_msgs__msg__RobotMotionController * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} uv_msgs__msg__RobotMotionController__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UV_MSGS__MSG__DETAIL__ROBOT_MOTION_CONTROLLER__STRUCT_H_
