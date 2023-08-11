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
include(benchmark.cmake)

# Graphviz paths
set(GRAPHVIZ_INCLUDE_DIR "C:/Program Files/Graphviz/include")
set(GRAPHVIZ_LIBRARY_DIR "C:/Program Files/Graphviz/lib")

# Add Graphviz directories
include_directories(${GRAPHVIZ_INCLUDE_DIR})
link_directories(${GRAPHVIZ_LIBRARY_DIR})


add_subdirectory(Include)
add_subdirectory(Examples)

add_executable(Main main.cpp Observers.h)
add_executable(Benchmark benchmark.cpp Observers.h)
add_executable(Test_stochastic_simulation test_stochastic_simulation.cpp)

target_link_libraries(Examples PRIVATE Include)
target_link_libraries(Main PRIVATE Include Examples cgraph gvc)
target_link_libraries(Benchmark PRIVATE Include Examples benchmark::benchmark)
TARGET_LINK_LIBRARIES(Test_stochastic_simulation PRIVATE Include Observers doctest::doctest)

enable_testing()
add_test(NAME Test_stochastic_simulation COMMAND Test_stochastic_simulation)