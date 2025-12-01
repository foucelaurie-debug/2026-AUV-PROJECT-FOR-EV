// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from uv_msgs:msg/RobotMotionController.idl
// generated code does not contain a copyright notice
#include "uv_msgs/msg/detail/robot_motion_controller__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `pos`
// Member `tpos_inbase`
// Member `tpos_inworld`
#include "uv_msgs/msg/detail/robot_axis__functions.h"
// Member `imu`
#include "uv_msgs/msg/detail/imu_data__functions.h"
// Member `thrust`
#include "uv_msgs/msg/detail/motor_thrust__functions.h"
// Member `pidstate`
#include "uv_msgs/msg/detail/pid_controllers_state__functions.h"

bool
uv_msgs__msg__RobotMotionController__init(uv_msgs__msg__RobotMotionController * msg)
{
  if (!msg) {
    return false;
  }
  // pos
  if (!uv_msgs__msg__RobotAxis__init(&msg->pos)) {
    uv_msgs__msg__RobotMotionController__fini(msg);
    return false;
  }
  // tpos_inbase
  if (!uv_msgs__msg__RobotAxis__init(&msg->tpos_inbase)) {
    uv_msgs__msg__RobotMotionController__fini(msg);
    return false;
  }
  // tpos_inworld
  if (!uv_msgs__msg__RobotAxis__init(&msg->tpos_inworld)) {
    uv_msgs__msg__RobotMotionController__fini(msg);
    return false;
  }
  // imu
  if (!uv_msgs__msg__ImuData__init(&msg->imu)) {
    uv_msgs__msg__RobotMotionController__fini(msg);
    return false;
  }
  // thrust
  if (!uv_msgs__msg__MotorThrust__init(&msg->thrust)) {
    uv_msgs__msg__RobotMotionController__fini(msg);
    return false;
  }
  // pidstate
  if (!uv_msgs__msg__PidControllersState__init(&msg->pidstate)) {
    uv_msgs__msg__RobotMotionController__fini(msg);
    return false;
  }
  return true;
}

void
uv_msgs__msg__RobotMotionController__fini(uv_msgs__msg__RobotMotionController * msg)
{
  if (!msg) {
    return;
  }
  // pos
  uv_msgs__msg__RobotAxis__fini(&msg->pos);
  // tpos_inbase
  uv_msgs__msg__RobotAxis__fini(&msg->tpos_inbase);
  // tpos_inworld
  uv_msgs__msg__RobotAxis__fini(&msg->tpos_inworld);
  // imu
  uv_msgs__msg__ImuData__fini(&msg->imu);
  // thrust
  uv_msgs__msg__MotorThrust__fini(&msg->thrust);
  // pidstate
  uv_msgs__msg__PidControllersState__fini(&msg->pidstate);
}

bool
uv_msgs__msg__RobotMotionController__are_equal(const uv_msgs__msg__RobotMotionController * lhs, const uv_msgs__msg__RobotMotionController * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pos
  if (!uv_msgs__msg__RobotAxis__are_equal(
      &(lhs->pos), &(rhs->pos)))
  {
    return false;
  }
  // tpos_inbase
  if (!uv_msgs__msg__RobotAxis__are_equal(
      &(lhs->tpos_inbase), &(rhs->tpos_inbase)))
  {
    return false;
  }
  // tpos_inworld
  if (!uv_msgs__msg__RobotAxis__are_equal(
      &(lhs->tpos_inworld), &(rhs->tpos_inworld)))
  {
    return false;
  }
  // imu
  if (!uv_msgs__msg__ImuData__are_equal(
      &(lhs->imu), &(rhs->imu)))
  {
    return false;
  }
  // thrust
  if (!uv_msgs__msg__MotorThrust__are_equal(
      &(lhs->thrust), &(rhs->thrust)))
  {
    return false;
  }
  // pidstate
  if (!uv_msgs__msg__PidControllersState__are_equal(
      &(lhs->pidstate), &(rhs->pidstate)))
  {
    return false;
  }
  return true;
}

bool
uv_msgs__msg__RobotMotionController__copy(
  const uv_msgs__msg__RobotMotionController * input,
  uv_msgs__msg__RobotMotionController * output)
{
  if (!input || !output) {
    return false;
  }
  // pos
  if (!uv_msgs__msg__RobotAxis__copy(
      &(input->pos), &(output->pos)))
  {
    return false;
  }
  // tpos_inbase
  if (!uv_msgs__msg__RobotAxis__copy(
      &(input->tpos_inbase), &(output->tpos_inbase)))
  {
    return false;
  }
  // tpos_inworld
  if (!uv_msgs__msg__RobotAxis__copy(
      &(input->tpos_inworld), &(output->tpos_inworld)))
  {
    return false;
  }
  // imu
  if (!uv_msgs__msg__ImuData__copy(
      &(input->imu), &(output->imu)))
  {
    return false;
  }
  // thrust
  if (!uv_msgs__msg__MotorThrust__copy(
      &(input->thrust), &(output->thrust)))
  {
    return false;
  }
  // pidstate
  if (!uv_msgs__msg__PidControllersState__copy(
      &(input->pidstate), &(output->pidstate)))
  {
    return false;
  }
  return true;
}

uv_msgs__msg__RobotMotionController *
uv_msgs__msg__RobotMotionController__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__RobotMotionController * msg = (uv_msgs__msg__RobotMotionController *)allocator.allocate(sizeof(uv_msgs__msg__RobotMotionController), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(uv_msgs__msg__RobotMotionController));
  bool success = uv_msgs__msg__RobotMotionController__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
uv_msgs__msg__RobotMotionController__destroy(uv_msgs__msg__RobotMotionController * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    uv_msgs__msg__RobotMotionController__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
uv_msgs__msg__RobotMotionController__Sequence__init(uv_msgs__msg__RobotMotionController__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__RobotMotionController * data = NULL;

  if (size) {
    data = (uv_msgs__msg__RobotMotionController *)allocator.zero_allocate(size, sizeof(uv_msgs__msg__RobotMotionController), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = uv_msgs__msg__RobotMotionController__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        uv_msgs__msg__RobotMotionController__fini(&data[i - 1]);
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
uv_msgs__msg__RobotMotionController__Sequence__fini(uv_msgs__msg__RobotMotionController__Sequence * array)
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
      uv_msgs__msg__RobotMotionController__fini(&array->data[i]);
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

uv_msgs__msg__RobotMotionController__Sequence *
uv_msgs__msg__RobotMotionController__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  uv_msgs__msg__RobotMotionController__Sequence * array = (uv_msgs__msg__RobotMotionController__Sequence *)allocator.allocate(sizeof(uv_msgs__msg__RobotMotionController__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = uv_msgs__msg__RobotMotionController__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
uv_msgs__msg__RobotMotionController__Sequence__destroy(uv_msgs__msg__RobotMotionController__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    uv_msgs__msg__RobotMotionController__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
uv_msgs__msg__RobotMotionController__Sequence__are_equal(const uv_msgs__msg__RobotMotionController__Sequence * lhs, const uv_msgs__msg__RobotMotionController__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!uv_msgs__msg__RobotMotionController__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
uv_msgs__msg__RobotMotionController__Sequence__copy(
  const uv_msgs__msg__RobotMotionController__Sequence * input,
  uv_msgs__msg__RobotMotionController__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(uv_msgs__msg__RobotMotionController);
    uv_msgs__msg__RobotMotionController * data =
      (uv_msgs__msg__RobotMotionController *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!uv_msgs__msg__RobotMotionController__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          uv_msgs__msg__RobotMotionController__fini(&data[i]);
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
    if (!uv_msgs__msg__RobotMotionController__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
