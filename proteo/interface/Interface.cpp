//!
//! \file Interface.cpp
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

#include "Interface.hpp"

/* ============================================================================
 *
 * */
Interface::Interface(std::string name)
    : core::Object(name)
{ }

/* ============================================================================
 *
 * */
const ObjRole Interface::ORole = Rinterface;

/* ============================================================================
 *
 * */
const Object::TagArray Interface::OTag = { 'I', 'T', 'R', 'F' };

/* ============================================================================
 *
 * */
const std::vector<Property> Interface::Properties = {

};

/* ============================================================================
 *
 * */
ObjRole Interface::objRole() const
{
    return ORole;
}

/* ============================================================================
 *
 * */
const Object::TagArray& Interface::objTag() const
{
    return OTag;
}

/* ============================================================================
 *
 * */
Variant Interface::propertyValue(uint8_t id)
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
void Interface::setPropertyValue(uint8_t id, const Variant& v)
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
const std::vector<Property>& Interface::properties() const
{
    return Properties;
}

