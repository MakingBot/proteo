#ifndef SENSORDISTANCE_HPP
#define SENSORDISTANCE_HPP
//!
//! \file SensorDistance.hpp
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

namespace proteo { namespace model {

//! \class SensorDistance
//! \brief Define model for sensor distance
//!
//! \author [XR]MakingBot ( http://makingbot.fr )
//!
class SensorDistance : public core::Object
{

public:

    //! \brief Distance property id
    //!
    static const uint8_t IdPropertyDistance;

    //! \brief Default constructo
    //!
    SensorDistance(std::string name);

    // ========================================================================
    // => Constantes

    //! \brief Role
    //!
    static const core::ObjRole ORole;

    //! \brief Tag
    //!
    static const core::Object::TagArray OTag;

    //! \brief Property vector
    //!
    static const std::vector<core::Property> Properties;

    // ========================================================================
    // => Object redefinition

    //! \brief FROM Object
    //!
    virtual core::ObjRole objRole() const;

    //! \brief FROM Object
    //!
    virtual const core::Object::TagArray& objTag() const;

    //! \brief FROM Object
    //!
    virtual const char* objType() const { return "SensorDistance"; }

    //! \brief FROM Object
    //!
    virtual core::Variant propertyValue(uint8_t id);

    //! \brief FROM Object
    //!
    virtual void setPropertyValue(uint8_t id, const core::Variant& v);

    //! \brief FROM Object
    //!
    virtual const std::vector<core::Property>& properties() const;

    // ========================================================================
    // => Object redefinition

    //! \brief Distance getter
    //!
    uint32_t distance();

    //! \brief Distance setter
    //!
    void setDistance(uint32_t distance);

protected:

    //! \brief Distance value in mm
    //!
    uint32_t m_distance;

};

} // model
} // proteo
#endif // SENSORDISTANCE_HPP
