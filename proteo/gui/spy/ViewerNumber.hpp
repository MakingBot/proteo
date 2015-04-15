#ifndef VIEWERNUMBER_HPP
#define VIEWERNUMBER_HPP
//!
//! \file ViewerNumber.hpp
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

#include <QSpinBox>
#include "SetButton.hpp"
#include "ViewerProperty.hpp"

//! \class ViewerNumber
//! \brief To display and modify integers
//!
//! \author [XR]MakingBot ( http://makingbot.fr )
//!
class ViewerNumber : public ViewerProperty
{
    Q_OBJECT

public:

    //! \brief Default constructor
    //!
    ViewerNumber(quint8 propid, bool readonly, int step = 1, int min = -0xFFFFFF, int max = 0xFFFFFF);

    //!
    //! Integer getter
    //!
    long getInteger()
    {
        return m_box.value();
    }

    //!
    //! Integer setter
    //!
    void setInterger(long integer)
    {
        m_box.setValue(integer);
        m_setButton.update();
    }

public slots:

    //! \brief To apply the choice of the user
    //!
    void apply();

    //! \brief Called when the user change the value
    //!
    void onValueChange(int value);

protected:

    //! \brief Box to display the value
    //!
    QSpinBox m_box;

    //! \brief Button to set the value
    //!
    SetButton m_setButton;

};

#endif // VIEWERNUMBER_HPP
