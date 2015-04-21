//!
//! \file ViewerInteger.cpp
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

#include "ViewerInteger.hpp"
#include <QHBoxLayout>

using namespace proteo::core;
using namespace proteo::gui;

/* ============================================================================
 *
 * */
ViewerInteger::ViewerInteger(quint8 propid, bool readonly, int step, int min, int max)
    : ViewerProperty(propid, readonly)
{
    // Create the layout
    QHBoxLayout* lay = new QHBoxLayout(this);
    lay->addWidget( &m_box );
    
    // Manage the read only parameter
    m_box.setReadOnly(readonly);
    connect(&m_box, SIGNAL(valueChanged(int)), this, SLOT(onValueChange(int)));
    if(!readonly)
    {
        lay->addWidget( &m_setButton );
        connect(&m_setButton, SIGNAL(clicked()), this, SLOT(apply()));
    }

    // Box property
    m_box.setSingleStep( step );
    m_box.setRange( min , max );
    m_box.setAlignment( Qt::AlignCenter );

}

/* ============================================================================
 *
 * */
void ViewerInteger::setValueFromVariant(const proteo::core::Variant& variant)
{
    setInterger(variant.toUint32());
}

/* ============================================================================
 *
 * */
void ViewerInteger::apply()
{
    if(m_setButton.hasChanged())
    {
        emit newValueRequestedFor(m_property, proteo::core::Variant((uint32_t)m_box.value()));
        m_setButton.update();
    }
}

/* ============================================================================
 *
 * */
void ViewerInteger::onValueChange(int value)
{
    Q_UNUSED(value);
    m_setButton.change();
}

