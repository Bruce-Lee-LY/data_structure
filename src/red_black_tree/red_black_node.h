// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 22:57:18 on Tue, May 24, 2022
//
// Description: red black node

#ifndef __DATA_STRUCTURE_RED_BLACK_NODE_H__
#define __DATA_STRUCTURE_RED_BLACK_NODE_H__

#include <ostream>

typedef enum {
    BLACK = 0,
    RED,
} red_black_color;

template <typename K_T, typename V_T>
class red_black_node {
    friend std::ostream &operator<<(std::ostream &out, const red_black_node<K_T, V_T> &node) {
        out << "(" << node.key << ", " << node.value << ", " << node.color << ")";
        return out;
    }

public:
    red_black_node(const K_T in_key = 0, const V_T in_value = 0)
        : color(BLACK), parent(nullptr), left(nullptr), right(nullptr) {
        this->key = in_key;
        this->value = in_value;
    }

    ~red_black_node() = default;

    red_black_node<K_T, V_T> &operator=(const red_black_node<K_T, V_T> &node) {
        key = node.key;
        value = node.value;
        color = node.color;
        parent = node.parent;
        left = node.left;
        right = node.right;

        return *this;
    }

    K_T key;
    V_T value;
    red_black_color color;
    red_black_node<K_T, V_T> *parent;
    red_black_node<K_T, V_T> *left;
    red_black_node<K_T, V_T> *right;
};

#endif  // __DATA_STRUCTURE_RED_BLACK_NODE_H__
