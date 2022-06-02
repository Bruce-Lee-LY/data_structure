// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 22:58:06 on Tue, May 24, 2022
//
// Description: red black tree

#ifndef __DATA_STRUCTURE_RED_BLACK_TREE_H__
#define __DATA_STRUCTURE_RED_BLACK_TREE_H__

#include <iostream>
#include <queue>

#include "red_black_node.h"

template <typename K_T, typename V_T>
class red_black_tree {
public:
    red_black_tree() : m_root(nullptr), m_node_num(0) {}

    ~red_black_tree() {
        clear();
    }

    bool insert(const K_T key, const V_T value) {
        red_black_node<K_T, V_T> *node = new red_black_node<K_T, V_T>(key, value);

        bool inserted = true;
        insert_node(m_root, node, inserted);
        if (inserted) {
            m_node_num++;
        }

        return inserted;
    }

    bool erase(const K_T key) {
        red_black_node<K_T, V_T> *node = search(key);
        if (!node) {
            return false;
        }

        erase_node(m_root, node);
        m_node_num--;

        return true;
    }

    red_black_node<K_T, V_T> *search(const K_T key) const {
        if (empty()) {
            return nullptr;
        }

        return search_node(m_root, key);
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
            red_black_node<K_T, V_T> node_tmp;
            std::queue<red_black_node<K_T, V_T>> queue_tmp;
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
    void insert_node(red_black_node<K_T, V_T> *&root, red_black_node<K_T, V_T> *node, bool &inserted) {
        red_black_node<K_T, V_T> *parent = nullptr;
        red_black_node<K_T, V_T> *child = root;
        while (child) {
            parent = child;
            if (node->key < child->key) {
                child = child->left;
            } else {
                child = child->right;
            }
        }

        node->parent = parent;
        if (parent) {
            if (node->key < parent->key) {
                parent->left = node;
            } else if (node->key > parent->key) {
                parent->right = node;
            } else {
                parent->value = node->value;
                delete node;
                node = nullptr;
                inserted = false;
                return;
            }
        } else {
            root = node;
        }

        node->color = RED;
        insert_balance(root, node);
    }

    void insert_balance(red_black_node<K_T, V_T> *&root, red_black_node<K_T, V_T> *node) {
        red_black_node<K_T, V_T> *grandparent = nullptr;
        red_black_node<K_T, V_T> *parent = node->parent;
        red_black_node<K_T, V_T> *uncle = nullptr;
        red_black_node<K_T, V_T> *node_tmp = nullptr;
        while (parent && parent->color == RED) {
            grandparent = parent->parent;
            if (parent == grandparent->left) {
                uncle = grandparent->right;
                if (uncle && uncle->color == RED) {
                    uncle->color = BLACK;
                    parent->color = BLACK;
                    grandparent->color = RED;
                    node = grandparent;
                    parent = node->parent;
                    continue;
                }

                if (node == parent->right) {
                    rotate_left(root, parent);
                    node_tmp = parent;
                    parent = node;
                    node = node_tmp;
                }

                parent->color = BLACK;
                grandparent->color = RED;
                rotate_right(root, grandparent);
            } else {
                uncle = grandparent->left;
                if (uncle && uncle->color == RED) {
                    uncle->color = BLACK;
                    parent->color = BLACK;
                    grandparent->color = RED;
                    node = grandparent;
                    parent = node->parent;
                    continue;
                }

                if (node == parent->left) {
                    rotate_right(root, parent);
                    node_tmp = parent;
                    parent = node;
                    node = node_tmp;
                }

                parent->color = BLACK;
                grandparent->color = RED;
                rotate_left(root, grandparent);
            }

            parent = node->parent;
        }

        root->color = BLACK;
    }

    void rotate_left(red_black_node<K_T, V_T> *&root, red_black_node<K_T, V_T> *node) {
        red_black_node<K_T, V_T> *right = node->right;
        node->right = right->left;
        if (right->left) {
            right->left->parent = node;
        }

        right->parent = node->parent;
        if (!node->parent) {
            root = right;
        } else {
            if (node == node->parent->left) {
                node->parent->left = right;
            } else {
                node->parent->right = right;
            }
        }

        right->left = node;
        node->parent = right;
    }

    void rotate_right(red_black_node<K_T, V_T> *&root, red_black_node<K_T, V_T> *node) {
        red_black_node<K_T, V_T> *left = node->left;
        node->left = left->right;
        if (left->right) {
            left->right->parent = node;
        }

        left->parent = node->parent;
        if (!node->parent) {
            root = left;
        } else {
            if (node == node->parent->right) {
                node->parent->right = left;
            } else {
                node->parent->left = left;
            }
        }

        left->right = node;
        node->parent = left;
    }

    red_black_node<K_T, V_T> *search_node(red_black_node<K_T, V_T> *node, const K_T key) const {
        if (!node) {
            return nullptr;
        }

        if (key < node->key) {
            return search_node(node->left, key);
        } else if (key > node->key) {
            return search_node(node->right, key);
        }

        return node;
    }

    void erase_node(red_black_node<K_T, V_T> *&root, red_black_node<K_T, V_T> *node) {
        red_black_node<K_T, V_T> *parent = nullptr;
        red_black_node<K_T, V_T> *child = nullptr;
        red_black_node<K_T, V_T> *replace = nullptr;
        red_black_color color = BLACK;
        if (node->left && node->right) {
            replace = node;
            replace = replace->right;
            while (replace->left) {
                replace = replace->left;
            }

            if (node->parent) {
                if (node == node->parent->left) {
                    node->parent->left = replace;
                } else {
                    node->parent->right = replace;
                }
            } else {
                root = replace;
            }

            child = replace->right;
            parent = replace->parent;
            color = replace->color;
            if (node == parent) {
                parent = replace;
            } else {
                if (child) {
                    child->parent = parent;
                }

                parent->left = child;
                replace->right = node->right;
                node->right->parent = replace;
            }

            replace->parent = node->parent;
            replace->color = node->color;
            replace->left = node->left;
            node->left->parent = replace;

            if (color == BLACK) {
                erase_balance(root, child, parent);
            }

            delete node;
            node = nullptr;

            return;
        }

        if (node->left) {
            child = node->left;
        } else {
            child = node->right;
        }

        parent = node->parent;
        color = node->color;
        if (child) {
            child->parent = parent;
        }

        if (parent) {
            if (node == parent->left) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        } else {
            root = child;
        }

        if (color == BLACK) {
            erase_balance(root, child, parent);
        }

        delete node;
        node = nullptr;
    }

    void erase_balance(red_black_node<K_T, V_T> *&root, red_black_node<K_T, V_T> *node,
                       red_black_node<K_T, V_T> *parent) {
        red_black_node<K_T, V_T> *other = nullptr;
        while ((!node || node->color == BLACK) && node != root) {
            if (node == parent->left) {
                other = parent->right;
                if (other->color == RED) {
                    other->color = BLACK;
                    parent->color = RED;
                    rotate_left(root, parent);
                    other = parent->right;
                }

                if ((!other->left || other->left->color == BLACK) && (!other->right || other->right->color == BLACK)) {
                    other->color = RED;
                    node = parent;
                    parent = node->parent;
                } else {
                    if (!other->right || other->right->color == BLACK) {
                        other->left->color = BLACK;
                        other->color = RED;
                        rotate_right(root, other);
                        other = parent->right;
                    }

                    other->color = parent->color;
                    parent->color = BLACK;
                    other->right->color = BLACK;
                    rotate_left(root, parent);
                    node = root;
                    break;
                }
            } else {
                other = parent->left;
                if (other->color == RED) {
                    other->color = BLACK;
                    parent->color = RED;
                    rotate_right(root, parent);
                    other = parent->left;
                }

                if ((!other->left || other->left->color == BLACK) && (!other->right || other->right->color == BLACK)) {
                    other->color = RED;
                    node = parent;
                    parent = node->parent;
                } else {
                    if (!other->left || other->left->color == BLACK) {
                        other->right->color = BLACK;
                        other->color = RED;
                        rotate_left(root, other);
                        other = parent->left;
                    }

                    other->color = parent->color;
                    parent->color = BLACK;
                    other->left->color = BLACK;
                    rotate_right(root, parent);
                    node = root;
                    break;
                }
            }
        }

        if (node) {
            node->color = BLACK;
        }
    }

    void clear_node(red_black_node<K_T, V_T> *&node) {
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

    red_black_node<K_T, V_T> *m_root;
    size_t m_node_num;
};

#endif  // __DATA_STRUCTURE_RED_BLACK_TREE_H__
