//!
//! \file wrapper_gui.hpp
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
#include <proteo/gui/Gui.hpp>

/* ============================================================================
 *
 * */
void export_gui()
{
    namespace bp = boost::python;
    namespace pc = proteo::core;
    namespace pg = proteo::gui;

    // Map the gui namespace to a sub-module
    // Make "from proteo.gui import ..." work
    bp::object gui_module(bp::handle<>(bp::borrowed(PyImport_AddModule("proteo.gui"))));
    // Make "from proteo import gui" work
    bp::scope().attr("gui") = gui_module;
    // Set the current scope to the new sub-module
    bp::scope gui_scope = gui_module;

    // === Export

  

    //
    // Scheduler
    //
    bp::class_<pg::Scheduler>("Scheduler")
        .def("start", &pg::Scheduler::start)
        ;


    bp::class_<pg::Spy, bp::bases<pc::Object> >("Spy", bp::init<std::string>())


        ;

}


