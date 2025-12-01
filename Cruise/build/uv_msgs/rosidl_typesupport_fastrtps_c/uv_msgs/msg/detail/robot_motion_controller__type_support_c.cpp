// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from uv_msgs:msg/RobotMotionController.idl
// generated code does not contain a copyright notice
#include "uv_msgs/msg/detail/robot_motion_controller__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "uv_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "uv_msgs/msg/detail/robot_motion_controller__struct.h"
#include "uv_msgs/msg/detail/robot_motion_controller__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "uv_msgs/msg/detail/imu_data__functions.h"  // imu
#include "uv_msgs/msg/detail/motor_thrust__functions.h"  // thrust
#include "uv_msgs/msg/detail/pid_controllers_state__functions.h"  // pidstate
#include "uv_msgs/msg/detail/robot_axis__functions.h"  // pos, tpos_inbase, tpos_inworld

// forward declare type support functions
size_t get_serialized_size_uv_msgs__msg__ImuData(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_uv_msgs__msg__ImuData(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, uv_msgs, msg, ImuData)();
size_t get_serialized_size_uv_msgs__msg__MotorThrust(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_uv_msgs__msg__MotorThrust(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, uv_msgs, msg, MotorThrust)();
size_t get_serialized_size_uv_msgs__msg__PidControllersState(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_uv_msgs__msg__PidControllersState(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, uv_msgs, msg, PidControllersState)();
size_t get_serialized_size_uv_msgs__msg__RobotAxis(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_uv_msgs__msg__RobotAxis(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, uv_msgs, msg, RobotAxis)();


using _RobotMotionController__ros_msg_type = uv_msgs__msg__RobotMotionController;

static bool _RobotMotionController__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _RobotMotionController__ros_msg_type * ros_message = static_cast<const _RobotMotionController__ros_msg_type *>(untyped_ros_message);
  // Field name: pos
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, RobotAxis
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->pos, cdr))
    {
      return false;
    }
  }

  // Field name: tpos_inbase
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, RobotAxis
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->tpos_inbase, cdr))
    {
      return false;
    }
  }

  // Field name: tpos_inworld
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, RobotAxis
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->tpos_inworld, cdr))
    {
      return false;
    }
  }

  // Field name: imu
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, ImuData
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->imu, cdr))
    {
      return false;
    }
  }

  // Field name: thrust
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, MotorThrust
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->thrust, cdr))
    {
      return false;
    }
  }

  // Field name: pidstate
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, PidControllersState
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->pidstate, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _RobotMotionController__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _RobotMotionController__ros_msg_type * ros_message = static_cast<_RobotMotionController__ros_msg_type *>(untyped_ros_message);
  // Field name: pos
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, RobotAxis
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->pos))
    {
      return false;
    }
  }

  // Field name: tpos_inbase
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, RobotAxis
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->tpos_inbase))
    {
      return false;
    }
  }

  // Field name: tpos_inworld
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, RobotAxis
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->tpos_inworld))
    {
      return false;
    }
  }

  // Field name: imu
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, ImuData
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->imu))
    {
      return false;
    }
  }

  // Field name: thrust
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, MotorThrust
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->thrust))
    {
      return false;
    }
  }

  // Field name: pidstate
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, uv_msgs, msg, PidControllersState
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->pidstate))
    {
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_uv_msgs
size_t get_serialized_size_uv_msgs__msg__RobotMotionController(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RobotMotionController__ros_msg_type * ros_message = static_cast<const _RobotMotionController__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name pos

  current_alignment += get_serialized_size_uv_msgs__msg__RobotAxis(
    &(ros_message->pos), current_alignment);
  // field.name tpos_inbase

  current_alignment += get_serialized_size_uv_msgs__msg__RobotAxis(
    &(ros_message->tpos_inbase), current_alignment);
  // field.name tpos_inworld

  current_alignment += get_serialized_size_uv_msgs__msg__RobotAxis(
    &(ros_message->tpos_inworld), current_alignment);
  // field.name imu

  current_alignment += get_serialized_size_uv_msgs__msg__ImuData(
    &(ros_message->imu), current_alignment);
  // field.name thrust

  current_alignment += get_serialized_size_uv_msgs__msg__MotorThrust(
    &(ros_message->thrust), current_alignment);
  // field.name pidstate

  current_alignment += get_serialized_size_uv_msgs__msg__PidControllersState(
    &(ros_message->pidstate), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _RobotMotionController__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_uv_msgs__msg__RobotMotionController(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_uv_msgs
size_t max_serialized_size_uv_msgs__msg__RobotMotionController(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: pos
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_uv_msgs__msg__RobotAxis(
        full_bounded, current_alignment);
    }
  }
  // member: tpos_inbase
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_uv_msgs__msg__RobotAxis(
        full_bounded, current_alignment);
    }
  }
  // member: tpos_inworld
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_uv_msgs__msg__RobotAxis(
        full_bounded, current_alignment);
    }
  }
  // member: imu
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_uv_msgs__msg__ImuData(
        full_bounded, current_alignment);
    }
  }
  // member: thrust
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_uv_msgs__msg__MotorThrust(
        full_bounded, current_alignment);
    }
  }
  // member: pidstate
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_uv_msgs__msg__PidControllersState(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _RobotMotionController__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_uv_msgs__msg__RobotMotionController(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_RobotMotionController = {
  "uv_msgs::msg",
  "RobotMotionController",
  _RobotMotionController__cdr_serialize,
  _RobotMotionController__cdr_deserialize,
  _RobotMotionController__get_serialized_size,
  _RobotMotionController__max_serialized_size
};

static rosidl_message_type_support_t _RobotMotionController__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RobotMotionController,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, uv_msgs, msg, RobotMotionController)() {
  return &_RobotMotionController__type_support;
}

#if defined(__cplusplus)
}
#endif
