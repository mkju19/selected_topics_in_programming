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

add_executable(Exam main.cpp)
add_executable(Test_func Test_doctest.cpp FunctionToTest.h)
target_link_libraries(Test_func PRIVATE doctest::doctest)

enable_testing()
add_test(NAME Test_func COMMAND Test_func)