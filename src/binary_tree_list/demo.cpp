// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 22:50:32 on Tue, May 24, 2022
//
// Description: test binary tree list

#include "binary_tree_list.h"
#include "coordinate.h"

void test_coordinate() {
    binary_tree_list<coordinate> btl;

    for (size_t i = 0; i < 10; ++i) {
        btl.insert(i, tree_node<coordinate>(i * 2 + 1, coordinate(i * 2 + 1, (i * 2 + 1) * (i * 2 + 1))),
                   (i * 2 + 1) % 2);
        btl.insert(i, tree_node<coordinate>(i * 2 + 2, coordinate(i * 2 + 2, (i * 2 + 2) * (i * 2 + 2))),
                   (i * 2 + 2) % 2);
    }

    std::cout << "------ traverse_preorder ------" << std::endl;
    btl.traverse_preorder();
    std::cout << "------ traverse_preorder_without_recursive ------" << std::endl;
    btl.traverse_preorder_without_recursive();
    std::cout << "------ traverse_inorder ------" << std::endl;
    btl.traverse_inorder();
    std::cout << "------ traverse_inorder_without_recursive ------" << std::endl;
    btl.traverse_inorder_without_recursive();
    std::cout << "------ traverse_postorder ------" << std::endl;
    btl.traverse_postorder();
    std::cout << "------ traverse_postorder_without_recursive ------" << std::endl;
    btl.traverse_postorder_without_recursive();
    std::cout << "------ traverse_level ------" << std::endl;
    btl.traverse_level();

    tree_node<coordinate> node_tmp;
    std::cout << btl.erase(6, node_tmp) << " " << node_tmp.data << std::endl;
}

void test_int() {
    binary_tree_list<size_t> btl;

    for (size_t i = 0; i < 10; ++i) {
        btl.insert(i, tree_node<size_t>(i * 2 + 1, (i * 2 + 1) * (i * 2 + 1)), (i * 2 + 1) % 2);
        btl.insert(i, tree_node<size_t>(i * 2 + 2, (i * 2 + 2) * (i * 2 + 2)), (i * 2 + 2) % 2);
    }

    std::cout << "------ traverse_preorder ------" << std::endl;
    btl.traverse_preorder();
    std::cout << "------ traverse_preorder_without_recursive ------" << std::endl;
    btl.traverse_preorder_without_recursive();
    std::cout << "------ traverse_inorder ------" << std::endl;
    btl.traverse_inorder();
    std::cout << "------ traverse_inorder_without_recursive ------" << std::endl;
    btl.traverse_inorder_without_recursive();
    std::cout << "------ traverse_postorder ------" << std::endl;
    btl.traverse_postorder();
    std::cout << "------ traverse_postorder_without_recursive ------" << std::endl;
    btl.traverse_postorder_without_recursive();
    std::cout << "------ traverse_level ------" << std::endl;
    btl.traverse_level();

    tree_node<size_t> node_tmp;
    std::cout << btl.erase(6, node_tmp) << " " << node_tmp.data << std::endl;
}

int main() {
    std::cout << "----------------- int -----------------" << std::endl;
    test_int();
    std::cout << "----------------- coordinate -----------------" << std::endl;
    test_coordinate();

    return 0;
}
