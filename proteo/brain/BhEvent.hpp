#ifndef BHEVENT_HPP
#define BHEVENT_HPP
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

#include <boost/python.hpp>

namespace proteo { namespace brain {

//! \class BhEvent
//! \brief Behaviour event interface
//!
//! \author [XR]MakingBot ( http://makingbot.fr )
//!
class BhEvent
{

public:

    //! \brief Default constructor
    //!
    inline BhEvent();

    //! \brief Action getter
    //!
    inline const boost::python::object& action();

    //! \brief Action setter
    //!
    inline void setAction(boost::python::object& action);

protected:

    //! \brief Event action
    //!
    boost::python::object m_action;

};

/* ============================================================================
 *
 * */
inline BhEvent::BhEvent()
{ }

/* ============================================================================
 *
 * */
inline const boost::python::object& BhEvent::action()
{
    return m_action;
}

/* ============================================================================
 *
 * */
inline void BhEvent::setAction(boost::python::object& action)
{
    m_action = action;
}

} // brain
} // proteo
#endif // BHEVENT_HPP
