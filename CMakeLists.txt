cmake_minimum_required(VERSION 3.16)
project(simple_engine)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include)

# Add executable
# add_executable(sql-engine
#     src/main.cpp
#     src/core/parser.cpp
# )


# Automatically gather all .cpp files in the src directory
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Add executable
add_executable(sql-engine ${SOURCES})