#ifndef GUIOBJECT_HPP
#define GUIOBJECT_HPP
//!
//! \file GuiObject.hpp
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

#include <proteo/core/Object.hpp>

namespace proteo { namespace gui {

class GuiObject : public core::Object
{

    //! \brief Default constructor
    //!
    GuiObject(std::string name);

    //! \brief Visible getter
    //!
    bool isVisible();

    //! \brief Visible setter
    //!
    setVisible(bool v);

    //! \brief 
    //!
    virtual QSharedPointer<QWidget> uiWidget() = 0;

protected:

    //! \brief Visible property
    //!
    bool m_visible;

    //! \brief widget
    //!
    QSharedPointer<QWidget> m_widget;

};


} // gui
} // proteo
#endif // GUIOBJECT_HPP
