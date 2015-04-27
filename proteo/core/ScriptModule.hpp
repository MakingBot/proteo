#ifndef SCRIPTMODULE_HPP
#define SCRIPTMODULE_HPP
//!
//! \file ScriptModule.hpp
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

#include "ScriptScope.hpp"

#include <boost/python.hpp>
using namespace boost::python;

namespace proteo { namespace core {

//! \class ScriptModule
//! \brief 
//!
//! \author [XR]MakingBot ( http://makingbot.fr )
//!
class ScriptModule
{

public:

    //! \brief Default constructor
    //!
    inline ScriptModule(const std::string& name, const ScriptScope& scope);

    //! \brief Import flag getter
    //!
    inline bool isImported()const;
    
    //! \brief Import flag setter
    //!
    inline void setImported(bool imp) ;

    //! \brief Name getter
    //!
    inline const std::string& name() const;

    //! \brief Name setter
    //!
    inline void setName(const std::string& n);

    //! \brief Scope getter
    //!
    inline ScriptScope& scope();

    //! \brief Scope setter
    //!
    inline void setScope(const ScriptScope& s);

    //! \brief Scope name list to dot chain 'path.to.scope'
    //!
    std::string toDotChain() const;

protected:

    //! \brief True if the module has been imported
    //!
    bool m_imported;

    //! \brief Module name
    //!
    std::string m_name;

    //! \brief Module scope
    //!
    ScriptScope m_scope;

};

/* ============================================================================
 *
 * */
inline ScriptModule::ScriptModule(const std::string& name, const ScriptScope& scope)
    : m_imported(false)
    , m_name(name)
    , m_scope(scope)
{ }

/* ============================================================================
 *
 * */
inline bool ScriptModule::isImported() const
{
    return m_imported;
}

/* ============================================================================
 *
 * */
inline void ScriptModule::setImported(bool imp)
{
    m_imported = imp;
    if(m_imported)
    {
        //object result = import(toDotChain().toStdString().c_str());

        std::string import_cmd = "from " + toDotChain() + " import *";
        exec(import_cmd.c_str());
    }
}

/* ============================================================================
 *
 * */
inline const std::string& ScriptModule::name() const
{
    return m_name;
}

/* ============================================================================
 *
 * */
inline void ScriptModule::setName(const std::string& n)
{
    m_name = n;
}

/* ============================================================================
 *
 * */
inline ScriptScope& ScriptModule::scope()
{
    return m_scope;
}

/* ============================================================================
 *
 * */
inline void ScriptModule::setScope(const ScriptScope& s)
{
    m_scope = s;
}



} // core
} // proteo
#endif // SCRIPTMODULE_HPP
