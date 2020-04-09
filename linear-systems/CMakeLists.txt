cmake_minimum_required(VERSION 3.10)

project(SolutionOfEquations)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(lib/utils)
add_subdirectory(lib/model)
add_subdirectory(lib/weave)
add_subdirectory(src)