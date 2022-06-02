// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 22:55:54 on Tue, May 24, 2022
//
// Description: hash map list

#ifndef __DATA_STRUCTURE_HASH_MAP_LIST_H__
#define __DATA_STRUCTURE_HASH_MAP_LIST_H__

#include <iostream>
#include <list>

#include "hash_node.h"

template <typename K_T, typename V_T>
class hash_map_list {
public:
    hash_map_list(size_t max_size, float load_threshold)
        : m_max_size(max_size), m_load_num(0), m_load_threshold(load_threshold) {
        m_list = new std::list<hash_node<K_T, V_T>>[m_max_size];
    }

    ~hash_map_list() {
        clear();

        if (m_list) {
            delete[] m_list;
            m_list = nullptr;
        }
    }

    bool push_front(const K_T key, const V_T value) {
        if (!load(key)) {
            if (full()) {
                return false;
            }

            m_load_num++;
        }

        if (search(key)) {
            return false;
        }

        size_t hash_key = make_hash_key(key);
        m_list[hash_key].push_front(hash_node<K_T, V_T>(key, value));

        return true;
    }

    bool push_back(const K_T key, const V_T value) {
        if (!load(key)) {
            if (full()) {
                return false;
            }

            m_load_num++;
        }

        if (search(key)) {
            return false;
        }

        size_t hash_key = make_hash_key(key);
        m_list[hash_key].push_back(hash_node<K_T, V_T>(key, value));

        return true;
    }

    bool erase(const K_T key) {
        if (!search(key)) {
            return false;
        }

        size_t hash_key = make_hash_key(key);

        auto iter = m_list[hash_key].begin();
        for (; iter != m_list[hash_key].end(); ++iter) {
            if (iter->key == key) {
                m_list[hash_key].erase(iter);
                break;
            }
        }

        if (iter == m_list[hash_key].end()) {
            return false;
        }

        if (m_list[hash_key].empty()) {
            m_load_num--;
        }

        return true;
    }

    bool search(const K_T key) const {
        if (!load(key)) {
            return false;
        }

        size_t hash_key = make_hash_key(key);
        if (m_list[hash_key].empty()) {
            return false;
        }

        for (auto iter = m_list[hash_key].begin(); iter != m_list[hash_key].end(); ++iter) {
            if (iter->key == key) {
                return true;
            }
        }

        return false;
    }

    bool load(const K_T key) const {
        if (empty()) {
            return false;
        }

        size_t hash_key = make_hash_key(key);

        return !m_list[hash_key].empty();
    }

    size_t make_hash_key(const K_T key) const {
        return key % m_max_size;
    }

    float get_load_factor() const {
        return static_cast<float>(m_load_num) / static_cast<float>(m_max_size);
    }

    void clear() {
        if (empty()) {
            return;
        }

        for (size_t i = 0; i < m_max_size; ++i) {
            m_list[i].clear();
        }

        m_load_num = 0;
    }

    bool empty() const {
        return m_load_num == 0;
    }

    bool full() const {
        return get_load_factor() >= m_load_threshold;
    }

    void traverse() const {
        if (!empty()) {
            for (size_t i = 0; i < m_max_size; ++i) {
                std::cout << "------ hash_key = " << i << " ------" << std::endl;
                for (auto iter = m_list[i].begin(); iter != m_list[i].end(); ++iter) {
                    std::cout << *iter << std::endl;
                }
            }
        }
    }

private:
    std::list<hash_node<K_T, V_T>> *m_list;
    const size_t m_max_size;
    size_t m_load_num;
    const float m_load_threshold;
};

#endif  // __DATA_STRUCTURE_HASH_MAP_LIST_H__
