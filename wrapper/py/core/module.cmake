# Module name
SET(MODULE_NAME "core")

# Headers
SET(PROJECT_HEADER_FILES

    proteo/core/Type.hpp
    proteo/core/Object.hpp
    proteo/core/Variant.hpp
    proteo/core/Property.hpp
    proteo/core/Container.hpp
    proteo/core/SharedCout.hpp

    )

# Sources
SET(PROJECT_SOURCE_FILES

    proteo/core/Type.cpp
    proteo/core/Object.cpp
    proteo/core/Container.cpp
    proteo/core/SharedCout.cpp

    wrapper/py/core/wrapper_core.cpp
    wrapper/py/core/wrapper_core_object.cpp
    wrapper/py/core/wrapper_core_objsize.cpp
    wrapper/py/core/wrapper_core_objposition.cpp
    wrapper/py/core/wrapper_core_container.cpp

    )

# Define the wrapper library that wraps our library
ADD_LIBRARY( ${MODULE_NAME} SHARED 
    ${PROJECT_SOURCE_FILES} 
    ${PROJECT_HEADER_FILES} )
TARGET_LINK_LIBRARIES( ${MODULE_NAME} ${Boost_LIBRARIES} ${PythonLibs_LIBRARIES} )

# Do not prepend wrapper library name with lib
SET_TARGET_PROPERTIES( ${MODULE_NAME} PROPERTIES PREFIX "" OUTPUT_NAME ${MODULE_NAME} )

# Installation
INSTALL( TARGETS ${MODULE_NAME} DESTINATION py/proteo )
