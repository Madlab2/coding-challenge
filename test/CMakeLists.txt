
#  CMake file for Tests of #HeyMErcedes Coding Challenge
#  Author: Patrick Madlindl
#  April 2021


add_executable(runTest CodingChallenge_test.cpp)

target_link_libraries(runTest PUBLIC
    CodingChallenge_lib
    gtest 
    gtest_main
    pthread
)

add_test(runTest runTest)