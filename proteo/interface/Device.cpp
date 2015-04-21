//!
//! \file Device.cpp
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

#include "Device.hpp"

/* ============================================================================
 *
 * */
Device::Device(std::string name)
    : core::Object(name)
{ }

/* ============================================================================
 *
 * */
const ObjRole Device::ORole = Rdevice;

/* ============================================================================
 *
 * */
const Object::TagArray Device::OTag = { 'D', 'E', 'V', 'C' };

/* ============================================================================
 *
 * */
const std::vector<Property> Device::Properties = {

};

/* ============================================================================
 *
 * */
ObjRole Device::objRole() const
{
    return ORole;
}

/* ============================================================================
 *
 * */
const Object::TagArray& Device::objTag() const
{
    return OTag;
}

/* ============================================================================
 *
 * */
Variant Device::propertyValue(uint8_t id)
{
    switch(id)
    {

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
void Device::setPropertyValue(uint8_t id, const Variant& v)
{
    switch(id)
    {


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
const std::vector<Property>& Device::properties() const
{
    return Properties;
}


/* ============================================================================
 *
 * */
uint8_t Device::id()
{
    return m_busId;
}

/* ============================================================================
 *
 * */
void Device::setId(uint8_t id)
{
    m_busId = id;
}

