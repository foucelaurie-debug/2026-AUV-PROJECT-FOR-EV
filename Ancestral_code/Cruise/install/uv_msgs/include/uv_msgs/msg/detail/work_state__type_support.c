// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from uv_msgs:msg/WorkState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "uv_msgs/msg/detail/work_state__rosidl_typesupport_introspection_c.h"
#include "uv_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "uv_msgs/msg/detail/work_state__functions.h"
#include "uv_msgs/msg/detail/work_state__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void WorkState__rosidl_typesupport_introspection_c__WorkState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  uv_msgs__msg__WorkState__init(message_memory);
}

void WorkState__rosidl_typesupport_introspection_c__WorkState_fini_function(void * message_memory)
{
  uv_msgs__msg__WorkState__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember WorkState__rosidl_typesupport_introspection_c__WorkState_message_member_array[1] = {
  {
    "state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(uv_msgs__msg__WorkState, state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers WorkState__rosidl_typesupport_introspection_c__WorkState_message_members = {
  "uv_msgs__msg",  // message namespace
  "WorkState",  // message name
  1,  // number of fields
  sizeof(uv_msgs__msg__WorkState),
  WorkState__rosidl_typesupport_introspection_c__WorkState_message_member_array,  // message members
  WorkState__rosidl_typesupport_introspection_c__WorkState_init_function,  // function to initialize message memory (memory has to be allocated)
  WorkState__rosidl_typesupport_introspection_c__WorkState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t WorkState__rosidl_typesupport_introspection_c__WorkState_message_type_support_handle = {
  0,
  &WorkState__rosidl_typesupport_introspection_c__WorkState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_uv_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uv_msgs, msg, WorkState)() {
  if (!WorkState__rosidl_typesupport_introspection_c__WorkState_message_type_support_handle.typesupport_identifier) {
    WorkState__rosidl_typesupport_introspection_c__WorkState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &WorkState__rosidl_typesupport_introspection_c__WorkState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
