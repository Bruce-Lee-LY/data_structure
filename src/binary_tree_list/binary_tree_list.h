// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 22:50:00 on Tue, May 24, 2022
//
// Description: binary tree list

#ifndef __DATA_STRUCTURE_BINARY_TREE_LIST_H__
#define __DATA_STRUCTURE_BINARY_TREE_LIST_H__

#include "tree_node.h"

template <typename T>
class binary_tree_list {
public:
    binary_tree_list() {
        m_root = new tree_node<T>;
    }

    ~binary_tree_list() {
        if (m_root) {
            m_root->erase();
        }
    }

    bool insert(const size_t idx, const tree_node<T> node, const bool left_child) {
        tree_node<T> *tmp1 = nullptr;
        if (!search(idx, &tmp1)) {
            return false;
        }

        tree_node<T> *tmp2 = new tree_node<T>;
        tmp2->idx = node.idx;
        tmp2->data = node.data;
        tmp2->parent = tmp1;

        if (left_child) {
            tmp1->left = tmp2;
        } else {
            tmp1->right = tmp2;
        }

        return true;
    }

    bool erase(const size_t idx, tree_node<T> &node) {
        tree_node<T> *tmp = nullptr;
        if (!search(idx, &tmp)) {
            return false;
        }

        node.data = tmp->data;
        tmp->erase();
        return true;
    }

    bool search(const size_t idx, tree_node<T> **node) const {
        return m_root->search(idx, node);
    }

    void traverse_preorder() const {
        if (m_root) {
            m_root->traverse_preorder();
        }
    }

    void traverse_preorder_without_recursive() const {
        if (m_root) {
            m_root->traverse_preorder_without_recursive();
        }
    }

    void traverse_inorder() const {
        if (m_root) {
            m_root->traverse_inorder();
        }
    }

    void traverse_inorder_without_recursive() const {
        if (m_root) {
            m_root->traverse_inorder_without_recursive();
        }
    }

    void traverse_postorder() const {
        if (m_root) {
            m_root->traverse_postorder();
        }
    }

    void traverse_postorder_without_recursive() const {
        if (m_root) {
            m_root->traverse_postorder_without_recursive();
        }
    }

    void traverse_level() const {
        if (m_root) {
            m_root->traverse_level();
        }
    }

private:
    tree_node<T> *m_root;
};

#endif  // __DATA_STRUCTURE_BINARY_TREE_LIST_H__
