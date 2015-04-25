//!
//! \file ComposerParameter.hpp
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

#include "ComposerParameter.hpp"

using namespace proteo;
using namespace proteo::gui;


#include <stdlib.h>
#include <iostream>


/* ============================================================================
 *
 * */
ComposerParameter::ComposerParameter()
    : QObject()
{

    refreshModuleList();
}


/* ============================================================================
 *
 * */
void ComposerParameter::refreshModuleList()
{
    QString path_env(getenv("PYTHONPATH"));
    QStringList path_list = path_env.split(":", QString::SkipEmptyParts);

    

    foreach(const QString& path, path_list)
    {

        QStringList modules = QDir(path).entryList(QDir::Dirs | QDir::NoDotAndDotDot);
        int i = modules.indexOf("proteo");
        if(i!=-1)
        {
            m_modulePath = path ;//+ QDir::separator() + modules[i];
        }

    }

    std::cout << "Proteo path:" << m_modulePath.toStdString() << std::endl;


    extractModules(ScriptScope("proteo"));

}


/* ============================================================================
 *
 * */
void ComposerParameter::extractModules(const ScriptScope& scope)
{
    const QString scope_dir_path = m_modulePath + QDir::separator() + scope.toPathChain();
    QDir scope_dir( scope_dir_path );


    QStringList scope_module_list = scope_dir.entryList(QDir::Files | QDir::NoDotAndDotDot);

    foreach(const QString& module, scope_module_list)
    {
        QString name = module.split(".",QString::SkipEmptyParts).at(0);
        QString extension = module.split(".",QString::SkipEmptyParts).at(1);

        if( extension.compare("so") == 0 )
        {

            m_modules << ScriptModule(name, scope);
        
        }

        
    }

}


/* ============================================================================
 *
 * */
void ComposerParameter::signalParamModification()
{
    emit moduleListModified();
}

