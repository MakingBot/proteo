#ifndef COMPOSERMENU_HPP
#define COMPOSERMENU_HPP
//!
//! \file ComposerMenu.hpp
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

#include <QWidget>
#include <QTabWidget>
#include "ComposerMenuObjects.hpp"
#include "ComposerMenuModules.hpp"

namespace proteo { namespace gui {

//! \class ComposerMenu
//! \brief Menu of the composer widget
//!
//! \author [XR]MakingBot ( http://makingbot.fr )
//!
class ComposerMenu : public QWidget
{
    Q_OBJECT

public:

    ComposerMenu(QSharedPointer<ComposerParameter> parameter);

protected:

    //! \brief Tab container
    //!
    QTabWidget m_tabContainer;

    // tabwidget 
    // Modules
    // Objects



    QSharedPointer<ComposerParameter> m_parameter;



    ComposerMenuModules m_tabModules;

    ComposerMenuObjects m_tabObjects;

};

} // gui
} // proteo
#endif // COMPOSERMENU_HPP
