#ifndef COMPOSERVIEW_HPP
#define COMPOSERVIEW_HPP
//!
//! \file ComposerView.hpp
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
#include <QGraphicsView>
    
namespace proteo { namespace gui {

//! \class ComposerView
//! \brief Menu of the composer widget
//!
//! \author [XR]MakingBot ( http://makingbot.fr )
//!
class ComposerView : public QGraphicsView
{
    Q_OBJECT

public:

    ComposerView();

protected:




};

} // gui
} // proteo
#endif // COMPOSERVIEW_HPP
