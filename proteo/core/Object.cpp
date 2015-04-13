//!
//! \file Object.cpp
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

#include <proteo/core/Object.hpp>

using namespace proteo::core;

/* ============================================================================
 *
 * */
Object::Object(std::string name)
    : m_oName(name), m_oSignals(new ObjSignals())
{ }

/* ============================================================================
 *
 * */
const std::string Object::objName() const
{
    //std::lock_guard<std::mutex> lock(m_mutex_identification);
    return m_oName;
}

/* ============================================================================
 *
 * */
void Object::setObjName(const std::string name)
{
    //m_mutex_identification.lock();
    if( m_oName.compare(name) != 0 )
    {
        m_oName = name;
    //    m_mutex_identification.unlock();
        objSignals()->nameModified();
    }
    else
    {
    //    m_mutex_identification.unlock();
    }
}

/* ============================================================================
 *
 * */
bool Object::initiativeConnect(boost::shared_ptr<Object> obj)
{
    connect(obj,true);
}

/* ============================================================================
 *
 * */
bool Object::connect(boost::shared_ptr<Object> obj, bool initiative)
{





    if( std::find(m_oConnections.begin(), m_oConnections.end(), obj) != m_oConnections.end() )
    {
        // Connection refused
        // Log error "object already connected"
        return false;
    }

    connectionHook(obj, initiative);
}

/* ============================================================================
 *
 * */
bool Object::connectionHook(boost::shared_ptr<Object> obj, bool initiative)
{
    return true;
}

/* ============================================================================
 *
 * */
bool Object::disconnectionHook(boost::shared_ptr<Object> obj, bool initiative)
{
    return true;
}

/* ============================================================================
 *
 * */
Variant Object::propertyValue(uint8_t id)
{
    return Variant();
}

/* ============================================================================
 *
 * */
void Object::setPropertyValue(uint8_t id, const Variant& v)
{

}

/* ============================================================================
 *
 * */
bool Object::isPropertyActive(uint8_t id)
{

}

/* ============================================================================
 *
 * */
bool Object::setPropertyActivity(uint8_t id, bool b)
{

}

