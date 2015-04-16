#ifndef PROPERTY_HPP
#define PROPERTY_HPP
//!
//! \file Property.hpp
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

#include <proteo/core/Type.hpp>

namespace proteo { namespace core {

//! \class Property
//! \brief Provide meta information for object property member
//!
class Property
{

public:

    //! \brief Default constructor
    //!
    Property(uint8_t id, const char* name, MetaType type);

    //! \brief Copy constructor
    //!
    Property(const Property& p);

    //! \brief Id getter
    //!
    uint8_t id() const;

    //! \brief Name getter
    //!
    const std::string& name() const;

    //! \brief Meta type getter
    //!
    inline MetaType mtype() const;


    inline bool readOnly() const;

    //! \brief Copy assignement
    //!
    void operator=(const Property& p)
    {
        m_id   = p.id();
        m_name = p.name();
        m_type = p.mtype();
    }

protected:

    //! \brief Property unique id in the object
    //! The property id is limited to 255
    //!
    uint8_t m_id;

    //! \brief Property unique name in the object
    //!
    std::string m_name;

    //! \brief Property metatype
    //! It gives useful information to create the user interface
    //!
    MetaType m_type;

    //! \brief True if the property is can only be read
    //!
    bool m_readOnly;

};

/* ============================================================================
 *
 * */
inline Property::Property(uint8_t id, const char* name, MetaType type)
    : m_id(id), m_name(name), m_type(type)
{ }

/* ============================================================================
 *
 * */
inline Property::Property(const Property& p)
    : m_id(p.id()), m_name(p.name()), m_type(p.mtype())
{ }

/* ============================================================================
 *
 * */
inline uint8_t Property::id() const
{
    return m_id;
}

/* ============================================================================
 *
 * */
inline const std::string& Property::name() const
{
    return m_name;
}

/* ============================================================================
 *
 * */
inline MetaType Property::mtype() const
{
    return m_type;
}

/* ============================================================================
 *
 * */
bool Property::readOnly() const
{
    return m_readOnly;
}


} // core
} // proteo
#endif // PROPERTY_HPP
