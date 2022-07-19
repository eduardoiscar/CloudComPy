//##########################################################################
//#                                                                        #
//#                              CloudComPy                                #
//#                                                                        #
//#  This program is free software; you can redistribute it and/or modify  #
//#  it under the terms of the GNU General Public License as published by  #
//#  the Free Software Foundation; either version 3 of the License, or     #
//#  any later version.                                                    #
//#                                                                        #
//#  This program is distributed in the hope that it will be useful,       #
//#  but WITHOUT ANY WARRANTY; without even the implied warranty of        #
//#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the          #
//#  GNU General Public License for more details.                          #
//#                                                                        #
//#  You should have received a copy of the GNU General Public License     #
//#  along with this program. If not, see <https://www.gnu.org/licenses/>. #
//#                                                                        #
//#          Copyright 2020-2021 Paul RASCLE www.openfields.fr             #
//#                                                                        #
//##########################################################################

#ifndef CCSENSORPY_DOCSTRINGS_HPP_
#define CCSENSORPY_DOCSTRINGS_HPP_

const char* ccSensorPy_ccSensor_doc= R"(
Generic sensor interface

Sensor information is provided in acquisition file with clouds,
for instance in ``.e57`` format files.
New sensor framework now relies on separate positions (stored
in a buffer) as generated by a GPS/IMU. This way, sensor objects
only contains intrinsic parameters. They are also associated
to a 'rigid transformation' (e.g. a rigid mechanical link between
the sensor 'optical' center and the GPS/IMU center position).

constructor:

:param string name: sensor name.
)";

const char* ccSensorPy_ccSensor_getType_doc= R"(
Returns the Sensor type, from :py:class:`CC_SENSOR_TYPE`.
Possibles values are UNKNOWN_SENSOR or GROUND_BASED_LIDAR

:return: Sensor type
:rtype: :py:class:`CC_SENSOR_TYPE`
)";

const char* ccSensorPy_ccSensor_getRigidTransformation_doc= R"(
Returns the rigid transformation between this sensor and its associated positions

:return: a rigid transformation
:rtype: :py:class:`ccGLMatrix`
)";

const char* ccSensorPy_ccSensor_getGraphicScale_doc= R"(
Returns the sensor graphic representation scale

:return: the sensor graphic representation scale
:rtype: float
)";

const char* ccSensorPy_ccSensor_ComputeScatteringAnglesPy_doc= R"(
Compute scattering angles for this sensor.
The result is a new or updated scalar field on the cloud.

:param ccPointCloud,optional cloud: cloud on which the scattering angles are computed, default parent point cloud
:param bool,optional toDegreeFlag: whether to convert angles in degrees or leave in radians, default True
)";

const char* ccSensorPy_ccSensor_addPosition_doc= R"(
Adds a new position

:param ccGLMatrix trans: transformation matrix associated to the new position.

:return: success
:rtype: bool
)";

const char* ccSensorPy_ccSensor_setRigidTransformation_doc= R"(
Sets the rigid transformation between this sensor and its associated positions
Rigid transformation goes from the sensor position(s) to the sensor "optical" center.

:param ccGLMatrix mat: transformation matrix.
)";

const char* ccSensorPy_ccSensor_setGraphicScale_doc= R"(
Sets the sensor graphic representation scale

:param float scale: graphic representation scale
)";
//const char* ccSensorPy_ccSensor__doc= R"()";
//const char* ccSensorPy_ccSensor__doc= R"()";

const char* ccSensorPy_ccGBLSensor_doc= R"(
Ground-based Laser sensor
An implementation of the ccSensor interface that can be used to represent a depth sensor
relying on 2 rotations relatively to two perpendicular axes, such as ground based laser
scanners typically.

constructor:

:param ROTATION_ORDER,optional rotOrder: default ROTATION_ORDER.YAW_THEN_PITCH
)";

const char* ccSensorPy_ccGBLSensor_getUncertainty_doc= R"(
Returns the Z-buffer uncertainty on depth values.
The uncertainty is used to handle numerical inaccuracies.

:return: Z-buffer uncertainty on depth values.
:rtype: float
)";

const char* ccSensorPy_ccGBLSensor_getType_doc= R"(
Returns the Sensor type, from :py:class:`CC_SENSOR_TYPE`.
Possibles values are UNKNOWN_SENSOR or GROUND_BASED_LIDAR

:return: Sensor type
:rtype: :py:class:`CC_SENSOR_TYPE`
)";

//const char* ccSensorPy_ccGBLSensor__doc= R"()";
//const char* ccSensorPy_ccGBLSensor__doc= R"()";

#endif /* CCSENSORPY_DOCSTRINGS_HPP_ */
