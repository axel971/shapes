CMAKE_MINIMUM_REQUIRED(VERSION 2.8.8)

PROJECT(rootsProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)


set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/output/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})


add_subdirectory(./modules/core/shape2D)

