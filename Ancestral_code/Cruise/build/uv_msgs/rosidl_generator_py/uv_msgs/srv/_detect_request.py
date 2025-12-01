# generated from rosidl_generator_py/resource/_idl.py.em
# with input from uv_msgs:srv/DetectRequest.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DetectRequest_Request(type):
    """Metaclass of message 'DetectRequest_Request'."""

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
                'uv_msgs.srv.DetectRequest_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__detect_request__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__detect_request__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__detect_request__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__detect_request__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__detect_request__request

            from sensor_msgs.msg import Image
            if Image.__class__._TYPE_SUPPORT is None:
                Image.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DetectRequest_Request(metaclass=Metaclass_DetectRequest_Request):
    """Message class 'DetectRequest_Request'."""

    __slots__ = [
        '_imagein',
        '_target',
        '_stero',
    ]

    _fields_and_field_types = {
        'imagein': 'sensor_msgs/Image',
        'target': 'string',
        'stero': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'Image'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from sensor_msgs.msg import Image
        self.imagein = kwargs.get('imagein', Image())
        self.target = kwargs.get('target', str())
        self.stero = kwargs.get('stero', str())

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
        if self.imagein != other.imagein:
            return False
        if self.target != other.target:
            return False
        if self.stero != other.stero:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def imagein(self):
        """Message field 'imagein'."""
        return self._imagein

    @imagein.setter
    def imagein(self, value):
        if __debug__:
            from sensor_msgs.msg import Image
            assert \
                isinstance(value, Image), \
                "The 'imagein' field must be a sub message of type 'Image'"
        self._imagein = value

    @property
    def target(self):
        """Message field 'target'."""
        return self._target

    @target.setter
    def target(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'target' field must be of type 'str'"
        self._target = value

    @property
    def stero(self):
        """Message field 'stero'."""
        return self._stero

    @stero.setter
    def stero(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'stero' field must be of type 'str'"
        self._stero = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_DetectRequest_Response(type):
    """Metaclass of message 'DetectRequest_Response'."""

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
                'uv_msgs.srv.DetectRequest_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__detect_request__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__detect_request__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__detect_request__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__detect_request__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__detect_request__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DetectRequest_Response(metaclass=Metaclass_DetectRequest_Response):
    """Message class 'DetectRequest_Response'."""

    __slots__ = [
        '_s',
        '_x',
        '_y',
        '_z',
    ]

    _fields_and_field_types = {
        's': 'uint8',
        'x': 'float',
        'y': 'float',
        'z': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.s = kwargs.get('s', int())
        self.x = kwargs.get('x', float())
        self.y = kwargs.get('y', float())
        self.z = kwargs.get('z', float())

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
        if self.s != other.s:
            return False
        if self.x != other.x:
            return False
        if self.y != other.y:
            return False
        if self.z != other.z:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def s(self):
        """Message field 's'."""
        return self._s

    @s.setter
    def s(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 's' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 's' field must be an unsigned integer in [0, 255]"
        self._s = value

    @property
    def x(self):
        """Message field 'x'."""
        return self._x

    @x.setter
    def x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'x' field must be of type 'float'"
        self._x = value

    @property
    def y(self):
        """Message field 'y'."""
        return self._y

    @y.setter
    def y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'y' field must be of type 'float'"
        self._y = value

    @property
    def z(self):
        """Message field 'z'."""
        return self._z

    @z.setter
    def z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'z' field must be of type 'float'"
        self._z = value


class Metaclass_DetectRequest(type):
    """Metaclass of service 'DetectRequest'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('uv_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'uv_msgs.srv.DetectRequest')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__detect_request

            from uv_msgs.srv import _detect_request
            if _detect_request.Metaclass_DetectRequest_Request._TYPE_SUPPORT is None:
                _detect_request.Metaclass_DetectRequest_Request.__import_type_support__()
            if _detect_request.Metaclass_DetectRequest_Response._TYPE_SUPPORT is None:
                _detect_request.Metaclass_DetectRequest_Response.__import_type_support__()


class DetectRequest(metaclass=Metaclass_DetectRequest):
    from uv_msgs.srv._detect_request import DetectRequest_Request as Request
    from uv_msgs.srv._detect_request import DetectRequest_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
