#ifndef COMPOSERMENUMODULES_HPP
#define COMPOSERMENUMODULES_HPP
//!
//! \file ComposerMenuModules.hpp
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
#include <QCheckBox>
#include "ComposerParameter.hpp"

namespace proteo { namespace gui {




class ModuleCheckBox : public QCheckBox
{

public:

    ModuleCheckBox(const QString & text = "", int ind = 0)
        : QCheckBox(text), index(ind)
    {

    }


    int index;

};





//! \class ComposerMenuModules
//! \brief Menu of the composer widget
//!
//! \author [XR]MakingBot ( http://makingbot.fr )
//!
class ComposerMenuModules : public QWidget
{
    Q_OBJECT

public:

    ComposerMenuModules(QSharedPointer<ComposerParameter> parameter);



public slots:


    void onStateChange(int state);

protected:

    //! \brief Parameters
    //!
    QSharedPointer<ComposerParameter> m_parameter;


    QList<QSharedPointer<ModuleCheckBox> > m_checkBoxs;



};

} // gui
} // proteo
#endif // COMPOSERMENUMODULES_HPP
