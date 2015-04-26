//!
//! \file ComposerWidget.cpp
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

#include "ComposerWidget.hpp"

#include <QFormLayout>
#include <QGridLayout>
#include <proteo/gui/Composer.hpp>

using namespace proteo;
using namespace proteo::gui;

/* ============================================================================
 *
 * */
ComposerWidget::ComposerWidget(Composer* c)
    : QWidget()
    , m_parameter   (new ComposerParameter())
    , m_scene       (new ComposerScene(c, m_parameter))
    , m_splitter    (Qt::Horizontal)
    , m_menu        (c, m_parameter)
    , m_graphic     (c, m_parameter)
    , m_editor      (c, m_parameter)
    , m_composer    (c)
{
    // Create the layout
    QGridLayout* lay = new QGridLayout(this);
    lay->addWidget(&m_splitter, 0, 0);
    m_splitter.insertWidget(0, &m_menu      );
    m_splitter.insertWidget(1, &m_graphic   );
    m_splitter.insertWidget(2, &m_editor    );

    // Window configuration
    setWindowTitle("Composer");
    setMinimumSize(1024 , 800);

    // Attach the scene to the view
    m_graphic.setScene(m_scene);


    connect(&m_graphic, SIGNAL(gridSizeModified()), m_scene.data(), SLOT(refreshGrid()));

}

/* ============================================================================
 *
 * */
void ComposerWidget::onRequestTopObjectCreation(const QPointF& scenePos, const QString& type)
{


}

/* ============================================================================
 *
 * */
void ComposerWidget::wheelEvent(QWheelEvent* event)
{

}

/* ============================================================================
 *
 * */
void ComposerWidget::closeEvent(QCloseEvent* event)
{

}

/* ============================================================================
 *
 * */
void ComposerWidget::keyPressEvent(QKeyEvent* event)
{

}

/* ============================================================================
 *
 * */
void ComposerWidget::keyReleaseEvent(QKeyEvent* event)
{

}

