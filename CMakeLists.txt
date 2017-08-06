cmake_minimum_required(VERSION 3.8)
project(uVision)

set( CMAKE_CXX_STANDARD 14 )

set(UVISION_INCLUDE_DIRS uvision)
include_directories(${UVISION_INCLUDE_DIRS})

add_subdirectory(tests)
