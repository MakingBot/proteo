#ifndef ITEMCROSSPOINT_HPP
#define ITEMCROSSPOINT_HPP
//!
//! \file ItemCrossPoint.hpp
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

#include <QGraphicsItem>

#include "ComposerParameter.hpp"

namespace proteo { namespace gui {



class ItemCrossPoint : public QGraphicsItem
{

public:

    inline ItemCrossPoint();

    //! FROM QGraphicsItem
    //!
    QRectF boundingRect() const;

    //! FROM QGraphicsItem
    //!
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


protected:

    //! \brief Bounding rectangle
    //!
    QRectF m_bounding;


    //! \brief Update the item geometry
    //!
    void updateGeometry();

};

/* ============================================================================
 *
 * */
inline ItemCrossPoint::ItemCrossPoint()
    : QGraphicsItem()
{
    // Define flags
    setFlag(ItemSendsGeometryChanges);
    
    // First update
    updateGeometry();
}


} // gui
} // proteo
#endif // ITEMCROSSPOINT_HPP
