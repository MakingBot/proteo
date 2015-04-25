//!
//! \file Composer.cpp
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

#include <proteo/gui/Composer.hpp>
#include <proteo/gui/composer/ComposerWidget.hpp>

using namespace proteo;
using namespace proteo::gui;
using namespace proteo::core;

/* ============================================================================
 *
 * */
Composer::Composer(std::string name)
    : GuiObject(name), m_composer(new ComposerWidget())
{
    // Set widget for GuiObject
    m_widget = qSharedPointerObjectCast<QWidget>( m_composer );

    // Enable properties
    setPropertyActivity(IdPropertyVisible, true);
}

/* ============================================================================
 *
 * */
const ObjRole Composer::ORole = Rgui;

/* ============================================================================
 *
 * */
const Object::TagArray Composer::OTag = { 'C', 'O', 'M', 'P' };

/* ============================================================================
 *
 * */
const std::vector<Property> Composer::Properties = {
    Property(IdPropertyVisible, "visible", Tbool)
};

/* ============================================================================
 *
 * */
ObjRole Composer::objRole() const
{
    return ORole;
}

/* ============================================================================
 *
 * */
const Object::TagArray& Composer::objTag() const
{
    return OTag;
}


/* ============================================================================
 *
 * */
Variant Composer::propertyValue(uint8_t id)
{
    switch(id)
    {
        case IdPropertyVisible:
        {
            return Variant(isVisible());
            break;
        }

        default:
        {
            return Object::propertyValue(id);
            break;
        }
    }
}

/* ============================================================================
 *
 * */
void Composer::setPropertyValue(uint8_t id, const Variant& v)
{
    switch(id)
    {
        case IdPropertyVisible:
        {
            setVisible(v.toBool());
            break;
        }

        default:
        {
            Object::setPropertyValue(id, v);
            break;
        }
    }
}

/* ============================================================================
 *
 * */
const std::vector<Property>& Composer::properties() const
{
    return Properties;
}






/* ============================================================================
 *
 * */
// bool Composer::isVisible()
// {
//     return m_widget->isVisible();
// }

/* ============================================================================
 *
 * */
// void Composer::setVisible(bool vis)
// {
//     // Check widget allocation    
//     // if(!m_widget)
//     // {
//     //     return;
//     // }

//     // Set the variable
//     // m_visible = v;

//     // Command the widget
//     if(vis)
//     {
//         std::cout << "vis = true" << std::endl;
//         show();
//         // ComposerWidget* rr = new ComposerWidget();
//         // rr->show();
//     }
//     else
//     {
//         m_widget->hide();
//     }
// }


// void Composer::show()
// {
//     m_widget->show();
// }
