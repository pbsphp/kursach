cmake_minimum_required(VERSION 2.8)

project(kursach)

set(SOURCE main.cpp)

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-O2")
endif()

add_executable(kursach ${SOURCE})
