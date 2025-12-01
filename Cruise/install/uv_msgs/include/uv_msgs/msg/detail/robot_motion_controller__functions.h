// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from uv_msgs:msg/RobotMotionController.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__MSG__DETAIL__ROBOT_MOTION_CONTROLLER__FUNCTIONS_H_
#define UV_MSGS__MSG__DETAIL__ROBOT_MOTION_CONTROLLER__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "uv_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "uv_msgs/msg/detail/robot_motion_controller__struct.h"

/// Initialize msg/RobotMotionController message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * uv_msgs__msg__RobotMotionController
 * )) before or use
 * uv_msgs__msg__RobotMotionController__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_uv_msgs
bool
uv_msgs__msg__RobotMotionController__init(uv_msgs__msg__RobotMotionController * msg);

/// Finalize msg/RobotMotionController message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uv_msgs
void
uv_msgs__msg__RobotMotionController__fini(uv_msgs__msg__RobotMotionController * msg);

/// Create msg/RobotMotionController message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * uv_msgs__msg__RobotMotionController__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_uv_msgs
uv_msgs__msg__RobotMotionController *
uv_msgs__msg__RobotMotionController__create();

/// Destroy msg/RobotMotionController message.
/**
 * It calls
 * uv_msgs__msg__RobotMotionController__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uv_msgs
void
uv_msgs__msg__RobotMotionController__destroy(uv_msgs__msg__RobotMotionController * msg);

/// Check for msg/RobotMotionController message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_uv_msgs
bool
uv_msgs__msg__RobotMotionController__are_equal(const uv_msgs__msg__RobotMotionController * lhs, const uv_msgs__msg__RobotMotionController * rhs);

/// Copy a msg/RobotMotionController message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_uv_msgs
bool
uv_msgs__msg__RobotMotionController__copy(
  const uv_msgs__msg__RobotMotionController * input,
  uv_msgs__msg__RobotMotionController * output);

/// Initialize array of msg/RobotMotionController messages.
/**
 * It allocates the memory for the number of elements and calls
 * uv_msgs__msg__RobotMotionController__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_uv_msgs
bool
uv_msgs__msg__RobotMotionController__Sequence__init(uv_msgs__msg__RobotMotionController__Sequence * array, size_t size);

/// Finalize array of msg/RobotMotionController messages.
/**
 * It calls
 * uv_msgs__msg__RobotMotionController__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uv_msgs
void
uv_msgs__msg__RobotMotionController__Sequence__fini(uv_msgs__msg__RobotMotionController__Sequence * array);

/// Create array of msg/RobotMotionController messages.
/**
 * It allocates the memory for the array and calls
 * uv_msgs__msg__RobotMotionController__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_uv_msgs
uv_msgs__msg__RobotMotionController__Sequence *
uv_msgs__msg__RobotMotionController__Sequence__create(size_t size);

/// Destroy array of msg/RobotMotionController messages.
/**
 * It calls
 * uv_msgs__msg__RobotMotionController__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uv_msgs
void
uv_msgs__msg__RobotMotionController__Sequence__destroy(uv_msgs__msg__RobotMotionController__Sequence * array);

/// Check for msg/RobotMotionController message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_uv_msgs
bool
uv_msgs__msg__RobotMotionController__Sequence__are_equal(const uv_msgs__msg__RobotMotionController__Sequence * lhs, const uv_msgs__msg__RobotMotionController__Sequence * rhs);

/// Copy an array of msg/RobotMotionController messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_uv_msgs
bool
uv_msgs__msg__RobotMotionController__Sequence__copy(
  const uv_msgs__msg__RobotMotionController__Sequence * input,
  uv_msgs__msg__RobotMotionController__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // UV_MSGS__MSG__DETAIL__ROBOT_MOTION_CONTROLLER__FUNCTIONS_H_
