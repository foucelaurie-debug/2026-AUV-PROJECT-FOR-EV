# generated from rosidl_generator_py/resource/_idl.py.em
# with input from uv_msgs:msg/TargetParams.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TargetParams(type):
    """Metaclass of message 'TargetParams'."""

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
                'uv_msgs.msg.TargetParams')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__target_params
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__target_params
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__target_params
            cls._TYPE_SUPPORT = module.type_support_msg__msg__target_params
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__target_params

            from uv_msgs.msg import PixelAxis
            if PixelAxis.__class__._TYPE_SUPPORT is None:
                PixelAxis.__class__.__import_type_support__()

            from uv_msgs.msg import TargetAxis
            if TargetAxis.__class__._TYPE_SUPPORT is None:
                TargetAxis.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TargetParams(metaclass=Metaclass_TargetParams):
    """Message class 'TargetParams'."""

    __slots__ = [
        '_tpos_inpic',
        '_tpos_inworld',
    ]

    _fields_and_field_types = {
        'tpos_inpic': 'uv_msgs/PixelAxis',
        'tpos_inworld': 'uv_msgs/TargetAxis',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['uv_msgs', 'msg'], 'PixelAxis'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['uv_msgs', 'msg'], 'TargetAxis'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from uv_msgs.msg import PixelAxis
        self.tpos_inpic = kwargs.get('tpos_inpic', PixelAxis())
        from uv_msgs.msg import TargetAxis
        self.tpos_inworld = kwargs.get('tpos_inworld', TargetAxis())

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
        if self.tpos_inpic != other.tpos_inpic:
            return False
        if self.tpos_inworld != other.tpos_inworld:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def tpos_inpic(self):
        """Message field 'tpos_inpic'."""
        return self._tpos_inpic

    @tpos_inpic.setter
    def tpos_inpic(self, value):
        if __debug__:
            from uv_msgs.msg import PixelAxis
            assert \
                isinstance(value, PixelAxis), \
                "The 'tpos_inpic' field must be a sub message of type 'PixelAxis'"
        self._tpos_inpic = value

    @property
    def tpos_inworld(self):
        """Message field 'tpos_inworld'."""
        return self._tpos_inworld

    @tpos_inworld.setter
    def tpos_inworld(self, value):
        if __debug__:
            from uv_msgs.msg import TargetAxis
            assert \
                isinstance(value, TargetAxis), \
                "The 'tpos_inworld' field must be a sub message of type 'TargetAxis'"
        self._tpos_inworld = value
