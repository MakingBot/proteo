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
ObjSize::ObjSize(uint32_t w, uint32_t h)
    : m_width(w), m_height(h)
{ }

/* ============================================================================
 *
 * */
uint32_t ObjSize::width()
{
    return m_width;
}

/* ============================================================================
 *
 * */
void ObjSize::setWidth(uint32_t w)
{
    m_width = w;
}

/* ============================================================================
 *
 * */
uint32_t ObjSize::height()
{
    return m_height;
}

/* ============================================================================
 *
 * */
void ObjSize::setHeight(uint32_t h)
{
    m_height = h;
}

/* ============================================================================
 *
 * */
ObjPosition::ObjPosition(uint32_t x, uint32_t y)
    : m_x(x), m_y(y)
{ }

/* ============================================================================
 *
 * */
uint32_t ObjPosition::x()
{
    return m_x;
}

/* ============================================================================
 *
 * */
void ObjPosition::setX(uint32_t x)
{
    m_x = x;
}

/* ============================================================================
 *
 * */
uint32_t ObjPosition::y()
{
    return m_y;
}

/* ============================================================================
 *
 * */
void ObjPosition::setY(uint32_t y)
{
    m_y = y;
}

/* ============================================================================
 *
 * */
Object::Object(std::string name)
    : m_oName(name), m_oMutex(new ObjMutex()), m_oSignals(new ObjSignals())
{ }

/* ============================================================================
 *
 * */
const std::string Object::objName() const
{
    std::lock_guard<std::mutex> lock(m_oMutex->id);
    return m_oName;
}

/* ============================================================================
 *
 * */
void Object::setObjName(const std::string name)
{
    m_oMutex->id.lock();
    if( m_oName.compare(name) != 0 )
    {
        m_oName = name;
        m_oMutex->id.unlock();
        objSignals()->nameModified();
    }
    else
    {
        m_oMutex->id.unlock();
    }
}

/* ============================================================================
 *
 * */
uint32_t Object::objIdNumber() const
{
    return m_oIdNumber;
}

/* ============================================================================
 *
 * */
std::string Object::objIdChain() const
{
    return m_oIdChain;
}

/* ============================================================================
 *
 * */
ObjSize Object::objSize() const
{
    return m_oSize;
}

/* ============================================================================
 *
 * */
void Object::setObjSize(const ObjSize size)
{
    m_oSize = size;
}

/* ============================================================================
 *
 * */
ObjPosition Object::objPosition() const
{
    return m_oPosition;
}

/* ============================================================================
 *
 * */
void Object::setObjPosition(const ObjPosition pos)
{
    m_oPosition = pos;
}

/* ============================================================================
 *
 * */
bool Object::hasObjParent()
{
    if(m_oParent)
    {
        return true;
    }
    return false;
}

/* ============================================================================
 *
 * */
boost::shared_ptr<Object> Object::objParent()
{
    return m_oParent;
}

/* ============================================================================
 *
 * */
void Object::setObjParent(boost::shared_ptr<Object> p)
{
    m_oParent = p;
}

/* ============================================================================
 *
 * */
void Object::resetObjParent()
{
    m_oParent.reset();
}

/* ============================================================================
 *
 * */
uint32_t Object::nbObjChilds() const
{
    return m_oChilds.size();
}

/* ============================================================================
 *
 * */
void Object::append(boost::shared_ptr<Object> chd)
{
    // Store the childs
    m_oChilds[chd->objName()] = chd;

    // Set the parent of the child
    chd->setObjParent( shared_from_this() );
}

/* ============================================================================
 *
 * */
boost::shared_ptr<Object> Object::operator+=(boost::shared_ptr<Object> chd)
{
    this->append(chd);
    return shared_from_this();
}

/* ============================================================================
 *
 * */
void Object::remove(boost::shared_ptr<Object> chd)
{
    std::map<std::string, boost::shared_ptr<Object> >::iterator it;
    it = m_oChilds.find(chd->objName());
    if( it != m_oChilds.end() )
    {
        chd->resetObjParent();
        m_oChilds.erase(it);
    }
}

/* ============================================================================
 *
 * */
boost::shared_ptr<Object> Object::operator-=(boost::shared_ptr<Object> chd)
{
    this->remove(chd);
    return shared_from_this();
}

/* ============================================================================
 *
 * */
boost::shared_ptr<Object> Object::rootParent()
{
    if(hasObjParent())
    {
        return m_oParent->rootParent();
    }
    else
    {
        return shared_from_this();
    }
}

/* ============================================================================
 *
 * */
bool Object::connect(boost::shared_ptr<Object> obj, bool initiative)
{
    // // Check that the connection does not already exist
    // if( std::find(m_oConnections.begin(), m_oConnections.end(), obj) != m_oConnections.end() )
    // {
    //     // Connection refused
    //     // Log error "object already connected"
    //     return false;
    // }

    // // Call the connection process of the other object
    // if( initiative )
    // {
    //     if( ! obj->connect(shared_from_this(), false) )
    //     {
    //         return false;
    //     }
    // }

    // Call hook
    if( ! connectionHook(obj, initiative) )
    {

    }

    // Save connection pointer
    m_oConnections.push_back(obj);

    return true;
}

/* ============================================================================
 *
 * */
bool Object::initiativeConnect(boost::shared_ptr<Object> obj)
{
    connect(obj, true);
}

/* ============================================================================
 *
 * */
boost::shared_ptr<Object> Object::operator*=(boost::shared_ptr<Object> obj)
{
    initiativeConnect(obj);
    return shared_from_this();
}

/* ============================================================================
 *
 * */
bool Object::disconnect(boost::shared_ptr<Object> obj, bool initiative)
{
    std::list<boost::shared_ptr<Object> >::iterator it;
    it = std::find(m_oConnections.begin(), m_oConnections.end(), obj);

    // Check if the connection exists
    if(it != m_oConnections.end())
    {
        return false;
    }

    // Call hook
    if( ! disconnectionHook(obj, initiative) )
    {

    }

    // Disconnect
    m_oConnections.erase(it);
    return true;
}

/* ============================================================================
 *
 * */
bool Object::initiativeDisconnect(boost::shared_ptr<Object> obj)
{
    disconnect(obj, true);
}

/* ============================================================================
 *
 * */
boost::shared_ptr<Object> Object::operator/=(boost::shared_ptr<Object> obj)
{
    initiativeDisconnect(obj);
    return shared_from_this();
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
uint32_t Object::nbObjConnections() const
{
    return m_oConnections.size();
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
    PROTEO_UNUSED(v);
    PROTEO_UNUSED(id);
}

/* ============================================================================
 *
 * */
bool Object::isPropertyActive(uint8_t id)
{
    return (bool)m_oActiveProperties[id];
}

/* ============================================================================
 *
 * */
bool Object::setPropertyActivity(uint8_t id, bool b)
{
    m_oActiveProperties[id] = (int)b;
}

