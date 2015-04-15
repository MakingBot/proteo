//!
//! \file ViewerNumber.cpp
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

#include <ViewerNumber.hpp>
#include <QHBoxLayout>

using namespace proteo::core;

/* ============================================================================
 *
 * */
ViewerNumber::ViewerNumber(quint8 propid, bool readonly, int step, int min, int max)
    : ViewerIProperty(propid, readonly)
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
        connect(&m_setButton, SIGNAL(click()), this, SLOT(apply()));
    }

    // Box property
    m_box.setSingleStep( step );
    m_box.setRange( min , max );
}

/* ============================================================================
 *
 * */
void ViewerNumber::apply()
{
    if(m_setButton.hasChanged())
    {
        emit newValueRequestedFor(_propid, );
    }
}

/* ============================================================================
 *
 * */
void ViewerNumber::onValueChange(int value)
{
    Q_UNSED(value);
    m_setButton.change();
}

