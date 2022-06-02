// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 22:46:26 on Tue, May 24, 2022
//
// Description: test AVL tree

#include "AVL_tree.h"
#include "coordinate.h"

void test_coordinate() {
    AVL_tree<size_t, coordinate> at;
    std::cout << at.size() << std::endl;

    for (size_t i = 16; i > 0; --i) {
        at.insert(i, coordinate(i, i * i));
    }

    std::cout << at.size() << std::endl;

    at.traverse_level();

    std::cout << at.search(5) << std::endl;
    std::cout << at.erase(5) << std::endl;
    std::cout << at.search(5) << std::endl;

    at.traverse_level();
}

void test_int() {
    AVL_tree<size_t, size_t> at;
    std::cout << at.size() << std::endl;

    for (size_t i = 16; i > 0; --i) {
        at.insert(i, i);
    }

    std::cout << at.size() << std::endl;

    at.traverse_level();

    std::cout << at.search(5) << std::endl;
    std::cout << at.erase(5) << std::endl;
    std::cout << at.search(5) << std::endl;

    at.traverse_level();
}

int main() {
    std::cout << "----------------- int -----------------" << std::endl;
    test_int();
    std::cout << "----------------- coordinate -----------------" << std::endl;
    test_coordinate();

    return 0;
}
