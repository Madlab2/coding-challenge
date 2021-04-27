
#  Top Level CMake file for #HeyMErcedes Coding Challenge
#  Author: Patrick Madlindl
#  April 2021

cmake_minimum_required(VERSION 3.10)

project(CodingChallenge VERSION 0.0
        DESCRIPTION "#HeyMercedes Coding Challenge by Patrick Madlindl"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

include_directories(
    include
)

#will import testChallenge lib
add_subdirectory(test)


#library that contains the src for the entire project
add_library(CodingChallenge_lib STATIC
    src/Menu.cpp
)

add_executable(main 
    main.cpp
)

#the exec is linked to the src library
target_link_libraries(main
    CodingChallenge_lib
)
