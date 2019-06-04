cmake_minimum_required(VERSION 3.14.3)
project(random-numbers)
include_directories(include)
find_package(Qt5Widgets)
find_package(Qt5Charts)
add_executable(random-numbers 
        src/random-numbers.cc
        src/sampling.cc)
target_link_libraries(random-numbers Qt5::Widgets Qt5::Charts)
