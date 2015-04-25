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

namespace proteo { namespace gui {



class ScriptScope
{


public:

    ScriptScope(const QString& base = "")
    {
        m_scopeChain = base.split('.');
    }

    ScriptScope join(ScriptScope& scope, QString sub_scope)
    {
       // return ScriptScope();
    }

    QString toPathChain() const
    {
        QString path_chain;
        foreach(const QString& scope, m_scopeChain)
        {
            path_chain += scope;
            path_chain += QDir::separator();    
        }
        return path_chain;
    }

protected:


    //! 
    //!
    QStringList m_scopeChain;

};



//! \class ScriptModule
//! \brief Menu of the composer widget
//!
//! \author [XR]MakingBot ( http://makingbot.fr )
//!
class ScriptModule
{

public:

    //! \brief Default constructor
    //!
    ScriptModule(const QString& name, const ScriptScope& scope)
        : m_imported(false), m_name(name), m_scope(scope)
    {

    }


    bool isImported()
    {
        return m_imported;
    }

    const QString& name()
    {
        return m_name;
    }

    ScriptScope& scope()
    {
        return m_scope;
    }

protected:

    //! 
    //!
    bool m_imported;

    //! \brief Module name
    //!
    QString m_name;

    //! \brief Module scope
    //!
    ScriptScope m_scope;

};

} // gui
} // proteo
#endif // SCRIPTMODULE_HPP
