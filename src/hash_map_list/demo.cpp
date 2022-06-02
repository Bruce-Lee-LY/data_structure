// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 22:55:26 on Tue, May 24, 2022
//
// Description: test hash map list

#include "coordinate.h"
#include "hash_map_list.h"

void test_coordinate() {
    hash_map_list<size_t, coordinate> hml(10, 0.75);

    for (size_t i = 0; i < 20; ++i) {
        std::cout << i << " " << hml.push_back(i, coordinate(i, i * i)) << std::endl;
    }

    for (size_t i = 0; i < 20; ++i) {
        std::cout << i << " " << hml.push_front(i, coordinate(i * i, i * i * i)) << std::endl;
    }

    hml.traverse();

    std::cout << hml.erase(3) << std::endl;
    std::cout << hml.erase(30) << std::endl;

    hml.traverse();
}

void test_int() {
    hash_map_list<size_t, size_t> hml(10, 0.75);

    for (size_t i = 0; i < 20; ++i) {
        std::cout << i << " " << hml.push_front(i, i) << std::endl;
    }

    for (size_t i = 0; i < 20; ++i) {
        std::cout << i << " " << hml.push_back(i, i * i) << std::endl;
    }

    hml.traverse();

    std::cout << hml.erase(3) << std::endl;
    std::cout << hml.erase(30) << std::endl;

    hml.traverse();
}

int main() {
    std::cout << "----------------- int -----------------" << std::endl;
    test_int();
    std::cout << "----------------- coordinate -----------------" << std::endl;
    test_coordinate();

    return 0;
}
