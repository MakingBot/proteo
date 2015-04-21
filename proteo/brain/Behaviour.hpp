#ifndef BEHAVIOUR_HPP
#define BEHAVIOUR_HPP
//!
//! \file Behaviour.hpp
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

#include "BhCyclicEvent.hpp"
#include "BhConditionedEvent.hpp"
#include "BhPropertyEvent.hpp"


#include <boost/python.hpp>

namespace proteo { namespace brain {

//! \class Behaviour
//! \brief Provide to users a way to create behaviour.
//!
//! \author [XR]MakingBot ( http://makingbot.fr )
//!
class Behaviour : public core::Object
{

public:

    //! \struct ThreadControl
    //! \brief Thread control variables
    //!
    struct ThreadControl
    {
        ThreadControl()
            : run(false)
        {
            // baseFreq = 
        }

        //! \brief Behaviour thread
        //!
        std::thread thread;

        //! \brief The thread must run until run is true
        //!
        std::atomic_bool run;

        //! \brief Requested frequency
        //!
        std::atomic_uint baseFreq;

        //! \brief Number of milliseconds between 2 loop
        //!
        std::chrono::milliseconds loopStep;

        //! \brief Number of missed step loop
        //!
        std::atomic_uint rtShift;
/*
definir une frequence minimum
step = 1000/frequency
each loop must last 'step' ms 
*/

        //! \brief Time point the thread have to wait before starting the new loop
        //!
        std::chrono::high_resolution_clock::time_point nextTimePoint;

    };


    //! \brief Run property id
    //!
    static const uint8_t IdPropertyRun;

    //! \brief Freq property id
    //!
    static const uint8_t IdPropertyFreq;

    //! \brief Freq property id
    //!
    static const uint8_t IdPropertyRtShift;

    //! \brief Default constructor
    //!
    Behaviour(std::string name);

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
    virtual core::Variant propertyValue(uint8_t id);

    //! \brief FROM Object
    //!
    virtual void setPropertyValue(uint8_t id, const core::Variant& v);

    //! \brief FROM Object
    //!
    virtual const std::vector<core::Property>& properties() const;

    // ========================================================================
    // => Behaviour

    //! \brief Run getter
    //!
    bool isRunning();

    //! \brief Run setter
    //!
    void setRun(bool run);

    //! \brief Frequence getter
    //!
    uint32_t freq();

    //! \brief Frequence setter
    //!
    void setFreq(uint32_t freq);

    //! \brief Rt Shift counter getter
    //!
    uint32_t rtShift();

    //! \brief Start behaviour thread
    //!
    void start();

    //! \brief Stop bhaviour thread
    //!
    void stop();

    //! \brief Create an event called 'name' that is triggered at the provided 'frequency'
    //!
    void createCyclicEvent(const std::string name, uint8_t frequency);

    //! \brief Create an event called 'name' that is triggered when 'condition' is true
    //! The condition is checked at the base frequency
    //!
    void createConditionedEvent(const std::string name, const boost::python::object& condition);

    //! \brief Create an event called 'name' that is triggered when 'condition' is true
    //! The condition is checked only when the property is modified
    //!
    void createPropertyEvent(const std::string name, std::shared_ptr<core::Object> obj, const std::string property_id, boost::python::object condition);

    //! \brief Create an event called 'name' that is triggered at the provided 'frequency'
    //!
    inline void createEvent(const std::string name, uint8_t frequency);

    //! \brief Attach an action to the event 'name'
    //!
    void attachEvent(const std::string name, const boost::python::object& action);

protected:

    //! \brief Thread management
    //!
    std::shared_ptr<ThreadControl> m_thread;


    //std::map<std::string, BhCyclicEvent> m_cyclicEvents;


    //! \brief Map of the conditioned events
    //!
    std::map<std::string, BhConditionedEvent> m_conditionedEvents;


    //std::map<std::string, BhPropertyEvent> m_propertyEvents;






    //! \brief Function executed by the thread
    //!
    void execute();

};

/* ============================================================================
 *
 * */
inline void Behaviour::createEvent(const std::string name, uint8_t frequency)
{
    createCyclicEvent(name, frequency);
}

} // brain
} // proteo
#endif // BEHAVIOUR_HPP

