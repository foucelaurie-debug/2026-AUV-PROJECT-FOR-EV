// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from uv_msgs:msg/ThrustCurves.idl
// generated code does not contain a copyright notice
#include "uv_msgs/msg/detail/thrust_curves__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `m0`
// Member `m1`
// Member `m2`
// Member `m3`
// Member `m4`
// Member `m5`
#include "uv_msgs/msg/detail/thrust_curve__functions.h"

bool
uv_msgs__msg__ThrustCurves__init(uv_msgs__msg__ThrustCurves * msg)
{
  if (!msg) {
    return false;
  }
  // m0
  if (!uv_msgs__msg__ThrustCurve__init(&msg->m0)) {
    uv_msgs__msg__ThrustCurves__fini(msg);
    return false;
  }
  // m1
  if (!uv_msgs__msg__ThrustCurve__init(&msg->m1)) {
    uv_msgs__msg__ThrustCurves__fini(msg);
    return false;
  }
  // m2
  if (!uv_msgs__msg__ThrustCurve__init(&msg->m2)) {
    uv_msgs__msg__ThrustCurves__fini(msg);
    return false;
  }
  // m3
  if (!uv_msgs__msg__ThrustCurve__init(&msg->m3)) {
    uv_msgs__msg__ThrustCurves__fini(msg);
    return false;
  }
  // m4
  if (!uv_msgs__msg__ThrustCurve__init(&msg->m4)) {
    uv_msgs__msg__ThrustCurves__fini(msg);
    return false;
  }
  // m5
  if (!uv_msgs__msg__ThrustCurve__init(&msg->m5)) {
    uv_msgs__msg__ThrustCurves__fini(msg);
    return false;
  }
  return true;
}

void
uv_msgs__msg__ThrustCurves__fini(uv_msgs__msg__ThrustCurves * msg)
{
  if (!msg) {
    return;
  }
  // m0
  uv_msgs__msg__ThrustCurve__fini(&msg->m0);
  // m1
  uv_msgs__msg__ThrustCurve__fini(&msg->m1);
  // m2
  uv_msgs__msg__ThrustCurve__fini(&msg->m2);
  // m3
  uv_msgs__msg__ThrustCurve__fini(&msg->m3);
  // m4
  uv_msgs__msg__ThrustCurve__fini(&msg->m4);
  // m5
  uv_msgs__msg__ThrustCurve__fini(&msg->m5);
}

bool
uv_msgs__msg__ThrustCurves__are_equal(const uv_msgs__msg__ThrustCurves * lhs, const uv_msgs__msg__ThrustCurves * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // m0
  if (!uv_msgs__msg__ThrustCurve__are_equal(
      &(lhs->m0), &(rhs->m0)))
  {
    return false;
  }
  // m1
  if (!uv_msgs__msg__ThrustCurve__are_equal(
      &(lhs->m1), &(rhs->m1)))
  {
    return false;
  }
  // m2
  if (!uv_msgs__msg__ThrustCurve__are_equal(
      &(lhs->m2), &(rhs->m2)))
  {
    return false;
  }
  // m3
  if (!uv_msgs__msg__ThrustCurve__are_equal(
      &(lhs->m3), &(rhs->m3)))
  {
    return false;
  }
  // m4
  if (!uv_msgs__msg__ThrustCurve__are_equal(
      &(lhs->m4), &(rhs->m4)))
  {
    return false;
  }
  // m5
  if (!uv_msgs__msg__ThrustCurve__are_equal(
      &(lhs->m5), &(rhs->m5)))
  {
    return false;
  }
  return true;
}

bool
uv_msgs__msg__ThrustCurves__copy(
  const uv_msgs__msg__ThrustCurves * input,
  uv_msgs__msg__ThrustCurves * output)
{
  if (!input || !output) {
    return false;
  }
  // m0
  if (!uv_msgs__msg__ThrustCurve__copy(
      &(input->m0), &(output->m0)))
  {
    return false;
  }
  // m1
  if (!uv_msgs__msg__ThrustCurve__copy(
      &(input->m1), &(output->m1)))
  {
    return false;
  }
  // m2
  if (!uv_msgs__msg__ThrustCurve__copy(
      &(input->m2), &(output->m2)))
  {
    return false;
  }
  // m3
  if (!uv_msgs__msg__ThrustCurve__copy(
      &(input->m3), &(output->m3)))
  {
    return false;
  }
  // m4
  if (!uv_msgs__msg__ThrustCurve__copy(
      &(input->m4), &(output->m4)))
  {
    return false;
  }
  // m5
  if (!uv_msgs__msg__ThrustCurve__copy(
      &(input->m5), &(output->m5)))
  {
    return false;
  }
  return true;
}

uv_msgs__msg__ThrustCurves *
uv_msgs__msg__ThrustCurves__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__ThrustCurves * msg = (uv_msgs__msg__ThrustCurves *)allocator.allocate(sizeof(uv_msgs__msg__ThrustCurves), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(uv_msgs__msg__ThrustCurves));
  bool success = uv_msgs__msg__ThrustCurves__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
uv_msgs__msg__ThrustCurves__destroy(uv_msgs__msg__ThrustCurves * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    uv_msgs__msg__ThrustCurves__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
uv_msgs__msg__ThrustCurves__Sequence__init(uv_msgs__msg__ThrustCurves__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__ThrustCurves * data = NULL;

  if (size) {
    data = (uv_msgs__msg__ThrustCurves *)allocator.zero_allocate(size, sizeof(uv_msgs__msg__ThrustCurves), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = uv_msgs__msg__ThrustCurves__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        uv_msgs__msg__ThrustCurves__fini(&data[i - 1]);
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
uv_msgs__msg__ThrustCurves__Sequence__fini(uv_msgs__msg__ThrustCurves__Sequence * array)
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
      uv_msgs__msg__ThrustCurves__fini(&array->data[i]);
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

uv_msgs__msg__ThrustCurves__Sequence *
uv_msgs__msg__ThrustCurves__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__ThrustCurves__Sequence * array = (uv_msgs__msg__ThrustCurves__Sequence *)allocator.allocate(sizeof(uv_msgs__msg__ThrustCurves__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = uv_msgs__msg__ThrustCurves__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
uv_msgs__msg__ThrustCurves__Sequence__destroy(uv_msgs__msg__ThrustCurves__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    uv_msgs__msg__ThrustCurves__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
uv_msgs__msg__ThrustCurves__Sequence__are_equal(const uv_msgs__msg__ThrustCurves__Sequence * lhs, const uv_msgs__msg__ThrustCurves__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!uv_msgs__msg__ThrustCurves__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
uv_msgs__msg__ThrustCurves__Sequence__copy(
  const uv_msgs__msg__ThrustCurves__Sequence * input,
  uv_msgs__msg__ThrustCurves__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(uv_msgs__msg__ThrustCurves);
    uv_msgs__msg__ThrustCurves * data =
      (uv_msgs__msg__ThrustCurves *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!uv_msgs__msg__ThrustCurves__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          uv_msgs__msg__ThrustCurves__fini(&data[i]);
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
    if (!uv_msgs__msg__ThrustCurves__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
