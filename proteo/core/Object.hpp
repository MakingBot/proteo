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

//! \typedef Tag array type
//!
typedef std::array<char, 8> TagArray;

//! \class ObjSignals
//! \brief Define object common signals
//!
//! \author [XR]MakingBot ( http://makingbot.fr )
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

//! \class Object
//! \brief Main object interface
//!
//! \author [XR]MakingBot ( http://makingbot.fr )
//!
class Object : public boost::enable_shared_from_this<Object>
{

public:

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

    // ========================================================================
    // => Object connections

    //! \brief Main function to connect 2 objects
    //!
    bool connect(boost::shared_ptr<Object> obj, bool initiative = true);

    //! \brief Interface for connect function in which initiative is always true
    //!
    bool initiativeConnect(boost::shared_ptr<Object> obj);

    //! \brief Hook on the connection process
    //!
    virtual bool connectionHook(boost::shared_ptr<Object> obj, bool initiative);

    //! \brief Hook on the disconnection process
    //!
    virtual bool disconnectionHook(boost::shared_ptr<Object> obj, bool initiative);

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

    // ========================================================================
    // => Object connections

    //! \brief Object connections getter
    //!
    inline boost::shared_ptr<ObjSignals> objSignals();

    //! \brief Object connections getter
    //!
    inline const std::list<boost::shared_ptr<Object> >& objConnections();




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

    //! \brief Mutex for every dynamic identification element
    //!
    // std::mutex m_mutex_identification;

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

    //! \brief Activation
    //!
    std::bitset<256> m_oActiveProperties;

    // ========================================================================
    // => Object connections

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
inline boost::shared_ptr<ObjSignals> Object::objSignals()
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
