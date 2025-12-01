// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from uv_msgs:msg/PidControllers.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "uv_msgs/msg/detail/pid_controllers__rosidl_typesupport_introspection_c.h"
#include "uv_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "uv_msgs/msg/detail/pid_controllers__functions.h"
#include "uv_msgs/msg/detail/pid_controllers__struct.h"


// Include directives for member types
// Member `x`
// Member `y`
// Member `z`
// Member `rx`
// Member `ry`
// Member `rz`
// Member `vx`
// Member `vy`
#include "uv_msgs/msg/pid_params.h"
// Member `x`
// Member `y`
// Member `z`
// Member `rx`
// Member `ry`
// Member `rz`
// Member `vx`
// Member `vy`
#include "uv_msgs/msg/detail/pid_params__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void PidControllers__rosidl_typesupport_introspection_c__PidControllers_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  uv_msgs__msg__PidControllers__init(message_memory);
}

void PidControllers__rosidl_typesupport_introspection_c__PidControllers_fini_function(void * message_memory)
{
  uv_msgs__msg__PidControllers__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember PidControllers__rosidl_typesupport_introspection_c__PidControllers_message_member_array[8] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uv_msgs__msg__PidControllers, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uv_msgs__msg__PidControllers, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uv_msgs__msg__PidControllers, z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rx",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uv_msgs__msg__PidControllers, rx),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ry",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uv_msgs__msg__PidControllers, ry),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rz",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uv_msgs__msg__PidControllers, rz),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vx",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uv_msgs__msg__PidControllers, vx),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vy",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uv_msgs__msg__PidControllers, vy),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers PidControllers__rosidl_typesupport_introspection_c__PidControllers_message_members = {
  "uv_msgs__msg",  // message namespace
  "PidControllers",  // message name
  8,  // number of fields
  sizeof(uv_msgs__msg__PidControllers),
  PidControllers__rosidl_typesupport_introspection_c__PidControllers_message_member_array,  // message members
  PidControllers__rosidl_typesupport_introspection_c__PidControllers_init_function,  // function to initialize message memory (memory has to be allocated)
  PidControllers__rosidl_typesupport_introspection_c__PidControllers_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t PidControllers__rosidl_typesupport_introspection_c__PidControllers_message_type_support_handle = {
  0,
  &PidControllers__rosidl_typesupport_introspection_c__PidControllers_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_uv_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uv_msgs, msg, PidControllers)() {
  PidControllers__rosidl_typesupport_introspection_c__PidControllers_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uv_msgs, msg, PidParams)();
  PidControllers__rosidl_typesupport_introspection_c__PidControllers_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uv_msgs, msg, PidParams)();
  PidControllers__rosidl_typesupport_introspection_c__PidControllers_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uv_msgs, msg, PidParams)();
  PidControllers__rosidl_typesupport_introspection_c__PidControllers_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uv_msgs, msg, PidParams)();
  PidControllers__rosidl_typesupport_introspection_c__PidControllers_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uv_msgs, msg, PidParams)();
  PidControllers__rosidl_typesupport_introspection_c__PidControllers_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uv_msgs, msg, PidParams)();
  PidControllers__rosidl_typesupport_introspection_c__PidControllers_message_member_array[6].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uv_msgs, msg, PidParams)();
  PidControllers__rosidl_typesupport_introspection_c__PidControllers_message_member_array[7].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uv_msgs, msg, PidParams)();
  if (!PidControllers__rosidl_typesupport_introspection_c__PidControllers_message_type_support_handle.typesupport_identifier) {
    PidControllers__rosidl_typesupport_introspection_c__PidControllers_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &PidControllers__rosidl_typesupport_introspection_c__PidControllers_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
