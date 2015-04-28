//!
//! \file ComposerScene.cpp
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

#include "ComposerScene.hpp"
#include <proteo/gui/Composer.hpp>

#include <QMimeData>
#include <QGraphicsSceneDragDropEvent>

using namespace proteo;
using namespace proteo::gui;



#include <boost/python.hpp>
using namespace boost::python;

/* ============================================================================
 *
 * */
ComposerScene::ComposerScene(Composer* c, QSharedPointer<ComposerParameter> parameter)
    : QGraphicsScene()
    , m_composer (c)
    , m_parameter(parameter)
{
    // Check new connections
    m_composer->objSignals()->newConnection.connect( boost::bind(&ComposerScene::refreshGrid, this) );


}


/* ============================================================================
 *
 * */
void ComposerScene::refreshGrid()
{
    // Delete old grid
    m_crossPoints.clear();

    // Get the size of the container
    boost::shared_ptr<core::Object> container = m_composer->container();
    if(!container)
    {
        return;
    }

    // Get size
    const float w = container->objSize().width();
    const float h = container->objSize().height();

    const float w2= w/2.0f;
    const float h2= h/2.0f;

    // 
    for(float xcase = -w2 ; xcase <= w2 ; xcase++)
    {
        for(float ycase = -h2 ; ycase <= h2 ; ycase++)
        {
            QSharedPointer<ItemCrossPoint> point(new ItemCrossPoint());
            point->setPos( xcase * (float)ComposerParameter::CASE_PIXEL_SIZE
                         , ycase * (float)ComposerParameter::CASE_PIXEL_SIZE ); 

            m_crossPoints.append(point);
            addItem( point.data() );
        }
    }
}





/* ============================================================================
 *
 * */
void ComposerScene::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    if (event->mimeData()->hasText())
    {
        event->setAccepted(true);
        
        // _dragOver = true;

        // update();

        std::cout << "in" << std::endl;
    }
    else
    {
        event->setAccepted(false);
    }
}

/* ============================================================================
 *
 * */
void ComposerScene::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    Q_UNUSED(event);

    // _dragOver = false;

        std::cout << "out" << std::endl;
    // update();
}

/* ============================================================================
 *
 * */
void ComposerScene::dragMoveEvent(QGraphicsSceneDragDropEvent* event)
{
    if (event->mimeData()->hasText())
    {
        event->setAccepted(true);
    }
    else
    {
        event->setAccepted(false);
    }
}

/* ============================================================================
 *
 * */
void ComposerScene::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    // If has text -> block creation
    if ( event->mimeData()->hasText() )
    {
        // Get the requested block name
        QString type = event->mimeData()->text();


        std::cout << "drop " << type.toStdString() << std::endl;

        // Request the block creation
        // emit requestTopObjectCreation(event->scenePos(), type);


        // Retrieve the main module.
        object main = import("__main__");

        // Retrieve the main module's namespace
        object global(main.attr("__dict__"));

        //
        QString object_creation = type.toLower() + QString(" = ") + type + "('" + type.toLower() + "')";
        std::cout << "exec: " << object_creation.toStdString() << std::endl;
        exec(object_creation.toStdString().c_str());


        // Define greet function in Python.
        object result = eval(type.toLower().toStdString().c_str(), global, global);


        boost::shared_ptr<core::Object> temp = extract< boost::shared_ptr<core::Object> >(result);

        m_parameter->composer()->container()->append(temp);

        QSharedPointer<ItemObject> item( new ItemObject( temp) );
        item->setPos(event->scenePos());

        std::cout << "Pos: " << item->pos().x() << "  "  << item->pos().y() << std::endl;

        addItem( item.data() );


        m_objects << item;

        //std::cout << "Res: " << temp->objName() << std::endl;

        m_parameter->containerModified();

        // Accept the drop
        event->setAccepted(true);
    }


    
}

