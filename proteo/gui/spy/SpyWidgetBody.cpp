//!
//! \file SpyWidgetBody.cpp
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

#include "SpyWidgetBody.hpp"
#include <proteo/gui/Spy.hpp>

#include <QEvent>
#include <QPainter>
#include <QFormLayout>
#include <QGridLayout>
#include <QMapIterator>
#include <QStyleOption>
#include <QVectorIterator>

#include <QLabel>
#include <QSpinBox>
#include <QLineEdit>
#include <QComboBox>
#include <QDoubleSpinBox>

using namespace proteo::core;
using namespace proteo::gui;

/* ============================================================================
 *
 * */
SpyWidgetBody::SpyWidgetBody(Spy* spy)
    : QWidget(), m_spy(spy)
{
    new QFormLayout(this);
    ((QFormLayout*)layout())->setSpacing(8);
    ((QFormLayout*)layout())->setContentsMargins(10,10,10,10);
}

/* ============================================================================
 *
 * */
void SpyWidgetBody::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

/* ============================================================================
 *
 * */
void SpyWidgetBody::onSpiedObjChange()
{
    updateStructure();
}

/* ============================================================================
 *
 * */
void SpyWidgetBody::updateStructure()
{
    // Clean structure
    destroyStructure();

    // Get properties
    const std::vector<Property>& properties = m_spy->spiedObj()->properties();

    // Go through properties
    for( uint8_t pid=0 ; pid<properties.size() ; pid++ )
    {
        // Check if the property is active
        if( ! m_spy->spiedObj()->isPropertyActive(pid) )
        {
            continue;
        }

        // Get the property
        const Property property = properties[pid];
        switch( property.mtype() )
        {

            case Tuint:
            {
                
                break;
            }
            
    // Tint,

    // Tbool,
    // Tenum,

    // Tstring,

    // Treserved

        }
    }
}

/* ============================================================================
 *
 * */
void SpyWidgetBody::destroyStructure()
{
//     // Go through widgets
//     QMapIterator<quint8, QWidget*> widget(_widgetMap);
//     while (widget.hasNext())
//     {
//         widget.next();

//         // Find the label and destroy it
//         QWidget* label = ((QFormLayout*)layout())->labelForField(widget.value());
//         if(label)
//         {
//             label->deleteLater();
//         }

//         // Destroy the widget
//         widget.value()->deleteLater();
//     }
//     _widgetMap.clear();
}