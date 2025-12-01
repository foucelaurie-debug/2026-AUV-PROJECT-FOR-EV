// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from uv_msgs:msg/PidControllers.idl
// generated code does not contain a copyright notice
#include "uv_msgs/msg/detail/pid_controllers__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `x`
// Member `y`
// Member `z`
// Member `rx`
// Member `ry`
// Member `rz`
// Member `vx`
// Member `vy`
#include "uv_msgs/msg/detail/pid_params__functions.h"

bool
uv_msgs__msg__PidControllers__init(uv_msgs__msg__PidControllers * msg)
{
  if (!msg) {
    return false;
  }
  // x
  if (!uv_msgs__msg__PidParams__init(&msg->x)) {
    uv_msgs__msg__PidControllers__fini(msg);
    return false;
  }
  // y
  if (!uv_msgs__msg__PidParams__init(&msg->y)) {
    uv_msgs__msg__PidControllers__fini(msg);
    return false;
  }
  // z
  if (!uv_msgs__msg__PidParams__init(&msg->z)) {
    uv_msgs__msg__PidControllers__fini(msg);
    return false;
  }
  // rx
  if (!uv_msgs__msg__PidParams__init(&msg->rx)) {
    uv_msgs__msg__PidControllers__fini(msg);
    return false;
  }
  // ry
  if (!uv_msgs__msg__PidParams__init(&msg->ry)) {
    uv_msgs__msg__PidControllers__fini(msg);
    return false;
  }
  // rz
  if (!uv_msgs__msg__PidParams__init(&msg->rz)) {
    uv_msgs__msg__PidControllers__fini(msg);
    return false;
  }
  // vx
  if (!uv_msgs__msg__PidParams__init(&msg->vx)) {
    uv_msgs__msg__PidControllers__fini(msg);
    return false;
  }
  // vy
  if (!uv_msgs__msg__PidParams__init(&msg->vy)) {
    uv_msgs__msg__PidControllers__fini(msg);
    return false;
  }
  return true;
}

void
uv_msgs__msg__PidControllers__fini(uv_msgs__msg__PidControllers * msg)
{
  if (!msg) {
    return;
  }
  // x
  uv_msgs__msg__PidParams__fini(&msg->x);
  // y
  uv_msgs__msg__PidParams__fini(&msg->y);
  // z
  uv_msgs__msg__PidParams__fini(&msg->z);
  // rx
  uv_msgs__msg__PidParams__fini(&msg->rx);
  // ry
  uv_msgs__msg__PidParams__fini(&msg->ry);
  // rz
  uv_msgs__msg__PidParams__fini(&msg->rz);
  // vx
  uv_msgs__msg__PidParams__fini(&msg->vx);
  // vy
  uv_msgs__msg__PidParams__fini(&msg->vy);
}

bool
uv_msgs__msg__PidControllers__are_equal(const uv_msgs__msg__PidControllers * lhs, const uv_msgs__msg__PidControllers * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (!uv_msgs__msg__PidParams__are_equal(
      &(lhs->x), &(rhs->x)))
  {
    return false;
  }
  // y
  if (!uv_msgs__msg__PidParams__are_equal(
      &(lhs->y), &(rhs->y)))
  {
    return false;
  }
  // z
  if (!uv_msgs__msg__PidParams__are_equal(
      &(lhs->z), &(rhs->z)))
  {
    return false;
  }
  // rx
  if (!uv_msgs__msg__PidParams__are_equal(
      &(lhs->rx), &(rhs->rx)))
  {
    return false;
  }
  // ry
  if (!uv_msgs__msg__PidParams__are_equal(
      &(lhs->ry), &(rhs->ry)))
  {
    return false;
  }
  // rz
  if (!uv_msgs__msg__PidParams__are_equal(
      &(lhs->rz), &(rhs->rz)))
  {
    return false;
  }
  // vx
  if (!uv_msgs__msg__PidParams__are_equal(
      &(lhs->vx), &(rhs->vx)))
  {
    return false;
  }
  // vy
  if (!uv_msgs__msg__PidParams__are_equal(
      &(lhs->vy), &(rhs->vy)))
  {
    return false;
  }
  return true;
}

bool
uv_msgs__msg__PidControllers__copy(
  const uv_msgs__msg__PidControllers * input,
  uv_msgs__msg__PidControllers * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  if (!uv_msgs__msg__PidParams__copy(
      &(input->x), &(output->x)))
  {
    return false;
  }
  // y
  if (!uv_msgs__msg__PidParams__copy(
      &(input->y), &(output->y)))
  {
    return false;
  }
  // z
  if (!uv_msgs__msg__PidParams__copy(
      &(input->z), &(output->z)))
  {
    return false;
  }
  // rx
  if (!uv_msgs__msg__PidParams__copy(
      &(input->rx), &(output->rx)))
  {
    return false;
  }
  // ry
  if (!uv_msgs__msg__PidParams__copy(
      &(input->ry), &(output->ry)))
  {
    return false;
  }
  // rz
  if (!uv_msgs__msg__PidParams__copy(
      &(input->rz), &(output->rz)))
  {
    return false;
  }
  // vx
  if (!uv_msgs__msg__PidParams__copy(
      &(input->vx), &(output->vx)))
  {
    return false;
  }
  // vy
  if (!uv_msgs__msg__PidParams__copy(
      &(input->vy), &(output->vy)))
  {
    return false;
  }
  return true;
}

uv_msgs__msg__PidControllers *
uv_msgs__msg__PidControllers__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__PidControllers * msg = (uv_msgs__msg__PidControllers *)allocator.allocate(sizeof(uv_msgs__msg__PidControllers), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(uv_msgs__msg__PidControllers));
  bool success = uv_msgs__msg__PidControllers__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
uv_msgs__msg__PidControllers__destroy(uv_msgs__msg__PidControllers * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    uv_msgs__msg__PidControllers__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
uv_msgs__msg__PidControllers__Sequence__init(uv_msgs__msg__PidControllers__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__PidControllers * data = NULL;

  if (size) {
    data = (uv_msgs__msg__PidControllers *)allocator.zero_allocate(size, sizeof(uv_msgs__msg__PidControllers), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = uv_msgs__msg__PidControllers__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        uv_msgs__msg__PidControllers__fini(&data[i - 1]);
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
uv_msgs__msg__PidControllers__Sequence__fini(uv_msgs__msg__PidControllers__Sequence * array)
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
      uv_msgs__msg__PidControllers__fini(&array->data[i]);
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

uv_msgs__msg__PidControllers__Sequence *
uv_msgs__msg__PidControllers__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__PidControllers__Sequence * array = (uv_msgs__msg__PidControllers__Sequence *)allocator.allocate(sizeof(uv_msgs__msg__PidControllers__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = uv_msgs__msg__PidControllers__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
uv_msgs__msg__PidControllers__Sequence__destroy(uv_msgs__msg__PidControllers__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    uv_msgs__msg__PidControllers__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
uv_msgs__msg__PidControllers__Sequence__are_equal(const uv_msgs__msg__PidControllers__Sequence * lhs, const uv_msgs__msg__PidControllers__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!uv_msgs__msg__PidControllers__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
uv_msgs__msg__PidControllers__Sequence__copy(
  const uv_msgs__msg__PidControllers__Sequence * input,
  uv_msgs__msg__PidControllers__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(uv_msgs__msg__PidControllers);
    uv_msgs__msg__PidControllers * data =
      (uv_msgs__msg__PidControllers *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!uv_msgs__msg__PidControllers__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          uv_msgs__msg__PidControllers__fini(&data[i]);
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
    if (!uv_msgs__msg__PidControllers__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
