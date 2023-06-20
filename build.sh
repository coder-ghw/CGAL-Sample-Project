#!/bin/bash

rm -rf build/
mkdir build/
cd build/

cmake -DCMAKE_BUILD_TYPE=Debug \
      -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
      .. || exit 1

make -j8 || exit 1

./cgalTest-hello

