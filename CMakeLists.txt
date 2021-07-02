cmake_minimum_required(VERSION 3.19)
project(Bellman_Ford)

set(CMAKE_CXX_STANDARD 20)

add_executable(Bellman_Ford main.cpp graph.h edge.h vertex.h Tag.h)
