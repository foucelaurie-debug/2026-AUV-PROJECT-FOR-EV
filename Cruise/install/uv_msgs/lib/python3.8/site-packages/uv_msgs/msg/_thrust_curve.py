# generated from rosidl_generator_py/resource/_idl.py.em
# with input from uv_msgs:msg/ThrustCurve.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ThrustCurve(type):
    """Metaclass of message 'ThrustCurve'."""

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
                'uv_msgs.msg.ThrustCurve')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__thrust_curve
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__thrust_curve
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__thrust_curve
            cls._TYPE_SUPPORT = module.type_support_msg__msg__thrust_curve
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__thrust_curve

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ThrustCurve(metaclass=Metaclass_ThrustCurve):
    """Message class 'ThrustCurve'."""

    __slots__ = [
        '_num',
        '_np_mid',
        '_np_ini',
        '_pp_ini',
        '_pp_mid',
        '_nt_end',
        '_nt_mid',
        '_pt_mid',
        '_pt_end',
    ]

    _fields_and_field_types = {
        'num': 'uint8',
        'np_mid': 'float',
        'np_ini': 'float',
        'pp_ini': 'float',
        'pp_mid': 'float',
        'nt_end': 'float',
        'nt_mid': 'float',
        'pt_mid': 'float',
        'pt_end': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.num = kwargs.get('num', int())
        self.np_mid = kwargs.get('np_mid', float())
        self.np_ini = kwargs.get('np_ini', float())
        self.pp_ini = kwargs.get('pp_ini', float())
        self.pp_mid = kwargs.get('pp_mid', float())
        self.nt_end = kwargs.get('nt_end', float())
        self.nt_mid = kwargs.get('nt_mid', float())
        self.pt_mid = kwargs.get('pt_mid', float())
        self.pt_end = kwargs.get('pt_end', float())

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
        if self.num != other.num:
            return False
        if self.np_mid != other.np_mid:
            return False
        if self.np_ini != other.np_ini:
            return False
        if self.pp_ini != other.pp_ini:
            return False
        if self.pp_mid != other.pp_mid:
            return False
        if self.nt_end != other.nt_end:
            return False
        if self.nt_mid != other.nt_mid:
            return False
        if self.pt_mid != other.pt_mid:
            return False
        if self.pt_end != other.pt_end:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def num(self):
        """Message field 'num'."""
        return self._num

    @num.setter
    def num(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'num' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'num' field must be an unsigned integer in [0, 255]"
        self._num = value

    @property
    def np_mid(self):
        """Message field 'np_mid'."""
        return self._np_mid

    @np_mid.setter
    def np_mid(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'np_mid' field must be of type 'float'"
        self._np_mid = value

    @property
    def np_ini(self):
        """Message field 'np_ini'."""
        return self._np_ini

    @np_ini.setter
    def np_ini(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'np_ini' field must be of type 'float'"
        self._np_ini = value

    @property
    def pp_ini(self):
        """Message field 'pp_ini'."""
        return self._pp_ini

    @pp_ini.setter
    def pp_ini(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pp_ini' field must be of type 'float'"
        self._pp_ini = value

    @property
    def pp_mid(self):
        """Message field 'pp_mid'."""
        return self._pp_mid

    @pp_mid.setter
    def pp_mid(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pp_mid' field must be of type 'float'"
        self._pp_mid = value

    @property
    def nt_end(self):
        """Message field 'nt_end'."""
        return self._nt_end

    @nt_end.setter
    def nt_end(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'nt_end' field must be of type 'float'"
        self._nt_end = value

    @property
    def nt_mid(self):
        """Message field 'nt_mid'."""
        return self._nt_mid

    @nt_mid.setter
    def nt_mid(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'nt_mid' field must be of type 'float'"
        self._nt_mid = value

    @property
    def pt_mid(self):
        """Message field 'pt_mid'."""
        return self._pt_mid

    @pt_mid.setter
    def pt_mid(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pt_mid' field must be of type 'float'"
        self._pt_mid = value

    @property
    def pt_end(self):
        """Message field 'pt_end'."""
        return self._pt_end

    @pt_end.setter
    def pt_end(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pt_end' field must be of type 'float'"
        self._pt_end = value
