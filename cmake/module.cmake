# Append directory
INCLUDE_DIRECTORIES(.)

# Module name
SET(MODULE_NAME "proteo")

# Headers
SET(PROJECT_HEADER_FILES
    proteo/core/Type.hpp
    proteo/core/Object.hpp
    proteo/core/Variant.hpp
    proteo/core/Property.hpp


    proteo/gui/Gui.hpp
    proteo/gui/Scheduler.hpp
    
    proteo/gui/Spy.hpp
    proteo/gui/spy/SpyWidget.hpp
    proteo/gui/spy/SpyWidgetHeader.hpp    
    proteo/gui/spy/SpyWidgetBody.hpp    
    
    proteo/gui/spy/SetButton.hpp
    proteo/gui/spy/DoubleLabel.hpp
    proteo/gui/spy/ViewerProperty.hpp    
    proteo/gui/spy/ViewerInteger.hpp    


    proteo/gui/Shell.hpp
    proteo/gui/shell/ShellWidget.hpp

    proteo/model/SensorDistance.hpp
    
    )

# Sources
SET(PROJECT_SOURCE_FILES
    proteo/core/Object.cpp

    proteo/gui/Scheduler.cpp

    proteo/gui/Spy.cpp
    proteo/gui/spy/SpyWidget.cpp
    proteo/gui/spy/SpyWidgetHeader.cpp    
    proteo/gui/spy/SpyWidgetBody.cpp

    proteo/gui/spy/ViewerInteger.cpp

    proteo/gui/Shell.cpp
    proteo/gui/shell/ShellWidget.cpp


    proteo/model/SensorDistance.cpp
    
    wrapper/py/wrapper_gui.cpp
    wrapper/py/wrapper_core.cpp
    wrapper/py/wrapper_model.cpp
    wrapper/py/wrapper_module.cpp
    )

# Define the wrapper library that wraps our library
ADD_LIBRARY( ${MODULE_NAME} SHARED 
    ${PROJECT_SOURCE_FILES} 
    ${PROJECT_HEADER_FILES} )
TARGET_LINK_LIBRARIES( ${MODULE_NAME} ${Boost_LIBRARIES} ${PythonLibs_LIBRARIES} )

# Link Qt
QT5_USE_MODULES( ${MODULE_NAME} Gui Core Widgets )

# Do not prepend wrapper library name with lib
SET_TARGET_PROPERTIES( ${MODULE_NAME} PROPERTIES PREFIX "" OUTPUT_NAME ${MODULE_NAME} )

# Installation
INSTALL( TARGETS ${MODULE_NAME} DESTINATION py )
