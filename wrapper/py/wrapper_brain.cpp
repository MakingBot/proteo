//!
//! \file wrapper_brain.cpp
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
#include <proteo/brain/Behaviour.hpp>

using namespace std;
using namespace boost::python;
using namespace proteo::core;
using namespace proteo::brain;

/* ============================================================================
 *
 * */
void export_brain()
{


    //
    // Behaviour
    //
    class_<Behaviour, bases<Object> >("Behaviour", init<std::string>())


        .def("start", &Behaviour::start)
        .def("stop" , &Behaviour::stop)

        .def("createEvent" , &Behaviour::createCyclicEvent)
        //.def("createEvent" , &Behaviour::createEvent)
        .def("attachEvent" , &Behaviour::attachEvent)

 

        ;

}
