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

namespace proteo { namespace brain {

//! \class Behaviour
//! \brief 
//!
class Behaviour : public core::Object
{

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
    static const core::TagArray OTag;

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
    virtual const core::TagArray& objTag() const;

    //! \brief FROM Object
    //!
    virtual const std::vector<core::Property>& properties() const;

    // ========================================================================
    // => Behaviour

    //! \brief Start behaviour thread
    //!
    void start();

    //! \brief Stop bhaviour thread
    //!
    void stop();

    //! \brief Create an event called 'name' that is triggered at the provided 'frequency'
    //!
    void createEvent(const std::string name, uint8_t frequency);

    //! \brief Create an event called 'name' that is triggered when 'condition' is true
    //!
    void createEvent(const std::string name, pyobj condition);

    void createEvent(const std::string name, shared_ptr<core::Object> obj, const std::string property_id, pyobj condition);

    void createEvent(const std::string name, shared_ptr<core::Object> obj, const std::string property_name, pyobj condition);

    //! \brief Attach an action to the event 'name'
    //!
    void attachEvent(const std::string name, pyobj action);



protected:


    std::atomic_bool m_tRun;

    //! \brief Behaviour thread
    //!
    std::thread m_thread;


    //! \brief Function executed by the thread
    //!
    void execute();


};

} // brain
} // proteo
#endif // BEHAVIOUR_HPP

