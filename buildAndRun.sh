#!/bin/bash

mkdir build
cd build
conan install -r conancenter ..
cmake ..
cmake --build .
./bin/getterReturnCopyVsConstRef
