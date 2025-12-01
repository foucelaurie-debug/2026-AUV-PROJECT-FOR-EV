// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from uv_msgs:msg/PixelAxis.idl
// generated code does not contain a copyright notice
#include "uv_msgs/msg/detail/pixel_axis__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
uv_msgs__msg__PixelAxis__init(uv_msgs__msg__PixelAxis * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  return true;
}

void
uv_msgs__msg__PixelAxis__fini(uv_msgs__msg__PixelAxis * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
}

bool
uv_msgs__msg__PixelAxis__are_equal(const uv_msgs__msg__PixelAxis * lhs, const uv_msgs__msg__PixelAxis * rhs)
{
  if (!lhs || !rhs) {
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
  return true;
}

bool
uv_msgs__msg__PixelAxis__copy(
  const uv_msgs__msg__PixelAxis * input,
  uv_msgs__msg__PixelAxis * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  return true;
}

uv_msgs__msg__PixelAxis *
uv_msgs__msg__PixelAxis__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__PixelAxis * msg = (uv_msgs__msg__PixelAxis *)allocator.allocate(sizeof(uv_msgs__msg__PixelAxis), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(uv_msgs__msg__PixelAxis));
  bool success = uv_msgs__msg__PixelAxis__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
uv_msgs__msg__PixelAxis__destroy(uv_msgs__msg__PixelAxis * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    uv_msgs__msg__PixelAxis__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
uv_msgs__msg__PixelAxis__Sequence__init(uv_msgs__msg__PixelAxis__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__PixelAxis * data = NULL;

  if (size) {
    data = (uv_msgs__msg__PixelAxis *)allocator.zero_allocate(size, sizeof(uv_msgs__msg__PixelAxis), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = uv_msgs__msg__PixelAxis__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        uv_msgs__msg__PixelAxis__fini(&data[i - 1]);
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
uv_msgs__msg__PixelAxis__Sequence__fini(uv_msgs__msg__PixelAxis__Sequence * array)
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
      uv_msgs__msg__PixelAxis__fini(&array->data[i]);
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

uv_msgs__msg__PixelAxis__Sequence *
uv_msgs__msg__PixelAxis__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__PixelAxis__Sequence * array = (uv_msgs__msg__PixelAxis__Sequence *)allocator.allocate(sizeof(uv_msgs__msg__PixelAxis__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = uv_msgs__msg__PixelAxis__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
uv_msgs__msg__PixelAxis__Sequence__destroy(uv_msgs__msg__PixelAxis__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    uv_msgs__msg__PixelAxis__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
uv_msgs__msg__PixelAxis__Sequence__are_equal(const uv_msgs__msg__PixelAxis__Sequence * lhs, const uv_msgs__msg__PixelAxis__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!uv_msgs__msg__PixelAxis__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
uv_msgs__msg__PixelAxis__Sequence__copy(
  const uv_msgs__msg__PixelAxis__Sequence * input,
  uv_msgs__msg__PixelAxis__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(uv_msgs__msg__PixelAxis);
    uv_msgs__msg__PixelAxis * data =
      (uv_msgs__msg__PixelAxis *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!uv_msgs__msg__PixelAxis__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          uv_msgs__msg__PixelAxis__fini(&data[i]);
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
    if (!uv_msgs__msg__PixelAxis__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
