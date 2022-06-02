// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 22:52:28 on Tue, May 24, 2022
//
// Description: ds stack

#ifndef __DATA_STRUCTURE_DS_STACK_H__
#define __DATA_STRUCTURE_DS_STACK_H__

#include <iostream>

template <typename T>
class ds_stack {
public:
    ds_stack(const size_t max_size) : m_max_size(max_size), m_top(0) {
        m_ptr = new T[m_max_size];
    }

    ~ds_stack() {
        if (m_ptr) {
            delete[] m_ptr;
            m_ptr = nullptr;
        }
    }

    bool push(const T elem) {
        if (full()) {
            return false;
        }

        m_ptr[m_top] = elem;
        m_top++;

        return true;
    }

    bool pop(T &elem) {
        if (empty()) {
            return false;
        }

        m_top--;
        elem = m_ptr[m_top];

        return true;
    }

    void clear() {
        m_top = 0;
    }

    size_t size() const {
        return m_top;
    }

    bool empty() const {
        return m_top == 0;
    }

    bool full() const {
        return m_top == m_max_size;
    }

    bool find(const T elem) const {
        if (empty()) {
            return false;
        }

        for (size_t i = 0; i < m_top; ++i) {
            if (m_ptr[i] == elem) {
                return true;
            }
        }

        return false;
    }

    void traverse(bool bottom_to_top) const {
        if (!empty()) {
            if (bottom_to_top) {
                for (size_t i = 0; i < m_top; ++i) {
                    std::cout << m_ptr[i] << std::endl;
                }
            } else {
                size_t j = m_top;
                while (j) {
                    j--;
                    std::cout << m_ptr[j] << std::endl;
                }
            }
        }
    }

private:
    T *m_ptr;
    const size_t m_max_size;
    size_t m_top;
};

#endif  // __DATA_STRUCTURE_DS_STACK_H__
