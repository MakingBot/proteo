#ifndef COMPOSERSCENE_HPP
#define COMPOSERSCENE_HPP
//!
//! \file ComposerScene.hpp
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
#include <QGraphicsScene>
    
namespace proteo { namespace gui {

//! \class ComposerScene
//! \brief Menu of the composer widget
//!
//! \author [XR]MakingBot ( http://makingbot.fr )
//!
class ComposerScene : public QGraphicsScene
{
    Q_OBJECT

public:

    //! \brief Default constructor
    //!
    ComposerScene();

protected:




};


/* ============================================================================
 *
 * */
inline ComposerScene::ComposerScene()
    : QGraphicsScene()
{

}


} // gui
} // proteo
#endif // COMPOSERSCENE_HPP
