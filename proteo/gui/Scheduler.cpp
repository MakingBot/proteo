//!
//! \file Scheduler.cpp
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

#include <QPainter>
#include <proteo/gui/Scheduler.hpp>

using namespace proteo::gui;
using namespace proteo::core;

/* ============================================================================
 *
 * */
class Style_tweaks : public QProxyStyle
{
    public:
    void drawPrimitive(PrimitiveElement element, const QStyleOption *option,
                       QPainter *painter, const QWidget *widget) const
    {
        /* do not draw focus rectangles - this permits modern styling */
        if (element == QStyle::PE_FrameFocusRect)
            return;

        QProxyStyle::drawPrimitive(element, option, painter, widget);
    }
};

/* ============================================================================
 *
 * */
Scheduler::Scheduler()
   // : core::Object(name)std::string name
{
    // Create the QApplication
    int argc = 1;
    char * argv[1] = { "proteo" } ;
    m_app = QSharedPointer<QApplication>( new QApplication(argc, argv) );

    // Set tweaks style
    m_app->setStyle(new Style_tweaks);

    // Define application attributes
    QApplication::setApplicationName("proteo");
    QApplication::setApplicationVersion("1.0");

    QApplication::setOrganizationName("MakingBot");
    QApplication::setOrganizationDomain("makingbot.com");
}





/* ============================================================================
 *
 * */
// const ObjRole Scheduler::ORole = Rgui;

/* ============================================================================
 *
 * */
// const Object::TagArray Scheduler::OTag = { 'S', 'H', 'L', 'L' };

/* ============================================================================
 *
 * */
// const std::vector<Property> Scheduler::Properties = {
//    // Property()
// };

/* ============================================================================
 *
 * */
// ObjRole Scheduler::objRole() const
// {
//     return ORole;
// }

/* ============================================================================
 *
 * */
// const Object::TagArray& Scheduler::objTag() const
// {
//     return OTag;
// }

/* ============================================================================
 *
 * */
// const std::vector<Property>& Scheduler::properties() const
// {
//     return Properties;
// }





/* ============================================================================
 *
 * */
void Scheduler::start()
{
    m_app->exec();
}

/* ============================================================================
 *
 * */
// void Scheduler::start(int sec)
// {
//     m_app->exec();   
// }



