// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 22:45:43 on Tue, May 24, 2022
//
// Description: AVL tree

#ifndef __DATA_STRUCTURE_AVL_TREE_H__
#define __DATA_STRUCTURE_AVL_TREE_H__

#include <algorithm>
#include <iostream>
#include <queue>

#include "AVL_node.h"

template <typename K_T, typename V_T>
class AVL_tree {
public:
    AVL_tree() : m_root(nullptr), m_node_num(0) {}

    ~AVL_tree() {
        clear();
    }

    void insert(const K_T key, const V_T value) {
        bool inserted = true;
        insert_node(m_root, key, value, inserted);

        if (inserted) {
            m_node_num++;
        }
    }

    bool erase(const K_T key) {
        if (empty() || !search(key)) {
            return false;
        }

        bool erased = false;
        erase_node(m_root, key, erased);

        if (erased) {
            m_node_num--;
        }

        return erased;
    }

    bool search(const K_T key) {
        if (empty()) {
            return false;
        }

        bool searched = false;
        search_node(m_root, key, searched);

        return searched;
    }

    size_t get_height(const AVL_node<K_T, V_T> *node) const {
        if (node) {
            return node->height;
        }
        return 0;
    }

    void clear() {
        if (empty()) {
            return;
        }

        clear_node(m_root);
        m_node_num = 0;
    }

    size_t size() const {
        return m_node_num;
    }

    bool empty() const {
        return m_node_num == 0;
    }

    void traverse_level() const {
        if (!empty()) {
            AVL_node<K_T, V_T> node_tmp;
            std::queue<AVL_node<K_T, V_T>> queue_tmp;
            queue_tmp.push(*m_root);
            while (!queue_tmp.empty()) {
                node_tmp = queue_tmp.front();
                queue_tmp.pop();
                std::cout << node_tmp << std::endl;
                if (node_tmp.left) {
                    queue_tmp.push(*node_tmp.left);
                }

                if (node_tmp.right) {
                    queue_tmp.push(*node_tmp.right);
                }
            }
        }
    }

private:
    AVL_node<K_T, V_T> *insert_node(AVL_node<K_T, V_T> *&node, const K_T key, const V_T value, bool &inserted) {
        if (!node) {
            node = new AVL_node<K_T, V_T>(key, value);
        } else if (key < node->key) {
            node->left = insert_node(node->left, key, value, inserted);
            node = insert_balance(node, key);
        } else if (key > node->key) {
            node->right = insert_node(node->right, key, value, inserted);
            node = insert_balance(node, key);
        } else if (key == node->key) {
            node->value = value;
            inserted = false;
        }

        node->height = std::max(get_height(node->left), get_height(node->right)) + 1;
        return node;
    }

    AVL_node<K_T, V_T> *insert_balance(AVL_node<K_T, V_T> *node, const K_T key) {
        if (get_height(node->left) - get_height(node->right) == 2) {
            if (key < node->left->key) {
                node = rotate_right(node);
            } else {
                node->left = rotate_left(node->left);
                node = rotate_right(node);
            }
        } else if (get_height(node->right) - get_height(node->left) == 2) {
            if (key > node->right->key) {
                node = rotate_left(node);
            } else {
                node->right = rotate_right(node->right);
                node = rotate_left(node);
            }
        }

        return node;
    }

    AVL_node<K_T, V_T> *rotate_left(AVL_node<K_T, V_T> *node) {
        AVL_node<K_T, V_T> *right = node->right;
        node->right = right->left;
        right->left = node;

        node->height = std::max(get_height(node->left), get_height(node->right)) + 1;
        right->height = std::max(node->height, get_height(right->right)) + 1;
        return right;
    }

    AVL_node<K_T, V_T> *rotate_right(AVL_node<K_T, V_T> *node) {
        AVL_node<K_T, V_T> *left = node->left;
        node->left = left->right;
        left->right = node;

        node->height = std::max(get_height(node->left), get_height(node->right)) + 1;
        left->height = std::max(get_height(left->left), node->height) + 1;
        return left;
    }

    void search_node(AVL_node<K_T, V_T> *node, const K_T key, bool &searched) {
        if (!node) {
            return;
        }

        if (key == node->key) {
            searched = true;
        } else if (key < node->key) {
            search_node(node->left, key, searched);
        } else if (key > node->key) {
            search_node(node->right, key, searched);
        }
    }

    AVL_node<K_T, V_T> *erase_node(AVL_node<K_T, V_T> *&node, const K_T key, bool &erased) {
        if (!node) {
            return nullptr;
        }

        if (key < node->key) {
            node->left = erase_node(node->left, key, erased);
            node = erase_balance(node);
        } else if (key > node->key) {
            node->right = erase_node(node->right, key, erased);
            node = erase_balance(node);
        } else {
            if (node->left && node->right) {
                if (get_height(node->left) > get_height(node->right)) {
                    AVL_node<K_T, V_T> *max_node = get_max_node(node->left);
                    node->key = max_node->key;
                    node->value = max_node->value;
                    node->left = erase_node(node->left, max_node->key, erased);
                } else {
                    AVL_node<K_T, V_T> *min_node = get_min_node(node->right);
                    node->key = min_node->key;
                    node->value = min_node->value;
                    node->right = erase_node(node->right, min_node->key, erased);
                }
            } else {
                AVL_node<K_T, V_T> *node_tmp = node;
                node = (node->left) ? node->left : node->right;
                delete node_tmp;
                node_tmp = nullptr;
                erased = true;
            }
        }

        return node;
    }

    AVL_node<K_T, V_T> *erase_balance(AVL_node<K_T, V_T> *node) {
        if (get_height(node->right) - get_height(node->left) == 2) {
            if (get_height(node->right->left) > get_height(node->right->right)) {
                node->right = rotate_right(node->right);
                node = rotate_left(node);
            } else {
                node = rotate_left(node);
            }
        } else if (get_height(node->left) - get_height(node->right) == 2) {
            if (get_height(node->left->left) < get_height(node->left->right)) {
                node->left = rotate_left(node->left);
                node = rotate_right(node);
            } else {
                node = rotate_right(node);
            }
        }

        return node;
    }

    AVL_node<K_T, V_T> *get_max_node(AVL_node<K_T, V_T> *node) {
        if (!node) {
            return nullptr;
        }

        AVL_node<K_T, V_T> *node_tmp = node;
        while (node_tmp->right) {
            node_tmp = node_tmp->right;
        }

        return node_tmp;
    }

    AVL_node<K_T, V_T> *get_min_node(AVL_node<K_T, V_T> *node) {
        if (!node) {
            return nullptr;
        }

        AVL_node<K_T, V_T> *node_tmp = node;
        while (node_tmp->left) {
            node_tmp = node_tmp->left;
        }

        return node_tmp;
    }

    void clear_node(AVL_node<K_T, V_T> *&node) {
        if (!node) {
            return;
        }

        if (node->left) {
            clear_node(node->left);
        }

        if (node->right) {
            clear_node(node->right);
        }

        delete node;
        node = nullptr;
    }

    AVL_node<K_T, V_T> *m_root;
    size_t m_node_num;
};

#endif  // __DATA_STRUCTURE_AVL_TREE_H__
