# generated from rosidl_generator_py/resource/_idl.py.em
# with input from uv_msgs:msg/RobotDeviceManager.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'led'
# Member 'angle'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RobotDeviceManager(type):
    """Metaclass of message 'RobotDeviceManager'."""

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
                'uv_msgs.msg.RobotDeviceManager')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__robot_device_manager
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__robot_device_manager
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__robot_device_manager
            cls._TYPE_SUPPORT = module.type_support_msg__msg__robot_device_manager
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__robot_device_manager

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RobotDeviceManager(metaclass=Metaclass_RobotDeviceManager):
    """Message class 'RobotDeviceManager'."""

    __slots__ = [
        '_leak',
        '_tem',
        '_hum',
        '_vol',
        '_magnet',
        '_led',
        '_angle',
    ]

    _fields_and_field_types = {
        'leak': 'uint8',
        'tem': 'float',
        'hum': 'float',
        'vol': 'float',
        'magnet': 'uint8',
        'led': 'uint8[2]',
        'angle': 'float[2]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 2),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 2),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.leak = kwargs.get('leak', int())
        self.tem = kwargs.get('tem', float())
        self.hum = kwargs.get('hum', float())
        self.vol = kwargs.get('vol', float())
        self.magnet = kwargs.get('magnet', int())
        if 'led' not in kwargs:
            self.led = numpy.zeros(2, dtype=numpy.uint8)
        else:
            self.led = numpy.array(kwargs.get('led'), dtype=numpy.uint8)
            assert self.led.shape == (2, )
        if 'angle' not in kwargs:
            self.angle = numpy.zeros(2, dtype=numpy.float32)
        else:
            self.angle = numpy.array(kwargs.get('angle'), dtype=numpy.float32)
            assert self.angle.shape == (2, )

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
        if self.leak != other.leak:
            return False
        if self.tem != other.tem:
            return False
        if self.hum != other.hum:
            return False
        if self.vol != other.vol:
            return False
        if self.magnet != other.magnet:
            return False
        if all(self.led != other.led):
            return False
        if all(self.angle != other.angle):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

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
    def tem(self):
        """Message field 'tem'."""
        return self._tem

    @tem.setter
    def tem(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'tem' field must be of type 'float'"
        self._tem = value

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
    def vol(self):
        """Message field 'vol'."""
        return self._vol

    @vol.setter
    def vol(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vol' field must be of type 'float'"
        self._vol = value

    @property
    def magnet(self):
        """Message field 'magnet'."""
        return self._magnet

    @magnet.setter
    def magnet(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'magnet' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'magnet' field must be an unsigned integer in [0, 255]"
        self._magnet = value

    @property
    def led(self):
        """Message field 'led'."""
        return self._led

    @led.setter
    def led(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'led' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 2, \
                "The 'led' numpy.ndarray() must have a size of 2"
            self._led = value
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
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'led' field must be a set or sequence with length 2 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._led = numpy.array(value, dtype=numpy.uint8)

    @property
    def angle(self):
        """Message field 'angle'."""
        return self._angle

    @angle.setter
    def angle(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'angle' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 2, \
                "The 'angle' numpy.ndarray() must have a size of 2"
            self._angle = value
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
                "The 'angle' field must be a set or sequence with length 2 and each value of type 'float'"
        self._angle = numpy.array(value, dtype=numpy.float32)
