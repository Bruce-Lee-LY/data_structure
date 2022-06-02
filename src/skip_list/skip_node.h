// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 23:02:12 on Tue, May 24, 2022
//
// Description: skip node

#ifndef __DATA_STRUCTURE_SKIP_NODE_H__
#define __DATA_STRUCTURE_SKIP_NODE_H__

#include <ostream>

template <typename K_T, typename V_T>
class skip_node {
    friend std::ostream &operator<<(std::ostream &out, const skip_node<K_T, V_T> &node) {
        out << "(" << node.key << ", " << node.value << ")";
        return out;
    }

public:
    skip_node(const K_T in_key = 0, const V_T in_value = 0)
        : prior(nullptr), next(nullptr), up(nullptr), down(nullptr) {
        this->key = in_key;
        this->value = in_value;
    }

    ~skip_node() = default;

    K_T key;
    V_T value;
    skip_node<K_T, V_T> *prior;
    skip_node<K_T, V_T> *next;
    skip_node<K_T, V_T> *up;
    skip_node<K_T, V_T> *down;
};

#endif  // __DATA_STRUCTURE_SKIP_NODE_H__
