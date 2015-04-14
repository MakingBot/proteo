//!
//! \file SpyWidgetHeader.cpp
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

#include "SpyWidgetHeader.hpp"
#include <proteo/gui/Spy.hpp>

#include <QEvent>
#include <QPainter>
#include <QGridLayout>
#include <QStyleOption>

using namespace proteo::gui;

/* ============================================================================
 *
 * */
SpyWidgetHeader::SpyWidgetHeader(Spy* spy)
    : QWidget()
    , m_labelTag     ( "tag" )
    , m_labelRole    ( "role" )
    , m_labelParent  ( "parent" )
    , m_labelChildNb ( "childs" )
    , m_labelConnNb  ( "connections" )
    , m_spy          ( spy )
{
    // Widget geometrie
    const int height_name = 96;
    const int height      = height_name + 64;
    this->setMinimumHeight(height);
    this->setMaximumHeight(height);

    // Widget properties
    this->setObjectName("SpyWidgetHeader");
    this->setStyleSheet("QWidget#SpyWidgetHeader"
    "{"
    "background-color: #FFFFFF;"\
    "}");

    // Label name properties
    m_labelName.setMinimumHeight(height_name);
    m_labelName.setMaximumHeight(height_name);
    m_labelName.setAlignment(Qt::AlignBottom);

    // Widget composition
    new QGridLayout(this);
    ((QGridLayout*)layout())->setSpacing(5);
    ((QGridLayout*)layout())->setContentsMargins(0,0,0,0);
    ((QGridLayout*)layout())->addWidget(&m_labelName   , 0, 0, 1, 6, Qt::AlignTop);
    ((QGridLayout*)layout())->addWidget(&m_labelTag    , 1, 0);
    ((QGridLayout*)layout())->addWidget(&m_labelRole   , 1, 1);
    ((QGridLayout*)layout())->addWidget(&m_labelParent , 1, 2);
    ((QGridLayout*)layout())->addWidget(&m_labelChildNb, 1, 3);
    ((QGridLayout*)layout())->addWidget(&m_labelConnNb , 1, 4);

    // First
    updateProperties();
}

/* ============================================================================
 *
 * */
void SpyWidgetHeader::paintEvent(QPaintEvent *event)
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
void SpyWidgetHeader::onSpiedObjChange()
{
    updateProperties();
}

/* ============================================================================
 *
 * */
void SpyWidgetHeader::updateProperties()
{
    if(m_spy->spiedObj())
    {
        // Name
        updateLabelName(m_spy->spiedObj()->objName(), m_spy->spiedObj()->objRole());

        // Object tag
        std::string tag_str(std::begin( m_spy->spiedObj()->objTag() ), std::end( m_spy->spiedObj()->objTag() ));
        m_labelTag.setValue( QString(tag_str.c_str()) );

        // objRole()
        // m_labelRole   .setValue("");

        // Childs and connections number
        m_labelChildNb.setValue(QString::number(m_spy->spiedObj()->nbObjChilds     ()));
        m_labelConnNb .setValue(QString::number(m_spy->spiedObj()->nbObjConnections()));

        // Parent
        boost::shared_ptr<core::Object> parent = m_spy->spiedObj()->objParent();
        if(parent)
        {
            m_labelParent.setValue( QString(parent->objName().c_str()) );
        }
        else
        {
            m_labelParent .setValue("X");
        }
    }
    else
    {
        updateLabelName("No object spied", 0x424242);
        m_labelTag    .setValue("");
        m_labelRole   .setValue("");
        m_labelParent .setValue("");
        m_labelChildNb.setValue("");
        m_labelConnNb .setValue("");
    }
}

/* ============================================================================
 *
 * */
void SpyWidgetHeader::updateLabelName(const std::string& name, quint32 color)
{
    // Set text
    m_labelName.setText( QString(name.c_str()) );

    // Set style
    m_labelName.setStyleSheet(
        "background-color: #" + QString::number(color, 16) + ";"
        "color: #FFFFFF; font: 34px Roboto; padding: 10px;"
        );
}

/* ============================================================================
 *
 * */
void SpyWidgetHeader::onObjNameModification()
{
    if(m_spy->spiedObj())
    {
        updateLabelName(m_spy->spiedObj()->objName(), m_spy->spiedObj()->objRole());
    }
    else
    {
        
        updateLabelName("No object spied", 0x424242);
    }

}
