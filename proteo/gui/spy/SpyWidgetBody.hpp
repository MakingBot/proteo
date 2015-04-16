#ifndef SPYWIDGETBODY_HPP
#define SPYWIDGETBODY_HPP
//!
//! \file SpyWidgetBody.hpp
//!
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

#include <QMap>
#include <QWidget>
#include <proteo/core/Variant.hpp>

namespace proteo { namespace gui {

class Spy;

//! \class SpyWidgetBody
//! \brief Widget that display object properties 
//!
//! \author [XR]MakingBot ( http://makingbot.fr )
//!
class SpyWidgetBody : public QWidget
{
    Q_OBJECT

public:

    //! \brief Default constructor
    //!
    SpyWidgetBody(Spy* spy);

    //! \brief FROM QWidget
    //!
    void paintEvent(QPaintEvent *event);

    //! \brief 
    //!
    void onPropertyModified(uint8_t id);

public slots:
    
    //! \brief When the spied change
    //!
    void onSpiedObjChange();

    //! \brief Update property structure
    //!
    void updateStructure();

    //! \brief Change the value of the property
    //!
    void onNewValueRequestedFor(quint8 id, proteo::core::Variant variant);


protected:

    //! \brief Spy object
    //!
    Spy* m_spy;

    //! \brief Map that contains widget of each property
    //!
    QMap<quint8, QWidget*> m_widgets;

    //! \brief Delete all current widgets
    //!
    void destroyStructure();

};

} // gui
} // proteo
#endif // SPYWIDGETBODY_HPP

