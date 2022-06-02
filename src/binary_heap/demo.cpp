// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 22:47:54 on Tue, May 24, 2022
//
// Description: test binary heap

#include "binary_heap.h"
#include "coordinate.h"

void test_coordinate() {
    binary_heap<coordinate> bh(16);
    std::cout << bh.size() << std::endl;

    for (size_t i = 16; i > 0; --i) {
        bh.push_small_top(coordinate(i, i * i));
    }

    std::cout << bh.size() << std::endl;

    std::cout << "------ traverse ------" << std::endl;
    bh.traverse();

    std::cout << "------ pop_small_top ------" << std::endl;
    bh.pop_small_top();
    bh.traverse();

    std::cout << "------ sort_ascend ------" << std::endl;
    bh.sort_ascend();
    bh.traverse();
}

void test_int() {
    binary_heap<size_t> bh(16);
    std::cout << bh.size() << std::endl;

    for (size_t i = 1; i < 17; ++i) {
        bh.push_big_top(i);
    }

    std::cout << bh.size() << std::endl;

    std::cout << "------ traverse ------" << std::endl;
    bh.traverse();

    std::cout << "------ pop_big_top ------" << std::endl;
    bh.pop_big_top();
    bh.traverse();

    std::cout << "------ sort_descend ------" << std::endl;
    bh.sort_descend();
    bh.traverse();
}

int main() {
    std::cout << "----------------- int -----------------" << std::endl;
    test_int();
    std::cout << "----------------- coordinate -----------------" << std::endl;
    test_coordinate();

    return 0;
}
