// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 22:48:54 on Tue, May 24, 2022
//
// Description: binary tree array

#ifndef __DATA_STRUCTURE_BINARY_TREE_ARRAY_H__
#define __DATA_STRUCTURE_BINARY_TREE_ARRAY_H__

#include <iostream>

template <typename T>
class binary_tree_array {
public:
    binary_tree_array(const size_t max_size, const T root) : m_max_size(max_size), m_elem_num(1) {
        m_ptr = new T[m_max_size];
        m_ptr[0] = root;
        for (size_t i = 1; i < m_max_size; ++i) {
            m_ptr[i] = 0;
        }
    }

    ~binary_tree_array() {
        if (m_ptr) {
            delete[] m_ptr;
            m_ptr = nullptr;
        }
    }

    bool insert(const size_t idx, const T elem, const bool left_child) {
        if (idx >= m_max_size || elem == 0 || m_ptr[idx] == 0) {
            return false;
        }

        size_t child_idx = 0;
        if (left_child) {
            child_idx = idx * 2 + 1;
        } else {
            child_idx = idx * 2 + 2;
        }

        if (child_idx >= m_max_size || m_ptr[child_idx] != 0) {
            return false;
        }

        m_ptr[child_idx] = elem;
        m_elem_num++;
        return true;
    }

    bool erase(const size_t idx, T &elem) {
        if (idx >= m_max_size || empty() || m_ptr[idx] == 0) {
            return false;
        }

        elem = m_ptr[idx];
        m_ptr[idx] = 0;
        m_elem_num--;
        return true;
    }

    bool get(const size_t idx, T &elem) const {
        if (idx >= m_max_size || empty() || m_ptr[idx] == 0) {
            return false;
        }

        elem = m_ptr[idx];
        return true;
    }

    bool find(const T elem, size_t &idx) const {
        if (elem == 0 || empty()) {
            return false;
        }

        for (size_t i = 0; i < m_max_size; ++i) {
            if (m_ptr[i] == elem) {
                idx = i;
                return true;
            }
        }

        return false;
    }

    void clear() {
        if (empty()) {
            return;
        }

        for (size_t i = 1; i < m_max_size; ++i) {
            m_ptr[i] = 0;
        }

        m_elem_num = 1;
    }

    size_t size() const {
        return m_elem_num;
    }

    bool empty() const {
        return m_elem_num == 0;
    }

    void traverse() const {
        for (size_t i = 0; i < m_max_size; ++i) {
            std::cout << m_ptr[i] << std::endl;
        }
    }

private:
    T *m_ptr;
    const size_t m_max_size;
    size_t m_elem_num;
};

#endif  // __DATA_STRUCTURE_BINARY_TREE_ARRAY_H__
