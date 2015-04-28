//!
//! \file wrapper_core_object.cpp
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
void export_core_object()
{
    class_<Object, boost::shared_ptr<Object>, boost::noncopyable>
    (
        "Object"
    ,   "Main proteo interface"
    ,   no_init
    )

    .add_property("objName", &Object::objName, &Object::setObjName)

    // ========================================================================
    // => Object parent link

    .def("hasObjParent", &Object::hasObjParent)
    .add_property("objParent", &Object::objParent, &Object::setObjParent)
    .def("nbObjChilds", &Object::nbObjChilds)
    
    .def("append" , &Object::append)
    .def(self += other<boost::shared_ptr<Object> >())

    .def("remove" , &Object::remove)
    .def(self -= other<boost::shared_ptr<Object> >())

    .def("rootParent" , &Object::rootParent)

    // ========================================================================
    // => Object connections

    .def("connect", &Object::initiativeConnect)
    .def(self *= other<boost::shared_ptr<Object> >())

    .def("disconnect", &Object::initiativeDisconnect)
    .def(self /= other<boost::shared_ptr<Object> >())

    .def("nbObjConnections", &Object::nbObjConnections)


    ;
}

