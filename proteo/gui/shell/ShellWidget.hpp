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
#include <QScrollArea>
#include <QListWidget>
#include <QStringListModel>

namespace proteo { namespace gui {


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

    void onNewCmd();

    void onItemClick(QListWidgetItem * item);


protected:

    QTextEdit m_resultArea;

    //! \brief Line in which user can enter python commands
    //!
    QLineEdit m_cmdLine;

    //! \brief
    //!
    QStringList m_histo;

    
    QScrollArea m_histoArea;

    QListWidget m_histoView;


    QStringListModel m_histoModel;

};


} // gui
} // proteo
#endif // SHELLWIDGET_HPP
