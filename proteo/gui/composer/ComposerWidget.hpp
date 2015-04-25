#ifndef COMPOSERWIDGET_HPP
#define COMPOSERWIDGET_HPP
//!
//! \file ComposerWidget.hpp
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
#include <QSplitter>
#include <proteo/gui/Composer.hpp>

#include "ComposerMenu.hpp"
#include "ComposerGraphic.hpp"
#include "ComposerEditor.hpp"
#include "ComposerParameter.hpp"

namespace proteo { namespace gui {

class Composer;

//! \class ComposerWidget
//! \brief Widget of the composer object
//!
//! \author [XR]MakingBot ( http://makingbot.fr )
//!
class ComposerWidget : public QWidget
{
    Q_OBJECT

public:

    //! \brief Default constructor
    //!
    explicit ComposerWidget(Composer* c);

signals:

public slots:

protected:

    //! \brief Parameter used for the composer
    //!
    QSharedPointer<ComposerParameter> m_parameter;
    
    //! \brief The graphic scene
    //!
    QSharedPointer<ComposerScene> m_scene;

    //! \brief
    //!
    QSplitter m_splitter;

    //! \brief Object menu
    //!
    ComposerMenu m_menu;

    //! \brief Software architecture view
    //!
    ComposerGraphic m_graphic;

    //! \brief Script editor
    //!
    ComposerEditor m_editor;

    //! \brief Composer object
    //!
    Composer* m_composer;

};

} // gui
} // proteo
#endif // COMPOSERWIDGET_HPP
