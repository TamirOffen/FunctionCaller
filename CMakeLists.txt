cmake_minimum_required(VERSION 3.0.0)

project(ex3 LANGUAGES CXX)

set(MTM_FLAGS_DEBUG "-std=c++11 -pedantic-errors -Wall -Werror -g")

set(MTM_FLAGS_RELEASE "${MTM_FLAGS_DEBUG} -DNDEBUG")

set(CMAKE_CXX_FLAGS ${MTM_FLAGS_DEBUG})

set(CMAKE_CXX_STANDARD 11)

# link_directories() TODO: add in

add_executable(
    ex3
    Part_A/date_wrap.cpp
    Part_A/date.c  #need to link provided library instead

    Part_A/main.cpp
)

