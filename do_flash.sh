#!/bin/bash

cd build
cmake -DCMAKE_TOOLCHAIN_FILE=cmake/arm-toolchain.cmake ..
make

cd ..
sudo bash scripts/flash_stlink.sh build/OpenFlightController_.bin

