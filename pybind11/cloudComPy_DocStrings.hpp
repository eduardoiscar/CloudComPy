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

#ifndef CLOUDCOMPY_DOCSTRINGS_HPP_
#define CLOUDCOMPY_DOCSTRINGS_HPP_

const char* cloudComPy_doc= R"(
cloudComPy is the Python module interfacing cloudCompare library.
Python3 access to cloudCompare objects is done like this:
::

  import cloudComPy as cc 
  cloud = cc.loadPointCloud("/home/paul/CloudComPy/Data/boule.bin")
 
 )";

const char* cloudComPy_ComputeVolume25D_doc= R"(
Compute a 2.5D volume between a cloud and a ground plane,or two clouds,following a given direction (X, Y or Z).

If only one cloud is given, the direction (X, Y or Z) defines the normal to the plane used for calculation.

:param ReportInfoVol reportInfo: the object instance to be completed with results
:param ccPointCloud ground: either a point cloud or None
:param ccPointCloud ceil: either a point cloud or None
:param int vertDim: direction from (0,1,2): 0: X, 1: Y, 2: Z
:param float gridStep: size of the grid step
:param float groundHeight: altitude of the ground plane along the direction, if ground is None
:param float ceilHeight: altitude of the ceil plane along the direction, if ceil is None

:return: True if success, False if problem detected in parameters
:rtype: bool
)";

const char* cloudComPy_deleteEntity_doc= R"(
Delete an entity and its children (mesh, cloud...)

**Warning** No automatic action on the Python side on the variables referencing the C++ object!
::

    cc.deleteEntity(anEntity)
    anEntity = None

:param ccHObject entity: the entity to remove)";

const char* cloudComPy_ExtractConnectedComponents_doc= R"(
Extracts connected components from a set of clouds.

This tool segments the selected cloud(s) in smaller parts separated by a minimum distance. 
Each part is a connected component (i.e. a set of 'connected' points). 
CloudCompare uses a 3D grid to extract the connected components.
This grid is deduced from the octree structure. 
By selecting on octree level you define how small is the minimum gap between two components.
If n is the octree level and d the dimension of the clouds (Bounding box side),
the gap is roughly d/2**n.

:param list[ccPointCloud] clouds: the set of clouds
:param int,optional octreeLevel: the octree level used to define the connection between nodes, default 8.
:param int,optional minComponentSize: the minimum number of nodes to constitute a component, default 100.
:param int,optional maxNumberComponents: maximum number of components accepted (default 100):
                                         The process stops when this number is reached. 
                                         The return gives the number of clouds already processed.
                                         Check this number to see if some clouds have not been processed.
:param bool optional randomColors: whether to color randomly the components or not, default False.

:return: a tuple (number of clouds processed, list of components)
:rtype: tuple
)";

const char* cloudComPy_ExtractSlicesAndContours_doc= R"(
Extract slices, envelopes and contours from a set of clouds and meshes (Cross section).

Slices are the part of cloud or mesh contained in the bounding box used as a tool to cut.
Slicing can be repeated selectively along the 3 directions X, Y, Z, with optional gaps between slices.
Optional envelopes are closed polylines defining a concave external boundary of the slices.
Optional contours are closed polylines defining boundaries (external and internal) of the slices.
The contours are built via a rasterisation process.

:param list[ccHObjects] entities: the list of point clouds and meshes to slice.
:param ccBBox bbox: the bounding box used as a slice tool.
:param ccGLMatrix,optional bboxTrans: optional transformation (rotation translation) of the bounding box, default identity.
:param boolean,optional singleSliceMode: whether to cut just one slice or repeat the process, default True, i.e. only one slice.
:param boolean,optional processRepeatX: whether to repeat along the X direction (if singleSliceMode False), default False. 
:param boolean,optional processRepeatY: whether to repeat along the Y direction (if singleSliceMode False), default False. 
:param boolean,optional processRepeatZ: whether to repeat along the Z direction (if singleSliceMode False), default True.
:param boolean,optional extractEnvelopes: whether to extract the envelopes or not, default False.
:param double,optional maxEdgeLength: maximum edge length for the envelope, default 0=convex envelope.
:param int,optional envelopeType: type of envelope, default 0.
                                  0: envelope built on the lower part of the slice, 1: upper part, 2: all the slice.
:param boolean,optional extractLevelSet: whether to extract contours or not, default False.
:param double,optional levelSetGridStep: grid step to use for the rasterisation needed to build the contours
:param int,optional levelSetMinVertCount: number of points required to define a contour, default 0 (change it!).
:param double,optional gap: gap between slices, default 0.
:param boolean,optional multiPass: Multi-pass process where longer edges may be temporarily created to obtain a better fit...
                                   or a worst one! Default False.
:param boolean,optional splitEnvelopes: split the generated contour(s) in smaller parts to avoid creating edges longer
                                        than the specified max edge length. Default False.
:param boolean,optional projectOnBestFitPlane: Before extracting the contour, points can be projected along the repeat dimension
                                               (if only one is defined) or on the best fit plane. Default False.
:param boolean,optionalgenerateRandomColors: whether to define random colors per slice (will overwrite existing colors!)
                                             or not. Default False.

:return: a tuple of 3 lists ([slices], [envelopes], [contours])
:rtype: tuple
)";

const char* cloudComPy_importFile_doc= R"(
Load the entities (cloud or mesh) from a file containing several entities,
and get file structure
(some files as ``.E57`` provide structured information on content, 
given here as a list of strings).

**WARNING** 
Shift parameters are not always taken into account, depending on the type of file,
shift values, following the internal rules of CloudCompare: when using the CloudCompare GUI,
shift dialog at import is not always available. When the shift dialog is not proposed
in the GUI, shift parameters are likely not taken into account in CloudCompare.

Optional string extraData can be used in ply file, for instance, to select extra fields
for import as scalarFields (by default, all extra fields are imported as scalar fields).
Here, the filter is a regular expression that works on the field name in uppercase.


:param str filename: file Name
:param CC_SHIFT_MODE,optional mode: default AUTO, value from AUTO, XYZ, FIRST_GLOBAL_SHIFT, NO_GLOBAL_SHIFT
:param float,optional x: default 0
:param float,optional y: default 0
:param float,optional z: default 0
:param string,optional extraData: default empty string

:return: a tuple (list of meshes, list of clouds, file structure)
:rtype: tuple
)";

const char* cloudComPy_interpolatorParameters_doc=R"(
Parameters for scalar fields interpolation from a source cloud to a destination cloud.

:ivar int method: from INTERPOL_METHOD: NEAREST_NEIGHBOR, K_NEAREST_NEIGHBORS, RADIUS, default NEAREST_NEIGHBOR
:ivar int algos: from INTERPOL_ALGO: AVERAGE, MEDIAN, NORMAL_DIST, default AVERAGE
:ivar int knn: number of neighbors, default 0
:ivar float radius: default 0
:ivar float sigma: default 0
)";

const char* cloudComPy_interpolateScalarFieldsFrom_doc=R"(
Interpolate scalar fields from a source cloud to a destination cloud.

:param ccPointCloud destCloud: the cloud receiving the interpolatated scalar fields.
:param ccPointCloud srcCloud: the source cloud containing the scalar fields to interpolate.
:param list sfIndexes: the list of indexes of scalar fields in the source cloud, to interpolate.
:param interpolatorParameters params: interpolation parameter structure
:param int,optional octreeLevel: octree level, default 0

:return: success
:rtype: bool
)";

const char* cloudComPy_ICPres_doc=R"(
Result values on ICP registration.

:ivar ccPointCloud aligned: the point cloud on which the transformation must be applied
:ivar ccGLMatrix transMat: the resulting transformation to apply
:ivar float finalScale: calculated scale if rescale required
:ivar float finalRMS: final error (RMS)
:ivar int finalPointCount: number of points used to compute the final RMS
)";

const char* cloudComPy_ICP_doc=R"(
Applies ICP registration on two entities.

:param ccHObject data: cloud to align.
:param ccHObject model: reference cloud.
:param float minRMSDecrease: The minimum error (RMS) reduction between two consecutive steps to continue process,
       if CONVERGENCE_TYPE == MAX_ERROR_CONVERGENCE.
:param int maxIterationCount: Stop after this number of iterations,
       if CONVERGENCE_TYPE == MAX_ITER_CONVERGENCE.
:param int randomSamplingLimit: Limit above which clouds should be randomly resampled.
:param bool removeFarthestPoints: If `True`, the algorithm will automatically ignore farthest points from the reference.
       This is a trick to improve registration for slightly different clouds.
:param CONVERGENCE_TYPE method: Mode of convergence, CONVERGENCE_TYPE.MAX_ITER_CONVERGENCE or CONVERGENCE_TYPE.MAX_ERROR_CONVERGENCE.
:param bool adjustScale: Whether to release the scale parameter during the registration procedure or not.
:param float,optional finalOverlapRatio: Theoretical overlap ratio (at each iteration, only this percentage (between 0 and 1).
       Will be used for registration (default 1.0).
:param bool,optional useDataSFAsWeights: Weights for data points (default `False`).
:param bool,optional useModelSFAsWeights: Weights for model points (default `False`).
:param TRANSFORMATION_FILTERS,optional transformationFilters: Filters to be applied on the resulting transformation at each step (default 0).

   - SKIP_NONE           = 0
   - SKIP_RXY            = 1
   - SKIP_RYZ            = 2
   - SKIP_RXZ            = 4
   - SKIP_ROTATION       = 7
   - SKIP_TX             = 8
   - SKIP_TY             = 16
   - SKIP_TZ             = 32
   - SKIP_TRANSLATION    = 56

:param int,optional maxThreadCount: Maximum number of threads to use (default 0 = max)

:return: ICPres structure :py:class:`ICPres`
)";

const char* cloudComPy_initCC_doc= R"(
Done at module init, should be done once before using plugins!)";

const char* cloudComPy_initCloudCompare_doc= R"(
Done at module init, should be done once after initCC before using plugins!)";

const char* cloudComPy_isPluginDraco_doc= R"(
returns True if CloudComPy is built with the Draco plugin.

:return: True if CloudComPy is built with the Draco plugin, False otherwise.
:rtype: bool)";

const char* cloudComPy_isPluginFbx_doc= R"(
returns True if CloudComPy is built with the Fbx plugin.

:return: True if CloudComPy is built with the Fbx plugin, False otherwise.
:rtype: bool)";

const char* cloudComPy_isPluginHPR_doc= R"(
returns True if CloudComPy is built with the HPR plugin.

:return: True if CloudComPy is built with the HPR plugin, False otherwise.
:rtype: bool)";

const char* cloudComPy_isPluginM3C2_doc= R"(
returns True if CloudComPy is built with the M3C2 plugin.

:return: True if CloudComPy is built with the M3C2 plugin, False otherwise.
:rtype: bool)";

const char* cloudComPy_isPluginMeshBoolean_doc= R"(
returns True if CloudComPy is built with the MeshBoolean plugin.

:return: True if CloudComPy is built with the MeshBoolean plugin, False otherwise.
:rtype: bool)";

const char* cloudComPy_isPluginPCL_doc= R"(
returns True if CloudComPy is built with the PCL plugin.

:return: True if CloudComPy is built with the PCL plugin, False otherwise.
:rtype: bool)";

const char* cloudComPy_isPluginPCV_doc= R"(
returns True if CloudComPy is built with the PCV plugin.

:return: True if CloudComPy is built with the PCV plugin, False otherwise.
:rtype: bool)";

const char* cloudComPy_isPluginCSF_doc= R"(
returns True if CloudComPy is built with the CSF plugin.

:return: True if CloudComPy is built with the CSF plugin, False otherwise.
:rtype: bool)";

const char* cloudComPy_isPluginRANSAC_SD_doc= R"(
returns True if CloudComPy is built with the RANSAC_SD plugin.

:return: True if CloudComPy is built with the RANSAC_SD plugin, False otherwise.
:rtype: bool)";

const char* cloudComPy_loadPointCloud_doc= R"(
Load a 3D cloud from a file.

**WARNING** 
Shift parameters are not always taken into account, depending on the type of file,
shift values, following the internal rules of CloudCompare: when using the CloudCompare GUI,
shift dialog at import is not always available. When the shift dialog is not proposed
in the GUI, shift parameters are likely not taken into account in CloudCompare.

Optional string extraData can be used in ply file, for instance, to select extra fields
for import as scalarFields (by default, all extra fields are imported as scalar fields).
Here, the filter is a regular expression that works on the field name in uppercase.

:param str filename: file name
:param CC_SHIFT_MODE,optional shiftMode: shift mode from `CC_SHIFT_MODE` enum, default `AUTO`.

  - `CC_SHIFT_MODE.AUTO`: automatic shift of coordinates
  - `CC_SHIFT_MODE.XYZ`:  coordinates shift given by x, y, z parameters
  - `CC_SHIFT_MODE.FIRST_GLOBAL_SHIFT`: use the first encountered global shift value (if any)
  - `CC_SHIFT_MODE.NO_GLOBAL_SHIFT`: no shift at all 

:param int,optional skip: parameter not used yet! default 0
:param float,optional x: shift value for coordinates (mode XYZ),  default 0
:param float,optional y: shift value for coordinates (mode XYZ),  default 0
:param float,optional z: shift value for coordinates (mode XYZ),  default 0
:param string,optional extraData: default empty string

:return: a `ccPointCloud` object. Usage: see ccPointCloud doc.
:rtype: ccPointCloud)";

const char* cloudComPy_loadMesh_doc= R"(
Load a Mesh from a file.

**WARNING** 
Shift parameters are not always taken into account, depending on the type of file,
shift values, following the internal rules of CloudCompare: when using the CloudCompare GUI,
shift dialog at import is not always available. When the shift dialog is not proposed
in the GUI, shift parameters are likely not taken into account in CloudCompare.
 
Optional string extraData can be used in ply file, for instance, to select extra fields
for import as scalarFields (by default, all extra fields are imported as scalar fields).
Here, the filter is a regular expression that works on the field name in uppercase.
 
:param str filename: file name
:param CC_SHIFT_MODE,optional shiftMode: shift mode from `CC_SHIFT_MODE` enum, default `AUTO`.

  - `CC_SHIFT_MODE.AUTO`: automatic shift of coordinates
  - `CC_SHIFT_MODE.XYZ`:  coordinates shift given by x, y, z parameters
  - `CC_SHIFT_MODE.FIRST_GLOBAL_SHIFT`: use the first encountered global shift value (if any)
  - `CC_SHIFT_MODE.NO_GLOBAL_SHIFT`: no shift at all 
  
:param int,optional skip: parameter not used yet! default 0
:param float,optional x: shift value for coordinates (mode XYZ),  default 0
:param float,optional y: shift value for coordinates (mode XYZ),  default 0
:param float,optional z: shift value for coordinates (mode XYZ),  default 0
:param string,optional extraData: default empty string

:return: a `ccMesh` object. Usage: see ccMesh doc.
:rtype: ccMesh)";

const char* cloudComPy_loadPolyline_doc= R"(
Load a polyline from a file.

:param str filename: The polyline file.
:param CC_SHIFT_MODE,optional mode: from (AUTO, XYZ),  optional, default AUTO.

  - AUTO: automatic shift of coordinates
  - XYZ:  coordinates shift given by x, y, z parameters

:param int,optional skip: not used yet! default 0.
:param float,optional x: optional shift value for coordinates (mode XYZ), default 0
:param float,optional y: optional shift value for coordinates (mode XYZ), default 0
:param float,optional z: optional shift value for coordinates (mode XYZ), default 0

:return: a ccPolyline object.
:rtype: ccPolyline

Usage: see ccPolyline doc.)";

const char* cloudComPy_ReportInfoVol_doc= R"(
Result values on 2.5D volume calculation. See :py:class:`ComputeVolume25D`

The volume is considered between a point cloud and a ground plane following a given direction (X, Y or Z),
or between two point clouds.

:ivar float volume: the resulting volume
:ivar float addedVolume: the positive part of the volume (ceil > floor)
:ivar float removedVolume: the negative part of the volume (ceil < floor)
:ivar float surface: the section of the point cloud along in the given direction
:ivar float matchingPercent: percentage of the section matching ceil and floor
:ivar float ceilNonMatchingPercent: percentage of the ceil section non matching floor
:ivar float groundNonMatchingPercent: percentage of the floor section non matching ceil
:ivar int averageNeighborsPerCell: average Neighbor number per cell (see 'gridStep' in :py:meth`ComputeVolume25D`)
)";

const char* cloudComPy_SavePointCloud_doc= R"(
Save a 3D cloud in a file.

The file name extension determines the format (.asc .las .E57 .sbf .ply .vtk .dxf .pcd .pn .pv .bin)
An optional string can be used to specify format:
To use the LAS_FWF IO plugin to save .las or .laz file in format 1.4: version="1.4"
(without version, las or laz file are saved in format 1.2)

:param ccPointCloud cloud: the cloud to save.
:param str filename: The cloud file.
:param string,optional version: optional string, default "", used to specify a particular version.  

:return: 0 or I/O error.
:rtype: CC_FILE_ERROR)";

const char* cloudComPy_SaveMesh_doc= R"(
Save a 3D mesh in a file.

The file name extension determines the format (.ma .dxf .off .stl .vtk .obj .ply .bin .fbx)

:param ccMesh mesh: the mesh to save.
:param str filename: The mesh file.

:return: 0 or I/O error.
:rtype: CC_FILE_ERROR)";

const char* cloudComPy_SaveEntities_doc= R"(
Save a list of entities (cloud, meshes, primitives...) in a file: use bin format!

:param entities: list of entities
:type entities: list of :py:class:`ccHObject`
:param str filename: The entities file.

:return: 0 or I/O error.
:rtype: CC_FILE_ERROR)";

const char* cloudComPy_computeCurvature_doc= R"(
Compute the curvature on a list of point clouds (create a scalarField).

The curvature at each point is estimated by best fitting a quadric around it.
If there's not enough neighbors to compute a quadric (i.e. less than 6) an invalid scalar value (NaN) is set for this point.
This point will appear in grey (or not at all if you uncheck the 'display NaN values in grey' option of the scalar field parameters).

:param CurvatureType cvt: from CurvatureType.GAUSSIAN_CURV, CurvatureType.MEAN_CURV, CurvatureType.NORMAL_CHANGE_RATE.
:param float radius: try value obtained by :py:meth:`GetPointCloudRadius`.
:param clouds: list of clouds
:type clouds: list of :py:class:`ccHObject`

:return: True if OK, else False
:rtype: bool)";

const char* cloudComPy_computeFeature_doc= R"(
Compute a geometric characteristic on a list of points clouds (create a scalarField).

Geometric feature computed from eigen values/vectors.
Most of them are defined in "Contour detection in unstructured 3D point clouds", Hackel et al, 2016.
PCA1 and PCA2 are defined in "3D terrestrial lidar data classification of complex natural scenes
using a multi-scale dimensionality criterion: Applications in geomorphology", Brodu and Lague, 2012.

:param GeomFeature feature: from GeomFeature enum
:param float radius: try value obtained by :py:meth:`GetPointCloudRadius`.
:param clouds: list of clouds
:type clouds: list of :py:class:`ccHObject`

:return: True if OK, else False
:rtype: bool)";

const char* cloudComPy_computeLocalDensity_doc=R"(
Computes the local density on a list of points clouds (create a scalarField).

The density output can be:

- the number of neighbors N (only available in 'Precise' mode)
- a surface density: number of neighbors divided by the neighborhood surface = N / (Pi.R2)
- a volume density: number of neighbors divided by the neighborhood volume = N / (4/3.Pi.R3)

:param Density density: from Density enum
:param float radius: try value obtained by :py:meth:`GetPointCloudRadius`.
:param clouds: list of clouds
:type clouds: list of :py:class:`ccHObject`

:return: True if OK, else False
:rtype: bool)";

const char* cloudComPy_computeApproxLocalDensity_doc=R"(
Computes the local density (approximate) on a list of points clouds (create a scalarField).

Old method (based only on the distance to the nearest neighbor).

**Warning** As only one neighbor is extracted, the DENSITY_KNN type corresponds in fact to the (inverse) distance to the nearest neighbor.

The density output can be:

- the number of neighbors N (only available in 'Precise' mode)
- a surface density: number of neighbors divided by the neighborhood surface = N / (Pi.R2)
- a volume density: number of neighbors divided by the neighborhood volume = N / (4/3.Pi.R3)

:param Density density: from Density enum
:param float radius: try value obtained by :py:meth:`GetPointCloudRadius`.
:param clouds: list of clouds
:type clouds: list of :py:class:`ccHObject`

:return: True if OK, else False
:rtype: bool)";

const char* cloudComPy_computeRoughness_doc=R"(
Computes the roughness on a list of points clouds (create a scalarField).

Roughness estimation is very... simple: for each point, the 'roughness' value is equal to the distance between this point
and the best fitting plane computed on its nearest neighbors.
If there's not enough neighbors to compute a LS plane (i.e. less than 3) an invalid scalar value (NaN) is set for this point.
This point will appear in grey (or not at all if you uncheck the 'display NaN values in grey' option in the scalar field properties).

:param float radius: try value obtained by :py:meth:`GetPointCloudRadius`.
:param clouds: list of clouds
:type clouds: list of :py:class:`ccHObject`

:return: True if OK, else False
:rtype: bool)";

const char* cloudComPy_computeMomentOrder1_doc=R"(
Computes the first order moment on a list of points clouds (create a scalarField).

:param float radius: try value obtained by :py:meth:`GetPointCloudRadius`.
:param clouds: list of clouds
:type clouds: list of :py:class:`ccHObject`

:return: True if OK, else False
:rtype: bool)";

const char* cloudComPy_computeM3C2_doc=R"(
Compute Multiscale Model to Model Cloud Comparison (plugin M3C2)
The computation parameters are regrouped in a text file: see the GUI to get a first version.

:param list clouds: two or three clouds to compare. If a 3rd cloud is present, it will be used as core points.
:param string paramFilename: full path of the parameter file

:return: output cloud with computed scalar fields
:rtype: ccPointCloud
)";

const char* cloudComPy_filterBySFValue_doc= R"(
Create a new point cloud by filtering points using the current out ScalarField (see cloud.setCurrentOutScalarField).
Keep the points whose ScalarField value is between the min and max parameters.

:param float min: minimum value to keep
:param float max: maximum value to keep
:param ccPointCloud cloud: the input cloud

:return: a ccPointCloud object.
:rtype: ccPointCloud )";

const char* cloudComPy_GetPointCloudRadius_doc= R"(
Compute an estimate radius to use in computeCurvature.

:param list clouds: list of clouds(list of :py:class:`ccHObject`)
:param int,optional nodes: number of nodes wanted within the radius, default 12

:return: estimated radius
:rtype: float )";

const char* cloudComPy_getScalarType_doc= R"(
Get the scalar type used in cloudCompare under the form defined in Numpy: 'float32' or 'float64'

:return: scalar type
:rtype: str )";

const char* cloudComPy_computeNormals_doc= R"(
Compute normals on a list of clouds and meshes.

:param selectedEntities: list of entities (clouds, meshes)
:type selectedEntities: list of :py:class:`ccHObject`
:param LOCAL_MODEL_TYPES,optional model: default = LOCAL_MODEL_TYPES.LS (Least Square best fitting plane)
:param bool,optional useScanGridsForComputation: default `True`, whether to use ScanGrids when available
:param float,optional defaultRadius: default 0.0
:param float,optional minGridAngle_deg: default 1.0
:param bool,optional orientNormals: default `True`
:param bool,optional useScanGridsForOrientation: default `True`, when ScanGrids available
:param bool,optional useSensorsForOrientation: default `True`, when Sensors available
:param Orientation,optional preferredOrientation: default Orientation.UNDEFINED
:param bool,optional orientNormalsMST: default `True`, use Minimum Spanning Tree
:param int,optional mstNeighbors: default 6, for Minimum Spanning Tree
:param bool,optional computePerVertexNormals: default `True`, apply on mesh, if `True`, compute on vertices, if `False`, compute on triangles

:return: success
:rtype: bool)";

const char* cloudComPy_invertNormals_doc=R"(
Invert normals on a list of clouds and meshes.

:return: success
:rtype: bool)";

const char* cloudComPy_RasterizeToCloud_doc= R"(
Compute a Raster cloud from a point cloud, given a grid step and a direction, plus an optional GeoTiff file.

GeoTiff files are only available with the GDAL plugin.

:param ccGenericPointCloud* cloud: the original cloud
:param float gridStep: the raster grid step
:param CC_DIRECTION,optional vertDir: default = CC_DIRECTION.Z, direction of projection
:param bool,optional outputRasterZ: default False, create also a GeoTiff file (3D tiff with altitude)
:param bool,optional outputRasterSFs: default False, add scalar fields to the GeoTiff file (requires outputRasterZ)
:param bool,optional outputRasterRGB: default False, create also a GeoTiff file with GRB values (choose either Z or RGB, not the two)
:param string,optional pathToImages: default "." for current directory, directory for the GeoTiff file, name basesd on Cloud name plus suffix
:param bool,optional resample: default False, resample the point cloud
:param ProjectionType,optional projectionType: default ProjectionType.PROJ_AVERAGE_VALUE,
:param ProjectionType,optional sfProjectionType: default ProjectionType.PROJ_AVERAGE_VALUE,
:param EmptyCellFillOption,optional emptyCellFillStrategy: default EmptyCellFillOption.LEAVE_EMPTY
:param float,optional customHeight: default float('nan')
:param ccBBox,optional gridBBox: default ccBBox() the bounding box used for the raster is by default the cloud bounding box);
:param bool export_perCellCount: export scalarField, default False
:param bool export_perCellMinHeight: export scalarField, default False
:param bool export_perCellMaxHeight: export scalarField, default False
:param bool export_perCellAvgHeight: export scalarField, default False
:param bool export_perCellHeightStdDev: export scalarField, default False
:param bool export_perCellHeightRange: export scalarField, default False

:return: the raster cloud
:rtype: ccPointCloud
)";

const char* cloudComPy_RasterizeToMesh_doc= R"(
Compute a Raster mesh from a point cloud, given a grid step and a direction, plus an optional GeoTiff file.

GeoTiff files are only available with the GDAL plugin.

:param ccGenericPointCloud* cloud: the original cloud
:param float gridStep: the raster grid step
:param CC_DIRECTION,optional vertDir: default = CC_DIRECTION.Z, direction of projection
:param bool,optional outputRasterZ: default False, create also a GeoTiff file (3D tiff with altitude)
:param bool,optional outputRasterSFs: default False, add scalar fields to the GeoTiff file (requires outputRasterZ)
:param bool,optional outputRasterRGB: default False, create also a GeoTiff file with GRB values (choose either Z or RGB, not the two)
:param string,optional pathToImages: default "." for current directory, directory for the GeoTiff file, name basesd on Cloud name plus suffix
:param bool,optional resample: default False, resample the point cloud
:param ProjectionType,optional projectionType: default ProjectionType.PROJ_AVERAGE_VALUE,
:param ProjectionType,optional sfProjectionType: default ProjectionType.PROJ_AVERAGE_VALUE,
:param EmptyCellFillOption,optional emptyCellFillStrategy: default EmptyCellFillOption.LEAVE_EMPTY
:param float,optional customHeight: default float('nan')
:param ccBBox,optional gridBBox: default ccBBox() the bounding box used for the raster is by default the cloud bounding box);
:param bool export_perCellCount: export scalarField, default False
:param bool export_perCellMinHeight: export scalarField, default False
:param bool export_perCellMaxHeight: export scalarField, default False
:param bool export_perCellAvgHeight: export scalarField, default False
:param bool export_perCellHeightStdDev: export scalarField, default False
:param bool export_perCellHeightRange: export scalarField, default False

:return: the raster mesh
:rtype: ccMesh
)";

const char* cloudComPy_RasterizeGeoTiffOnly_doc= R"(
Compute a GeoTiff file from a point cloud, given a grid step and a direction.

GeoTiff files are only available with the GDAL plugin.

:param ccGenericPointCloud* cloud: the original cloud
:param float gridStep: the raster grid step
:param CC_DIRECTION,optional vertDir: default = CC_DIRECTION.Z, direction of projection
:param bool,optional outputRasterZ: default False, create a GeoTiff file (3D tiff with altitude)
:param bool,optional outputRasterSFs: default False, add scalar fields to the GeoTiff file (requires outputRasterZ)
:param bool,optional outputRasterRGB: default False, create a GeoTiff file with GRB values (choose either Z or RGB, not the two)
:param string,optional pathToImages: default "." for current directory, directory for the GeoTiff file, name basesd on Cloud name plus suffix
:param bool,optional resample: default False, resample the point cloud
:param ProjectionType,optional projectionType: default ProjectionType.PROJ_AVERAGE_VALUE,
:param ProjectionType,optional sfProjectionType: default ProjectionType.PROJ_AVERAGE_VALUE,
:param EmptyCellFillOption,optional emptyCellFillStrategy: default EmptyCellFillOption.LEAVE_EMPTY
:param float,optional customHeight: default float('nan')
:param ccBBox,optional gridBBox: default ccBBox() the bounding box used for the raster is by default the cloud bounding box);
:param bool export_perCellCount: export scalarField, default False
:param bool export_perCellMinHeight: export scalarField, default False
:param bool export_perCellMaxHeight: export scalarField, default False
:param bool export_perCellAvgHeight: export scalarField, default False
:param bool export_perCellHeightStdDev: export scalarField, default False
:param bool export_perCellHeightRange: export scalarField, default False

:return: None
:rtype: None
)";

#endif /* CLOUDCOMPY_DOCSTRINGS_HPP_ */
