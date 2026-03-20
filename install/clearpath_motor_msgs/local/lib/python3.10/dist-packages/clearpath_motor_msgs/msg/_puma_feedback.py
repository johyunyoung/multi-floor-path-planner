# generated from rosidl_generator_py/resource/_idl.py.em
# with input from clearpath_motor_msgs:msg/PumaFeedback.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_PumaFeedback(type):
    """Metaclass of message 'PumaFeedback'."""

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
            module = import_type_support('clearpath_motor_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'clearpath_motor_msgs.msg.PumaFeedback')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__puma_feedback
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__puma_feedback
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__puma_feedback
            cls._TYPE_SUPPORT = module.type_support_msg__msg__puma_feedback
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__puma_feedback

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PumaFeedback(metaclass=Metaclass_PumaFeedback):
    """Message class 'PumaFeedback'."""

    __slots__ = [
        '_device_number',
        '_device_name',
        '_duty_cycle',
        '_current',
        '_travel',
        '_speed',
        '_setpoint',
    ]

    _fields_and_field_types = {
        'device_number': 'uint8',
        'device_name': 'string',
        'duty_cycle': 'float',
        'current': 'float',
        'travel': 'double',
        'speed': 'double',
        'setpoint': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.device_number = kwargs.get('device_number', int())
        self.device_name = kwargs.get('device_name', str())
        self.duty_cycle = kwargs.get('duty_cycle', float())
        self.current = kwargs.get('current', float())
        self.travel = kwargs.get('travel', float())
        self.speed = kwargs.get('speed', float())
        self.setpoint = kwargs.get('setpoint', float())

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
        if self.device_number != other.device_number:
            return False
        if self.device_name != other.device_name:
            return False
        if self.duty_cycle != other.duty_cycle:
            return False
        if self.current != other.current:
            return False
        if self.travel != other.travel:
            return False
        if self.speed != other.speed:
            return False
        if self.setpoint != other.setpoint:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def device_number(self):
        """Message field 'device_number'."""
        return self._device_number

    @device_number.setter
    def device_number(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'device_number' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'device_number' field must be an unsigned integer in [0, 255]"
        self._device_number = value

    @builtins.property
    def device_name(self):
        """Message field 'device_name'."""
        return self._device_name

    @device_name.setter
    def device_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'device_name' field must be of type 'str'"
        self._device_name = value

    @builtins.property
    def duty_cycle(self):
        """Message field 'duty_cycle'."""
        return self._duty_cycle

    @duty_cycle.setter
    def duty_cycle(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'duty_cycle' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'duty_cycle' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._duty_cycle = value

    @builtins.property
    def current(self):
        """Message field 'current'."""
        return self._current

    @current.setter
    def current(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'current' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'current' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._current = value

    @builtins.property
    def travel(self):
        """Message field 'travel'."""
        return self._travel

    @travel.setter
    def travel(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'travel' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'travel' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._travel = value

    @builtins.property
    def speed(self):
        """Message field 'speed'."""
        return self._speed

    @speed.setter
    def speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'speed' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'speed' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._speed = value

    @builtins.property
    def setpoint(self):
        """Message field 'setpoint'."""
        return self._setpoint

    @setpoint.setter
    def setpoint(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'setpoint' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'setpoint' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._setpoint = value
