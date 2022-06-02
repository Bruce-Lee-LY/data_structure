// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 23:01:03 on Tue, May 24, 2022
//
// Description: single list

#ifndef __DATA_STRUCTURE_SINGLE_LIST_H__
#define __DATA_STRUCTURE_SINGLE_LIST_H__

#include <iostream>

#include "list_node.h"

template <typename T>
class single_list {
public:
    single_list() : m_node_num(0) {
        m_head = new list_node<T>;
    }

    ~single_list() {
        clear();

        if (m_head) {
            delete m_head;
            m_head = nullptr;
        }
    }

    void push_back(const T data) {
        list_node<T> *curr = m_head;
        for (size_t i = 0; i < m_node_num; ++i) {
            curr = curr->next;
        }

        curr->next = new list_node<T>;
        curr->next->data = data;
        m_node_num++;
    }

    void push_front(const T data) {
        list_node<T> *first = m_head->next;
        m_head->next = new list_node<T>;
        m_head->next->data = data;
        m_head->next->next = first;
        m_node_num++;
    }

    T pop_back() {
        T data = 0;
        if (empty()) {
            return data;
        }

        list_node<T> *curr = m_head;
        list_node<T> *prior = nullptr;
        for (size_t i = 0; i < m_node_num; ++i) {
            prior = curr;
            curr = curr->next;
        }

        data = curr->data;
        prior->next = nullptr;
        delete curr;
        m_node_num--;

        return data;
    }

    T pop_front() {
        T data = 0;
        if (empty()) {
            return data;
        }

        list_node<T> *first = m_head->next;
        data = first->data;
        m_head->next = first->next;
        delete first;
        m_node_num--;

        return data;
    }

    bool insert(const list_node<T> node, const size_t idx) {
        if (idx > m_node_num) {
            return false;
        }

        list_node<T> *curr = m_head;
        for (size_t i = 0; i < idx; ++i) {
            curr = curr->next;
        }

        list_node<T> *tmp = new list_node<T>;
        tmp->data = node.data;
        tmp->next = curr->next;
        curr->next = tmp;

        m_node_num++;
        return true;
    }

    bool erase(const size_t idx, list_node<T> &node) {
        if (idx >= m_node_num || empty()) {
            return false;
        }

        list_node<T> *curr = m_head;
        list_node<T> *prior = nullptr;
        for (size_t i = 0; i <= idx; ++i) {
            prior = curr;
            curr = curr->next;
        }

        prior->next = curr->next;
        node.data = curr->data;
        delete curr;
        curr = nullptr;

        m_node_num--;
        return true;
    }

    bool erase(const size_t idx) {
        if (idx >= m_node_num || empty()) {
            return false;
        }

        list_node<T> *curr = m_head;
        list_node<T> *prior = nullptr;
        for (size_t i = 0; i <= idx; ++i) {
            prior = curr;
            curr = curr->next;
        }

        prior->next = curr->next;
        delete curr;
        curr = nullptr;

        m_node_num--;
        return true;
    }

    bool get(const size_t idx, list_node<T> &node) const {
        if (idx >= m_node_num || empty()) {
            return false;
        }

        list_node<T> *curr = m_head;
        for (size_t i = 0; i <= idx; ++i) {
            curr = curr->next;
        }

        node = *curr;
        return true;
    }

    bool get(const size_t idx, T &data) const {
        if (idx >= m_node_num || empty()) {
            return false;
        }

        list_node<T> *curr = m_head;
        for (size_t i = 0; i <= idx; ++i) {
            curr = curr->next;
        }

        data = curr->data;
        return true;
    }

    bool find(const list_node<T> node, size_t &idx) const {
        if (empty()) {
            return false;
        }

        list_node<T> *curr = m_head;
        for (size_t i = 0; i < m_node_num; ++i) {
            curr = curr->next;
            if (curr->data == node.data) {
                idx = i;
                return true;
            }
        }

        return false;
    }

    bool find(const T data, size_t &idx) const {
        if (empty()) {
            return false;
        }

        list_node<T> *curr = m_head;
        for (size_t i = 0; i < m_node_num; ++i) {
            curr = curr->next;
            if (curr->data == data) {
                idx = i;
                return true;
            }
        }

        return false;
    }

    bool find(const T data) const {
        if (empty()) {
            return false;
        }

        list_node<T> *curr = m_head;
        for (size_t i = 0; i < m_node_num; ++i) {
            curr = curr->next;
            if (curr->data == data) {
                return true;
            }
        }

        return false;
    }

    bool set(const size_t idx, const T data) {
        if (idx >= m_node_num || empty()) {
            return false;
        }

        list_node<T> *curr = m_head;
        for (size_t i = 0; i <= idx; ++i) {
            curr = curr->next;
        }

        curr->data = data;

        return true;
    }

    bool prior(const list_node<T> node, list_node<T> &prior_node) const {
        size_t idx = 0;
        if (!find(node, idx) || !idx) {
            return false;
        }

        list_node<T> *curr = m_head;
        list_node<T> *prior = nullptr;
        for (size_t i = 0; i < m_node_num; ++i) {
            prior = curr;
            curr = curr->next;
            if (curr->data == node.data) {
                prior_node.data = prior->data;
                return true;
            }
        }

        return false;
    }

    bool next(const list_node<T> node, list_node<T> &next_node) const {
        size_t idx = 0;
        if (!find(node, idx) || idx == m_node_num - 1) {
            return false;
        }

        list_node<T> *curr = m_head;
        for (size_t i = 0; i < m_node_num; ++i) {
            curr = curr->next;
            if (curr->data == node.data) {
                next_node.data = curr->next->data;
                return true;
            }
        }

        return false;
    }

    void clear() {
        if (empty()) {
            return;
        }

        list_node<T> *curr = m_head->next;
        list_node<T> *next = nullptr;
        while (curr) {
            next = curr->next;
            delete curr;
            curr = next;
        }

        m_head->next = nullptr;
        m_node_num = 0;
    }

    size_t size() const {
        return m_node_num;
    }

    bool empty() const {
        return m_node_num == 0;
    }

    void reverse() {
        if (empty()) {
            return;
        }

        list_node<T> *pre = nullptr;
        list_node<T> *curr = m_head->next;
        list_node<T> *next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }

        m_head->next = pre;
    }

    void traverse() const {
        if (!empty()) {
            list_node<T> *curr = m_head;
            for (size_t i = 0; i < m_node_num; ++i) {
                curr = curr->next;
                std::cout << curr->data << std::endl;
            }
        }
    }

private:
    list_node<T> *m_head;
    size_t m_node_num;
};

#endif  // __DATA_STRUCTURE_SINGLE_LIST_H__
