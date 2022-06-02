// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 22:56:55 on Tue, May 24, 2022
//
// Description: test red black tree

#include "coordinate.h"
#include "red_black_tree.h"

void test_coordinate() {
    red_black_tree<size_t, coordinate> rbt;
    std::cout << rbt.size() << std::endl;

    for (size_t i = 16; i > 0; --i) {
        rbt.insert(i, coordinate(i, i * i));
    }

    std::cout << rbt.size() << std::endl;

    rbt.traverse_level();

    std::cout << rbt.search(5) << std::endl;
    std::cout << rbt.erase(5) << std::endl;
    std::cout << rbt.search(5) << std::endl;

    rbt.traverse_level();
}

void test_int() {
    red_black_tree<size_t, size_t> rbt;
    std::cout << rbt.size() << std::endl;

    for (size_t i = 16; i > 0; --i) {
        rbt.insert(i, i);
    }

    std::cout << rbt.size() << std::endl;

    rbt.traverse_level();

    std::cout << rbt.search(5) << std::endl;
    std::cout << rbt.erase(5) << std::endl;
    std::cout << rbt.search(5) << std::endl;

    rbt.traverse_level();
}

int main() {
    std::cout << "----------------- int -----------------" << std::endl;
    test_int();
    std::cout << "----------------- coordinate -----------------" << std::endl;
    test_coordinate();

    return 0;
}
