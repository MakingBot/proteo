//!
//! \file ComposerEditor.cpp
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

#include "ComposerEditor.hpp"

#include <QGridLayout>
#include <proteo/gui/Composer.hpp>

using namespace proteo;
using namespace proteo::gui;
using namespace proteo::core;

/* ============================================================================
 *
 * */
ComposerEditor::ComposerEditor(Composer* c, QSharedPointer<ComposerParameter> parameter)
    : QWidget()
    , m_composer (c)
    , m_parameter(parameter)
{
    // Widget properties
    this->setMinimumWidth(400);


    QGridLayout* lay = new QGridLayout(this);

    lay->addWidget(&m_editor, 0, 0);


    // Connect the box signal
    connect(m_parameter.data()  , &ComposerParameter::moduleListModified    ,
            this                , &ComposerEditor::onModuleListModified );


    connect(m_parameter.data()  , &ComposerParameter::containerModified    ,
            this                , &ComposerEditor::onModuleListModified );




    new ComposerEditorHighlighter(m_editor.document());
}

/* ============================================================================
 *
 * */
void ComposerEditor::onModuleListModified()
{
    CodeStream cs;
    cs << m_parameter->modules();
    cs << m_parameter->composer()->container();

    m_editor.setText(QString(cs.code().c_str()));
}

