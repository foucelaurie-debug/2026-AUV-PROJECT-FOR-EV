// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from uv_msgs:msg/PidParams.idl
// generated code does not contain a copyright notice
#include "uv_msgs/msg/detail/pid_params__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"

bool
uv_msgs__msg__PidParams__init(uv_msgs__msg__PidParams * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    uv_msgs__msg__PidParams__fini(msg);
    return false;
  }
  // p
  // i
  // d
  // i_limit
  // output_limit
  return true;
}

void
uv_msgs__msg__PidParams__fini(uv_msgs__msg__PidParams * msg)
{
  if (!msg) {
    return;
  }
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // p
  // i
  // d
  // i_limit
  // output_limit
}

bool
uv_msgs__msg__PidParams__are_equal(const uv_msgs__msg__PidParams * lhs, const uv_msgs__msg__PidParams * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // p
  if (lhs->p != rhs->p) {
    return false;
  }
  // i
  if (lhs->i != rhs->i) {
    return false;
  }
  // d
  if (lhs->d != rhs->d) {
    return false;
  }
  // i_limit
  if (lhs->i_limit != rhs->i_limit) {
    return false;
  }
  // output_limit
  if (lhs->output_limit != rhs->output_limit) {
    return false;
  }
  return true;
}

bool
uv_msgs__msg__PidParams__copy(
  const uv_msgs__msg__PidParams * input,
  uv_msgs__msg__PidParams * output)
{
  if (!input || !output) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // p
  output->p = input->p;
  // i
  output->i = input->i;
  // d
  output->d = input->d;
  // i_limit
  output->i_limit = input->i_limit;
  // output_limit
  output->output_limit = input->output_limit;
  return true;
}

uv_msgs__msg__PidParams *
uv_msgs__msg__PidParams__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__PidParams * msg = (uv_msgs__msg__PidParams *)allocator.allocate(sizeof(uv_msgs__msg__PidParams), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(uv_msgs__msg__PidParams));
  bool success = uv_msgs__msg__PidParams__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
uv_msgs__msg__PidParams__destroy(uv_msgs__msg__PidParams * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    uv_msgs__msg__PidParams__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
uv_msgs__msg__PidParams__Sequence__init(uv_msgs__msg__PidParams__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__PidParams * data = NULL;

  if (size) {
    data = (uv_msgs__msg__PidParams *)allocator.zero_allocate(size, sizeof(uv_msgs__msg__PidParams), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = uv_msgs__msg__PidParams__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        uv_msgs__msg__PidParams__fini(&data[i - 1]);
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
uv_msgs__msg__PidParams__Sequence__fini(uv_msgs__msg__PidParams__Sequence * array)
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
      uv_msgs__msg__PidParams__fini(&array->data[i]);
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

uv_msgs__msg__PidParams__Sequence *
uv_msgs__msg__PidParams__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__PidParams__Sequence * array = (uv_msgs__msg__PidParams__Sequence *)allocator.allocate(sizeof(uv_msgs__msg__PidParams__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = uv_msgs__msg__PidParams__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
uv_msgs__msg__PidParams__Sequence__destroy(uv_msgs__msg__PidParams__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    uv_msgs__msg__PidParams__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
uv_msgs__msg__PidParams__Sequence__are_equal(const uv_msgs__msg__PidParams__Sequence * lhs, const uv_msgs__msg__PidParams__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!uv_msgs__msg__PidParams__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
uv_msgs__msg__PidParams__Sequence__copy(
  const uv_msgs__msg__PidParams__Sequence * input,
  uv_msgs__msg__PidParams__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(uv_msgs__msg__PidParams);
    uv_msgs__msg__PidParams * data =
      (uv_msgs__msg__PidParams *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!uv_msgs__msg__PidParams__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          uv_msgs__msg__PidParams__fini(&data[i]);
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
    if (!uv_msgs__msg__PidParams__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
