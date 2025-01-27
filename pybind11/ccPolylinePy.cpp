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

#include "cloudComPy.hpp"

#include <ccPolyline.h>
#include <Polyline.h>
#include <ccShiftedObject.h>
#include <GenericIndexedCloudPersist.h>
#include "ccPolylinePy_DocStrings.hpp"

void export_ccPolyline(py::module &m0)
{

	py::class_<CCCoreLib::Polyline, CCCoreLib::ReferenceCloud> (m0, "Polyline",
			ccPolylinePy_Polyline_doc)
		 .def(py::init<CCCoreLib::GenericIndexedCloudPersist*>())
         .def("isClosed", &ccPolyline::isClosed, ccPolylinePy_isClosed_doc)
	     .def("setClosed", &ccPolyline::setClosed, ccPolylinePy_setClosed_doc)
		 ;

    py::class_<ccPolyline,CCCoreLib::Polyline, ccShiftedObject >(m0, "ccPolyline",
    		ccPolylinePy_ccPolyline_doc)
        .def(py::init<CCCoreLib::GenericIndexedCloudPersist*>())
        .def("computeLength", &ccPolyline::computeLength, ccPolylinePy_computeLength_doc)
        .def("getName", &ccPolyline::getName, ccPolylinePy_getName_doc)
        .def("is2DMode", &ccPolyline::is2DMode, ccPolylinePy_is2DMode_doc)
        .def("segmentCount", &ccPolyline::segmentCount, ccPolylinePy_segmentCount_doc)
        .def("set2DMode", &ccPolyline::set2DMode, ccPolylinePy_set2DMode_doc)
        .def("setName", &ccPolyline::setName, ccPolylinePy_setName_doc)
        .def("size", &ccPolyline::size, ccPolylinePy_size_doc)
        .def("smoothChaikin", &ccPolyline::smoothChaikin,
             ccPolylinePy_smoothChaikin_doc, py::return_value_policy::reference)
        ;
}
