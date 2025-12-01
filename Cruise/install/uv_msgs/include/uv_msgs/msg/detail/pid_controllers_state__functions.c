// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from uv_msgs:msg/PidControllersState.idl
// generated code does not contain a copyright notice
#include "uv_msgs/msg/detail/pid_controllers_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
uv_msgs__msg__PidControllersState__init(uv_msgs__msg__PidControllersState * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // z
  // rx
  // ry
  // rz
  // vy
  // vx
  return true;
}

void
uv_msgs__msg__PidControllersState__fini(uv_msgs__msg__PidControllersState * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // z
  // rx
  // ry
  // rz
  // vy
  // vx
}

bool
uv_msgs__msg__PidControllersState__are_equal(const uv_msgs__msg__PidControllersState * lhs, const uv_msgs__msg__PidControllersState * rhs)
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
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  // rx
  if (lhs->rx != rhs->rx) {
    return false;
  }
  // ry
  if (lhs->ry != rhs->ry) {
    return false;
  }
  // rz
  if (lhs->rz != rhs->rz) {
    return false;
  }
  // vy
  if (lhs->vy != rhs->vy) {
    return false;
  }
  // vx
  if (lhs->vx != rhs->vx) {
    return false;
  }
  return true;
}

bool
uv_msgs__msg__PidControllersState__copy(
  const uv_msgs__msg__PidControllersState * input,
  uv_msgs__msg__PidControllersState * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  // rx
  output->rx = input->rx;
  // ry
  output->ry = input->ry;
  // rz
  output->rz = input->rz;
  // vy
  output->vy = input->vy;
  // vx
  output->vx = input->vx;
  return true;
}

uv_msgs__msg__PidControllersState *
uv_msgs__msg__PidControllersState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__PidControllersState * msg = (uv_msgs__msg__PidControllersState *)allocator.allocate(sizeof(uv_msgs__msg__PidControllersState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(uv_msgs__msg__PidControllersState));
  bool success = uv_msgs__msg__PidControllersState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
uv_msgs__msg__PidControllersState__destroy(uv_msgs__msg__PidControllersState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    uv_msgs__msg__PidControllersState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
uv_msgs__msg__PidControllersState__Sequence__init(uv_msgs__msg__PidControllersState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__PidControllersState * data = NULL;

  if (size) {
    data = (uv_msgs__msg__PidControllersState *)allocator.zero_allocate(size, sizeof(uv_msgs__msg__PidControllersState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = uv_msgs__msg__PidControllersState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        uv_msgs__msg__PidControllersState__fini(&data[i - 1]);
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
uv_msgs__msg__PidControllersState__Sequence__fini(uv_msgs__msg__PidControllersState__Sequence * array)
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
      uv_msgs__msg__PidControllersState__fini(&array->data[i]);
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

uv_msgs__msg__PidControllersState__Sequence *
uv_msgs__msg__PidControllersState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__PidControllersState__Sequence * array = (uv_msgs__msg__PidControllersState__Sequence *)allocator.allocate(sizeof(uv_msgs__msg__PidControllersState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = uv_msgs__msg__PidControllersState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
uv_msgs__msg__PidControllersState__Sequence__destroy(uv_msgs__msg__PidControllersState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    uv_msgs__msg__PidControllersState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
uv_msgs__msg__PidControllersState__Sequence__are_equal(const uv_msgs__msg__PidControllersState__Sequence * lhs, const uv_msgs__msg__PidControllersState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!uv_msgs__msg__PidControllersState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
uv_msgs__msg__PidControllersState__Sequence__copy(
  const uv_msgs__msg__PidControllersState__Sequence * input,
  uv_msgs__msg__PidControllersState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(uv_msgs__msg__PidControllersState);
    uv_msgs__msg__PidControllersState * data =
      (uv_msgs__msg__PidControllersState *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!uv_msgs__msg__PidControllersState__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          uv_msgs__msg__PidControllersState__fini(&data[i]);
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
    if (!uv_msgs__msg__PidControllersState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
