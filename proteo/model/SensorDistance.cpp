//!
//! \file SensorDistance.cpp
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

#include <proteo/model/SensorDistance.hpp>

using namespace proteo::core;
using namespace proteo::model;

/* ============================================================================
 *
 * */
const uint8_t SensorDistance::IdPropertyDistance = 0;

/* ============================================================================
 *
 * */
SensorDistance::SensorDistance(std::string name)
    : core::Object(name)
{
    setPropertyActivity(IdPropertyDistance, true);
}

/* ============================================================================
 *
 * */
const ObjRole SensorDistance::ORole = Rgui;

/* ============================================================================
 *
 * */
const TagArray SensorDistance::OTag = { 'S', 'E', 'N', 'S', 'D', 'I', 'S', 'T' };

/* ============================================================================
 *
 * */
const std::vector<Property> SensorDistance::Properties = {
    Property(IdPropertyDistance, "distance", Tuint)
};

/* ============================================================================
 *
 * */
ObjRole SensorDistance::objRole() const
{
    return ORole;
}

/* ============================================================================
 *
 * */
const TagArray& SensorDistance::objTag() const
{
    return OTag;
}

/* ============================================================================
 *
 * */
Variant SensorDistance::propertyValue(uint8_t id)
{
    switch(id)
    {
        case IdPropertyDistance:
        {
            return Variant(distance());
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
void SensorDistance::setPropertyValue(uint8_t id, const Variant& v)
{
    switch(id)
    {
        case IdPropertyDistance:
        {
            setDistance(v.toUint32());
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
const std::vector<Property>& SensorDistance::properties() const
{
    return Properties;
}

/* ============================================================================
 *
 * */
uint32_t SensorDistance::distance()
{
    return m_distance;
}

/* ============================================================================
 *
 * */
void SensorDistance::setDistance(uint32_t distance)
{
    m_distance = distance;
}