// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 22:59:32 on Tue, May 24, 2022
//
// Description: test sequence list

#include "coordinate.h"
#include "sequence_list.h"

void test_coordinate() {
    sequence_list<coordinate> sl(7);
    std::cout << sl.size() << std::endl;

    for (size_t i = 0; i < 10; ++i) {
        sl.insert(coordinate(i, i * i), i);
    }

    std::cout << sl.size() << std::endl;

    sl.traverse();

    coordinate coor_tmp;
    std::cout << sl.get(3, coor_tmp) << " " << coor_tmp << std::endl;
    std::cout << sl.prior(coor_tmp, coor_tmp) << " " << coor_tmp << std::endl;
    std::cout << sl.next(coor_tmp, coor_tmp) << " " << coor_tmp << std::endl;

    size_t idx_tmp = 0;
    std::cout << sl.find(coor_tmp, idx_tmp) << " " << idx_tmp << std::endl;
    std::cout << sl.erase(idx_tmp, coor_tmp) << " " << coor_tmp << std::endl;
    std::cout << sl.find(coor_tmp, idx_tmp) << std::endl;
}

void test_int() {
    sequence_list<size_t> sl(7);
    std::cout << sl.size() << std::endl;

    for (size_t i = 0; i < 10; ++i) {
        sl.insert(i, i);
    }

    std::cout << sl.size() << std::endl;

    sl.traverse();

    size_t ui_tmp = 0;
    std::cout << sl.get(3, ui_tmp) << " " << ui_tmp << std::endl;
    std::cout << sl.prior(ui_tmp, ui_tmp) << " " << ui_tmp << std::endl;
    std::cout << sl.next(ui_tmp, ui_tmp) << " " << ui_tmp << std::endl;

    size_t idx_tmp = 0;
    std::cout << sl.find(ui_tmp, idx_tmp) << " " << idx_tmp << std::endl;
    std::cout << sl.erase(idx_tmp, ui_tmp) << " " << ui_tmp << std::endl;
    std::cout << sl.find(ui_tmp, idx_tmp) << std::endl;
}

int main() {
    std::cout << "----------------- int -----------------" << std::endl;
    test_int();
    std::cout << "----------------- coordinate -----------------" << std::endl;
    test_coordinate();

    return 0;
}
