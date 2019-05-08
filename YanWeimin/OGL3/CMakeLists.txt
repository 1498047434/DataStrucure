cmake_minimum_required(VERSION 3.13)
project(OGL3)

set(CMAKE_CXX_STANDARD 14)

link_directories("G:\\c++\\mingw-w64\\x86_64-7.3.0-posix-seh-rt_v5-rev0\\mingw64\\x86_64-w64-mingw32\\lib")
#link_directories("G:\c++\mingw-w64\x86_64-7.3.0-posix-seh-rt_v5-rev0\mingw64\lib")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -D FREEGLUT_STATIC")

add_executable(OGL3 main.cpp)
target_link_libraries(OGL3 freeglut_static opengl32 winmm gdi32 glu32.lib)


