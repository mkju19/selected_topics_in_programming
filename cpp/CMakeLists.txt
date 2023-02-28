cmake_minimum_required(VERSION 3.23)
project(cpp)

set(CMAKE_CXX_STANDARD 20)

#add_executable(cpp main.cpp)
add_executable(session1 session1.cpp)
add_executable(session2 Session2/session2.cpp Session2/sizes.h Session2/sizes.cpp Session2/endian.cpp Session2/endian.h Session2/pointers.cpp Session2/pointers.h Session2/randomNumbers.cpp Session2/randomNumbers.h)
add_executable(session3 Session3/session3.cpp)