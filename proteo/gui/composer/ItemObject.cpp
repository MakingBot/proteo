//!
//! \file ItemObject.cpp
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

#include "ItemObject.hpp"

#include <QPainter>

using namespace proteo;
using namespace proteo::gui;

/* ============================================================================
 *
 * */
ItemObject::ItemObject(boost::shared_ptr<core::Object> obj, QGraphicsItem* parent)
    : QObject()
    , QGraphicsItemGroup(parent)
    , m_object(obj)
{
    // Configure events
    setAcceptDrops(true);
    setAcceptHoverEvents(true);
    setHandlesChildEvents(false);
    setAcceptedMouseButtons(Qt::LeftButton);

    // Define flags
    setFlag(ItemIsMovable);
    setFlag(ItemIsSelectable);
    setFlag(ItemSendsGeometryChanges);

    updateGeometry();
}


/* ============================================================================
 *
 * */
QRectF ItemObject::boundingRect() const
{
    return m_bounding;
}

/* ============================================================================
 *
 * */
void ItemObject::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // Activate antialiasing
    painter->setRenderHints(painter->renderHints() | QPainter::Antialiasing);


    painter->setBrush( Qt::SolidPattern  );
    painter->setBrush( QBrush("#FF4444") );
    painter->drawRoundedRect( m_bounding, 10, 10 );
}


/* ============================================================================
 *
 * */
void ItemObject::updateGeometry()
{
    prepareGeometryChange();

    
    const float diameter = (float)ComposerParameter::CASE_PIXEL_SIZE - (float)ComposerParameter::CASE_PIXEL_PADDING;
    const int coef = -(diameter/2.0f);

    // std::cout << (float)ComposerParameter::CASE_PIXEL_SIZE << std::endl;
    // std::cout << (float)ComposerParameter::CROSS_POINT_RATIO << std::endl;
    std::cout << diameter << std::endl;
    std::cout << coef << std::endl;


    m_bounding = QRectF( coef, coef, diameter,diameter);
}


