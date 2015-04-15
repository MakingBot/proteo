#ifndef SETBUTTON_HPP
#define SETBUTTON_HPP
//!
//! \file SetButton.hpp
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

#include <QPushButton>

//! \class SetButton
//! \brief Button for interative properties viewer
//!
//! \author [XR]MakingBot ( http://makingbot.fr )
//!
class SetButton : public QPushButton
{
    Q_OBJECT

public:

    //! \brief Default constructor
    //!
    SetButton(QWidget* parent=0)
        : QPushButton(parent), m_changed(false)
    {
        this->setText("-");
    }

    //! \brief To check to state of the button
    //!
    bool hasChanged()
    {
        return m_changed;
    }

    //! \brief Viewer have to call this function when its data has been changed
    //!
    void change()
    {
        if( !m_changed )
        {
            setText("UPDATE");
            m_changed = true;
        }
    }

    //! \brief To reset the button
    //!
    void update()
    {
        if( m_changed )
        {
            setText("-");
            m_changed = false;
        }
    }

protected:

    //! \brief True when the data has changed
    //!
    bool m_changed;

};

#endif // SETBUTTON_HPP

