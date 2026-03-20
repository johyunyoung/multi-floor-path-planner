from setuptools import find_packages
from setuptools import setup

setup(
    name='clearpath_motor_msgs',
    version='1.0.1',
    packages=find_packages(
        include=('clearpath_motor_msgs', 'clearpath_motor_msgs.*')),
)
