//!
//! \file Behaviour.cpp
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

#include "Behaviour.hpp"

using namespace std;
using namespace std::chrono;
using namespace proteo::core;
using namespace proteo::brain;

/* ============================================================================
 *
 * */
Behaviour::Behaviour(std::string name)
    : core::Object(name)
    , m_thread(new ThreadControl)
{
}

/* ============================================================================
 *
 * */
const ObjRole Behaviour::ORole = Rgui;

/* ============================================================================
 *
 * */
const Object::TagArray Behaviour::OTag = { 'B', 'E', 'H', 'V' };

/* ============================================================================
 *
 * */
const std::vector<Property> Behaviour::Properties = {
    // Property(IdPropertyDistance, "distance", Tuint)
};

/* ============================================================================
 *
 * */
ObjRole Behaviour::objRole() const
{
    return ORole;
}

/* ============================================================================
 *
 * */
const Object::TagArray& Behaviour::objTag() const
{
    return OTag;
}

/* ============================================================================
 *
 * */
const std::vector<Property>& Behaviour::properties() const
{
    return Properties;
}

/* ============================================================================
 *
 * */
bool Behaviour::isRunning()
{
    return m_thread->run;
}

/* ============================================================================
 *
 * */
void Behaviour::setRun(bool run)
{
    if( run )
    {
        if( !isRunning() )
        {
            start();
        }
    }
    else
    {
        if( isRunning() )
        {
            stop();
        }
    }
}

/* ============================================================================
 *
 * */
void Behaviour::start()
{
    m_thread->run = true;
    m_thread->thread = std::move( std::thread(&Behaviour::execute, this) );
}

/* ============================================================================
 *
 * */
void Behaviour::stop()
{
    m_thread->run = false;
    m_thread->thread.join();
}



// Helper function to check if an object has an attribute.
bool hasattr(const boost::python::object& obj,
             const std::string& name)
{
    return PyObject_HasAttrString(obj.ptr(), name.c_str());
}


/* ============================================================================
 *
 * */
void Behaviour::createCyclicEvent(const std::string name, uint8_t frequency)
{

}

/* ============================================================================
 *
 * */
void Behaviour::createConditionedEvent(const std::string name, const boost::python::object& condition)
{
    m_conditionedEvents.insert( std::pair<std::string, BhConditionedEvent>(name,BhConditionedEvent(condition)) );
}

/* ============================================================================
 *
 * */
void Behaviour::createPropertyEvent(const std::string name, std::shared_ptr<core::Object> obj, const std::string property_id, boost::python::object condition)
{
    //BhPropertyEvent event(obj, property_id, condition);
}

/* ============================================================================
 *
 * */
void Behaviour::attachEvent(const std::string name, const boost::python::object& action)
{
    if( ! hasattr(action, "__call__") )
    {
        return;
    }

    if( m_conditionedEvents.find(name) != m_conditionedEvents.end() )
    {
        m_conditionedEvents[name].setAction(action);
    }

    // boost::python::call<void>(action.ptr());
}

/* ============================================================================
 *
 * */
void Behaviour::execute()
{
    // Initialize thread
    uint32_t rt_shift = 0;
    std::chrono::milliseconds time_elapsed = 0;
    m_thread->nextTimePoint = high_resolution_clock::now() + m_thread->loopStep;

    // Main loop
    while(m_thread->run)
    {
        // Compute elapsed time
        time_elapsed = m_thread->loopStep + (rt_shift*m_thread->loopStep)


        // Actions




        // Conditioned events
        for (std::map<std::string, BhConditionedEvent>::iterator it=m_conditionedEvents.begin() ; it!=m_conditionedEvents.end() ; ++it)
        {
            const BhConditionedEvent& event = it->second;
            event.check()
        }




        // Check real time shift
        rt_shift = 0;
        while( high_resolution_clock::now() >= m_thread->nextTimePoint )
        {
            rt_shift++;
            m_thread->nextTimePoint += step;
        }

        // Sleep until the next loop
        std::this_thread::sleep_until(m_thread->nextTimePoint);
    }
}

