// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from uv_msgs:msg/RobotMotionController.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "uv_msgs/msg/detail/robot_motion_controller__rosidl_typesupport_introspection_c.h"
#include "uv_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "uv_msgs/msg/detail/robot_motion_controller__functions.h"
#include "uv_msgs/msg/detail/robot_motion_controller__struct.h"


// Include directives for member types
// Member `pos`
// Member `tpos_inbase`
// Member `tpos_inworld`
#include "uv_msgs/msg/robot_axis.h"
// Member `pos`
// Member `tpos_inbase`
// Member `tpos_inworld`
#include "uv_msgs/msg/detail/robot_axis__rosidl_typesupport_introspection_c.h"
// Member `imu`
#include "uv_msgs/msg/imu_data.h"
// Member `imu`
#include "uv_msgs/msg/detail/imu_data__rosidl_typesupport_introspection_c.h"
// Member `thrust`
#include "uv_msgs/msg/motor_thrust.h"
// Member `thrust`
#include "uv_msgs/msg/detail/motor_thrust__rosidl_typesupport_introspection_c.h"
// Member `pidstate`
#include "uv_msgs/msg/pid_controllers_state.h"
// Member `pidstate`
#include "uv_msgs/msg/detail/pid_controllers_state__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RobotMotionController__rosidl_typesupport_introspection_c__RobotMotionController_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  uv_msgs__msg__RobotMotionController__init(message_memory);
}

void RobotMotionController__rosidl_typesupport_introspection_c__RobotMotionController_fini_function(void * message_memory)
{
  uv_msgs__msg__RobotMotionController__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember RobotMotionController__rosidl_typesupport_introspection_c__RobotMotionController_message_member_array[6] = {
  {
    "pos",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uv_msgs__msg__RobotMotionController, pos),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tpos_inbase",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uv_msgs__msg__RobotMotionController, tpos_inbase),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tpos_inworld",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uv_msgs__msg__RobotMotionController, tpos_inworld),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "imu",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uv_msgs__msg__RobotMotionController, imu),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "thrust",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uv_msgs__msg__RobotMotionController, thrust),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pidstate",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uv_msgs__msg__RobotMotionController, pidstate),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers RobotMotionController__rosidl_typesupport_introspection_c__RobotMotionController_message_members = {
  "uv_msgs__msg",  // message namespace
  "RobotMotionController",  // message name
  6,  // number of fields
  sizeof(uv_msgs__msg__RobotMotionController),
  RobotMotionController__rosidl_typesupport_introspection_c__RobotMotionController_message_member_array,  // message members
  RobotMotionController__rosidl_typesupport_introspection_c__RobotMotionController_init_function,  // function to initialize message memory (memory has to be allocated)
  RobotMotionController__rosidl_typesupport_introspection_c__RobotMotionController_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t RobotMotionController__rosidl_typesupport_introspection_c__RobotMotionController_message_type_support_handle = {
  0,
  &RobotMotionController__rosidl_typesupport_introspection_c__RobotMotionController_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_uv_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uv_msgs, msg, RobotMotionController)() {
  RobotMotionController__rosidl_typesupport_introspection_c__RobotMotionController_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uv_msgs, msg, RobotAxis)();
  RobotMotionController__rosidl_typesupport_introspection_c__RobotMotionController_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uv_msgs, msg, RobotAxis)();
  RobotMotionController__rosidl_typesupport_introspection_c__RobotMotionController_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uv_msgs, msg, RobotAxis)();
  RobotMotionController__rosidl_typesupport_introspection_c__RobotMotionController_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uv_msgs, msg, ImuData)();
  RobotMotionController__rosidl_typesupport_introspection_c__RobotMotionController_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uv_msgs, msg, MotorThrust)();
  RobotMotionController__rosidl_typesupport_introspection_c__RobotMotionController_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uv_msgs, msg, PidControllersState)();
  if (!RobotMotionController__rosidl_typesupport_introspection_c__RobotMotionController_message_type_support_handle.typesupport_identifier) {
    RobotMotionController__rosidl_typesupport_introspection_c__RobotMotionController_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &RobotMotionController__rosidl_typesupport_introspection_c__RobotMotionController_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
