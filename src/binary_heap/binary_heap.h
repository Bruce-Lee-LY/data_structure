// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 22:47:16 on Tue, May 24, 2022
//
// Description: binary heap

#ifndef __DATA_STRUCTURE_BINARY_HEAP_H__
#define __DATA_STRUCTURE_BINARY_HEAP_H__

#include <iostream>

template <typename T>
class binary_heap {
public:
    binary_heap(const size_t max_size) : m_max_size(max_size), m_elem_num(0) {
        m_ptr = new T[m_max_size];
    }

    ~binary_heap() {
        if (m_ptr) {
            delete[] m_ptr;
            m_ptr = nullptr;
        }
    }

    bool push_big_top(const T elem) {
        if (full()) {
            return false;
        }

        m_elem_num++;
        m_ptr[m_elem_num - 1] = elem;

        heapify_max_bottom_to_up(m_elem_num - 1);

        return true;
    }

    bool push_small_top(const T elem) {
        if (full()) {
            return false;
        }

        m_elem_num++;
        m_ptr[m_elem_num - 1] = elem;

        heapify_min_bottom_to_up(m_elem_num - 1);

        return true;
    }

    bool pop_big_top() {
        if (empty()) {
            return false;
        }

        swap(m_ptr[0], m_ptr[m_elem_num - 1]);
        m_elem_num--;

        heapify_max_up_to_bottom(0, m_elem_num - 1);

        m_elem_num--;
        return true;
    }

    bool pop_small_top() {
        if (empty()) {
            return false;
        }

        swap(m_ptr[0], m_ptr[m_elem_num - 1]);
        m_elem_num--;

        heapify_min_up_to_bottom(0, m_elem_num - 1);

        m_elem_num--;
        return true;
    }

    bool search(const T elem) const {
        if (empty()) {
            return false;
        }

        for (size_t i = 0; i < m_max_size; ++i) {
            if (m_ptr[i] == elem) {
                return true;
            }
        }

        return false;
    }

    void sort_ascend() {
        for (int i = static_cast<int>(m_max_size) / 2; i >= 0; --i) {
            heapify_max_up_to_bottom(i, m_max_size);
        }

        for (int j = static_cast<int>(m_max_size) - 1; j > 0; --j) {
            swap(m_ptr[0], m_ptr[j]);
            heapify_max_up_to_bottom(0, j);
        }
    }

    void sort_descend() {
        for (int i = static_cast<int>(m_max_size) / 2; i >= 0; --i) {
            heapify_min_up_to_bottom(i, m_max_size);
        }

        for (int j = static_cast<int>(m_max_size) - 1; j > 0; --j) {
            swap(m_ptr[0], m_ptr[j]);
            heapify_min_up_to_bottom(0, j);
        }
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
            for (size_t i = 0; i < m_max_size; ++i) {
                std::cout << m_ptr[i] << std::endl;
            }
        }
    }

private:
    void swap(T &elem1, T &elem2) {
        T tmp = elem1;
        elem1 = elem2;
        elem2 = tmp;
    }

    void heapify_max_bottom_to_up(size_t idx) {
        size_t child = idx;
        size_t parent = 0;
        while (child > 0) {
            parent = (child - 1) / 2;
            if (m_ptr[parent] < m_ptr[child]) {
                swap(m_ptr[parent], m_ptr[child]);
            } else {
                break;
            }
            child = parent;
        }
    }

    void heapify_min_bottom_to_up(size_t idx) {
        size_t child = idx;
        size_t parent = 0;
        while (child > 0) {
            parent = (child - 1) / 2;
            if (m_ptr[parent] > m_ptr[child]) {
                swap(m_ptr[parent], m_ptr[child]);
            } else {
                break;
            }
            child = parent;
        }
    }

    void heapify_max_up_to_bottom(size_t idx, size_t len) {
        size_t left = 2 * idx + 1;
        size_t right = 2 * idx + 2;
        size_t tmp_max = idx;
        if (left < len && m_ptr[left] > m_ptr[tmp_max]) {
            tmp_max = left;
        }

        if (right < len && m_ptr[right] > m_ptr[tmp_max]) {
            tmp_max = right;
        }

        if (tmp_max != idx) {
            swap(m_ptr[tmp_max], m_ptr[idx]);
            heapify_max_up_to_bottom(tmp_max, len);
        }
    }

    void heapify_min_up_to_bottom(size_t idx, size_t len) {
        size_t left = 2 * idx + 1;
        size_t right = 2 * idx + 2;
        size_t tmp_max = idx;
        if (left < len && m_ptr[left] < m_ptr[tmp_max]) {
            tmp_max = left;
        }

        if (right < len && m_ptr[right] < m_ptr[tmp_max]) {
            tmp_max = right;
        }

        if (tmp_max != idx) {
            swap(m_ptr[tmp_max], m_ptr[idx]);
            heapify_min_up_to_bottom(tmp_max, len);
        }
    }

    T *m_ptr;
    const size_t m_max_size;
    size_t m_elem_num;
};

#endif  // __DATA_STRUCTURE_BINARY_HEAP_H__
