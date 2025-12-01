// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from uv_msgs:msg/Yolov8.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "uv_msgs/msg/detail/yolov8__rosidl_typesupport_introspection_c.h"
#include "uv_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "uv_msgs/msg/detail/yolov8__functions.h"
#include "uv_msgs/msg/detail/yolov8__struct.h"


// Include directives for member types
// Member `targets`
#include "uv_msgs/msg/target_params.h"
// Member `targets`
#include "uv_msgs/msg/detail/target_params__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void Yolov8__rosidl_typesupport_introspection_c__Yolov8_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  uv_msgs__msg__Yolov8__init(message_memory);
}

void Yolov8__rosidl_typesupport_introspection_c__Yolov8_fini_function(void * message_memory)
{
  uv_msgs__msg__Yolov8__fini(message_memory);
}

size_t Yolov8__rosidl_typesupport_introspection_c__size_function__TargetParams__targets(
  const void * untyped_member)
{
  (void)untyped_member;
  return 11;
}

const void * Yolov8__rosidl_typesupport_introspection_c__get_const_function__TargetParams__targets(
  const void * untyped_member, size_t index)
{
  const uv_msgs__msg__TargetParams ** member =
    (const uv_msgs__msg__TargetParams **)(untyped_member);
  return &(*member)[index];
}

void * Yolov8__rosidl_typesupport_introspection_c__get_function__TargetParams__targets(
  void * untyped_member, size_t index)
{
  uv_msgs__msg__TargetParams ** member =
    (uv_msgs__msg__TargetParams **)(untyped_member);
  return &(*member)[index];
}

static rosidl_typesupport_introspection_c__MessageMember Yolov8__rosidl_typesupport_introspection_c__Yolov8_message_member_array[2] = {
  {
    "state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    11,  // array size
    false,  // is upper bound
    offsetof(uv_msgs__msg__Yolov8, state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "targets",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    11,  // array size
    false,  // is upper bound
    offsetof(uv_msgs__msg__Yolov8, targets),  // bytes offset in struct
    NULL,  // default value
    Yolov8__rosidl_typesupport_introspection_c__size_function__TargetParams__targets,  // size() function pointer
    Yolov8__rosidl_typesupport_introspection_c__get_const_function__TargetParams__targets,  // get_const(index) function pointer
    Yolov8__rosidl_typesupport_introspection_c__get_function__TargetParams__targets,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Yolov8__rosidl_typesupport_introspection_c__Yolov8_message_members = {
  "uv_msgs__msg",  // message namespace
  "Yolov8",  // message name
  2,  // number of fields
  sizeof(uv_msgs__msg__Yolov8),
  Yolov8__rosidl_typesupport_introspection_c__Yolov8_message_member_array,  // message members
  Yolov8__rosidl_typesupport_introspection_c__Yolov8_init_function,  // function to initialize message memory (memory has to be allocated)
  Yolov8__rosidl_typesupport_introspection_c__Yolov8_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Yolov8__rosidl_typesupport_introspection_c__Yolov8_message_type_support_handle = {
  0,
  &Yolov8__rosidl_typesupport_introspection_c__Yolov8_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_uv_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uv_msgs, msg, Yolov8)() {
  Yolov8__rosidl_typesupport_introspection_c__Yolov8_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, uv_msgs, msg, TargetParams)();
  if (!Yolov8__rosidl_typesupport_introspection_c__Yolov8_message_type_support_handle.typesupport_identifier) {
    Yolov8__rosidl_typesupport_introspection_c__Yolov8_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Yolov8__rosidl_typesupport_introspection_c__Yolov8_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
