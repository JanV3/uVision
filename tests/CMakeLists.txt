cmake_minimum_required(VERSION 3.8)
project(uVisionTests)
find_package(Threads)
add_executable(uVisionTests tests.cpp)
target_link_libraries(uVisionTests Threads::Threads)

