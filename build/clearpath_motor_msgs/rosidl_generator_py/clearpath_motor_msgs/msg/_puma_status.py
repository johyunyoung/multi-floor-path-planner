# generated from rosidl_generator_py/resource/_idl.py.em
# with input from clearpath_motor_msgs:msg/PumaStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_PumaStatus(type):
    """Metaclass of message 'PumaStatus'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'MODE_VOLTAGE': 0,
        'MODE_CURRENT': 1,
        'MODE_SPEED': 2,
        'MODE_POSITION': 3,
        'MODE_VCOMP': 4,
        'FAULT_CURRENT': 1,
        'FAULT_TEMPERATURE': 2,
        'FAULT_BUS_VOLTAGE': 4,
        'FAULT_BRIDGE_DRIVER': 8,
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
                'clearpath_motor_msgs.msg.PumaStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__puma_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__puma_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__puma_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__puma_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__puma_status

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'MODE_VOLTAGE': cls.__constants['MODE_VOLTAGE'],
            'MODE_CURRENT': cls.__constants['MODE_CURRENT'],
            'MODE_SPEED': cls.__constants['MODE_SPEED'],
            'MODE_POSITION': cls.__constants['MODE_POSITION'],
            'MODE_VCOMP': cls.__constants['MODE_VCOMP'],
            'FAULT_CURRENT': cls.__constants['FAULT_CURRENT'],
            'FAULT_TEMPERATURE': cls.__constants['FAULT_TEMPERATURE'],
            'FAULT_BUS_VOLTAGE': cls.__constants['FAULT_BUS_VOLTAGE'],
            'FAULT_BRIDGE_DRIVER': cls.__constants['FAULT_BRIDGE_DRIVER'],
        }

    @property
    def MODE_VOLTAGE(self):
        """Message constant 'MODE_VOLTAGE'."""
        return Metaclass_PumaStatus.__constants['MODE_VOLTAGE']

    @property
    def MODE_CURRENT(self):
        """Message constant 'MODE_CURRENT'."""
        return Metaclass_PumaStatus.__constants['MODE_CURRENT']

    @property
    def MODE_SPEED(self):
        """Message constant 'MODE_SPEED'."""
        return Metaclass_PumaStatus.__constants['MODE_SPEED']

    @property
    def MODE_POSITION(self):
        """Message constant 'MODE_POSITION'."""
        return Metaclass_PumaStatus.__constants['MODE_POSITION']

    @property
    def MODE_VCOMP(self):
        """Message constant 'MODE_VCOMP'."""
        return Metaclass_PumaStatus.__constants['MODE_VCOMP']

    @property
    def FAULT_CURRENT(self):
        """Message constant 'FAULT_CURRENT'."""
        return Metaclass_PumaStatus.__constants['FAULT_CURRENT']

    @property
    def FAULT_TEMPERATURE(self):
        """Message constant 'FAULT_TEMPERATURE'."""
        return Metaclass_PumaStatus.__constants['FAULT_TEMPERATURE']

    @property
    def FAULT_BUS_VOLTAGE(self):
        """Message constant 'FAULT_BUS_VOLTAGE'."""
        return Metaclass_PumaStatus.__constants['FAULT_BUS_VOLTAGE']

    @property
    def FAULT_BRIDGE_DRIVER(self):
        """Message constant 'FAULT_BRIDGE_DRIVER'."""
        return Metaclass_PumaStatus.__constants['FAULT_BRIDGE_DRIVER']


class PumaStatus(metaclass=Metaclass_PumaStatus):
    """
    Message class 'PumaStatus'.

    Constants:
      MODE_VOLTAGE
      MODE_CURRENT
      MODE_SPEED
      MODE_POSITION
      MODE_VCOMP
      FAULT_CURRENT
      FAULT_TEMPERATURE
      FAULT_BUS_VOLTAGE
      FAULT_BRIDGE_DRIVER
    """

    __slots__ = [
        '_device_number',
        '_device_name',
        '_bus_voltage',
        '_temperature',
        '_output_voltage',
        '_analog_input',
        '_mode',
        '_fault',
    ]

    _fields_and_field_types = {
        'device_number': 'uint8',
        'device_name': 'string',
        'bus_voltage': 'float',
        'temperature': 'float',
        'output_voltage': 'float',
        'analog_input': 'float',
        'mode': 'uint8',
        'fault': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.device_number = kwargs.get('device_number', int())
        self.device_name = kwargs.get('device_name', str())
        self.bus_voltage = kwargs.get('bus_voltage', float())
        self.temperature = kwargs.get('temperature', float())
        self.output_voltage = kwargs.get('output_voltage', float())
        self.analog_input = kwargs.get('analog_input', float())
        self.mode = kwargs.get('mode', int())
        self.fault = kwargs.get('fault', int())

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
        if self.bus_voltage != other.bus_voltage:
            return False
        if self.temperature != other.temperature:
            return False
        if self.output_voltage != other.output_voltage:
            return False
        if self.analog_input != other.analog_input:
            return False
        if self.mode != other.mode:
            return False
        if self.fault != other.fault:
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
    def bus_voltage(self):
        """Message field 'bus_voltage'."""
        return self._bus_voltage

    @bus_voltage.setter
    def bus_voltage(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'bus_voltage' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'bus_voltage' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._bus_voltage = value

    @builtins.property
    def temperature(self):
        """Message field 'temperature'."""
        return self._temperature

    @temperature.setter
    def temperature(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'temperature' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'temperature' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._temperature = value

    @builtins.property
    def output_voltage(self):
        """Message field 'output_voltage'."""
        return self._output_voltage

    @output_voltage.setter
    def output_voltage(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'output_voltage' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'output_voltage' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._output_voltage = value

    @builtins.property
    def analog_input(self):
        """Message field 'analog_input'."""
        return self._analog_input

    @analog_input.setter
    def analog_input(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'analog_input' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'analog_input' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._analog_input = value

    @builtins.property
    def mode(self):
        """Message field 'mode'."""
        return self._mode

    @mode.setter
    def mode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mode' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'mode' field must be an unsigned integer in [0, 255]"
        self._mode = value

    @builtins.property
    def fault(self):
        """Message field 'fault'."""
        return self._fault

    @fault.setter
    def fault(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'fault' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'fault' field must be an unsigned integer in [0, 255]"
        self._fault = value
