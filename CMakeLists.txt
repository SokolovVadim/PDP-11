cmake_minimum_required(VERSION 3.6)
project(PDP-11)

add_executable(PDP-11 source/main.cpp source/Emulator.cpp source/Assembler.cpp)
include_directories(include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include))
