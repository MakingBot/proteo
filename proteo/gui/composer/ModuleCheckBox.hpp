#ifndef MODULECHECKBOX_HPP
#define MODULECHECKBOX_HPP
//!
//! \file ModuleCheckBox.hpp
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

#include <QCheckBox>
#include "ComposerParameter.hpp"

namespace proteo { namespace gui {



class ModuleCheckBox : public QCheckBox
{
    Q_OBJECT

public:

    ModuleCheckBox(const QString & text = "", int ind = 0)
        : QCheckBox(text), index(ind)
    {

    }


    int index;

};


} // gui
} // proteo
#endif // MODULECHECKBOX_HPP
