## \#HeyMercedes Coding Challenge

This is the solution proposed by Patrick Madlindl to the #HeyMercedes Coding Challenge.

See instructions below for building and starting the appplication.

When you are in the programme, type `strg+c` or `èxit` to leave.

#### Requirements
- CMake
- GoogleTest

### Instructions:

#### I) build the project:
    1. $ cd build
    2. $ cmake .. && make

#### II) run the tests:
    1. $ cd build
    2. $ ctest -VV

#### III) run application
    1. $ cd build
    2. $ ./main

By default, the tests are built with the project. 

To skip building them, comment out `enable_testing()` in the project's CMakeLists.txt.