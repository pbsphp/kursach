cmake_minimum_required(VERSION 2.8)

project(kursach)

set(SOURCE main.cpp)

file(GLOB_RECURSE SRC_FILES src/*)

include_directories(./include .)



if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "-O2 -pedantic -Wall --std=c++11")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "-O2 -pedantic -Wall --std=c++11")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


add_executable(kursach ${SOURCE} ${SRC_FILES})
