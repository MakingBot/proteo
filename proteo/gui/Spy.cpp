//!
//! \file Spy.cpp
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

#include <proteo/gui/Spy.hpp>
#include <proteo/gui/spy/SpyWidget.hpp>

using namespace proteo;
using namespace proteo::gui;
using namespace proteo::core;

/* ============================================================================
 *
 * */
Spy::Spy(std::string name)
    : GuiObject(name)
    , m_spy(new SpyWidget(this))
{
    // Set widget for GuiObject
    m_widget = qSharedPointerObjectCast<QWidget>(m_spy);

}

/* ============================================================================
 *
 * */
const ObjRole Spy::ORole = Rgui;

/* ============================================================================
 *
 * */
const Object::TagArray Spy::OTag = { '_', 'S', 'P', 'Y' };

/* ============================================================================
 *
 * */
const std::vector<Property> Spy::Properties = {
   // Property()
};

/* ============================================================================
 *
 * */
ObjRole Spy::objRole() const
{
    return ORole;
}

/* ============================================================================
 *
 * */
const Object::TagArray& Spy::objTag() const
{
    return OTag;
}

/* ============================================================================
 *
 * */
bool Spy::connectionHook(boost::shared_ptr<Object> obj, bool initiative)
{
    m_spied = obj;
    m_spy->onSpiedObjChange();
    return true;
}

/* ============================================================================
 *
 * */
const std::vector<Property>& Spy::properties() const
{
    return Properties;
}

/* ============================================================================
 *
 * */
boost::shared_ptr<Object> Spy::spiedObj()
{
    return m_spied;
}



