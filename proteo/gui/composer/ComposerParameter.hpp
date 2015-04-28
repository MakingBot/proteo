#ifndef COMPOSERPARAMETER_HPP
#define COMPOSERPARAMETER_HPP
//!
//! \file ComposerParameter.hpp
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

#include <QDir>
#include <QList>
#include <QStringList>
#include <proteo/core/ScriptModule.hpp>

namespace proteo { namespace gui {

class Composer;

//! \class ComposerParameter
//! \brief Menu of the composer widget
//!
//! \author [XR]MakingBot ( http://makingbot.fr )
//!
class ComposerParameter : public QObject
{
    Q_OBJECT

public:

    //! \brief Size in pixel of the architecture scene
    //!
    static constexpr int CASE_PIXEL_SIZE        = 200;

    //! \brief Space beteween the case border and the object item border
    //!
    static constexpr int CASE_PIXEL_PADDING     = 50;

    //! \brief Define the diameter of the cross point in function of the case pixel size
    //! diameter = CASE_PIXEL_SIZE * CROSS_POINT_RATIO
    //!
    static constexpr float CROSS_POINT_RATIO    = 0.05f;

    //! \brief Default constructor
    //!
    ComposerParameter(Composer* composer);

    //! \brief Composer pointer getter
    //!
    inline Composer* composer();

    //! \brief Modules list getter
    //!
    inline std::list<core::ScriptModule>& modules();

    //! \brief Emit signal modulesModified
    //!
    inline void emitModulesModified();

    //! \brief Emit signal modulesModified
    //!
    inline void emitContainerModified();



    void refreshModuleList();


    void extractModules(const core::ScriptScope& scope);



    //! \brief
    //!
    void signalParamModification();

signals:

    //! \brief Emitted when the module list is modified
    //!
    void moduleListModified();


    //! \brief Emitted when the module list is modified
    //!
    void modulesModified();

    //! \brief Emitted when the structure of the container is modified
    //!
    void containerModified();

protected:

    //! \brief Global pointer on the composer
    //!
    Composer* m_composer;

    //! \brief Path where proteo modules are stored
    //!
    QString m_modulePath;

    //! \brief List of availables modules on the system
    //!
    std::list<core::ScriptModule> m_modules;

};


/* ============================================================================
 *
 * */
inline Composer* ComposerParameter::composer()
{
    return m_composer;
}

/* ============================================================================
 *
 * */
inline std::list<core::ScriptModule>& ComposerParameter::modules()
{
    return m_modules;
}

/* ============================================================================
 *
 * */
inline void ComposerParameter::emitModulesModified()
{
    emit modulesModified();
}

/* ============================================================================
 *
 * */
inline void ComposerParameter::emitContainerModified()
{
    emit containerModified();
}


} // gui
} // proteo
#endif // COMPOSERPARAMETER_HPP
