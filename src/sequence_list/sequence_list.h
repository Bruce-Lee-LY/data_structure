// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 22:59:55 on Tue, May 24, 2022
//
// Description: sequence list

#ifndef __DATA_STRUCTURE_SEQUENCE_LIST_H__
#define __DATA_STRUCTURE_SEQUENCE_LIST_H__

#include <iostream>

template <typename T>
class sequence_list {
public:
    sequence_list(const size_t max_size) : m_max_size(max_size), m_elem_num(0) {
        m_ptr = new T[m_max_size];
    }

    ~sequence_list() {
        if (m_ptr) {
            delete[] m_ptr;
            m_ptr = nullptr;
        }
    }

    bool insert(const T elem, const size_t idx) {
        if (idx > m_elem_num || full()) {
            return false;
        }

        if (!empty()) {
            for (size_t i = m_elem_num - 1; i >= idx; ++i) {
                m_ptr[i + 1] = m_ptr[i];
            }
        }

        m_ptr[idx] = elem;
        m_elem_num++;
        return true;
    }

    bool erase(const size_t idx, T &elem) {
        if (idx >= m_elem_num || empty()) {
            return false;
        }

        elem = m_ptr[idx];
        for (size_t i = idx + 1; i < m_elem_num; ++i) {
            m_ptr[i - 1] = m_ptr[i];
        }

        m_elem_num--;
        return true;
    }

    bool get(const size_t idx, T &elem) const {
        if (idx >= m_elem_num || empty()) {
            return false;
        }

        elem = m_ptr[idx];
        return true;
    }

    bool find(const T elem, size_t &idx) const {
        if (empty()) {
            return false;
        }

        for (size_t i = 0; i < m_elem_num; ++i) {
            if (m_ptr[i] == elem) {
                idx = i;
                return true;
            }
        }

        return false;
    }

    bool prior(const T elem, T &prior_elem) const {
        size_t idx = 0;
        if (!find(elem, idx) || !idx) {
            return false;
        }

        prior_elem = m_ptr[--idx];
        return true;
    }

    bool next(const T elem, T &next_elem) const {
        size_t idx = 0;
        if (!find(elem, idx) || idx == m_elem_num - 1) {
            return false;
        }

        next_elem = m_ptr[++idx];
        return true;
    }

    void clear() {
        m_elem_num = 0;
    }

    size_t size() const {
        return m_elem_num;
    }

    bool empty() const {
        return m_elem_num == 0;
    }

    bool full() const {
        return m_elem_num >= m_max_size;
    }

    void traverse() const {
        if (!empty()) {
            for (size_t i = 0; i < m_elem_num; ++i) {
                std::cout << m_ptr[i] << std::endl;
            }
        }
    }

private:
    T *m_ptr;
    const size_t m_max_size;
    size_t m_elem_num;
};

#endif  // __DATA_STRUCTURE_SEQUENCE_LIST_H__
