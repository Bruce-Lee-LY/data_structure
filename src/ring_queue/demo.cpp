// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 22:58:50 on Tue, May 24, 2022
//
// Description: test ring queue

#include "coordinate.h"
#include "ring_queue.h"

void test_coordinate() {
    ring_queue<coordinate> rq(7);
    std::cout << rq.size() << std::endl;

    for (int i = 0; i < 10; ++i) {
        rq.enqueue(coordinate(i, i * i));
    }

    std::cout << rq.size() << std::endl;

    rq.traverse();

    coordinate coor_tmp;
    std::cout << rq.find(coor_tmp) << std::endl;
    std::cout << rq.dequeue(coor_tmp) << " " << coor_tmp << std::endl;
    std::cout << rq.find(coor_tmp) << std::endl;
}

void test_int() {
    ring_queue<int> rq(7);
    std::cout << rq.size() << std::endl;

    for (int i = 0; i < 10; ++i) {
        rq.enqueue(i);
    }

    std::cout << rq.size() << std::endl;

    rq.traverse();

    int i_tmp = 0;
    std::cout << rq.find(i_tmp) << std::endl;
    std::cout << rq.dequeue(i_tmp) << " " << i_tmp << std::endl;
    std::cout << rq.find(i_tmp) << std::endl;
}

int main() {
    std::cout << "----------------- int -----------------" << std::endl;
    test_int();
    std::cout << "----------------- coordinate -----------------" << std::endl;
    test_coordinate();

    return 0;
}
