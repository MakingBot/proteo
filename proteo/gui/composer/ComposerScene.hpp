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

#include "ItemObject.hpp"
#include "ItemCrossPoint.hpp"
#include "ComposerParameter.hpp"
    
namespace proteo { namespace gui {

class Composer;

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
    ComposerScene(Composer* c, QSharedPointer<ComposerParameter> parameter);


public slots:

    void refreshGrid();


signals:

    void requestTopObjectCreation(const QPointF& scenePos, const QString& type);

protected:


    //! \brief Cross points that compose the grid
    //!
    QList<QSharedPointer<ItemCrossPoint> > m_crossPoints;


    QList<QSharedPointer<ItemObject> > m_objects;


    //! \brief Composer object
    //!
    Composer* m_composer;

    //! \brief Composer parameters
    //!
    QSharedPointer<ComposerParameter> m_parameter;

    // ========================================================================
    // => QGraphicsScene

    //! FROM QGraphicsScene
    //!
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event) Q_DECL_OVERRIDE;

    //! FROM QGraphicsScene
    //!
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event) Q_DECL_OVERRIDE;

    //! FROM QGraphicsScene
    //!
    void dragMoveEvent(QGraphicsSceneDragDropEvent* event);

    //! FROM QGraphicsScene
    //!
    void dropEvent(QGraphicsSceneDragDropEvent *event) Q_DECL_OVERRIDE;


};




} // gui
} // proteo
#endif // COMPOSERSCENE_HPP
