# Module name
SET(MODULE_NAME "gui")

# Headers
SET(PROJECT_HEADER_FILES
    #
    # === GUIOBJECT
    #
    proteo/gui/GuiObject.hpp
    #
    # === SCHEDULER
    #
    proteo/gui/Scheduler.hpp
    #
    # === SPY
    #
    proteo/gui/Spy.hpp
    proteo/gui/spy/SpyWidget.hpp
    proteo/gui/spy/SpyWidgetHeader.hpp    
    proteo/gui/spy/SpyWidgetBody.hpp        
    proteo/gui/spy/SetButton.hpp
    proteo/gui/spy/DoubleLabel.hpp
    proteo/gui/spy/ViewerProperty.hpp 
    proteo/gui/spy/ViewerBool.hpp  
    proteo/gui/spy/ViewerInteger.hpp    
    #
    # === SHELL
    #
    proteo/gui/Shell.hpp
    proteo/gui/shell/ShellWidget.hpp
    #
    # === COMPOSER
    #
    proteo/gui/Composer.hpp
    proteo/gui/composer/ComposerEditor.hpp
    proteo/gui/composer/ComposerGraphic.hpp
    proteo/gui/composer/ComposerMenu.hpp
    proteo/gui/composer/ComposerMenuItem.hpp
    proteo/gui/composer/ComposerMenuModules.hpp
    proteo/gui/composer/ComposerMenuObjects.hpp
    proteo/gui/composer/ComposerWidget.hpp
    proteo/gui/composer/ComposerView.hpp
    proteo/gui/composer/ComposerScene.hpp
    proteo/gui/composer/ComposerEditorHighlighter.hpp
    proteo/gui/composer/ComposerParameter.hpp
    proteo/gui/composer/ModuleCheckBox.hpp
    proteo/gui/composer/ItemObject.hpp
    proteo/gui/composer/ItemCrossPoint.hpp
    proteo/gui/composer/ItemConnection.hpp
    )

# Sources
SET(PROJECT_SOURCE_FILES
    #
    # === GUIOBJECT
    #
    proteo/gui/GuiObject.cpp
    #
    # === SCHEDULER
    #
    proteo/gui/Scheduler.cpp
    #
    # === SPY
    #
    proteo/gui/Spy.cpp
    proteo/gui/spy/SpyWidget.cpp
    proteo/gui/spy/SpyWidgetHeader.cpp    
    proteo/gui/spy/SpyWidgetBody.cpp
    proteo/gui/spy/ViewerBool.cpp
    proteo/gui/spy/ViewerInteger.cpp
    #
    # === SHELL
    #
    proteo/gui/Shell.cpp
    proteo/gui/shell/ShellWidget.cpp
    #
    # === COMPOSER
    #
    proteo/gui/Composer.cpp
    proteo/gui/composer/ComposerEditor.cpp
    proteo/gui/composer/ComposerGraphic.cpp
    proteo/gui/composer/ComposerMenu.cpp
    proteo/gui/composer/ComposerMenuItem.cpp
    proteo/gui/composer/ComposerMenuObjects.cpp
    proteo/gui/composer/ComposerMenuModules.cpp
    proteo/gui/composer/ComposerWidget.cpp
    proteo/gui/composer/ComposerView.cpp
    proteo/gui/composer/ComposerScene.cpp
    proteo/gui/composer/ComposerEditorHighlighter.cpp
    proteo/gui/composer/ComposerParameter.cpp
    proteo/gui/composer/ItemObject.cpp
    proteo/gui/composer/ItemCrossPoint.cpp
    proteo/gui/composer/ItemConnection.cpp
    #
    # === WRAPPER
    #
    wrapper/py/gui/wrapper_gui.cpp
    wrapper/py/gui/wrapper_gui_scheduler.cpp
    wrapper/py/gui/wrapper_gui_spy.cpp
    wrapper/py/gui/wrapper_gui_shell.cpp
    wrapper/py/gui/wrapper_gui_composer.cpp
    wrapper/py/gui/wrapper_gui_guiobject.cpp
    )

# Append ressources
QT5_ADD_RESOURCES( proteo/gui/rsc/ressources.qrc )

# Define the wrapper library that wraps our library
ADD_LIBRARY( ${MODULE_NAME} SHARED 
    ${PROJECT_SOURCE_FILES} 
    ${PROJECT_HEADER_FILES} )

TARGET_LINK_LIBRARIES( ${MODULE_NAME}
    ${Boost_LIBRARIES}
    ${PythonLibs_LIBRARIES}
    ${CMAKE_INSTALL_PREFIX}/py/proteo/core.so
    )

# Link Qt
QT5_USE_MODULES( ${MODULE_NAME} Gui Core Widgets )

# Do not prepend wrapper library name with lib
SET_TARGET_PROPERTIES( ${MODULE_NAME} PROPERTIES PREFIX "" OUTPUT_NAME ${MODULE_NAME} )

# Installation
INSTALL( TARGETS ${MODULE_NAME} DESTINATION py/proteo )
