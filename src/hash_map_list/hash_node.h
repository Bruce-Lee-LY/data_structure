// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 22:56:33 on Tue, May 24, 2022
//
// Description: hash node

#ifndef __DATA_STRUCTURE_HASH_NODE_H__
#define __DATA_STRUCTURE_HASH_NODE_H__

#include <ostream>

template <typename K_T, typename V_T>
class hash_node {
    friend std::ostream &operator<<(std::ostream &out, const hash_node<K_T, V_T> &node) {
        out << "(" << node.key << ", " << node.value << ")";
        return out;
    }

public:
    hash_node(const K_T in_key = 0, const V_T in_value = 0) {
        this->key = in_key;
        this->value = in_value;
    }

    ~hash_node() = default;

    hash_node<K_T, V_T> &operator=(const hash_node<K_T, V_T> &node) {
        key = node.key;
        value = node.value;

        return *this;
    }

    K_T key;
    V_T value;
};

#endif  // __DATA_STRUCTURE_HASH_NODE_H__
