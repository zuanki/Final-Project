cmake_minimum_required(VERSION 3.0.0)

project(UET2022)

include_directories(include)

# set(SOURCES src/a.cpp src/b.cpp)

file(GLOB SOURCES "source/*.cpp")

add_executable(main ${SOURCES})