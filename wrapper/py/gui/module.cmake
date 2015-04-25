# Module name
SET(MODULE_NAME "gui")

# Headers
SET(PROJECT_HEADER_FILES

    proteo/gui/Scheduler.hpp
    
    proteo/gui/Spy.hpp
    proteo/gui/spy/SpyWidget.hpp
    proteo/gui/spy/SpyWidgetHeader.hpp    
    proteo/gui/spy/SpyWidgetBody.hpp    
    
    proteo/gui/spy/SetButton.hpp
    proteo/gui/spy/DoubleLabel.hpp
    proteo/gui/spy/ViewerProperty.hpp 
    proteo/gui/spy/ViewerBool.hpp  
    proteo/gui/spy/ViewerInteger.hpp    

    proteo/gui/Shell.hpp
    proteo/gui/shell/ShellWidget.hpp

    proteo/gui/Composer.hpp
    proteo/gui/composer/ComposerWidget.hpp
    proteo/gui/composer/ComposerMenu.hpp
    proteo/gui/composer/ComposerMenuItem.hpp

    proteo/gui/composer/ComposerMenuObjects.hpp
    proteo/gui/composer/ComposerMenuModules.hpp
    proteo/gui/composer/ComposerView.hpp
    proteo/gui/composer/ComposerScene.hpp
    proteo/gui/composer/ComposerEditor.hpp
    proteo/gui/composer/ScriptModule.hpp
    proteo/gui/composer/ComposerParameter.hpp

    proteo/gui/composer/ModuleCheckBox.hpp

    

    proteo/gui/GuiObject.hpp

    )

# Sources
SET(PROJECT_SOURCE_FILES

    proteo/gui/Scheduler.cpp

    proteo/gui/Spy.cpp
    proteo/gui/spy/SpyWidget.cpp
    proteo/gui/spy/SpyWidgetHeader.cpp    
    proteo/gui/spy/SpyWidgetBody.cpp

    proteo/gui/spy/ViewerBool.cpp
    proteo/gui/spy/ViewerInteger.cpp

    proteo/gui/Shell.cpp
    proteo/gui/shell/ShellWidget.cpp

    proteo/gui/Composer.cpp
    proteo/gui/composer/ComposerWidget.cpp
    proteo/gui/composer/ComposerMenu.cpp
    proteo/gui/composer/ComposerMenuItem.cpp

    proteo/gui/composer/ComposerMenuObjects.cpp
    proteo/gui/composer/ComposerMenuModules.cpp
    proteo/gui/composer/ComposerView.cpp
    proteo/gui/composer/ComposerScene.cpp
    proteo/gui/composer/ComposerEditor.cpp
    proteo/gui/composer/ScriptModule.cpp
    proteo/gui/composer/ComposerParameter.cpp

    proteo/gui/GuiObject.cpp

    wrapper/py/gui/wrapper_gui.cpp
    wrapper/py/gui/wrapper_gui_scheduler.cpp
    wrapper/py/gui/wrapper_gui_spy.cpp
    wrapper/py/gui/wrapper_gui_shell.cpp
    wrapper/py/gui/wrapper_gui_composer.cpp
    wrapper/py/gui/wrapper_gui_guiobject.cpp


    )

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
