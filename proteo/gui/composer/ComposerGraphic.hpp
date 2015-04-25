#ifndef COMPOSERGRAPHIC_HPP
#define COMPOSERGRAPHIC_HPP
//!
//! \file ComposerGraphic.hpp
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
#include <QSpinBox>
#include <QLineEdit>

#include "ComposerView.hpp"
#include "ComposerScene.hpp"
#include "ComposerParameter.hpp"

namespace proteo { namespace gui {

class Composer;

//! \class ComposerGraphic
//! \brief Menu of the composer widget
//!
//! \author [XR]MakingBot ( http://makingbot.fr )
//!
class ComposerGraphic : public QWidget
{
    Q_OBJECT

public:

    //! \brief Default constructor
    //!
    ComposerGraphic(Composer* c, QSharedPointer<ComposerParameter> parameter);


    void refreshBarInfo();

protected:

    //! \brief
    //!
    QLineEdit m_boxName;

    //! \brief
    //!
    QSpinBox m_boxWidth;

    //! \brief
    //!
    QSpinBox m_boxHeight;

    //! \brief 
    //!
    ComposerView m_view;


    //! \brief Composer object
    //!
    Composer* m_composer;

    //! \brief Composer parameters
    //!
    QSharedPointer<ComposerParameter> m_parameter;

};

} // gui
} // proteo
#endif // COMPOSERGRAPHIC_HPP
