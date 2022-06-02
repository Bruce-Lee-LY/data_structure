// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 23:00:21 on Tue, May 24, 2022
//
// Description: test single list

#include "coordinate.h"
#include "single_list.h"

void test_coordinate() {
    single_list<coordinate> sl;
    std::cout << sl.size() << std::endl;

    for (size_t i = 0; i < 10; ++i) {
        // sl.insert(list_node<coordinate>(coordinate(i, i * i)), i);
        sl.push_front(coordinate(i, i * i));
    }

    std::cout << sl.size() << std::endl;

    std::cout << "----------------- traverse -----------------" << std::endl;
    sl.traverse();
    std::cout << "----------------- reverse -----------------" << std::endl;
    sl.reverse();
    sl.traverse();

    list_node<coordinate> node_tmp;
    std::cout << sl.get(3, node_tmp) << " " << node_tmp.data << std::endl;
    std::cout << sl.prior(node_tmp, node_tmp) << " " << node_tmp.data << std::endl;
    std::cout << sl.next(node_tmp, node_tmp) << " " << node_tmp.data << std::endl;

    size_t idx_tmp = 0;
    std::cout << sl.find(node_tmp, idx_tmp) << " " << idx_tmp << std::endl;
    std::cout << sl.erase(idx_tmp, node_tmp) << " " << node_tmp.data << std::endl;
    std::cout << sl.find(node_tmp, idx_tmp) << std::endl;

    std::cout << sl.pop_front() << std::endl;
    std::cout << sl.pop_back() << std::endl;

    sl.traverse();
}

void test_int() {
    single_list<size_t> sl;
    std::cout << sl.size() << std::endl;

    for (size_t i = 0; i < 10; ++i) {
        // sl.insert(list_node<size_t>(i), i);
        sl.push_back(i);
    }

    std::cout << sl.size() << std::endl;

    std::cout << "----------------- traverse -----------------" << std::endl;
    sl.traverse();
    std::cout << "----------------- reverse -----------------" << std::endl;
    sl.reverse();
    sl.traverse();

    list_node<size_t> node_tmp;
    std::cout << sl.get(3, node_tmp) << " " << node_tmp.data << std::endl;
    std::cout << sl.prior(node_tmp, node_tmp) << " " << node_tmp.data << std::endl;
    std::cout << sl.next(node_tmp, node_tmp) << " " << node_tmp.data << std::endl;

    size_t idx_tmp = 0;
    std::cout << sl.find(node_tmp, idx_tmp) << " " << idx_tmp << std::endl;
    std::cout << sl.erase(idx_tmp, node_tmp) << " " << node_tmp.data << std::endl;
    std::cout << sl.find(node_tmp, idx_tmp) << std::endl;

    std::cout << sl.pop_front() << std::endl;
    std::cout << sl.pop_back() << std::endl;

    sl.traverse();
}

int main() {
    std::cout << "----------------- int -----------------" << std::endl;
    test_int();
    std::cout << "----------------- coordinate -----------------" << std::endl;
    test_coordinate();

    return 0;
}
