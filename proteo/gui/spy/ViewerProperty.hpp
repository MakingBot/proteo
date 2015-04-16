#ifndef VIEWERPROPERTY_HPP
#define VIEWERPROPERTY_HPP
//!
//! \file ViewerProperty.hpp
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
#include <proteo/core/Variant.hpp>

namespace proteo { namespace gui {

//! \class ViewerProperty
//! \brief Global interface for interactive property viewers
//!
//! \author [XR]MakingBot ( http://makingbot.fr )
//!
class ViewerProperty : public QWidget
{
    Q_OBJECT

public:

    //! \brief Default constructor
    //!
    ViewerProperty(quint8 id, bool readonly)
        : QWidget(0), m_property(id), m_readOnly(readonly)
    { }

    //!
    //!
    virtual void setValueFromVariant(const proteo::core::Variant& variant) = 0;

signals:

    //! \brief Signal which property has to be updated
    //!
    void newValueRequestedFor(quint8 id, proteo::core::Variant variant);

protected:

    //! \brief The ID of the property
    //!
    quint8 m_property;

    //! \brief True if the widget cannot be change by the user
    //!
    bool m_readOnly;

};


} // gui
} // proteo
#endif // VIEWERPROPERTY_HPP
