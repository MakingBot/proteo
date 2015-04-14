#ifndef SHELLWIDGET_HPP
#define SHELLWIDGET_HPP
//!
//! \file ShellWidget.hpp
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

#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QSettings>
#include <QScrollArea>
#include <QListWidget>
#include <QStringListModel>

namespace proteo { namespace gui {

//! \class Widget for the shell object
//!
//! \author [XR]MakingBot ( http://makingbot.fr )
//!
class ShellWidget : public QWidget
{
    Q_OBJECT

public:

    //! \brief Default constructor
    //! \param parent
    //!
    explicit ShellWidget(QWidget *parent = 0);

signals:

public slots:

    //! \brief 
    //!
    void onNewCmd();

    //! \brief 
    //!
    void onItemClick(QListWidgetItem * item);

protected:

    //! \brief Settings manager 
    //!
    QSettings m_settings;

    //! \brief Historic cmd list
    //!
    QStringList m_histo;

    //! \brief Text area where result are displayed
    //!
    QTextEdit m_resultArea;

    //! \brief Line in which user can enter python commands
    //!
    QLineEdit m_cmdLine;

    //! \brief
    //!
    QScrollArea m_histoArea;

    //! \brief
    //!
    QListWidget m_histoView;

    //! \brief
    //!
    QStringListModel m_histoModel;

};

} // gui
} // proteo
#endif // SHELLWIDGET_HPP
