cmake_minimum_required(VERSION 3.28)
project(raygun)

set(CMAKE_CXX_STANDARD 20)
set(SDL2_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/vendor/SDL2")
set(SDL2_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/vendor/SDL2/lib/x64/SDL2.lib;${CMAKE_CURRENT_LIST_DIR}/vendor/SDL2/lib/x64/SDL2main.lib")
string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)

find_package(SDL2 REQUIRED)

add_executable(raygun main.cpp
        engine/Application.cpp
        engine/Application.h)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
include_directories(${SDL2_INCLUDE_DIRS})
