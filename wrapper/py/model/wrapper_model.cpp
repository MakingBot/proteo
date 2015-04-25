//!
//! \file wrapper_model.cpp
//!
// Copyright 2015 MakingBot
// This file is part of proteo.
//
// proteo is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// proteo is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with proteo.  If not, see <http://www.gnu.org/licenses/>.

#include <boost/python.hpp>

using namespace boost::python;

void export_model_joint();
void export_model_robot();
void export_model_sensordistance();

/* ============================================================================
 *
 * */
std::string proteo_model_objects()
{
    return std::string("Joint-Rmodel;Robot-Rmodel;SensorDistance-Rmodel");
}

/* ============================================================================
 *
 * */
BOOST_PYTHON_MODULE(model)
{
    export_model_joint();
    export_model_robot();
    export_model_sensordistance();



    def("proteo_model_objects", proteo_model_objects);
}
