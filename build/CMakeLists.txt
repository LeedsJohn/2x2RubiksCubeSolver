cmake_minimum_required(VERSION 3.9.0)
project(2x2RubiksCubeSolver)

include_directories(include)
file(GLOB SOURCES "src/*.cpp

add_executable(Cube ${SOURCES})
