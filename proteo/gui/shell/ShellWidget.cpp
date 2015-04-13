//!
//! \file ShellWidget.cpp
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

#include "ShellWidget.hpp"
#include <QGridLayout>

using namespace proteo::gui;

#include <boost/python.hpp>
#include <iostream>
using namespace boost::python;

/* ============================================================================
 *
 * */
ShellWidget::ShellWidget(QWidget *parent) :
    QWidget(parent)
{
    // Window configuration
    setWindowTitle( "Shell" );



    m_histoArea.setWidget(&m_histoView);
    m_histoArea.setWidgetResizable(true);
    m_histoArea.setMaximumWidth(200);

    QGridLayout* lay = new QGridLayout(this);
    lay->addWidget(&m_resultArea, 0, 0);
    lay->addWidget(&m_histoArea , 0, 1, 2, 1);
    lay->addWidget(&m_cmdLine   , 1, 0);


    //

    connect(&m_cmdLine, SIGNAL(returnPressed()), this, SLOT(onNewCmd()));
    connect(&m_histoView, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onItemClick(QListWidgetItem*)));


    
    

}

/* ============================================================================
 *
 * */
void ShellWidget::onNewCmd()
{
    QString cmd = m_cmdLine.text();

    m_cmdLine.setText("");

    //object result = 
    exec(cmd.toStdString().c_str()); //eval

    //int five_squared = extract<int>(result);


    //m_resultArea.append( QString::number(five_squared) );


    m_histoView.addItem( cmd );



}

/* ============================================================================
 *
 * */
void ShellWidget::onItemClick(QListWidgetItem * item)
{
    m_cmdLine.setText(item->text());
}

