//!
//! \file SpyWidget.cpp
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

#include "SpyWidget.hpp"
#include <proteo/gui/Spy.hpp>

// #include <QString>
// #include <QLineEdit>
// #include <QComboBox>
// #include <QCloseEvent>
// #include <QGridLayout>
// #include <QMapIterator>
// #include <QMetaProperty>

using namespace proteo::gui;


/* ============================================================================
 *
 * */
SpyWidget::SpyWidget(Spy* spy)
    : QWidget(0)
    , m_spy  (spy)
    , m_header        (spy)
    // , _body             (parent_block)
    // , _footer           (parent_block)
{
    // Basic verification
    if(!m_spy)
    {
        throw std::runtime_error("Spy widget has been created without a parent spy block");
    }

    // Window configuration
    setWindowTitle( "Spy : " + QString(m_spy->objName().c_str()) );

    // Create layout
    QGridLayout* lay = new QGridLayout(this);
    lay->setSpacing(0);
    lay->setContentsMargins(0,0,0,0);
    
    lay->addWidget(&m_header, 0, 0, Qt::AlignTop);
    // ((QGridLayout*)layout())->addWidget(&_body  , 1, 0);
    // ((QGridLayout*)layout())->addWidget(&_footer, 2, 0, Qt::AlignBottom);
    
    // // Connect update signals
    // connect(_spyblock, SIGNAL(spiedBlockChanged()), this, SLOT(onSpiedBlockChange()));
}

/* ============================================================================
 *
 * */
// void SpyWidget::onSpiedBlockChange()
// {
    // _header.onSpiedBlockChange();
    // _body  .onSpiedBlockChange();
    // _footer.onSpiedBlockChange();

    // // Build the new one
    // QSharedPointer<BotBlock> spied = _spyblock->weakSpiedBlock().toStrongRef();
    // if(spied)
    // {        
    //     // Connect events to the header
    //     connect( spied.data(), SIGNAL(blockFamilyChanged     ()), &_header, SLOT(updateValues()) );
    // 	connect( spied.data(), SIGNAL(blockConnectionsChanged()), &_header, SLOT(updateValues()) );

    //     // Connect events to the body
    //     connect( spied.data(), SIGNAL(blockiPropertyValuesChanged   ()), &_body  , SLOT(updateValues   ()) );
    //     connect( spied.data(), SIGNAL(blockiPropertyStructureChanged()), &_body  , SLOT(updateStructure()) );

    //     // Connect events to the footer
    //     connect( spied.data(), SIGNAL(blockStatusChanged()), &_footer, SLOT(updateValues()) );
    // }
//}

/* ============================================================================
 *
 * */
void SpyWidget::closeEvent(QCloseEvent* event)
{
    // if(m_spy)
    // {
    //     //
    //     m_spy->hide();
        
    //     //
    //     event->ignore();
    // }
}
