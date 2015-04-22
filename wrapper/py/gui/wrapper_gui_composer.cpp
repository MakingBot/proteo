//!
//! \file wrapper_gui_composer.cpp
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
#include <proteo/gui/Composer.hpp>

#include <proteo/gui/GuiObject.hpp>


#include <proteo/gui/Scheduler.hpp>

using namespace boost::python;
using namespace proteo::core;
using namespace proteo::gui;



/* ============================================================================
 *
 * */
void export_gui_scheduler()
{
    class_<Scheduler, boost::shared_ptr<Scheduler>, bases<Object>, boost::noncopyable>
    (
        "Scheduler"
    ,   init<std::string>()
    )
    .def("start", &Scheduler::start)

    ;
}



/* ============================================================================
 *
 * */
void export_gui_guiobject()
{
    class_<GuiObject, boost::shared_ptr<GuiObject>, bases<Object>, boost::noncopyable>
    (
        "GuiObject"
    ,   no_init
    )

    .add_property("visible", &GuiObject::isVisible, &GuiObject::setVisible)

    ;
}


/* ============================================================================
 *
 * */
void export_gui_composer()
{
    class_<Composer, boost::shared_ptr<Composer>, bases<GuiObject>, boost::noncopyable>
    (
        "Composer"
    ,   init<std::string>()
    )
    ;
}

