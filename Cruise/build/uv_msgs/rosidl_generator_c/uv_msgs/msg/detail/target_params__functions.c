// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from uv_msgs:msg/TargetParams.idl
// generated code does not contain a copyright notice
#include "uv_msgs/msg/detail/target_params__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `tpos_inpic`
#include "uv_msgs/msg/detail/pixel_axis__functions.h"
// Member `tpos_inworld`
#include "uv_msgs/msg/detail/target_axis__functions.h"

bool
uv_msgs__msg__TargetParams__init(uv_msgs__msg__TargetParams * msg)
{
  if (!msg) {
    return false;
  }
  // tpos_inpic
  if (!uv_msgs__msg__PixelAxis__init(&msg->tpos_inpic)) {
    uv_msgs__msg__TargetParams__fini(msg);
    return false;
  }
  // tpos_inworld
  if (!uv_msgs__msg__TargetAxis__init(&msg->tpos_inworld)) {
    uv_msgs__msg__TargetParams__fini(msg);
    return false;
  }
  return true;
}

void
uv_msgs__msg__TargetParams__fini(uv_msgs__msg__TargetParams * msg)
{
  if (!msg) {
    return;
  }
  // tpos_inpic
  uv_msgs__msg__PixelAxis__fini(&msg->tpos_inpic);
  // tpos_inworld
  uv_msgs__msg__TargetAxis__fini(&msg->tpos_inworld);
}

bool
uv_msgs__msg__TargetParams__are_equal(const uv_msgs__msg__TargetParams * lhs, const uv_msgs__msg__TargetParams * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // tpos_inpic
  if (!uv_msgs__msg__PixelAxis__are_equal(
      &(lhs->tpos_inpic), &(rhs->tpos_inpic)))
  {
    return false;
  }
  // tpos_inworld
  if (!uv_msgs__msg__TargetAxis__are_equal(
      &(lhs->tpos_inworld), &(rhs->tpos_inworld)))
  {
    return false;
  }
  return true;
}

bool
uv_msgs__msg__TargetParams__copy(
  const uv_msgs__msg__TargetParams * input,
  uv_msgs__msg__TargetParams * output)
{
  if (!input || !output) {
    return false;
  }
  // tpos_inpic
  if (!uv_msgs__msg__PixelAxis__copy(
      &(input->tpos_inpic), &(output->tpos_inpic)))
  {
    return false;
  }
  // tpos_inworld
  if (!uv_msgs__msg__TargetAxis__copy(
      &(input->tpos_inworld), &(output->tpos_inworld)))
  {
    return false;
  }
  return true;
}

uv_msgs__msg__TargetParams *
uv_msgs__msg__TargetParams__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__TargetParams * msg = (uv_msgs__msg__TargetParams *)allocator.allocate(sizeof(uv_msgs__msg__TargetParams), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(uv_msgs__msg__TargetParams));
  bool success = uv_msgs__msg__TargetParams__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
uv_msgs__msg__TargetParams__destroy(uv_msgs__msg__TargetParams * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    uv_msgs__msg__TargetParams__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
uv_msgs__msg__TargetParams__Sequence__init(uv_msgs__msg__TargetParams__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__TargetParams * data = NULL;

  if (size) {
    data = (uv_msgs__msg__TargetParams *)allocator.zero_allocate(size, sizeof(uv_msgs__msg__TargetParams), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = uv_msgs__msg__TargetParams__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        uv_msgs__msg__TargetParams__fini(&data[i - 1]);
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
uv_msgs__msg__TargetParams__Sequence__fini(uv_msgs__msg__TargetParams__Sequence * array)
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
      uv_msgs__msg__TargetParams__fini(&array->data[i]);
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

uv_msgs__msg__TargetParams__Sequence *
uv_msgs__msg__TargetParams__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__TargetParams__Sequence * array = (uv_msgs__msg__TargetParams__Sequence *)allocator.allocate(sizeof(uv_msgs__msg__TargetParams__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = uv_msgs__msg__TargetParams__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
uv_msgs__msg__TargetParams__Sequence__destroy(uv_msgs__msg__TargetParams__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    uv_msgs__msg__TargetParams__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
uv_msgs__msg__TargetParams__Sequence__are_equal(const uv_msgs__msg__TargetParams__Sequence * lhs, const uv_msgs__msg__TargetParams__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!uv_msgs__msg__TargetParams__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
uv_msgs__msg__TargetParams__Sequence__copy(
  const uv_msgs__msg__TargetParams__Sequence * input,
  uv_msgs__msg__TargetParams__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(uv_msgs__msg__TargetParams);
    uv_msgs__msg__TargetParams * data =
      (uv_msgs__msg__TargetParams *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!uv_msgs__msg__TargetParams__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          uv_msgs__msg__TargetParams__fini(&data[i]);
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
    if (!uv_msgs__msg__TargetParams__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
