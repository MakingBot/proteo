#ifndef COMPOSERPARAMETER_HPP
#define COMPOSERPARAMETER_HPP
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

#include <QDir>
#include <QList>
#include <QStringList>
#include "ScriptModule.hpp"



namespace proteo { namespace gui {

//! \class ComposerParameter
//! \brief Menu of the composer widget
//!
//! \author [XR]MakingBot ( http://makingbot.fr )
//!
class ComposerParameter
{

public:

    //! \brief Size in pixel of the architecture scene
    //!
    static const int CASE_PIXEL_SIZE = 300;

    //! \brief Default constructor
    //!
    ComposerParameter();


    void refreshModuleList();


    void extractModules(const ScriptScope& scope);



    QList<ScriptModule>& modules()
    {
        return m_modules;
    }

protected:

    //! \brief Path where proteo modules are stored
    //!
    QString m_modulePath;

    //! \brief List of availables modules on the system
    //!
    QList<ScriptModule> m_modules;

};

} // gui
} // proteo
#endif // COMPOSERPARAMETER_HPP
