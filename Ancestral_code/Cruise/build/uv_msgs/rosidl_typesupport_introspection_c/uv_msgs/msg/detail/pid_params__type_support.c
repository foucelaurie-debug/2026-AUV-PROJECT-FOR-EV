// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from uv_msgs:msg/PidParams.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "uv_msgs/msg/detail/pid_params__rosidl_typesupport_introspection_c.h"
#include "uv_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "uv_msgs/msg/detail/pid_params__functions.h"
#include "uv_msgs/msg/detail/pid_params__struct.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void PidParams__rosidl_typesupport_introspection_c__PidParams_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  uv_msgs__msg__PidParams__init(message_memory);
}

void PidParams__rosidl_typesupport_introspection_c__PidParams_fini_function(void * message_memory)
{
  uv_msgs__msg__PidParams__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember PidParams__rosidl_typesupport_introspection_c__PidParams_message_member_array[6] = {
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uv_msgs__msg__PidParams, name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "p",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uv_msgs__msg__PidParams, p),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "i",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uv_msgs__msg__PidParams, i),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "d",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uv_msgs__msg__PidParams, d),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "i_limit",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uv_msgs__msg__PidParams, i_limit),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "output_limit",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uv_msgs__msg__PidParams, output_limit),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers PidParams__rosidl_typesupport_introspection_c__PidParams_message_members = {
  "uv_msgs__msg",  // message namespace
  "PidParams",  // message name
  6,  // number of fields
  sizeof(uv_msgs__msg__PidParams),
  PidParams__rosidl_typesupport_introspection_c__PidParams_message_member_array,  // message members
  PidParams__rosidl_typesupport_introspection_c__PidParams_init_function,  // function to initialize message memory (memory has to be allocated)
  PidParams__rosidl_typesupport_introspection_c__PidParams_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t PidParams__rosidl_typesupport_introspection_c__PidParams_message_type_support_handle = {
  0,
  &PidParams__rosidl_typesupport_introspection_c__PidParams_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_uv_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uv_msgs, msg, PidParams)() {
  if (!PidParams__rosidl_typesupport_introspection_c__PidParams_message_type_support_handle.typesupport_identifier) {
    PidParams__rosidl_typesupport_introspection_c__PidParams_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &PidParams__rosidl_typesupport_introspection_c__PidParams_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
