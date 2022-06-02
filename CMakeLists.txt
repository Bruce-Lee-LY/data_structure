# Copyright 2022. All Rights Reserved.
# Author: Bruce-Lee-LY
# Date: 22:31:56 on Tue, May 24, 2022
#
# Description: cmake for data structure

cmake_minimum_required (VERSION 3.8)

project (data_structure LANGUAGES CXX)

set (CMAKE_VERBOSE_MAKEFILE ${VERBOSE_MAKEFILE})

set (CMAKE_CXX_FLAGS "-std=c++11")
set (CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -g2 -ggdb")
set (CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3")

set (CMAKE_EXE_LINKER_FLAGS "-Wl,--as-needed")

add_compile_options (
    -Wall
    -Werror
    -Wextra
    -Wswitch-default
    -Wfloat-equal
    -Wshadow
    -Wcast-qual
)

include_directories (
    ${PROJECT_SOURCE_DIR}/src/common
    ${PROJECT_SOURCE_DIR}/src/ring_queue
    ${PROJECT_SOURCE_DIR}/src/ds_stack
    ${PROJECT_SOURCE_DIR}/src/sequence_list
    ${PROJECT_SOURCE_DIR}/src/single_list
    ${PROJECT_SOURCE_DIR}/src/hash_map_list
    ${PROJECT_SOURCE_DIR}/src/skip_list
    ${PROJECT_SOURCE_DIR}/src/binary_tree_array
    ${PROJECT_SOURCE_DIR}/src/binary_tree_list
    ${PROJECT_SOURCE_DIR}/src/AVL_tree
    ${PROJECT_SOURCE_DIR}/src/red_black_tree
    ${PROJECT_SOURCE_DIR}/src/binary_heap
    ${PROJECT_SOURCE_DIR}/src/graph_adjacency_matrix
)

add_executable (ring_queue ${PROJECT_SOURCE_DIR}/src/ring_queue/demo.cpp)
add_executable (ds_stack ${PROJECT_SOURCE_DIR}/src/ds_stack/demo.cpp)
add_executable (sequence_list ${PROJECT_SOURCE_DIR}/src/sequence_list/demo.cpp)
add_executable (single_list ${PROJECT_SOURCE_DIR}/src/single_list/demo.cpp)
add_executable (hash_map_list ${PROJECT_SOURCE_DIR}/src/hash_map_list/demo.cpp)
add_executable (skip_list ${PROJECT_SOURCE_DIR}/src/skip_list/demo.cpp)
add_executable (binary_tree_array ${PROJECT_SOURCE_DIR}/src/binary_tree_array/demo.cpp)
add_executable (binary_tree_list ${PROJECT_SOURCE_DIR}/src/binary_tree_list/demo.cpp)
add_executable (AVL_tree ${PROJECT_SOURCE_DIR}/src/AVL_tree/demo.cpp)
add_executable (red_black_tree ${PROJECT_SOURCE_DIR}/src/red_black_tree/demo.cpp)
add_executable (binary_heap ${PROJECT_SOURCE_DIR}/src/binary_heap/demo.cpp)
add_executable (graph_adjacency_matrix ${PROJECT_SOURCE_DIR}/src/graph_adjacency_matrix/demo.cpp)

install (TARGETS ring_queue ds_stack sequence_list single_list hash_map_list skip_list binary_tree_array
    binary_tree_list AVL_tree red_black_tree binary_heap graph_adjacency_matrix
    RUNTIME DESTINATION sample
)
