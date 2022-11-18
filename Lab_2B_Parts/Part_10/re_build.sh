#!/bin/bash

# Check if `build` directory exists
if [[ -d build ]] ; then
    rm -r build
    echo "Removed build directory"
fi

# Compile the program
mkdir build && cd build && cmake ../ && make -j4

# Check if old binary exists
if [[ -f /mnt/d/higher_lower_new.uf2 ]] ; then
    rm /mnt/d/higher_lower_new.uf2
fi

# Copy the new executable into D
cp pio_ws2812.uf2 /mnt/d/higher_lower_new.uf2
