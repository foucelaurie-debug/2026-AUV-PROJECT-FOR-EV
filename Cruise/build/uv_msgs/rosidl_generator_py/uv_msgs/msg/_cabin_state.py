# generated from rosidl_generator_py/resource/_idl.py.em
# with input from uv_msgs:msg/CabinState.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'servo'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CabinState(type):
    """Metaclass of message 'CabinState'."""

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
                'uv_msgs.msg.CabinState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__cabin_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__cabin_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__cabin_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__cabin_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__cabin_state

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CabinState(metaclass=Metaclass_CabinState):
    """Message class 'CabinState'."""

    __slots__ = [
        '_temp',
        '_hum',
        '_leak',
        '_voltage',
        '_servo',
    ]

    _fields_and_field_types = {
        'temp': 'float',
        'hum': 'float',
        'leak': 'uint8',
        'voltage': 'float',
        'servo': 'float[2]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 2),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.temp = kwargs.get('temp', float())
        self.hum = kwargs.get('hum', float())
        self.leak = kwargs.get('leak', int())
        self.voltage = kwargs.get('voltage', float())
        if 'servo' not in kwargs:
            self.servo = numpy.zeros(2, dtype=numpy.float32)
        else:
            self.servo = numpy.array(kwargs.get('servo'), dtype=numpy.float32)
            assert self.servo.shape == (2, )

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
        if self.temp != other.temp:
            return False
        if self.hum != other.hum:
            return False
        if self.leak != other.leak:
            return False
        if self.voltage != other.voltage:
            return False
        if all(self.servo != other.servo):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def temp(self):
        """Message field 'temp'."""
        return self._temp

    @temp.setter
    def temp(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'temp' field must be of type 'float'"
        self._temp = value

    @property
    def hum(self):
        """Message field 'hum'."""
        return self._hum

    @hum.setter
    def hum(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'hum' field must be of type 'float'"
        self._hum = value

    @property
    def leak(self):
        """Message field 'leak'."""
        return self._leak

    @leak.setter
    def leak(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'leak' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'leak' field must be an unsigned integer in [0, 255]"
        self._leak = value

    @property
    def voltage(self):
        """Message field 'voltage'."""
        return self._voltage

    @voltage.setter
    def voltage(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'voltage' field must be of type 'float'"
        self._voltage = value

    @property
    def servo(self):
        """Message field 'servo'."""
        return self._servo

    @servo.setter
    def servo(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'servo' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 2, \
                "The 'servo' numpy.ndarray() must have a size of 2"
            self._servo = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 2 and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'servo' field must be a set or sequence with length 2 and each value of type 'float'"
        self._servo = numpy.array(value, dtype=numpy.float32)
