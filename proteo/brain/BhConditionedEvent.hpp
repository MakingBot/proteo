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


class BhConditionedEvent : public BhEvent
{

public:

    inline BhConditionedEvent(const boost::python::object& cond);


    inline const boost::python::object& condition();

protected:

    boost::python::object m_condition;

};


inline BhConditionedEvent::BhConditionedEvent(const boost::python::object& cond)
    : BhEvent()
{
    m_condition = cond;
}


inline const boost::python::object& BhConditionedEvent::condition()
{
    return m_condition;
}


} // brain
} // proteo
#endif // BHCONDITIONEDEVENT_HPP

