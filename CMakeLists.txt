cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directory
include_directories(include)

# Add all .cpp files from the src directory
file(GLOB SOURCES "src/*.cpp")

# Add executable with profiling flags

add_executable(main ${SOURCES})
	
