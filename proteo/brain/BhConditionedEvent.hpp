#ifndef BHCONDITIONEDEVENT_HPP
#define BHCONDITIONEDEVENT_HPP
//!
//! \file BhEvent.hpp
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

//! \class BhConditionedEvent
//! \brief
//!
//! \author [XR]MakingBot ( http://makingbot.fr )
//!
class BhConditionedEvent : public BhEvent
{

public:

    //! \brief Default constructor
    //!
    inline BhConditionedEvent(const boost::python::object& cond);

    //! \brief 
    //!
    inline const boost::python::object& condition();


    inline void check();

protected:

    bool m_triggered;

    //! \brief 
    //!
    boost::python::object m_condition;

};

/* ============================================================================
 *
 * */
inline BhConditionedEvent::BhConditionedEvent(const boost::python::object& cond)
    : BhEvent()
{
    m_condition = cond;
}

/* ============================================================================
 *
 * */
inline const boost::python::object& BhConditionedEvent::condition()
{
    return m_condition;
}

/* ============================================================================
 *
 * */
inline void BhConditionedEvent::check()
{
    // boost::python::call<bool>(m_condition.ptr())
    if( m_condition() )
    {
        if(!m_triggered)
        {
            m_action();
            m_triggered = true;
        }
    }
    else
    {
        if(m_triggered)
        {
            m_triggered = false;
        }
    }
}

} // brain
} // proteo
#endif // BHCONDITIONEDEVENT_HPP

