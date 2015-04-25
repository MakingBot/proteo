//!
//! \file ComposerMenu.cpp
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

#include "ComposerMenu.hpp"

#include <QGridLayout>

using namespace proteo;
using namespace proteo::gui;




/* ============================================================================
 *
 * */
ComposerMenu::ComposerMenu(QSharedPointer<ComposerParameter> parameter)
    : QWidget(), m_parameter(parameter)
    , m_tabObjects(m_parameter)
    , m_tabModules(m_parameter)
{



    m_tabContainer.addTab(&m_tabModules, "Modules");
    m_tabContainer.addTab(&m_tabObjects, "Objects");



    // Create the layout
    QGridLayout* lay = new QGridLayout(this);
    lay->addWidget(&m_tabContainer, 0, 0);




}




