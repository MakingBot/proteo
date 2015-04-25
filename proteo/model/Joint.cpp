//!
//! \file Joint.cpp
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

#include <proteo/model/Joint.hpp>

using namespace proteo::core;
using namespace proteo::model;


/* ============================================================================
 *
 * */
Joint::Joint(std::string name)
    : core::Object(name)
{
    //setPropertyActivity(IdPropertyDistance, true);
}

/* ============================================================================
 *
 * */
const ObjRole Joint::ORole = Rgui;

/* ============================================================================
 *
 * */
const Object::TagArray Joint::OTag = { 'D', 'I', 'S', 'T' };

/* ============================================================================
 *
 * */
const std::vector<Property> Joint::Properties = {
   // Property(IdPropertyDistance, "distance", Tuint)
};

/* ============================================================================
 *
 * */
ObjRole Joint::objRole() const
{
    return ORole;
}

/* ============================================================================
 *
 * */
const Object::TagArray& Joint::objTag() const
{
    return OTag;
}

/* ============================================================================
 *
 * */
Variant Joint::propertyValue(uint8_t id)
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
void Joint::setPropertyValue(uint8_t id, const Variant& v)
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
const std::vector<Property>& Joint::properties() const
{
    return Properties;
}


