// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from uv_msgs:msg/Yolov8.idl
// generated code does not contain a copyright notice
#include "uv_msgs/msg/detail/yolov8__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `targets`
#include "uv_msgs/msg/detail/target_params__functions.h"

bool
uv_msgs__msg__Yolov8__init(uv_msgs__msg__Yolov8 * msg)
{
  if (!msg) {
    return false;
  }
  // state
  // targets
  for (size_t i = 0; i < 11; ++i) {
    if (!uv_msgs__msg__TargetParams__init(&msg->targets[i])) {
      uv_msgs__msg__Yolov8__fini(msg);
      return false;
    }
  }
  return true;
}

void
uv_msgs__msg__Yolov8__fini(uv_msgs__msg__Yolov8 * msg)
{
  if (!msg) {
    return;
  }
  // state
  // targets
  for (size_t i = 0; i < 11; ++i) {
    uv_msgs__msg__TargetParams__fini(&msg->targets[i]);
  }
}

bool
uv_msgs__msg__Yolov8__are_equal(const uv_msgs__msg__Yolov8 * lhs, const uv_msgs__msg__Yolov8 * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // state
  for (size_t i = 0; i < 11; ++i) {
    if (lhs->state[i] != rhs->state[i]) {
      return false;
    }
  }
  // targets
  for (size_t i = 0; i < 11; ++i) {
    if (!uv_msgs__msg__TargetParams__are_equal(
        &(lhs->targets[i]), &(rhs->targets[i])))
    {
      return false;
    }
  }
  return true;
}

bool
uv_msgs__msg__Yolov8__copy(
  const uv_msgs__msg__Yolov8 * input,
  uv_msgs__msg__Yolov8 * output)
{
  if (!input || !output) {
    return false;
  }
  // state
  for (size_t i = 0; i < 11; ++i) {
    output->state[i] = input->state[i];
  }
  // targets
  for (size_t i = 0; i < 11; ++i) {
    if (!uv_msgs__msg__TargetParams__copy(
        &(input->targets[i]), &(output->targets[i])))
    {
      return false;
    }
  }
  return true;
}

uv_msgs__msg__Yolov8 *
uv_msgs__msg__Yolov8__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__Yolov8 * msg = (uv_msgs__msg__Yolov8 *)allocator.allocate(sizeof(uv_msgs__msg__Yolov8), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(uv_msgs__msg__Yolov8));
  bool success = uv_msgs__msg__Yolov8__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
uv_msgs__msg__Yolov8__destroy(uv_msgs__msg__Yolov8 * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    uv_msgs__msg__Yolov8__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
uv_msgs__msg__Yolov8__Sequence__init(uv_msgs__msg__Yolov8__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__Yolov8 * data = NULL;

  if (size) {
    data = (uv_msgs__msg__Yolov8 *)allocator.zero_allocate(size, sizeof(uv_msgs__msg__Yolov8), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = uv_msgs__msg__Yolov8__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        uv_msgs__msg__Yolov8__fini(&data[i - 1]);
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
uv_msgs__msg__Yolov8__Sequence__fini(uv_msgs__msg__Yolov8__Sequence * array)
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
      uv_msgs__msg__Yolov8__fini(&array->data[i]);
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

uv_msgs__msg__Yolov8__Sequence *
uv_msgs__msg__Yolov8__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__Yolov8__Sequence * array = (uv_msgs__msg__Yolov8__Sequence *)allocator.allocate(sizeof(uv_msgs__msg__Yolov8__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = uv_msgs__msg__Yolov8__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
uv_msgs__msg__Yolov8__Sequence__destroy(uv_msgs__msg__Yolov8__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    uv_msgs__msg__Yolov8__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
uv_msgs__msg__Yolov8__Sequence__are_equal(const uv_msgs__msg__Yolov8__Sequence * lhs, const uv_msgs__msg__Yolov8__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!uv_msgs__msg__Yolov8__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
uv_msgs__msg__Yolov8__Sequence__copy(
  const uv_msgs__msg__Yolov8__Sequence * input,
  uv_msgs__msg__Yolov8__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(uv_msgs__msg__Yolov8);
    uv_msgs__msg__Yolov8 * data =
      (uv_msgs__msg__Yolov8 *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!uv_msgs__msg__Yolov8__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          uv_msgs__msg__Yolov8__fini(&data[i]);
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
    if (!uv_msgs__msg__Yolov8__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
