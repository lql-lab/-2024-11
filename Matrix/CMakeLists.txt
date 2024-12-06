CMAKE_MINIMUM_REQUIRED(VERSION 3.15)

project(Matrix)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(
    /home/lql/Desktop/C++/Matrix/include
    /usr/include
)

add_executable(Matrix main.cpp)