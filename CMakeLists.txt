cmake_minimum_required(VERSION 3.0.0)

project(app LANGUAGES CXX)

set(MTM_FLAGS_DEBUG "-std=c++11 -pedantic-errors -Wall -Werror -g")

set(MTM_FLAGS_RELEASE "${MTM_FLAGS_DEBUG} -DNDEBUG")

set(CMAKE_CXX_FLAGS ${MTM_FLAGS_DEBUG})

set(CMAKE_CXX_STANDARD 11)

# link_directories() TODO: add in

add_executable(
    app
    partA/date_wrap.cpp
    partA/date.cpp  #need to link provided library instead

    partB/base_event.cpp
    partB/open_event.cpp
    partB/closed_event.cpp
    partB/event_container.cpp
    partB/festival.cpp
    # partB/main_B.cpp

    partC/schedule.cpp
    # partC/main_C.cpp

    # partA/main_A.cpp
    
    AdamTestB.cpp
    
)

