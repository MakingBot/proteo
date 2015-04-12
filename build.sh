#!/bin/bash

mkdir build
cd build

cmake -DCMAKE_INSTALL_PREFIX=/home/rodriguez/opt/proteo ..

make -j1
make install

