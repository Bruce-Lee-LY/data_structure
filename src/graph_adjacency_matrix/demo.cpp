// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 22:53:18 on Tue, May 24, 2022
//
// Description: test graph adjacency matrix

#include "coordinate.h"
#include "graph_adjacency_matrix.h"

void test_min_span_tree() {
    graph_adjacency_matrix<size_t, char> gam(6);

    for (size_t i = 0; i < 6; ++i) {
        gam.add_vertex(graph_vertex<char>('A' + i));
    }

    gam.set_undirected_matrix_val(0, 1, 6);
    gam.set_undirected_matrix_val(0, 4, 5);
    gam.set_undirected_matrix_val(0, 5, 1);
    gam.set_undirected_matrix_val(1, 2, 3);
    gam.set_undirected_matrix_val(1, 5, 2);
    gam.set_undirected_matrix_val(2, 3, 7);
    gam.set_undirected_matrix_val(2, 5, 8);
    gam.set_undirected_matrix_val(3, 4, 2);
    gam.set_undirected_matrix_val(3, 5, 4);
    gam.set_undirected_matrix_val(4, 5, 9);

    std::cout << "------ prim_min_span_tree ------" << std::endl;
    gam.prim_min_span_tree(0);
    gam.reset_edge();
    std::cout << "------ kruskal_min_span_tree ------" << std::endl;
    gam.kruskal_min_span_tree();
}

void test_coordinate() {
    graph_adjacency_matrix<size_t, coordinate> gam(8);

    for (size_t i = 0; i < 8; ++i) {
        gam.add_vertex(graph_vertex<coordinate>(coordinate(i, i * i)));
    }

    gam.set_undirected_matrix_val(0, 1);
    gam.set_undirected_matrix_val(0, 3);
    gam.set_undirected_matrix_val(1, 2);
    gam.set_undirected_matrix_val(1, 5);
    gam.set_undirected_matrix_val(2, 4);
    gam.set_undirected_matrix_val(3, 6);
    gam.set_undirected_matrix_val(3, 7);
    gam.set_undirected_matrix_val(4, 5);
    gam.set_undirected_matrix_val(6, 7);

    std::cout << "------ traverse_matrix ------" << std::endl;
    gam.traverse_matrix();
    std::cout << "------ traverse_vertex_depth ------" << std::endl;
    gam.traverse_vertex_depth(0);
    gam.reset_vertex();
    std::cout << "------ traverse_vertex_breadth ------" << std::endl;
    gam.traverse_vertex_breadth(0);
}

void test_char() {
    graph_adjacency_matrix<size_t, char> gam(8);

    for (size_t i = 0; i < 8; ++i) {
        gam.add_vertex(graph_vertex<char>('A' + i));
    }

    gam.set_undirected_matrix_val(0, 1);
    gam.set_undirected_matrix_val(0, 3);
    gam.set_undirected_matrix_val(1, 2);
    gam.set_undirected_matrix_val(1, 5);
    gam.set_undirected_matrix_val(2, 4);
    gam.set_undirected_matrix_val(3, 6);
    gam.set_undirected_matrix_val(3, 7);
    gam.set_undirected_matrix_val(4, 5);
    gam.set_undirected_matrix_val(6, 7);

    std::cout << "------ traverse_matrix ------" << std::endl;
    gam.traverse_matrix();
    std::cout << "------ traverse_vertex_depth ------" << std::endl;
    gam.traverse_vertex_depth(0);
    gam.reset_vertex();
    std::cout << "------ traverse_vertex_breadth ------" << std::endl;
    gam.traverse_vertex_breadth(0);
}

int main() {
    std::cout << "----------------- int -----------------" << std::endl;
    test_char();
    std::cout << "----------------- coordinate -----------------" << std::endl;
    test_coordinate();
    std::cout << "----------------- min_span_tree -----------------" << std::endl;
    test_min_span_tree();

    return 0;
}
