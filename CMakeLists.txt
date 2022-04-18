cmake_minimum_required(VERSION 3.0.0)

project(UET2022)

include_directories(include)

##################################
find_package(SDL2 REQUIRED)
include_directories(main ${SDL2_INCLUDE_DIRS})

# set(SOURCES src/a.cpp src/b.cpp)

file(GLOB SOURCES "source/*.cpp")

add_executable(main ${SOURCES})
target_link_libraries(main ${SDL2_LIBRARIES})