# Module name
SET(MODULE_NAME "model")

# Headers
SET(PROJECT_HEADER_FILES

    proteo/model/Joint.hpp
    proteo/model/Robot.hpp
    proteo/model/SensorDistance.hpp

    )

# Sources
SET(PROJECT_SOURCE_FILES

    proteo/model/Joint.cpp
    proteo/model/Robot.cpp
    proteo/model/SensorDistance.cpp

    wrapper/py/model/wrapper_model.cpp
    wrapper/py/model/wrapper_model_joint.cpp
    wrapper/py/model/wrapper_model_robot.cpp
    wrapper/py/model/wrapper_model_sensordistance.cpp

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

# Do not prepend wrapper library name with lib
SET_TARGET_PROPERTIES( ${MODULE_NAME} PROPERTIES PREFIX "" OUTPUT_NAME ${MODULE_NAME} )

# Installation
INSTALL( TARGETS ${MODULE_NAME} DESTINATION py/proteo )
