#ifndef VIEWERBOOL_HPP
#define VIEWERBOOL_HPP
//!
//! \file ViewerBool.hpp
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

#include <QComboBox>
#include "SetButton.hpp"
#include "ViewerProperty.hpp"

namespace proteo { namespace gui {

//! \class ViewerBool
//! \brief To display and modify real
//!
//! \author [XR]MakingBot ( http://makingbot.fr )
//!
class ViewerBool : public ViewerProperty
{
    Q_OBJECT

public:

    //! \brief Index of true in the combobox
    //!
    static const int TrueIndex;

    //! \brief Index of false in the combobox
    //!
    static const int FalseIndex;

    //! \brief Default constructor
    //!
    ViewerBool(quint8 propid, bool readonly);

    //! \brief 
    //!
    virtual void setValueFromVariant(const proteo::core::Variant& variant);

    //! \brief Integer getter
    //!
    bool getBool()
    {
        switch( m_box.currentIndex() )
        {
            case TrueIndex:
                return true;
                break;

            case FalseIndex:
                return false;
                break;
        }
    }

    //! \brief Integer setter
    //!
    void setBool(bool b)
    {
        if(b)
        {
            m_box.setCurrentIndex(TrueIndex);
        }
        else
        {
            m_box.setCurrentIndex(FalseIndex);
        }
        m_setButton.update();
    }

public slots:

    //! \brief To apply the choice of the user
    //!
    void apply();

    //! \brief Called when the user change the value
    //!
    void onValueChange(double value);

protected:

    //! \brief Box to display the value
    //!
    QComboBox m_box;

    //! \brief Button to set the value
    //!
    SetButton m_setButton;

};

} // gui
} // proteo
#endif // VIEWERBOOL_HPP
