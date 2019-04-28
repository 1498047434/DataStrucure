# cmake_minimum_required(VERSION <specify CMake version here>)
project(SelectionSort)

set(CMAKE_CXX_STANDARD 17)

add_executable(SelectionSort main.cpp SortTestHelper.h Student.h)