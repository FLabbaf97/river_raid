cmake_minimum_required(VERSION 3.6)
project(river_raid_logic)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Item.cpp Item.h)
add_executable(river_raid_logic ${SOURCE_FILES})