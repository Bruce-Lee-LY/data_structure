// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 23:01:50 on Tue, May 24, 2022
//
// Description: skiop list

#ifndef __DATA_STRUCTURE_SKIP_LIST_H__
#define __DATA_STRUCTURE_SKIP_LIST_H__

#include <iostream>

#include "skip_node.h"

template <typename K_T, typename V_T>
class skip_list {
public:
    skip_list(size_t max_level) : m_max_level(max_level), m_level(0), m_load_num(0) {
        m_head = new skip_node<K_T, V_T>;
    }

    ~skip_list() {
        clear();

        if (m_head) {
            delete m_head;
            m_head = nullptr;
        }
    }

    void insert(const K_T key, const V_T value) {
        skip_node<K_T, V_T> *curr = m_head;
        while (curr->down) {
            curr = curr->down;
        }

        skip_node<K_T, V_T> *curr_head = curr;
        skip_node<K_T, V_T> *node_tmp1 = nullptr;
        while (curr->next) {
            if (key < curr->next->key && !node_tmp1) {
                node_tmp1 = new skip_node<K_T, V_T>(key, value);
                node_tmp1->next = curr->next;
                curr->next = node_tmp1;
                m_load_num++;
                break;
            } else if (key == curr->next->key) {
                curr->value = value;
                break;
            }
            curr = curr->next;
        }

        if (!node_tmp1) {
            node_tmp1 = new skip_node<K_T, V_T>(key, value);
            curr->next = node_tmp1;
            m_load_num++;
        }

        size_t level = random_level();
        for (size_t i = 1; i < level; ++i) {
            if (m_level < i) {
                m_level++;
                skip_node<K_T, V_T> *head_tmp = new skip_node<K_T, V_T>(key, value);
                head_tmp->down = m_head;
                m_head->up = head_tmp;
                m_head = head_tmp;
            }

            curr_head = curr_head->up;
            curr = curr_head;

            skip_node<K_T, V_T> *node_tmp2 = nullptr;
            while (curr->next) {
                if (key < curr->next->key && !node_tmp2) {
                    node_tmp2 = new skip_node<K_T, V_T>(key, value);
                    node_tmp2->next = curr->next;
                    curr->next = node_tmp2;
                    break;
                } else if (key == curr->next->key) {
                    curr->value = value;
                    break;
                }
                curr = curr->next;
            }

            if (!node_tmp2) {
                node_tmp2 = new skip_node<K_T, V_T>(key, value);
                curr->next = node_tmp2;
            }

            node_tmp2->down = node_tmp1;
            node_tmp1->up = node_tmp2;
            node_tmp1 = node_tmp2;
        }
    }

    bool erase(const K_T key) {
        bool deleted = false;
        if (empty()) {
            return deleted;
        }

        skip_node<K_T, V_T> *curr = m_head;
        skip_node<K_T, V_T> *curr_head = m_head;
        skip_node<K_T, V_T> *up_head = nullptr;
        skip_node<K_T, V_T> *node_tmp = nullptr;
        while (curr) {
            curr_head = curr;
            if (up_head) {
                curr_head->up = nullptr;
                up_head->down = nullptr;
                delete up_head;
                up_head = nullptr;
                m_level--;
                m_head = curr_head;
            }

            while (curr && curr->next) {
                if (key == curr->next->key) {
                    node_tmp = curr->next;
                    curr->next = curr->next->next;
                    delete node_tmp;
                    node_tmp = nullptr;
                    deleted = true;
                    break;
                }
                curr = curr->next;
            }

            if (!curr_head->next) {
                up_head = curr_head;
            }

            curr = curr_head->down;
        }

        if (deleted) {
            m_load_num--;
        }

        return deleted;
    }

    bool search(const K_T key) {
        if (empty()) {
            return false;
        }

        skip_node<K_T, V_T> *curr = m_head;
        while (curr->down) {
            while (curr->next) {
                if (key <= curr->next->key) {
                    break;
                }
                curr = curr->next;
            }
            curr = curr->down;
        }

        while (curr->next) {
            if (key > curr->next->key) {
                curr = curr->next;
            } else if (key == curr->next->key) {
                return true;
            } else {
                return false;
            }
        }

        return false;
    }

    size_t random_level() const {
        size_t level = 1;
        while ((rand() % 2) == 0 && level <= m_max_level) {
            level += 1;
        }
        return level;
    }

    void clear() {
        if (empty()) {
            return;
        }

        skip_node<K_T, V_T> *curr = m_head;
        while (curr->down) {
            curr = curr->down;
        }

        while (curr->next) {
            curr = curr->next;
            std::cout << curr->key << " " << erase(curr->key) << std::endl;
        }

        m_level = 0;
        m_load_num = 0;
    }

    size_t get_load_num() const {
        return m_load_num;
    }

    bool empty() const {
        return get_load_num() == 0;
    }

    void traverse() const {
        if (!empty()) {
            size_t cnt = m_level;
            skip_node<K_T, V_T> *curr_head = m_head;
            while (curr_head) {
                std::cout << "------ level = " << cnt-- << " ------" << std::endl;
                skip_node<K_T, V_T> *curr = curr_head;
                while (curr->next) {
                    curr = curr->next;
                    std::cout << *curr << std::endl;
                }
                curr_head = curr_head->down;
            }
        }
    }

private:
    skip_node<K_T, V_T> *m_head;
    const size_t m_max_level;
    size_t m_level;
    size_t m_load_num;
};

#endif  // __DATA_STRUCTURE_SKIP_LIST_H__
