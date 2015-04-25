//!
//! \file wrapper_core_objsize.cpp
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
#include <proteo/core/Object.hpp>

using namespace proteo::core;
using namespace boost::python;

/* ============================================================================
 *
 * */
void export_core_objsize()
{
    class_<ObjSize>
    (
        "ObjSize"
    ,   "Size of the object in the architectural grid"
    ,   init<uint32_t, uint32_t>()
    )
    .add_property("width" , &ObjSize::width , &ObjSize::setWidth )
    .add_property("height", &ObjSize::height, &ObjSize::setHeight)
    ;
}


