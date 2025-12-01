# generated from rosidl_generator_py/resource/_idl.py.em
# with input from uv_msgs:msg/PidControllersState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_PidControllersState(type):
    """Metaclass of message 'PidControllersState'."""

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
                'uv_msgs.msg.PidControllersState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__pid_controllers_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__pid_controllers_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__pid_controllers_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__pid_controllers_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__pid_controllers_state

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PidControllersState(metaclass=Metaclass_PidControllersState):
    """Message class 'PidControllersState'."""

    __slots__ = [
        '_x',
        '_y',
        '_z',
        '_rx',
        '_ry',
        '_rz',
        '_vy',
        '_vx',
    ]

    _fields_and_field_types = {
        'x': 'uint8',
        'y': 'uint8',
        'z': 'uint8',
        'rx': 'uint8',
        'ry': 'uint8',
        'rz': 'uint8',
        'vy': 'uint8',
        'vx': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.x = kwargs.get('x', int())
        self.y = kwargs.get('y', int())
        self.z = kwargs.get('z', int())
        self.rx = kwargs.get('rx', int())
        self.ry = kwargs.get('ry', int())
        self.rz = kwargs.get('rz', int())
        self.vy = kwargs.get('vy', int())
        self.vx = kwargs.get('vx', int())

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
        if self.x != other.x:
            return False
        if self.y != other.y:
            return False
        if self.z != other.z:
            return False
        if self.rx != other.rx:
            return False
        if self.ry != other.ry:
            return False
        if self.rz != other.rz:
            return False
        if self.vy != other.vy:
            return False
        if self.vx != other.vx:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def x(self):
        """Message field 'x'."""
        return self._x

    @x.setter
    def x(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'x' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'x' field must be an unsigned integer in [0, 255]"
        self._x = value

    @property
    def y(self):
        """Message field 'y'."""
        return self._y

    @y.setter
    def y(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'y' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'y' field must be an unsigned integer in [0, 255]"
        self._y = value

    @property
    def z(self):
        """Message field 'z'."""
        return self._z

    @z.setter
    def z(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'z' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'z' field must be an unsigned integer in [0, 255]"
        self._z = value

    @property
    def rx(self):
        """Message field 'rx'."""
        return self._rx

    @rx.setter
    def rx(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'rx' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'rx' field must be an unsigned integer in [0, 255]"
        self._rx = value

    @property
    def ry(self):
        """Message field 'ry'."""
        return self._ry

    @ry.setter
    def ry(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ry' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'ry' field must be an unsigned integer in [0, 255]"
        self._ry = value

    @property
    def rz(self):
        """Message field 'rz'."""
        return self._rz

    @rz.setter
    def rz(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'rz' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'rz' field must be an unsigned integer in [0, 255]"
        self._rz = value

    @property
    def vy(self):
        """Message field 'vy'."""
        return self._vy

    @vy.setter
    def vy(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'vy' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'vy' field must be an unsigned integer in [0, 255]"
        self._vy = value

    @property
    def vx(self):
        """Message field 'vx'."""
        return self._vx

    @vx.setter
    def vx(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'vx' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'vx' field must be an unsigned integer in [0, 255]"
        self._vx = value
