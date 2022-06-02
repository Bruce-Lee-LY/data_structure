// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 22:51:08 on Tue, May 24, 2022
//
// Description: tree node

#ifndef __DATA_STRUCTURE_TREE_NODE_H__
#define __DATA_STRUCTURE_TREE_NODE_H__

#include <iostream>
#include <queue>
#include <stack>

template <typename T>
class tree_node {
    friend std::ostream &operator<<(std::ostream &out, const tree_node<T> &node) {
        out << "(" << node.idx << ", " << node.data << ")";
        return out;
    }

public:
    tree_node(const size_t in_idx = 0, const T in_data = 0) : parent(nullptr), left(nullptr), right(nullptr) {
        this->idx = in_idx;
        this->data = in_data;
    }

    ~tree_node() = default;

    bool search(const size_t in_idx, tree_node<T> **node) {
        if (this->idx == in_idx) {
            *node = this;
            return true;
        }

        if (this->left) {
            if (this->left->idx == in_idx) {
                *node = this->left;
                return true;
            } else {
                if (this->left->search(in_idx, node)) {
                    return true;
                }
            }
        }

        if (this->right) {
            if (this->right->idx == in_idx) {
                *node = this->right;
                return true;
            } else {
                if (this->right->search(in_idx, node)) {
                    return true;
                }
            }
        }

        return false;
    }

    void erase() {
        if (left) {
            this->left->erase();
        }

        if (right) {
            this->right->erase();
        }

        if (parent) {
            if (this->parent->left == this) {
                this->parent->left = nullptr;
            }

            if (this->parent->right == this) {
                this->parent->right = nullptr;
            }
        }

        delete this;
    }

    void traverse_preorder() const {
        std::cout << *this << std::endl;

        if (left) {
            left->traverse_preorder();
        }

        if (right) {
            right->traverse_preorder();
        }
    }

    void traverse_preorder_without_recursive() {
        tree_node<T> *tmp_node = this;
        tree_node<T> *tmp2_node = nullptr;
        std::stack<tree_node<T> *> tmp_stack;
        while (tmp_node || !tmp_stack.empty()) {
            if (tmp_node) {
                std::cout << *tmp_node << std::endl;
                tmp_stack.push(tmp_node);
                tmp_node = tmp_node->left;
            } else {
                tmp2_node = tmp_stack.top();
                tmp_stack.pop();
                tmp_node = tmp2_node->right;
            }
        }
    }

    void traverse_inorder() const {
        if (left) {
            left->traverse_inorder();
        }

        std::cout << *this << std::endl;

        if (right) {
            right->traverse_inorder();
        }
    }

    void traverse_inorder_without_recursive() {
        tree_node<T> *tmp_node = this;
        tree_node<T> *tmp2_node = nullptr;
        std::stack<tree_node<T> *> tmp_stack;
        while (tmp_node || !tmp_stack.empty()) {
            while (tmp_node) {
                tmp_stack.push(tmp_node);
                tmp_node = tmp_node->left;
            }

            tmp2_node = tmp_stack.top();
            tmp_stack.pop();
            std::cout << *tmp2_node << std::endl;
            tmp_node = tmp2_node->right;
        }
    }

    void traverse_postorder() const {
        if (left) {
            left->traverse_postorder();
        }

        if (right) {
            right->traverse_postorder();
        }

        std::cout << *this << std::endl;
    }

    void traverse_postorder_without_recursive() {
        tree_node<T> *pre_node = nullptr;
        tree_node<T> *curr_node = nullptr;
        std::stack<tree_node<T> *> tmp_stack;
        tmp_stack.push(this);
        while (!tmp_stack.empty()) {
            curr_node = tmp_stack.top();
            if ((!curr_node->left && !curr_node->right) ||
                (pre_node && (pre_node == curr_node->left || pre_node == curr_node->right))) {
                std::cout << *curr_node << std::endl;
                tmp_stack.pop();
                pre_node = curr_node;
            } else {
                if (curr_node->right) {
                    tmp_stack.push(curr_node->right);
                }
                if (curr_node->left) {
                    tmp_stack.push(curr_node->left);
                }
            }
        }
    }

    void traverse_level() {
        tree_node<T> *tmp_node = nullptr;
        std::queue<tree_node<T> *> tmp_queue;
        tmp_queue.push(this);
        while (!tmp_queue.empty()) {
            tmp_node = tmp_queue.front();
            tmp_queue.pop();
            std::cout << *tmp_node << std::endl;
            if (tmp_node->left) {
                tmp_queue.push(tmp_node->left);
            }

            if (tmp_node->right) {
                tmp_queue.push(tmp_node->right);
            }
        }
    }

    tree_node<T> &operator=(const tree_node<T> &node) {
        idx = node.idx;
        data = node.data;
        parent = node.parent;
        left = node.left;
        right = node.right;

        return *this;
    }

    size_t idx;
    T data;
    tree_node<T> *parent;
    tree_node<T> *left;
    tree_node<T> *right;
};

#endif  // __DATA_STRUCTURE_TREE_NODE_H__
