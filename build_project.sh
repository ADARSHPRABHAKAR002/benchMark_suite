#!/bin/bash

# Create a build directory
rm -r build
mkdir -p build
cd build

# Generate Makefiles using CMake
cmake ..

# Build the project using Make
make



# Run the main executable
#start=$(date +%s)
./main | tee ../BenchMarkScore/score.txt
#end=$(date +%s)
#echo "Elapsed time: $(($(($end-$start))/1000000)) ms"
#cd ..
#g++ -o main -I./include ./src/*.cpp -pg
#./main > output.txt 2>&1
#gprof main gmon.out > profiling_report.txt

#rm main output.txt gmon.out

# Clean up (optional)
make clean
