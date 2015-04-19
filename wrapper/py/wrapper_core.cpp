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
#include <proteo/core/Object.hpp>
#include <proteo/core/Container.hpp>

using namespace std;
using namespace proteo::core;
using namespace boost::python;

/* ============================================================================
 *
 * */
void export_core()
{
    // Map the core namespace to a sub-module
    // Make "from proteo.core import ..." work
    object core_module(handle<>(borrowed(PyImport_AddModule("proteo.core"))));
    // Make "from proteo import core" work
    scope().attr("core") = core_module;
    // Set the current scope to the new sub-module
    scope core_scope = core_module;

    //
    // Object
    //
    class_<Object, boost::noncopyable>("Object", no_init)

        .def("append" , &Object::append)
        .def("connect", &Object::initiativeConnect)

        .add_property("objName", &Object::objName, &Object::setObjName);

        ;

    //
    // Container
    //
    class_<Container, bases<Object> >("Container", init<string>())
        ;
}
