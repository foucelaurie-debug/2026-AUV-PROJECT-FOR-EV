# generated from rosidl_generator_py/resource/_idl.py.em
# with input from uv_msgs:msg/LedControllers.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_LedControllers(type):
    """Metaclass of message 'LedControllers'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('uv_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'uv_msgs.msg.LedControllers')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__led_controllers
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__led_controllers
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__led_controllers
            cls._TYPE_SUPPORT = module.type_support_msg__msg__led_controllers
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__led_controllers

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class LedControllers(metaclass=Metaclass_LedControllers):
    """Message class 'LedControllers'."""

    __slots__ = [
        '_led0',
        '_led1',
    ]

    _fields_and_field_types = {
        'led0': 'uint8',
        'led1': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.led0 = kwargs.get('led0', int())
        self.led1 = kwargs.get('led1', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.led0 != other.led0:
            return False
        if self.led1 != other.led1:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def led0(self):
        """Message field 'led0'."""
        return self._led0

    @led0.setter
    def led0(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'led0' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'led0' field must be an unsigned integer in [0, 255]"
        self._led0 = value

    @property
    def led1(self):
        """Message field 'led1'."""
        return self._led1

    @led1.setter
    def led1(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'led1' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'led1' field must be an unsigned integer in [0, 255]"
        self._led1 = value
