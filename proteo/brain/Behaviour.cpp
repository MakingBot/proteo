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

}







/* ============================================================================
 *
 * */
void Behaviour::attachEvent(const std::string name, const boost::python::object& action)
{
    if( hasattr(action, "__call__") )
    {
        boost::python::call<void>(action.ptr());    
    }
}

/* ============================================================================
 *
 * */
void Behaviour::execute()
{
    // Initialize thread
    m_thread->loopTime = high_resolution_clock::now();

    // Main loop
    while(m_thread->run)
    {
        // Get current time
        std::chrono::high_resolution_clock::time_point ms_time = high_resolution_clock::now();

        //
        // auto elapsed = duration_cast<std::chrono::milliseconds>(ms_time - m_thread->loopTime);


        // cout << "coucou : " << elapsed.count() << endl;


        //std::cout << typeid(elapsed).name() << std::endl;  


        // Save time
        m_thread->loopTime = ms_time;
    }




}

