
#  Top Level CMake file for #HeyMErcedes Coding Challenge
#  Author: Patrick Madlindl
#  April 2021

cmake_minimum_required(VERSION 3.11)

project(CodingChallenge VERSION 0.1.0
        DESCRIPTION "#HeyMercedes Coding Challenge by Patrick Madlindl"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

##############
# From gtest documentation: fetches GoogleTest and makes it available fot this project
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.10.0 
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
##############


include_directories(
    include
)

#will import testChallenge lib
add_subdirectory(test)


add_library(intent_lib INTERFACE)

target_include_directories(intent_lib INTERFACE
    include
)

#library that contains the src for the entire project
add_library(CodingChallenge_lib STATIC
    src/IntentMenu.cpp
    src/IntentEstimator.cpp
)


target_link_libraries(CodingChallenge_lib
    intent_lib
)

add_executable(main 
    main.cpp
)

#the exec is linked to the src library
target_link_libraries(main
    CodingChallenge_lib
)
