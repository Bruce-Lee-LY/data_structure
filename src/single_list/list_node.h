// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 23:00:38 on Tue, May 24, 2022
//
// Description: list node

#ifndef __DATA_STRUCTURE_LIST_NODE_H__
#define __DATA_STRUCTURE_LIST_NODE_H__

template <typename T>
class list_node {
public:
    list_node(const T in_data = 0) : prior(nullptr), next(nullptr) {
        this->data = in_data;
    }

    ~list_node() = default;

    list_node<T> &operator=(const list_node<T> &node) {
        data = node.data;
        prior = node.prior;
        next = node.next;

        return *this;
    }

    T data;
    list_node<T> *prior;
    list_node<T> *next;
};

#endif  // __DATA_STRUCTURE_LIST_NODE_H__
