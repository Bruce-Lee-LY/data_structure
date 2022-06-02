// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 22:59:08 on Tue, May 24, 2022
//
// Description: ring queue

#ifndef __DATA_STRUCTURE_RING_QUEUE_H__
#define __DATA_STRUCTURE_RING_QUEUE_H__

#include <iostream>

template <typename T>
class ring_queue {
public:
    ring_queue(const size_t max_size) : m_max_size(max_size), m_elem_num(0), m_head(0), m_tail(0) {
        m_ptr = new T[m_max_size];
    }

    ~ring_queue() {
        if (m_ptr) {
            delete[] m_ptr;
            m_ptr = nullptr;
        }
    }

    bool enqueue(const T elem) {
        if (full()) {
            return false;
        }

        m_ptr[m_tail] = elem;
        m_tail++;
        m_tail %= m_max_size;
        m_elem_num++;

        return true;
    }

    bool dequeue(T &elem) {
        if (empty()) {
            return false;
        }

        elem = m_ptr[m_head];
        m_head++;
        m_head %= m_max_size;
        m_elem_num--;

        return true;
    }

    void clear() {
        m_elem_num = 0;
        m_head = 0;
        m_tail = 0;
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

    bool find(const T elem) const {
        if (empty()) {
            return false;
        }

        for (size_t i = m_head; i < m_head + m_elem_num; ++i) {
            if (m_ptr[i % m_max_size] == elem) {
                return true;
            }
        }

        return false;
    }

    void traverse() const {
        if (!empty()) {
            for (size_t i = m_head; i < m_head + m_elem_num; ++i) {
                std::cout << m_ptr[i % m_max_size] << std::endl;
            }
        }
    }

private:
    T *m_ptr;
    const size_t m_max_size;
    size_t m_elem_num;
    size_t m_head;
    size_t m_tail;
};

#endif  // __DATA_STRUCTURE_RING_QUEUE_H__
