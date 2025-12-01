// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from uv_msgs:msg/ThrustCurve.idl
// generated code does not contain a copyright notice
#include "uv_msgs/msg/detail/thrust_curve__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
uv_msgs__msg__ThrustCurve__init(uv_msgs__msg__ThrustCurve * msg)
{
  if (!msg) {
    return false;
  }
  // num
  // np_mid
  // np_ini
  // pp_ini
  // pp_mid
  // nt_end
  // nt_mid
  // pt_mid
  // pt_end
  return true;
}

void
uv_msgs__msg__ThrustCurve__fini(uv_msgs__msg__ThrustCurve * msg)
{
  if (!msg) {
    return;
  }
  // num
  // np_mid
  // np_ini
  // pp_ini
  // pp_mid
  // nt_end
  // nt_mid
  // pt_mid
  // pt_end
}

bool
uv_msgs__msg__ThrustCurve__are_equal(const uv_msgs__msg__ThrustCurve * lhs, const uv_msgs__msg__ThrustCurve * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // num
  if (lhs->num != rhs->num) {
    return false;
  }
  // np_mid
  if (lhs->np_mid != rhs->np_mid) {
    return false;
  }
  // np_ini
  if (lhs->np_ini != rhs->np_ini) {
    return false;
  }
  // pp_ini
  if (lhs->pp_ini != rhs->pp_ini) {
    return false;
  }
  // pp_mid
  if (lhs->pp_mid != rhs->pp_mid) {
    return false;
  }
  // nt_end
  if (lhs->nt_end != rhs->nt_end) {
    return false;
  }
  // nt_mid
  if (lhs->nt_mid != rhs->nt_mid) {
    return false;
  }
  // pt_mid
  if (lhs->pt_mid != rhs->pt_mid) {
    return false;
  }
  // pt_end
  if (lhs->pt_end != rhs->pt_end) {
    return false;
  }
  return true;
}

bool
uv_msgs__msg__ThrustCurve__copy(
  const uv_msgs__msg__ThrustCurve * input,
  uv_msgs__msg__ThrustCurve * output)
{
  if (!input || !output) {
    return false;
  }
  // num
  output->num = input->num;
  // np_mid
  output->np_mid = input->np_mid;
  // np_ini
  output->np_ini = input->np_ini;
  // pp_ini
  output->pp_ini = input->pp_ini;
  // pp_mid
  output->pp_mid = input->pp_mid;
  // nt_end
  output->nt_end = input->nt_end;
  // nt_mid
  output->nt_mid = input->nt_mid;
  // pt_mid
  output->pt_mid = input->pt_mid;
  // pt_end
  output->pt_end = input->pt_end;
  return true;
}

uv_msgs__msg__ThrustCurve *
uv_msgs__msg__ThrustCurve__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__ThrustCurve * msg = (uv_msgs__msg__ThrustCurve *)allocator.allocate(sizeof(uv_msgs__msg__ThrustCurve), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(uv_msgs__msg__ThrustCurve));
  bool success = uv_msgs__msg__ThrustCurve__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
uv_msgs__msg__ThrustCurve__destroy(uv_msgs__msg__ThrustCurve * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    uv_msgs__msg__ThrustCurve__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
uv_msgs__msg__ThrustCurve__Sequence__init(uv_msgs__msg__ThrustCurve__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__ThrustCurve * data = NULL;

  if (size) {
    data = (uv_msgs__msg__ThrustCurve *)allocator.zero_allocate(size, sizeof(uv_msgs__msg__ThrustCurve), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = uv_msgs__msg__ThrustCurve__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        uv_msgs__msg__ThrustCurve__fini(&data[i - 1]);
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
uv_msgs__msg__ThrustCurve__Sequence__fini(uv_msgs__msg__ThrustCurve__Sequence * array)
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
      uv_msgs__msg__ThrustCurve__fini(&array->data[i]);
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

uv_msgs__msg__ThrustCurve__Sequence *
uv_msgs__msg__ThrustCurve__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__ThrustCurve__Sequence * array = (uv_msgs__msg__ThrustCurve__Sequence *)allocator.allocate(sizeof(uv_msgs__msg__ThrustCurve__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = uv_msgs__msg__ThrustCurve__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
uv_msgs__msg__ThrustCurve__Sequence__destroy(uv_msgs__msg__ThrustCurve__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    uv_msgs__msg__ThrustCurve__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
uv_msgs__msg__ThrustCurve__Sequence__are_equal(const uv_msgs__msg__ThrustCurve__Sequence * lhs, const uv_msgs__msg__ThrustCurve__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!uv_msgs__msg__ThrustCurve__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
uv_msgs__msg__ThrustCurve__Sequence__copy(
  const uv_msgs__msg__ThrustCurve__Sequence * input,
  uv_msgs__msg__ThrustCurve__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(uv_msgs__msg__ThrustCurve);
    uv_msgs__msg__ThrustCurve * data =
      (uv_msgs__msg__ThrustCurve *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!uv_msgs__msg__ThrustCurve__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          uv_msgs__msg__ThrustCurve__fini(&data[i]);
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
    if (!uv_msgs__msg__ThrustCurve__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
