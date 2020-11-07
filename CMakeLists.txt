cmake_minimum_required(VERSION 3.6)
project(PDP-11)

add_executable(PDP-11 src/main.cpp src/Emulator.cpp src/Assembler.cpp)
include_directories(include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include))
