cmake_minimum_required(VERSION 3.10.2)

set (CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_TYPE "${CMAKE_CXX_FLAGS} - -std=c++11")

project (list)

add_executable(
    list
    list_node.cc
    list.cc
    main.cc
)