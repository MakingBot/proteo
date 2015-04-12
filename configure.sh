#!/bin/bash

# =========================
# === Define Parameters ===
# =========================

RELEASE=true

CMAKE_VERSION="VERSION 2.8"

BOOST_VERSION="1.55.0"

INSTALL_PATH="$HOME/opt/proteo"

THREAD_NUMBER=1

USE_QT=false

QT_CMAKE_PATH=""

# =====================
# === HELP FUNCTION ===
# =====================

function fct_help {
    echo "    -d | --debug                          Debug build"
    echo "    --qt [qt cmake widget path]           Enable qt gui build"
    exit 0
}

# =======================
# === Parse Arguments ===
# =======================
while [ "$1" != "" ]; do
    case "$1" in
        -h|--help)
            fct_help
            shift ;;
        -d|--debug)
            RELEASE=false
            shift ;;
        --qt)
            shift
            USE_QT=true
            QT_CMAKE_PATH=$1
            shift ;;    
        *)
            # unknown option
            echo "Unknown option !" ; exit 1 ;;
    esac
done

# ========================
# === Write CMakeLists ===
# ========================

echo "-- create CMakeLists.txt"

# Minimum cmake version
echo 'CMAKE_MINIMUM_REQUIRED('$CMAKE_VERSION')'             >  CMakeLists.txt
echo ''                                                     >> CMakeLists.txt

# Release / Debug
if $RELEASE ; then
    echo '-- release'
    echo 'SET(CMAKE_BUILD_TYPE "RELEASE")'                  >> CMakeLists.txt
else
    echo '-- debug'
    echo 'SET(CMAKE_BUILD_TYPE "DEBUG")'                    >> CMakeLists.txt
fi
echo ''                                                     >> CMakeLists.txt

# Python
echo 'SET(Python_ADDITIONAL_VERSIONS 2.7)'                  >> CMakeLists.txt
echo 'FIND_PACKAGE( PythonLibs 2.7 REQUIRED )'              >> CMakeLists.txt
echo 'INCLUDE_DIRECTORIES( ${PYTHON_INCLUDE_DIRS} )'        >> CMakeLists.txt
echo ''                                                     >> CMakeLists.txt

# Boost
echo 'FIND_PACKAGE( Boost 1.55.0 COMPONENTS'                >> CMakeLists.txt
echo '   thread'                                            >> CMakeLists.txt
echo '   python'                                            >> CMakeLists.txt
echo '   REQUIRED )'                                        >> CMakeLists.txt
echo 'INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )'          >> CMakeLists.txt
echo ''                                                     >> CMakeLists.txt

# Compile flag for C++11
echo 'LIST(APPEND CMAKE_CXX_FLAGS "-std=c++0x -Wno-write-strings")' >> CMakeLists.txt

if $USE_QT ; then
    echo "-- use qt (cmake: '$QT_CMAKE_PATH')"

    # Search for Qt config
    echo 'SET(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} '$QT_CMAKE_PATH' )' >> CMakeLists.txt

    # Qt configuration
    echo 'SET(CMAKE_INCLUDE_CURRENT_DIR ON)'                >> CMakeLists.txt
    echo 'SET(CMAKE_AUTOMOC ON)'                            >> CMakeLists.txt
    echo 'FIND_PACKAGE(Qt5Widgets REQUIRED)'                >> CMakeLists.txt
    echo ''                                                 >> CMakeLists.txt
fi

# Append build cmake script
echo 'INCLUDE(cmake/module.cmake)'                          >> CMakeLists.txt
echo ''                                                     >> CMakeLists.txt

# ===================
# === Write build ===
# ===================

echo "-- create build.sh"

# Tag
echo '#!/bin/bash'                                          >  build.sh
echo ''                                                     >> build.sh

# Create build directory
echo 'mkdir build'                                          >> build.sh
echo 'cd build'                                             >> build.sh
echo ''                                                     >> build.sh

# Execute cmake
echo 'cmake -DCMAKE_INSTALL_PREFIX='$INSTALL_PATH' ..'      >> build.sh
echo ''                                                     >> build.sh

# Make and install
echo 'make -j'$THREAD_NUMBER                                >> build.sh
echo 'make install'                                         >> build.sh
echo ''                                                     >> build.sh

# ===================
# === Write clean ===
# ===================

echo "-- create clean.sh"

# Tag
echo '#!/bin/bash'                                          >  clean.sh
echo 'rm -r build'                                          >> clean.sh
echo ''                                                     >> clean.sh

# ========================
# === Export variables ===
# ========================

echo "-- create sysetup.sh"

echo "echo 'export PYTHONPATH=$PYTHONPATH:'"$INSTALL_PATH"/py >> ~/.bashrc" > sysetup.sh

