// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 22:49:28 on Tue, May 24, 2022
//
// Description: test binary tree array

#include "binary_tree_array.h"
#include "coordinate.h"

void test_coordinate() {
    binary_tree_array<coordinate> bta(20, coordinate(1, 1));
    std::cout << bta.size() << std::endl;

    for (size_t i = 0; i < 10; ++i) {
        bta.insert(i, coordinate(i * 2 + 1, (i * 2 + 1) * (i * 2 + 1)), (i * 2 + 1) % 2);
        bta.insert(i, coordinate(i * 2 + 2, (i * 2 + 2) * (i * 2 + 2)), (i * 2 + 2) % 2);
    }

    std::cout << bta.size() << std::endl;

    bta.traverse();

    coordinate coor_tmp;
    std::cout << bta.get(3, coor_tmp) << " " << coor_tmp << std::endl;

    size_t idx_tmp = 0;
    std::cout << bta.find(coor_tmp, idx_tmp) << " " << idx_tmp << std::endl;
    std::cout << bta.erase(idx_tmp, coor_tmp) << " " << coor_tmp << std::endl;
    std::cout << bta.find(coor_tmp, idx_tmp) << std::endl;
}

void test_int() {
    binary_tree_array<size_t> bta(20, 1);
    std::cout << bta.size() << std::endl;

    for (size_t i = 0; i < 10; ++i) {
        bta.insert(i, i * 2 + 1, (i * 2 + 1) % 2);
        bta.insert(i, i * 2 + 2, (i * 2 + 2) % 2);
    }

    std::cout << bta.size() << std::endl;

    bta.traverse();

    size_t ui_tmp = 0;
    std::cout << bta.get(3, ui_tmp) << " " << ui_tmp << std::endl;

    size_t idx_tmp = 0;
    std::cout << bta.find(ui_tmp, idx_tmp) << " " << idx_tmp << std::endl;
    std::cout << bta.erase(idx_tmp, ui_tmp) << " " << ui_tmp << std::endl;
    std::cout << bta.find(ui_tmp, idx_tmp) << std::endl;
}

int main() {
    std::cout << "----------------- int -----------------" << std::endl;
    test_int();
    std::cout << "----------------- coordinate -----------------" << std::endl;
    test_coordinate();

    return 0;
}
