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

add_executable(Exam main.cpp vessel_t.h Reaction/Reaction.cpp Reaction/Reaction.h Reaction/Agent.cpp Reaction/Agent.h Reaction/ReactionComponent.cpp Reaction/ReactionComponent.h Reaction/Rule.cpp Reaction/Rule.h)
add_executable(Test_stochastic_simulation test_stochastic_simulation.cpp vessel_t.h Reaction/Reaction.cpp Reaction/Reaction.h Reaction/Agent.cpp Reaction/Agent.h Reaction/ReactionComponent.cpp Reaction/ReactionComponent.h Reaction/Rule.cpp Reaction/Rule.h)
target_link_libraries(Test_stochastic_simulation PRIVATE doctest::doctest)

enable_testing()
add_test(NAME Test_stochastic_simulation COMMAND Test_stochastic_simulation)