cmake_minimum_required(VERSION 3.13)

project(libunr)

set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

add_subdirectory(external)
add_subdirectory(src)
add_subdirectory(tests)

