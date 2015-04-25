//!
//! \file wrapper_gui.cpp
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

void export_gui_guiobject();
void export_gui_scheduler();
void export_gui_spy();
void export_gui_shell();
void export_gui_composer();




std::string proteo_gui_objects()
{
    return std::string("Spy-Rgui;Shell-Rgui;Composer-Rgui");
}



/* ============================================================================
 *
 * */
BOOST_PYTHON_MODULE(gui)
{
    export_gui_guiobject();
    export_gui_scheduler();
    
    export_gui_spy();
    export_gui_shell();
    export_gui_composer();


    def("proteo_gui_objects", proteo_gui_objects);
}


