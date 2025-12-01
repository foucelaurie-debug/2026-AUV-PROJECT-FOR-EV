// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from uv_msgs:srv/DetectRequest.idl
// generated code does not contain a copyright notice

#ifndef UV_MSGS__SRV__DETAIL__DETECT_REQUEST__FUNCTIONS_H_
#define UV_MSGS__SRV__DETAIL__DETECT_REQUEST__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "uv_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "uv_msgs/srv/detail/detect_request__struct.h"

/// Initialize srv/DetectRequest message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * uv_msgs__srv__DetectRequest_Request
 * )) before or use
 * uv_msgs__srv__DetectRequest_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_uv_msgs
bool
uv_msgs__srv__DetectRequest_Request__init(uv_msgs__srv__DetectRequest_Request * msg);

/// Finalize srv/DetectRequest message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uv_msgs
void
uv_msgs__srv__DetectRequest_Request__fini(uv_msgs__srv__DetectRequest_Request * msg);

/// Create srv/DetectRequest message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * uv_msgs__srv__DetectRequest_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_uv_msgs
uv_msgs__srv__DetectRequest_Request *
uv_msgs__srv__DetectRequest_Request__create();

/// Destroy srv/DetectRequest message.
/**
 * It calls
 * uv_msgs__srv__DetectRequest_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uv_msgs
void
uv_msgs__srv__DetectRequest_Request__destroy(uv_msgs__srv__DetectRequest_Request * msg);

/// Check for srv/DetectRequest message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_uv_msgs
bool
uv_msgs__srv__DetectRequest_Request__are_equal(const uv_msgs__srv__DetectRequest_Request * lhs, const uv_msgs__srv__DetectRequest_Request * rhs);

/// Copy a srv/DetectRequest message.
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
uv_msgs__srv__DetectRequest_Request__copy(
  const uv_msgs__srv__DetectRequest_Request * input,
  uv_msgs__srv__DetectRequest_Request * output);

/// Initialize array of srv/DetectRequest messages.
/**
 * It allocates the memory for the number of elements and calls
 * uv_msgs__srv__DetectRequest_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_uv_msgs
bool
uv_msgs__srv__DetectRequest_Request__Sequence__init(uv_msgs__srv__DetectRequest_Request__Sequence * array, size_t size);

/// Finalize array of srv/DetectRequest messages.
/**
 * It calls
 * uv_msgs__srv__DetectRequest_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uv_msgs
void
uv_msgs__srv__DetectRequest_Request__Sequence__fini(uv_msgs__srv__DetectRequest_Request__Sequence * array);

/// Create array of srv/DetectRequest messages.
/**
 * It allocates the memory for the array and calls
 * uv_msgs__srv__DetectRequest_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_uv_msgs
uv_msgs__srv__DetectRequest_Request__Sequence *
uv_msgs__srv__DetectRequest_Request__Sequence__create(size_t size);

/// Destroy array of srv/DetectRequest messages.
/**
 * It calls
 * uv_msgs__srv__DetectRequest_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uv_msgs
void
uv_msgs__srv__DetectRequest_Request__Sequence__destroy(uv_msgs__srv__DetectRequest_Request__Sequence * array);

/// Check for srv/DetectRequest message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_uv_msgs
bool
uv_msgs__srv__DetectRequest_Request__Sequence__are_equal(const uv_msgs__srv__DetectRequest_Request__Sequence * lhs, const uv_msgs__srv__DetectRequest_Request__Sequence * rhs);

/// Copy an array of srv/DetectRequest messages.
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
uv_msgs__srv__DetectRequest_Request__Sequence__copy(
  const uv_msgs__srv__DetectRequest_Request__Sequence * input,
  uv_msgs__srv__DetectRequest_Request__Sequence * output);

/// Initialize srv/DetectRequest message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * uv_msgs__srv__DetectRequest_Response
 * )) before or use
 * uv_msgs__srv__DetectRequest_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_uv_msgs
bool
uv_msgs__srv__DetectRequest_Response__init(uv_msgs__srv__DetectRequest_Response * msg);

/// Finalize srv/DetectRequest message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uv_msgs
void
uv_msgs__srv__DetectRequest_Response__fini(uv_msgs__srv__DetectRequest_Response * msg);

/// Create srv/DetectRequest message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * uv_msgs__srv__DetectRequest_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_uv_msgs
uv_msgs__srv__DetectRequest_Response *
uv_msgs__srv__DetectRequest_Response__create();

/// Destroy srv/DetectRequest message.
/**
 * It calls
 * uv_msgs__srv__DetectRequest_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uv_msgs
void
uv_msgs__srv__DetectRequest_Response__destroy(uv_msgs__srv__DetectRequest_Response * msg);

/// Check for srv/DetectRequest message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_uv_msgs
bool
uv_msgs__srv__DetectRequest_Response__are_equal(const uv_msgs__srv__DetectRequest_Response * lhs, const uv_msgs__srv__DetectRequest_Response * rhs);

/// Copy a srv/DetectRequest message.
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
uv_msgs__srv__DetectRequest_Response__copy(
  const uv_msgs__srv__DetectRequest_Response * input,
  uv_msgs__srv__DetectRequest_Response * output);

/// Initialize array of srv/DetectRequest messages.
/**
 * It allocates the memory for the number of elements and calls
 * uv_msgs__srv__DetectRequest_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_uv_msgs
bool
uv_msgs__srv__DetectRequest_Response__Sequence__init(uv_msgs__srv__DetectRequest_Response__Sequence * array, size_t size);

/// Finalize array of srv/DetectRequest messages.
/**
 * It calls
 * uv_msgs__srv__DetectRequest_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uv_msgs
void
uv_msgs__srv__DetectRequest_Response__Sequence__fini(uv_msgs__srv__DetectRequest_Response__Sequence * array);

/// Create array of srv/DetectRequest messages.
/**
 * It allocates the memory for the array and calls
 * uv_msgs__srv__DetectRequest_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_uv_msgs
uv_msgs__srv__DetectRequest_Response__Sequence *
uv_msgs__srv__DetectRequest_Response__Sequence__create(size_t size);

/// Destroy array of srv/DetectRequest messages.
/**
 * It calls
 * uv_msgs__srv__DetectRequest_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_uv_msgs
void
uv_msgs__srv__DetectRequest_Response__Sequence__destroy(uv_msgs__srv__DetectRequest_Response__Sequence * array);

/// Check for srv/DetectRequest message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_uv_msgs
bool
uv_msgs__srv__DetectRequest_Response__Sequence__are_equal(const uv_msgs__srv__DetectRequest_Response__Sequence * lhs, const uv_msgs__srv__DetectRequest_Response__Sequence * rhs);

/// Copy an array of srv/DetectRequest messages.
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
uv_msgs__srv__DetectRequest_Response__Sequence__copy(
  const uv_msgs__srv__DetectRequest_Response__Sequence * input,
  uv_msgs__srv__DetectRequest_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // UV_MSGS__SRV__DETAIL__DETECT_REQUEST__FUNCTIONS_H_
