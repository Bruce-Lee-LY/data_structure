// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 22:45:06 on Tue, May 24, 2022
//
// Description: AVL node

#ifndef __DATA_STRUCTURE_AVL_NODE_H__
#define __DATA_STRUCTURE_AVL_NODE_H__

#include <ostream>

template <typename K_T, typename V_T>
class AVL_node {
    friend std::ostream &operator<<(std::ostream &out, const AVL_node<K_T, V_T> &node) {
        out << "(" << node.key << ", " << node.value << ", " << node.height << ")";
        return out;
    }

public:
    AVL_node(const K_T in_key = 0, const V_T in_value = 0) : height(0), parent(nullptr), left(nullptr), right(nullptr) {
        this->key = in_key;
        this->value = in_value;
    }

    ~AVL_node() = default;

    AVL_node<K_T, V_T> &operator=(const AVL_node<K_T, V_T> &node) {
        key = node.key;
        value = node.value;
        height = node.height;
        parent = node.parent;
        left = node.left;
        right = node.right;

        return *this;
    }

    K_T key;
    V_T value;
    size_t height;
    AVL_node<K_T, V_T> *parent;
    AVL_node<K_T, V_T> *left;
    AVL_node<K_T, V_T> *right;
};

#endif  // __DATA_STRUCTURE_AVL_NODE_H__
