#!/bin/bash

# Create a build directory
mkdir -p build
cd build

# Generate Makefiles using CMake
cmake ..

# Build the project using Make
make

# Run the main executable
#start=$(date +%s)
/usr/bin/time -f "Total execution time %e seconds" ./main
#end=$(date +%s)
#echo "Elapsed time: $(($(($end-$start))/1000000)) ms"
# Clean up (optional)
# make clean

