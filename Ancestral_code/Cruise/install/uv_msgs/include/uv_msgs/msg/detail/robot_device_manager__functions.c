// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from uv_msgs:msg/RobotDeviceManager.idl
// generated code does not contain a copyright notice
#include "uv_msgs/msg/detail/robot_device_manager__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
uv_msgs__msg__RobotDeviceManager__init(uv_msgs__msg__RobotDeviceManager * msg)
{
  if (!msg) {
    return false;
  }
  // leak
  // tem
  // hum
  // vol
  // magnet
  // led
  // angle
  return true;
}

void
uv_msgs__msg__RobotDeviceManager__fini(uv_msgs__msg__RobotDeviceManager * msg)
{
  if (!msg) {
    return;
  }
  // leak
  // tem
  // hum
  // vol
  // magnet
  // led
  // angle
}

bool
uv_msgs__msg__RobotDeviceManager__are_equal(const uv_msgs__msg__RobotDeviceManager * lhs, const uv_msgs__msg__RobotDeviceManager * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // leak
  if (lhs->leak != rhs->leak) {
    return false;
  }
  // tem
  if (lhs->tem != rhs->tem) {
    return false;
  }
  // hum
  if (lhs->hum != rhs->hum) {
    return false;
  }
  // vol
  if (lhs->vol != rhs->vol) {
    return false;
  }
  // magnet
  if (lhs->magnet != rhs->magnet) {
    return false;
  }
  // led
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->led[i] != rhs->led[i]) {
      return false;
    }
  }
  // angle
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->angle[i] != rhs->angle[i]) {
      return false;
    }
  }
  return true;
}

bool
uv_msgs__msg__RobotDeviceManager__copy(
  const uv_msgs__msg__RobotDeviceManager * input,
  uv_msgs__msg__RobotDeviceManager * output)
{
  if (!input || !output) {
    return false;
  }
  // leak
  output->leak = input->leak;
  // tem
  output->tem = input->tem;
  // hum
  output->hum = input->hum;
  // vol
  output->vol = input->vol;
  // magnet
  output->magnet = input->magnet;
  // led
  for (size_t i = 0; i < 2; ++i) {
    output->led[i] = input->led[i];
  }
  // angle
  for (size_t i = 0; i < 2; ++i) {
    output->angle[i] = input->angle[i];
  }
  return true;
}

uv_msgs__msg__RobotDeviceManager *
uv_msgs__msg__RobotDeviceManager__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__RobotDeviceManager * msg = (uv_msgs__msg__RobotDeviceManager *)allocator.allocate(sizeof(uv_msgs__msg__RobotDeviceManager), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(uv_msgs__msg__RobotDeviceManager));
  bool success = uv_msgs__msg__RobotDeviceManager__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
uv_msgs__msg__RobotDeviceManager__destroy(uv_msgs__msg__RobotDeviceManager * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    uv_msgs__msg__RobotDeviceManager__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
uv_msgs__msg__RobotDeviceManager__Sequence__init(uv_msgs__msg__RobotDeviceManager__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__RobotDeviceManager * data = NULL;

  if (size) {
    data = (uv_msgs__msg__RobotDeviceManager *)allocator.zero_allocate(size, sizeof(uv_msgs__msg__RobotDeviceManager), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = uv_msgs__msg__RobotDeviceManager__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        uv_msgs__msg__RobotDeviceManager__fini(&data[i - 1]);
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
uv_msgs__msg__RobotDeviceManager__Sequence__fini(uv_msgs__msg__RobotDeviceManager__Sequence * array)
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
      uv_msgs__msg__RobotDeviceManager__fini(&array->data[i]);
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

uv_msgs__msg__RobotDeviceManager__Sequence *
uv_msgs__msg__RobotDeviceManager__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__RobotDeviceManager__Sequence * array = (uv_msgs__msg__RobotDeviceManager__Sequence *)allocator.allocate(sizeof(uv_msgs__msg__RobotDeviceManager__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = uv_msgs__msg__RobotDeviceManager__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
uv_msgs__msg__RobotDeviceManager__Sequence__destroy(uv_msgs__msg__RobotDeviceManager__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    uv_msgs__msg__RobotDeviceManager__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
uv_msgs__msg__RobotDeviceManager__Sequence__are_equal(const uv_msgs__msg__RobotDeviceManager__Sequence * lhs, const uv_msgs__msg__RobotDeviceManager__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!uv_msgs__msg__RobotDeviceManager__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
uv_msgs__msg__RobotDeviceManager__Sequence__copy(
  const uv_msgs__msg__RobotDeviceManager__Sequence * input,
  uv_msgs__msg__RobotDeviceManager__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(uv_msgs__msg__RobotDeviceManager);
    uv_msgs__msg__RobotDeviceManager * data =
      (uv_msgs__msg__RobotDeviceManager *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!uv_msgs__msg__RobotDeviceManager__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          uv_msgs__msg__RobotDeviceManager__fini(&data[i]);
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
    if (!uv_msgs__msg__RobotDeviceManager__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
