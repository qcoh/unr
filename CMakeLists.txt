cmake_minimum_required(VERSION 3.13)

project(libunr)

include(CTest)

add_subdirectory(external)
add_subdirectory(src)
add_subdirectory(tests)

