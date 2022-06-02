// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 22:52:48 on Tue, May 24, 2022
//
// Description: test ds stack

#include "coordinate.h"
#include "ds_stack.h"

void test_coordinate() {
    ds_stack<coordinate> stack(7);
    std::cout << stack.size() << std::endl;

    for (int i = 0; i < 10; ++i) {
        stack.push(coordinate(i, i * i));
    }

    std::cout << stack.size() << std::endl;

    stack.traverse(false);

    coordinate coor_tmp;
    std::cout << stack.find(coor_tmp) << std::endl;
    std::cout << stack.pop(coor_tmp) << " " << coor_tmp << std::endl;
    std::cout << stack.find(coor_tmp) << std::endl;
}

void test_int() {
    ds_stack<int> stack(7);
    std::cout << stack.size() << std::endl;

    for (int i = 0; i < 10; ++i) {
        stack.push(i);
    }

    std::cout << stack.size() << std::endl;

    stack.traverse(false);

    int i_tmp = 0;
    std::cout << stack.find(i_tmp) << std::endl;
    std::cout << stack.pop(i_tmp) << " " << i_tmp << std::endl;
    std::cout << stack.find(i_tmp) << std::endl;
}

int main() {
    std::cout << "----------------- int -----------------" << std::endl;
    test_int();
    std::cout << "----------------- coordinate -----------------" << std::endl;
    test_coordinate();

    return 0;
}
