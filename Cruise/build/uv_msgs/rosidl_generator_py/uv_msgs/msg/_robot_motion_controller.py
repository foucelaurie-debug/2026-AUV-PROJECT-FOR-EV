# generated from rosidl_generator_py/resource/_idl.py.em
# with input from uv_msgs:msg/RobotMotionController.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RobotMotionController(type):
    """Metaclass of message 'RobotMotionController'."""

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
                'uv_msgs.msg.RobotMotionController')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__robot_motion_controller
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__robot_motion_controller
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__robot_motion_controller
            cls._TYPE_SUPPORT = module.type_support_msg__msg__robot_motion_controller
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__robot_motion_controller

            from uv_msgs.msg import ImuData
            if ImuData.__class__._TYPE_SUPPORT is None:
                ImuData.__class__.__import_type_support__()

            from uv_msgs.msg import MotorThrust
            if MotorThrust.__class__._TYPE_SUPPORT is None:
                MotorThrust.__class__.__import_type_support__()

            from uv_msgs.msg import PidControllersState
            if PidControllersState.__class__._TYPE_SUPPORT is None:
                PidControllersState.__class__.__import_type_support__()

            from uv_msgs.msg import RobotAxis
            if RobotAxis.__class__._TYPE_SUPPORT is None:
                RobotAxis.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RobotMotionController(metaclass=Metaclass_RobotMotionController):
    """Message class 'RobotMotionController'."""

    __slots__ = [
        '_pos',
        '_tpos_inbase',
        '_tpos_inworld',
        '_imu',
        '_thrust',
        '_pidstate',
    ]

    _fields_and_field_types = {
        'pos': 'uv_msgs/RobotAxis',
        'tpos_inbase': 'uv_msgs/RobotAxis',
        'tpos_inworld': 'uv_msgs/RobotAxis',
        'imu': 'uv_msgs/ImuData',
        'thrust': 'uv_msgs/MotorThrust',
        'pidstate': 'uv_msgs/PidControllersState',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['uv_msgs', 'msg'], 'RobotAxis'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['uv_msgs', 'msg'], 'RobotAxis'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['uv_msgs', 'msg'], 'RobotAxis'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['uv_msgs', 'msg'], 'ImuData'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['uv_msgs', 'msg'], 'MotorThrust'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['uv_msgs', 'msg'], 'PidControllersState'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from uv_msgs.msg import RobotAxis
        self.pos = kwargs.get('pos', RobotAxis())
        from uv_msgs.msg import RobotAxis
        self.tpos_inbase = kwargs.get('tpos_inbase', RobotAxis())
        from uv_msgs.msg import RobotAxis
        self.tpos_inworld = kwargs.get('tpos_inworld', RobotAxis())
        from uv_msgs.msg import ImuData
        self.imu = kwargs.get('imu', ImuData())
        from uv_msgs.msg import MotorThrust
        self.thrust = kwargs.get('thrust', MotorThrust())
        from uv_msgs.msg import PidControllersState
        self.pidstate = kwargs.get('pidstate', PidControllersState())

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
        if self.pos != other.pos:
            return False
        if self.tpos_inbase != other.tpos_inbase:
            return False
        if self.tpos_inworld != other.tpos_inworld:
            return False
        if self.imu != other.imu:
            return False
        if self.thrust != other.thrust:
            return False
        if self.pidstate != other.pidstate:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def pos(self):
        """Message field 'pos'."""
        return self._pos

    @pos.setter
    def pos(self, value):
        if __debug__:
            from uv_msgs.msg import RobotAxis
            assert \
                isinstance(value, RobotAxis), \
                "The 'pos' field must be a sub message of type 'RobotAxis'"
        self._pos = value

    @property
    def tpos_inbase(self):
        """Message field 'tpos_inbase'."""
        return self._tpos_inbase

    @tpos_inbase.setter
    def tpos_inbase(self, value):
        if __debug__:
            from uv_msgs.msg import RobotAxis
            assert \
                isinstance(value, RobotAxis), \
                "The 'tpos_inbase' field must be a sub message of type 'RobotAxis'"
        self._tpos_inbase = value

    @property
    def tpos_inworld(self):
        """Message field 'tpos_inworld'."""
        return self._tpos_inworld

    @tpos_inworld.setter
    def tpos_inworld(self, value):
        if __debug__:
            from uv_msgs.msg import RobotAxis
            assert \
                isinstance(value, RobotAxis), \
                "The 'tpos_inworld' field must be a sub message of type 'RobotAxis'"
        self._tpos_inworld = value

    @property
    def imu(self):
        """Message field 'imu'."""
        return self._imu

    @imu.setter
    def imu(self, value):
        if __debug__:
            from uv_msgs.msg import ImuData
            assert \
                isinstance(value, ImuData), \
                "The 'imu' field must be a sub message of type 'ImuData'"
        self._imu = value

    @property
    def thrust(self):
        """Message field 'thrust'."""
        return self._thrust

    @thrust.setter
    def thrust(self, value):
        if __debug__:
            from uv_msgs.msg import MotorThrust
            assert \
                isinstance(value, MotorThrust), \
                "The 'thrust' field must be a sub message of type 'MotorThrust'"
        self._thrust = value

    @property
    def pidstate(self):
        """Message field 'pidstate'."""
        return self._pidstate

    @pidstate.setter
    def pidstate(self, value):
        if __debug__:
            from uv_msgs.msg import PidControllersState
            assert \
                isinstance(value, PidControllersState), \
                "The 'pidstate' field must be a sub message of type 'PidControllersState'"
        self._pidstate = value
