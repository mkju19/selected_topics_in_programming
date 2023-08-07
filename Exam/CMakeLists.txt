cmake_minimum_required(VERSION 3.24)
project(Exam)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(BUILD_SHARED_LIBS OFF) # Stick with statically linked libraries

include(doctest.cmake)

add_subdirectory(Include)

add_executable(Main main.cpp)
add_executable(Test_stochastic_simulation test_stochastic_simulation.cpp)

TARGET_LINK_LIBRARIES(Main PRIVATE Include)
TARGET_LINK_LIBRARIES(Test_stochastic_simulation PRIVATE Include)
TARGET_LINK_LIBRARIES(Test_stochastic_simulation PRIVATE doctest::doctest)

enable_testing()
add_test(NAME Test_stochastic_simulation COMMAND Test_stochastic_simulation)