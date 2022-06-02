// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 23:01:38 on Tue, May 24, 2022
//
// Description: test skip list

#include "coordinate.h"
#include "skip_list.h"

void test_coordinate() {
    skip_list<size_t, coordinate> hml(10);
    std::cout << hml.get_load_num() << std::endl;

    for (size_t i = 0; i < 10; ++i) {
        hml.insert(i, coordinate(i, i * i));
    }

    std::cout << hml.get_load_num() << std::endl;
    hml.traverse();

    std::cout << hml.search(3) << std::endl;
    std::cout << hml.erase(3) << std::endl;
    std::cout << hml.erase(16) << std::endl;
    std::cout << hml.search(3) << std::endl;

    std::cout << hml.get_load_num() << std::endl;
    hml.traverse();
}

void test_int() {
    skip_list<size_t, size_t> hml(10);
    std::cout << hml.get_load_num() << std::endl;

    for (size_t i = 0; i < 10; ++i) {
        hml.insert(i, i);
    }

    std::cout << hml.get_load_num() << std::endl;
    hml.traverse();

    std::cout << hml.search(3) << std::endl;
    std::cout << hml.erase(3) << std::endl;
    std::cout << hml.erase(16) << std::endl;
    std::cout << hml.search(3) << std::endl;

    std::cout << hml.get_load_num() << std::endl;
    hml.traverse();
}

int main() {
    std::cout << "----------------- int -----------------" << std::endl;
    test_int();
    std::cout << "----------------- coordinate -----------------" << std::endl;
    test_coordinate();

    return 0;
}
