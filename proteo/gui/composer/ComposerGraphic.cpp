//!
//! \file ComposerGraphic.cpp
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

#include "ComposerGraphic.hpp"

#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <proteo/gui/Composer.hpp>

using namespace proteo;
using namespace proteo::gui;

/* ============================================================================
 *
 * */
ComposerGraphic::ComposerGraphic(Composer* c, QSharedPointer<ComposerParameter> parameter)
    : QWidget()
    , m_composer (c)
    , m_parameter(parameter)
{
    // Create the bar widget
    QWidget* bar = new QWidget();
    QHBoxLayout* barlay = new QHBoxLayout(bar);

    barlay->addWidget(new QLabel("Name"));
    barlay->addWidget(&m_boxName);
    m_boxName.setMaximumWidth(500);
    barlay->addWidget(new QLabel("Width"));
    barlay->addWidget(&m_boxWidth);
    m_boxWidth.setMinimumWidth(100);
    barlay->addWidget(new QLabel("Height"));
    barlay->addWidget(&m_boxHeight);
    m_boxHeight.setMinimumWidth(100);
    
    // Create the layout
    QGridLayout* lay = new QGridLayout(this);
    lay->addWidget(bar     , 0, 0);
    lay->addWidget(&m_view , 1, 0);

    // Check new connections
    m_composer->objSignals()->newConnection.connect( boost::bind(&ComposerGraphic::refreshBarInfo, this) );

    // First refresh
    refreshBarInfo();
}

/* ============================================================================
 *
 * */
void ComposerGraphic::refreshBarInfo()
{
    boost::shared_ptr<core::Object> container = m_composer->container();
    if(container)
    {
        m_boxName.setText(QString(container->objName().c_str()));
        m_boxWidth.setValue(0);
        m_boxHeight.setValue(0);
    }
    else
    {
        m_boxName.setText("No container connected");
        m_boxWidth.setValue(0);
        m_boxHeight.setValue(0);
    }
}



