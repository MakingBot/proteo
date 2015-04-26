#ifndef ITEMOBJECT_HPP
#define ITEMOBJECT_HPP
//!
//! \file ItemObject.hpp
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

#include <QGraphicsItemGroup>
#include <proteo/core/Object.hpp>

#include "ComposerParameter.hpp"

namespace proteo { namespace gui {



class ItemObject : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT

public:

    enum ItemCorner { ICTopLeft, ICBotLeft, ICBotRight, ICTopRight };


    ItemObject(boost::shared_ptr<core::Object> obj, QGraphicsItem* parent = 0);


    //! FROM QGraphicsItem
    QRectF boundingRect() const;

    //! FROM QGraphicsItem
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:

    //! \brief Bounding rectangle
    //!
    QRectF m_bounding;

    //! \brief Associated object
    //!
    boost::shared_ptr<core::Object> m_object;


    //! \brief Update the item geometry
    //!
    void updateGeometry();

};


} // gui
} // proteo
#endif // ITEMOBJECT_HPP
