cmake_minimum_required(VERSION 2.8)

project(kursach)

set(SOURCE main.cpp)

file(GLOB_RECURSE SRC_FILES src/*)

include_directories(include)


if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-O2 -pedantic -Wall")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


add_executable(kursach ${SOURCE} ${SRC_FILES})
