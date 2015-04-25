#ifndef OBJECT_HPP
#define OBJECT_HPP
//!
//! \file Object.hpp
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

#include <proteo/core/Variant.hpp>
#include <proteo/core/Property.hpp>

namespace proteo { namespace core {

//! \class ObjPosition
//! \brief Define the size of the object in an architectural grid
//!
class ObjSize
{

public:

    //! \brief Default constructor
    //!
    ObjSize(uint32_t w = 0, uint32_t h = 0);
    uint32_t width();
    void setWidth(uint32_t w);
    uint32_t height();
    void setHeight(uint32_t h);

protected:

    //! \brief Object width
    //!
    uint32_t m_width;

    //! \brief Object height
    //!
    uint32_t m_height;
};

//! \class ObjPosition
//! \brief Define the position of the object in an architectural grid
//!
class ObjPosition
{

public:

    //! \brief Default constructor
    //!
    ObjPosition(uint32_t x = 0, uint32_t y = 0);
    uint32_t x();
    void setX(uint32_t x);
    uint32_t y();
    void setY(uint32_t y);

protected:

    //! \brief Object x
    //!
    uint32_t m_x;

    //! \brief Object y
    //!
    uint32_t m_y;
};

//! \class Object
//! \brief Main object interface
//!
//! \author [XR]MakingBot ( http://makingbot.fr )
//!
class Object: public boost::enable_shared_from_this<Object>
{

public:

    //! \typedef Tag array type
    //!
    typedef std::array<char, 4> TagArray;

    //! \struct ObjSignals
    //! \brief Define object common signals
    //!
    struct ObjSignals
    {
        //! \brief Emitted when the object name is modified
        //!
        boost::signals2::signal<void ()> nameModified;

        //! \brief Emitted when a property value has been modified
        //! It takes a uint8 value which is the property id.
        //!
        boost::signals2::signal<void (uint8_t)> propertyModified;
    };

    //! \struct ObjMutex
    //! \brief Define mutex used by proteo Objects
    //!
    struct ObjMutex
    {
        //! \brief Mutex 
        //!
        std::mutex id;
    };

    //! \brief Default constructor
    //!
    Object(std::string name);

    // ========================================================================
    // => Object const identification

    //! \brief Object role getter
    //!
    virtual ObjRole objRole() const = 0;

    //! \brief Object type getter
    //!
    virtual const TagArray& objTag() const = 0;

    // ========================================================================
    // => Object dynamic identification

    //! \brief Object name getter
    //!
    const std::string objName() const;

    //! \brief Object name setter
    //!
    void setObjName(const std::string name);

    //! \brief
    //!
    uint32_t objIdNumber() const;

    //! \brief
    //!
    std::string objIdChain() const;

    // ========================================================================
    // => Block architectural properties

    //! \brief Size getter
    //!
    ObjSize objSize() const;
    
    //! \brief Size setter
    //!
    void setObjSize(const ObjSize size);

    //! \brief Position getter
    //!
    ObjPosition objPosition() const;

    //! \brief Position setter
    //!
    void setObjPosition(const ObjPosition pos);

    // ========================================================================
    // => Block status management



    // ========================================================================
    // => Object parent link

    //! \brief To check if the object has a parent
    //!
    bool hasObjParent();

    //! \brief Object parent getter
    //!
    boost::shared_ptr<Object> objParent();

    //! \brief Set the object parent to 'p'
    //!
    void setObjParent(boost::shared_ptr<Object> p);

    //! \brief Break the link between the object and its parent
    //!
    void resetObjParent();

    //! \brief Get the number of childs
    //!
    uint32_t nbObjChilds() const;

    //! \brief Append a child to this object as container
    //!
    void append(boost::shared_ptr<Object> chd);

    //! \brief Cool append overload
    //!
    boost::shared_ptr<Object> operator+=(boost::shared_ptr<Object> chd);

    //! \brief Remove a child
    //!
    void remove(boost::shared_ptr<Object> chd);

    //! \brief Cool remove overload
    //!
    boost::shared_ptr<Object> operator-=(boost::shared_ptr<Object> chd);

    //! \brief Objects are organised as tree, this function return the root
    //!
    boost::shared_ptr<Object> rootParent();

    // ========================================================================
    // => Object connections

    //! \brief Object mutex getter
    //!
    inline boost::shared_ptr<ObjMutex> objMutex();

    //! \brief Object connections getter
    //!
    inline boost::shared_ptr<ObjSignals> objSignals();

    //! \brief Main function to connect 2 objects
    //!
    bool connect(boost::shared_ptr<Object> obj, bool initiative = true);

    //! \brief Interface for connect function in which initiative is always true
    //!
    bool initiativeConnect(boost::shared_ptr<Object> obj);

    //! \brief Cool connect overload
    //!
    boost::shared_ptr<Object> operator*=(boost::shared_ptr<Object> obj);

    //! \brief Main function to disconnect 2 objects
    //!
    bool disconnect(boost::shared_ptr<Object> obj, bool initiative = true);

    //! \brief Interface for disconnect function in which initiative is always true
    //!
    bool initiativeDisconnect(boost::shared_ptr<Object> obj);

    //! \brief Cool disconnect overload
    //!
    boost::shared_ptr<Object> operator/=(boost::shared_ptr<Object> obj);

    //! \brief Hook on the connection process
    //!
    virtual bool connectionHook(boost::shared_ptr<Object> obj, bool initiative);

    //! \brief Hook on the disconnection process
    //!
    virtual bool disconnectionHook(boost::shared_ptr<Object> obj, bool initiative);

    //! \brief return the number of connected object
    //!
    uint32_t nbObjConnections() const;

    //! \brief Object connections getter
    //!
    inline const std::list<boost::shared_ptr<Object> >& objConnections();

    // ========================================================================
    // => Object properties

    //! \brief Property value getter
    //!
    virtual Variant propertyValue(uint8_t id);

    //! \brief Property value setter
    //!
    virtual void setPropertyValue(uint8_t id, const Variant& v);

    //! \brief
    //!
    virtual bool isPropertyActive(uint8_t id);

    //! \brief
    //!
    virtual bool setPropertyActivity(uint8_t id, bool b);

    //! \brief
    //!
    virtual const std::vector<Property>& properties() const = 0;

protected:

    // ========================================================================
    // => Object dynamic identification

    //! \brief Object name
    //! This name must be unique among its brothers.
    //!
    std::string m_oName;

    //! \brief Object id number
    //! This id is unique in the current container. It is provided by the parents.
    //! If the object has no parent, its id number is 0.
    //!
    uint32_t m_oIdNumber;

    //! \brief Object id chain
    //! The id chain is a unique string id to define this object pointer
    //! It is composed of every parent name of this object separated with a dot.
    //! If the object has no parent, its id chain is m_oName.
    //!
    std::string m_oIdChain;

    // ========================================================================
    // => Block architectural properties

    //! \brief
    //!
    ObjSize m_oSize;
    
    //! \brief
    //!
    ObjPosition m_oPosition;

    // ========================================================================
    // => Block status management

    //! \brief Object global state
    //!
    ObjState m_oState;

    //! \brief Object global status
    //!
    std::string m_oStatus;

    // ========================================================================
    // => Object parent link

    //! \brief Object parent
    //!
    boost::shared_ptr<Object> m_oParent;

    //! \brief Object childs
    //!
    std::map<std::string, boost::shared_ptr<Object> > m_oChilds;

    // ========================================================================
    // => Object properties

    //! \brief Activation bit set, one bit for property and 256 properties max
    //!
    std::bitset<256> m_oActiveProperties;

    // ========================================================================
    // => Object connections

    //! \brief Object mutex
    //!
    boost::shared_ptr<ObjMutex> m_oMutex;

    //! \brief Object signals
    //!
    boost::shared_ptr<ObjSignals> m_oSignals;

    //! \brief Object connections
    //!
    std::list<boost::shared_ptr<Object> > m_oConnections;
};


/* ============================================================================
 *
 * */
inline boost::shared_ptr<Object::ObjMutex> Object::objMutex()
{
    return m_oMutex;
}

/* ============================================================================
 *
 * */
inline boost::shared_ptr<Object::ObjSignals> Object::objSignals()
{
   return m_oSignals;
}

/* ============================================================================
 *
 * */
inline const std::list<boost::shared_ptr<Object> >& Object::objConnections()
{
   return m_oConnections;
}

} // core
} // proteo
#endif // OBJECT_HPP

