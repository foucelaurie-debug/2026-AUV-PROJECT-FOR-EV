// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from uv_msgs:msg/LedControllers.idl
// generated code does not contain a copyright notice
#include "uv_msgs/msg/detail/led_controllers__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
uv_msgs__msg__LedControllers__init(uv_msgs__msg__LedControllers * msg)
{
  if (!msg) {
    return false;
  }
  // led0
  // led1
  return true;
}

void
uv_msgs__msg__LedControllers__fini(uv_msgs__msg__LedControllers * msg)
{
  if (!msg) {
    return;
  }
  // led0
  // led1
}

bool
uv_msgs__msg__LedControllers__are_equal(const uv_msgs__msg__LedControllers * lhs, const uv_msgs__msg__LedControllers * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // led0
  if (lhs->led0 != rhs->led0) {
    return false;
  }
  // led1
  if (lhs->led1 != rhs->led1) {
    return false;
  }
  return true;
}

bool
uv_msgs__msg__LedControllers__copy(
  const uv_msgs__msg__LedControllers * input,
  uv_msgs__msg__LedControllers * output)
{
  if (!input || !output) {
    return false;
  }
  // led0
  output->led0 = input->led0;
  // led1
  output->led1 = input->led1;
  return true;
}

uv_msgs__msg__LedControllers *
uv_msgs__msg__LedControllers__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__LedControllers * msg = (uv_msgs__msg__LedControllers *)allocator.allocate(sizeof(uv_msgs__msg__LedControllers), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(uv_msgs__msg__LedControllers));
  bool success = uv_msgs__msg__LedControllers__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
uv_msgs__msg__LedControllers__destroy(uv_msgs__msg__LedControllers * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    uv_msgs__msg__LedControllers__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
uv_msgs__msg__LedControllers__Sequence__init(uv_msgs__msg__LedControllers__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__LedControllers * data = NULL;

  if (size) {
    data = (uv_msgs__msg__LedControllers *)allocator.zero_allocate(size, sizeof(uv_msgs__msg__LedControllers), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = uv_msgs__msg__LedControllers__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        uv_msgs__msg__LedControllers__fini(&data[i - 1]);
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
uv_msgs__msg__LedControllers__Sequence__fini(uv_msgs__msg__LedControllers__Sequence * array)
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
      uv_msgs__msg__LedControllers__fini(&array->data[i]);
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

uv_msgs__msg__LedControllers__Sequence *
uv_msgs__msg__LedControllers__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__LedControllers__Sequence * array = (uv_msgs__msg__LedControllers__Sequence *)allocator.allocate(sizeof(uv_msgs__msg__LedControllers__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = uv_msgs__msg__LedControllers__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
uv_msgs__msg__LedControllers__Sequence__destroy(uv_msgs__msg__LedControllers__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    uv_msgs__msg__LedControllers__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
uv_msgs__msg__LedControllers__Sequence__are_equal(const uv_msgs__msg__LedControllers__Sequence * lhs, const uv_msgs__msg__LedControllers__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!uv_msgs__msg__LedControllers__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
uv_msgs__msg__LedControllers__Sequence__copy(
  const uv_msgs__msg__LedControllers__Sequence * input,
  uv_msgs__msg__LedControllers__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(uv_msgs__msg__LedControllers);
    uv_msgs__msg__LedControllers * data =
      (uv_msgs__msg__LedControllers *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!uv_msgs__msg__LedControllers__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          uv_msgs__msg__LedControllers__fini(&data[i]);
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
    if (!uv_msgs__msg__LedControllers__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
