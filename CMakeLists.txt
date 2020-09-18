cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(test)

file(GLOB_RECURSE TESTFILES ./test/*.cpp)
add_executable(engine_test ${TESTFILES})