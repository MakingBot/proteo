//!
//! \file Robot.cpp
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

#include <proteo/model/Robot.hpp>

using namespace proteo::core;
using namespace proteo::model;


/* ============================================================================
 *
 * */
Robot::Robot(std::string name)
    : core::Object(name)
{
    //setPropertyActivity(IdPropertyDistance, true);
}

/* ============================================================================
 *
 * */
const ObjRole Robot::ORole = Rgui;

/* ============================================================================
 *
 * */
const Object::TagArray Robot::OTag = { 'D', 'I', 'S', 'T' };

/* ============================================================================
 *
 * */
const std::vector<Property> Robot::Properties = {
   // Property(IdPropertyDistance, "distance", Tuint)
};

/* ============================================================================
 *
 * */
ObjRole Robot::objRole() const
{
    return ORole;
}

/* ============================================================================
 *
 * */
const Object::TagArray& Robot::objTag() const
{
    return OTag;
}

/* ============================================================================
 *
 * */
Variant Robot::propertyValue(uint8_t id)
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
void Robot::setPropertyValue(uint8_t id, const Variant& v)
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
const std::vector<Property>& Robot::properties() const
{
    return Properties;
}


