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

#include <QDir>
#include <QString>
#include <QStringList>

#include <iostream>
#include <boost/python.hpp>
using namespace boost::python;

namespace proteo { namespace gui {

//! \class ScriptScope
//! \brief 
//!
//! \author [XR]MakingBot ( http://makingbot.fr )
//!
class ScriptScope
{

public:

    //! \brief Default constructor
    //!
    inline ScriptScope(const QString& base = "");

    //! \brief Scope name list to path chain 'path/to/scope'
    //!
    QString toPathChain() const;

    //! \brief Scope name list to dot chain 'path.to.scope'
    //!
    QString toDotChain() const;

protected:

    //! \brief List of scope namespace
    //!
    QStringList m_scopeChain;

};

/* ============================================================================
 *
 * */
inline ScriptScope::ScriptScope(const QString& base)
{
    m_scopeChain = base.split('.');
}

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
    inline ScriptModule(const QString& name, const ScriptScope& scope);

    //! \brief Import flag getter
    //!
    inline bool isImported();
    
    //! \brief Import flag setter
    //!
    inline void setImported(bool imp);

    //! \brief Name getter
    //!
    inline const QString& name();

    //! \brief Name setter
    //!
    inline void setName(const QString& n);

    //! \brief Scope getter
    //!
    inline ScriptScope& scope();

    //! \brief Scope setter
    //!
    inline void setScope(const ScriptScope& s);

    //! \brief Scope name list to dot chain 'path.to.scope'
    //!
    QString toDotChain() const;

protected:

    //! \brief True if the module has been imported
    //!
    bool m_imported;

    //! \brief Module name
    //!
    QString m_name;

    //! \brief Module scope
    //!
    ScriptScope m_scope;

};

inline ScriptModule::ScriptModule(const QString& name, const ScriptScope& scope)
    : m_imported(false)
    , m_name(name)
    , m_scope(scope)
{ }

/* ============================================================================
 *
 * */
inline bool ScriptModule::isImported()
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
        object result = import(toDotChain().toStdString().c_str());

        QString import_cmd = QString("from ") + toDotChain() + QString(" import *");
        exec(import_cmd.toStdString().c_str());

    }
}

/* ============================================================================
 *
 * */
inline const QString& ScriptModule::name()
{
    return m_name;
}

/* ============================================================================
 *
 * */
inline void ScriptModule::setName(const QString& n)
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

} // gui
} // proteo
#endif // SCRIPTMODULE_HPP


