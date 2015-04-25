//!
//! \file wrapper_core.cpp
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

void export_core_object();
void export_core_container();
void export_core_objsize();
void export_core_objposition();

/* ============================================================================
 *
 * */
std::string proteo_core_objects()
{
    return std::string("Container-Rtool");
}

/* ============================================================================
 *
 * */
BOOST_PYTHON_MODULE(core)
{
    export_core_objsize();
    export_core_objposition();

    export_core_object();
    export_core_container();

    def("proteo_core_objects", proteo_core_objects);
}
