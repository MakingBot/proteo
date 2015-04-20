
#ifndef BHCPROPERTYEVENT_HPP
#define BHCPROPERTYEVENT_HPP
//!
//! \file BhPropertyEvent.hpp
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


#include "BhEvent.hpp"

namespace proteo { namespace brain {

//! \class BhPropertyEvent
//! \brief Provide to users a way to create a behaviour that trigger only on property change.
//!
//! \author [XR]MakingBot ( http://makingbot.fr )
//!
class BhPropertyEvent : public BhEvent
{

public:

    inline BhPropertyEvent(std::shared_ptr<core::Object> obj, const std::string property_id, boost::python::object condition);


    

protected:

    std::shared_ptr<core::Object> m_obj;

    const uint8_t m_id;

    boost::python::object m_condition;

    void onPropertyModified(uint8_t id);

};

/* ============================================================================
 *
 * */
inline BhPropertyEvent::BhPropertyEvent(std::shared_ptr<core::Object> obj, uint8_t property_id, boost::python::object condition)
{

    // obj->objSignals()->propertyModified.connect( bind( onPropertyModified ) ));

}

/* ============================================================================
 *
 * */
void onPropertyModified(uint8_t id)
{
    // Check if the good property has been modified
    if(id != m_id)
    {
        return;
    }

}

} // brain
} // proteo
#endif // BHCPROPERTYEVENT_HPP

