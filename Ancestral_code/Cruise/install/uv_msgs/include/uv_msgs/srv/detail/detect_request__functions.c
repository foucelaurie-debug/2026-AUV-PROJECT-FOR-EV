// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from uv_msgs:srv/DetectRequest.idl
// generated code does not contain a copyright notice
#include "uv_msgs/srv/detail/detect_request__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `imagein`
#include "sensor_msgs/msg/detail/image__functions.h"
// Member `target`
// Member `stero`
#include "rosidl_runtime_c/string_functions.h"

bool
uv_msgs__srv__DetectRequest_Request__init(uv_msgs__srv__DetectRequest_Request * msg)
{
  if (!msg) {
    return false;
  }
  // imagein
  if (!sensor_msgs__msg__Image__init(&msg->imagein)) {
    uv_msgs__srv__DetectRequest_Request__fini(msg);
    return false;
  }
  // target
  if (!rosidl_runtime_c__String__init(&msg->target)) {
    uv_msgs__srv__DetectRequest_Request__fini(msg);
    return false;
  }
  // stero
  if (!rosidl_runtime_c__String__init(&msg->stero)) {
    uv_msgs__srv__DetectRequest_Request__fini(msg);
    return false;
  }
  return true;
}

void
uv_msgs__srv__DetectRequest_Request__fini(uv_msgs__srv__DetectRequest_Request * msg)
{
  if (!msg) {
    return;
  }
  // imagein
  sensor_msgs__msg__Image__fini(&msg->imagein);
  // target
  rosidl_runtime_c__String__fini(&msg->target);
  // stero
  rosidl_runtime_c__String__fini(&msg->stero);
}

bool
uv_msgs__srv__DetectRequest_Request__are_equal(const uv_msgs__srv__DetectRequest_Request * lhs, const uv_msgs__srv__DetectRequest_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // imagein
  if (!sensor_msgs__msg__Image__are_equal(
      &(lhs->imagein), &(rhs->imagein)))
  {
    return false;
  }
  // target
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->target), &(rhs->target)))
  {
    return false;
  }
  // stero
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->stero), &(rhs->stero)))
  {
    return false;
  }
  return true;
}

bool
uv_msgs__srv__DetectRequest_Request__copy(
  const uv_msgs__srv__DetectRequest_Request * input,
  uv_msgs__srv__DetectRequest_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // imagein
  if (!sensor_msgs__msg__Image__copy(
      &(input->imagein), &(output->imagein)))
  {
    return false;
  }
  // target
  if (!rosidl_runtime_c__String__copy(
      &(input->target), &(output->target)))
  {
    return false;
  }
  // stero
  if (!rosidl_runtime_c__String__copy(
      &(input->stero), &(output->stero)))
  {
    return false;
  }
  return true;
}

uv_msgs__srv__DetectRequest_Request *
uv_msgs__srv__DetectRequest_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__srv__DetectRequest_Request * msg = (uv_msgs__srv__DetectRequest_Request *)allocator.allocate(sizeof(uv_msgs__srv__DetectRequest_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(uv_msgs__srv__DetectRequest_Request));
  bool success = uv_msgs__srv__DetectRequest_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
uv_msgs__srv__DetectRequest_Request__destroy(uv_msgs__srv__DetectRequest_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    uv_msgs__srv__DetectRequest_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
uv_msgs__srv__DetectRequest_Request__Sequence__init(uv_msgs__srv__DetectRequest_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__srv__DetectRequest_Request * data = NULL;

  if (size) {
    data = (uv_msgs__srv__DetectRequest_Request *)allocator.zero_allocate(size, sizeof(uv_msgs__srv__DetectRequest_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = uv_msgs__srv__DetectRequest_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        uv_msgs__srv__DetectRequest_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
uv_msgs__srv__DetectRequest_Request__Sequence__fini(uv_msgs__srv__DetectRequest_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      uv_msgs__srv__DetectRequest_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

uv_msgs__srv__DetectRequest_Request__Sequence *
uv_msgs__srv__DetectRequest_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__srv__DetectRequest_Request__Sequence * array = (uv_msgs__srv__DetectRequest_Request__Sequence *)allocator.allocate(sizeof(uv_msgs__srv__DetectRequest_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = uv_msgs__srv__DetectRequest_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
uv_msgs__srv__DetectRequest_Request__Sequence__destroy(uv_msgs__srv__DetectRequest_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    uv_msgs__srv__DetectRequest_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
uv_msgs__srv__DetectRequest_Request__Sequence__are_equal(const uv_msgs__srv__DetectRequest_Request__Sequence * lhs, const uv_msgs__srv__DetectRequest_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!uv_msgs__srv__DetectRequest_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
uv_msgs__srv__DetectRequest_Request__Sequence__copy(
  const uv_msgs__srv__DetectRequest_Request__Sequence * input,
  uv_msgs__srv__DetectRequest_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(uv_msgs__srv__DetectRequest_Request);
    uv_msgs__srv__DetectRequest_Request * data =
      (uv_msgs__srv__DetectRequest_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!uv_msgs__srv__DetectRequest_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          uv_msgs__srv__DetectRequest_Request__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!uv_msgs__srv__DetectRequest_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
uv_msgs__srv__DetectRequest_Response__init(uv_msgs__srv__DetectRequest_Response * msg)
{
  if (!msg) {
    return false;
  }
  // s
  // x
  // y
  // z
  return true;
}

void
uv_msgs__srv__DetectRequest_Response__fini(uv_msgs__srv__DetectRequest_Response * msg)
{
  if (!msg) {
    return;
  }
  // s
  // x
  // y
  // z
}

bool
uv_msgs__srv__DetectRequest_Response__are_equal(const uv_msgs__srv__DetectRequest_Response * lhs, const uv_msgs__srv__DetectRequest_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // s
  if (lhs->s != rhs->s) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  return true;
}

bool
uv_msgs__srv__DetectRequest_Response__copy(
  const uv_msgs__srv__DetectRequest_Response * input,
  uv_msgs__srv__DetectRequest_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // s
  output->s = input->s;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  return true;
}

uv_msgs__srv__DetectRequest_Response *
uv_msgs__srv__DetectRequest_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__srv__DetectRequest_Response * msg = (uv_msgs__srv__DetectRequest_Response *)allocator.allocate(sizeof(uv_msgs__srv__DetectRequest_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(uv_msgs__srv__DetectRequest_Response));
  bool success = uv_msgs__srv__DetectRequest_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
uv_msgs__srv__DetectRequest_Response__destroy(uv_msgs__srv__DetectRequest_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    uv_msgs__srv__DetectRequest_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
uv_msgs__srv__DetectRequest_Response__Sequence__init(uv_msgs__srv__DetectRequest_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__srv__DetectRequest_Response * data = NULL;

  if (size) {
    data = (uv_msgs__srv__DetectRequest_Response *)allocator.zero_allocate(size, sizeof(uv_msgs__srv__DetectRequest_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = uv_msgs__srv__DetectRequest_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        uv_msgs__srv__DetectRequest_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
uv_msgs__srv__DetectRequest_Response__Sequence__fini(uv_msgs__srv__DetectRequest_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      uv_msgs__srv__DetectRequest_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

uv_msgs__srv__DetectRequest_Response__Sequence *
uv_msgs__srv__DetectRequest_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__srv__DetectRequest_Response__Sequence * array = (uv_msgs__srv__DetectRequest_Response__Sequence *)allocator.allocate(sizeof(uv_msgs__srv__DetectRequest_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = uv_msgs__srv__DetectRequest_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
uv_msgs__srv__DetectRequest_Response__Sequence__destroy(uv_msgs__srv__DetectRequest_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    uv_msgs__srv__DetectRequest_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
uv_msgs__srv__DetectRequest_Response__Sequence__are_equal(const uv_msgs__srv__DetectRequest_Response__Sequence * lhs, const uv_msgs__srv__DetectRequest_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!uv_msgs__srv__DetectRequest_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
uv_msgs__srv__DetectRequest_Response__Sequence__copy(
  const uv_msgs__srv__DetectRequest_Response__Sequence * input,
  uv_msgs__srv__DetectRequest_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(uv_msgs__srv__DetectRequest_Response);
    uv_msgs__srv__DetectRequest_Response * data =
      (uv_msgs__srv__DetectRequest_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!uv_msgs__srv__DetectRequest_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          uv_msgs__srv__DetectRequest_Response__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!uv_msgs__srv__DetectRequest_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
