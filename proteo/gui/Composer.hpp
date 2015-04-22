#ifndef COMPOSER_HPP
#define COMPOSER_HPP
//!
//! \file Composer.hpp
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

#include "GuiObject.hpp"

namespace proteo { namespace gui {

class ComposerWidget;

//! \class
//!
class Composer : public GuiObject
{

public:
    
    //! \brief Default constructor
    //!
    Composer(std::string name);


    // ========================================================================
    // => Constantes

    //! \brief Role
    //!
    static const core::ObjRole ORole;

    //! \brief Tag
    //!
    static const core::Object::TagArray OTag;

    //! \brief Property vector
    //!
    static const std::vector<core::Property> Properties;

    // ========================================================================
    // => Object redefinition

    //! \brief FROM Object
    //!
    virtual core::ObjRole objRole() const;

    //! \brief FROM Object
    //!
    virtual const core::Object::TagArray& objTag() const;

    //! \brief FROM Object
    //!
    virtual const std::vector<core::Property>& properties() const;

protected:

    //! \brief Container that is composed
    //!
    boost::shared_ptr<core::Object> m_container;


    QSharedPointer<ComposerWidget> m_composer;

};


} // gui
} // proteo
#endif // COMPOSER_HPP

