#ifndef SPYWIDGET_HPP
#define SPYWIDGET_HPP

//!
//! \file SpyWidget.hpp
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

#include "SpyWidgetBody.hpp"
#include "SpyWidgetHeader.hpp"
// #include <SpyWidgetFooter.hpp>

namespace proteo { namespace gui {

class Spy;

//!
//! Widget that display information from the block
//!
//! \author [XR]MakingBot ( http://makingbot.fr )
//!
class SpyWidget : public QWidget
{
    Q_OBJECT

public:
    //!
    //! Default constructor
    //!
    explicit SpyWidget(Spy* spy);

public slots:
    
    //! \brief When the spied change
    //!
    void onSpiedObjChange();

protected:
    
    //! \brief Spy object 
    //!
    Spy* m_spy;

    //! \brief Information header
    //!
    SpyWidgetHeader m_header;

    //! Information body
    SpyWidgetBody   m_body;

    // //! Information footer
    // SpyWidgetFooter _footer;

    //! FROM QWidget
    virtual void closeEvent(QCloseEvent* event);
};

} // gui
} // proteo
#endif // SPYWIDGET_HPP
