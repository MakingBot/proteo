//!
//! \file GuiObject.cpp
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

#include "GuiObject.hpp"

using namespace proteo::gui;

/* ============================================================================
 *
 * */
GuiObject::GuiObject(std::string name)
    : core::Object(name), m_visible(false)
{ }

/* ============================================================================
 *
 * */
//const ObjRole GuiObject::ORole = Rgui;


/* ============================================================================
 *
 * */
bool GuiObject::isVisible()
{
    return m_visible;
}

/* ============================================================================
 *
 * */
void GuiObject::setVisible(bool v)
{
    // Check widget allocation    
    // if(!m_widget)
    // {
    //     return;
    // }

    // Set the variable
    m_visible = v;

    // Command the widget
    if(m_visible)
    {

        std::cout << "vis = true" << std::endl;

        //show();
        m_widget->show();
    }
    else
    {
        m_widget->hide();
    }
}


void GuiObject::show()
{
    m_widget->show();  
}

/* ============================================================================
 *
 * */
// QSharedPointer<QWidget> GuiObject::uiWidget()
// {
//     return m_widget;
// }

