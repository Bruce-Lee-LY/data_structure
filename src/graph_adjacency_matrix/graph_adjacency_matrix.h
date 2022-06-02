// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 22:53:53 on Tue, May 24, 2022
//
// Description: graph adjacency matrix

#ifndef __DATA_STRUCTURE_GRAPH_ADJACENCY_MATRIX_H__
#define __DATA_STRUCTURE_GRAPH_ADJACENCY_MATRIX_H__

#include <cstring>
#include <iostream>
#include <vector>

#include "graph_edge.h"
#include "graph_vertex.h"

template <typename M_E_T, typename V_T>
class graph_adjacency_matrix {
public:
    graph_adjacency_matrix(const size_t max_size) : m_max_size(max_size), m_vertex_num(0), m_edge_num(0) {
        m_matrix_ptr = new M_E_T[m_max_size * m_max_size];
        memset((void *)m_matrix_ptr, 0x00, m_max_size * m_max_size * sizeof(M_E_T));
        m_vertex_ptr = new graph_vertex<V_T>[m_max_size];
        m_edge_ptr = new graph_edge<M_E_T>[m_max_size - 1];
    }

    ~graph_adjacency_matrix() {
        if (m_matrix_ptr) {
            delete[] m_matrix_ptr;
            m_matrix_ptr = nullptr;
        }

        if (m_vertex_ptr) {
            delete[] m_vertex_ptr;
            m_vertex_ptr = nullptr;
        }

        if (m_edge_ptr) {
            delete[] m_edge_ptr;
            m_edge_ptr = nullptr;
        }
    }

    bool set_directed_matrix_val(const size_t row, const size_t col, const M_E_T val = 1) {
        if (row >= m_max_size || col >= m_max_size) {
            return false;
        }

        m_matrix_ptr[m_max_size * row + col] = val;
        return true;
    }

    bool set_undirected_matrix_val(const size_t row, const size_t col, const M_E_T val = 1) {
        if (row >= m_max_size || col >= m_max_size) {
            return false;
        }

        m_matrix_ptr[m_max_size * row + col] = val;
        m_matrix_ptr[m_max_size * col + row] = val;
        return true;
    }

    void traverse_matrix() const {
        for (size_t i = 0; i < m_max_size; ++i) {
            for (size_t j = 0; j < m_max_size; ++j) {
                std::cout << m_matrix_ptr[m_max_size * i + j] << " ";
            }
            std::cout << std::endl;
        }
    }

    bool add_vertex(const graph_vertex<V_T> vertex) {
        if (vertex_full()) {
            return false;
        }

        m_vertex_ptr[m_vertex_num].data = vertex.data;
        m_vertex_num++;
        return true;
    }

    bool erase_vertex(graph_vertex<V_T> &vertex) {
        if (vertex_empty()) {
            return false;
        }

        vertex.data = m_vertex_ptr[m_vertex_num].data;
        m_vertex_num--;
        return true;
    }

    bool vertex_full() const {
        return m_vertex_num >= m_max_size;
    }

    bool vertex_empty() const {
        return m_vertex_num == 0;
    }

    void reset_vertex() {
        if (vertex_empty()) {
            return;
        }

        for (size_t i = 0; i < m_max_size; ++i) {
            m_vertex_ptr[i].visited = false;
        }
    }

    void traverse_vertex_depth(const size_t idx) {
        if (idx >= m_vertex_num || vertex_empty()) {
            return;
        }

        std::cout << m_vertex_ptr[idx].data << std::endl;
        m_vertex_ptr[idx].visited = true;

        M_E_T val_tmp = 0;
        for (size_t i = 0; i < m_vertex_num; ++i) {
            get_matrix_val(idx, i, val_tmp);
            if (val_tmp != 0) {
                if (!m_vertex_ptr[i].visited) {
                    traverse_vertex_depth(i);
                }
            }
        }
    }

    void traverse_vertex_breadth(const size_t idx) {
        if (idx >= m_vertex_num || vertex_empty()) {
            return;
        }

        std::cout << m_vertex_ptr[idx].data << std::endl;
        m_vertex_ptr[idx].visited = true;

        std::vector<size_t> idxs;
        idxs.push_back(idx);

        traverse_vertex_breadth_impl(idxs);
    }

    void prim_min_span_tree(const size_t vertex_idx) {
        if (vertex_idx >= m_vertex_num || vertex_empty()) {
            return;
        }

        m_edge_num = 0;

        std::vector<size_t> vertex_idxs;
        size_t head_idx = 0;
        size_t tail_idx = 0;

        M_E_T val_tmp = 0;

        std::vector<graph_edge<M_E_T>> edges;
        size_t min_edge_idx = 0;

        vertex_idxs.push_back(vertex_idx);
        m_vertex_ptr[vertex_idx].visited = true;
        std::cout << m_vertex_ptr[vertex_idx].data << std::endl;

        while (m_edge_num < m_vertex_num - 1) {
            head_idx = vertex_idxs.back();
            for (size_t i = 0; i < m_max_size; ++i) {
                get_matrix_val(head_idx, i, val_tmp);
                if (val_tmp != 0) {
                    if (!m_vertex_ptr[i].visited) {
                        edges.push_back(graph_edge<M_E_T>(head_idx, i, val_tmp));
                    }
                }
            }

            if (get_min_edge(edges, min_edge_idx)) {
                edges[min_edge_idx].selected = true;
                std::cout << edges[min_edge_idx].head_idx << " -> " << edges[min_edge_idx].tail_idx << ", "
                          << edges[min_edge_idx].data << std::endl;

                m_edge_ptr[m_edge_num] = edges[min_edge_idx];
                m_edge_num++;

                tail_idx = edges[min_edge_idx].tail_idx;
                vertex_idxs.push_back(tail_idx);
                m_vertex_ptr[tail_idx].visited = true;
                std::cout << m_vertex_ptr[tail_idx].data << std::endl;
            }
        }
    }

    void kruskal_min_span_tree() {
        if (vertex_empty()) {
            return;
        }

        m_edge_num = 0;

        M_E_T val_tmp = 0;
        std::vector<graph_edge<M_E_T>> edges;
        for (size_t i = 0; i < m_max_size; ++i) {
            for (size_t j = i + 1; j < m_max_size; ++j) {
                get_matrix_val(i, j, val_tmp);
                if (val_tmp != 0) {
                    edges.push_back(graph_edge<M_E_T>(i, j, val_tmp));
                }
            }
        }

        std::vector<std::vector<size_t>> idxs_set;
        size_t min_edge_idx = 0;
        size_t head_idx = 0;
        size_t tail_idx = 0;
        bool head_in_set = false;
        bool tail_in_set = false;

        while (m_edge_num < m_vertex_num - 1) {
            if (get_min_edge(edges, min_edge_idx)) {
                edges[min_edge_idx].selected = true;
                head_idx = edges[min_edge_idx].head_idx;
                tail_idx = edges[min_edge_idx].tail_idx;

                int head_set_idx = -1;
                int tail_set_idx = -1;
                for (size_t i = 0; i < idxs_set.size(); ++i) {
                    head_in_set = find_in_set(idxs_set[i], head_idx);
                    if (head_in_set) {
                        head_set_idx = static_cast<int>(i);
                    }

                    tail_in_set = find_in_set(idxs_set[i], tail_idx);
                    if (tail_in_set) {
                        tail_set_idx = static_cast<int>(i);
                    }
                }

                if (head_set_idx == -1 && tail_set_idx == -1) {
                    std::vector<size_t> idxs_tmp;
                    idxs_tmp.push_back(head_idx);
                    idxs_tmp.push_back(tail_idx);
                    idxs_set.push_back(idxs_tmp);
                } else if (head_set_idx != -1 && tail_set_idx == -1) {
                    idxs_set[head_set_idx].push_back(tail_idx);
                } else if (head_set_idx == -1 && tail_set_idx != -1) {
                    idxs_set[tail_set_idx].push_back(head_idx);
                } else if (head_set_idx != -1 && tail_set_idx != -1 && head_set_idx != tail_set_idx) {
                    merge_idx_set(idxs_set[head_set_idx], idxs_set[tail_set_idx]);

                    int set_idx = 0;
                    for (auto iter = idxs_set.begin(); iter != idxs_set.end(); ++set_idx) {
                        if (set_idx == tail_set_idx) {
                            idxs_set.erase(iter);
                        } else {
                            iter++;
                        }
                    }
                } else if (head_set_idx != -1 && tail_set_idx != -1 && head_set_idx == tail_set_idx) {
                    continue;
                }

                m_edge_ptr[m_edge_num] = edges[min_edge_idx];
                m_edge_num++;

                std::cout << edges[min_edge_idx].head_idx << " -> " << edges[min_edge_idx].tail_idx << ", "
                          << edges[min_edge_idx].data << std::endl;
            }
        }
    }

    void reset_edge() {
        if (vertex_empty()) {
            return;
        }

        for (size_t i = 0; i < m_max_size - 1; ++i) {
            m_edge_ptr[i].selected = false;
        }
    }

private:
    bool get_matrix_val(const size_t row, const size_t col, M_E_T &val) const {
        if (row >= m_max_size || col >= m_max_size) {
            return false;
        }

        val = m_matrix_ptr[m_max_size * row + col];
        return true;
    }

    void traverse_vertex_breadth_impl(const std::vector<size_t> idxs) {
        std::vector<size_t> next_idxs;
        M_E_T val_tmp = 0;
        for (size_t i = 0; i < idxs.size(); ++i) {
            for (size_t j = 0; j < m_vertex_num; ++j) {
                get_matrix_val(idxs[i], j, val_tmp);
                if (val_tmp != 0) {
                    if (!m_vertex_ptr[j].visited) {
                        std::cout << m_vertex_ptr[j].data << std::endl;
                        m_vertex_ptr[j].visited = true;

                        next_idxs.push_back(j);
                    }
                }
            }
        }

        if (next_idxs.size()) {
            traverse_vertex_breadth_impl(next_idxs);
        }
    }

    bool get_min_edge(const std::vector<graph_edge<M_E_T>> edges, size_t &edge_idx) const {
        M_E_T min_data = 0;
        size_t i = 0;
        for (; i < edges.size(); ++i) {
            if (!edges[i].selected) {
                min_data = edges[i].data;
                edge_idx = i;
                break;
            }
        }

        if (min_data == 0) {
            return false;
        }

        for (; i < edges.size(); ++i) {
            if (!edges[i].selected) {
                if (min_data > edges[i].data) {
                    min_data = edges[i].data;
                    edge_idx = i;
                }
            }
        }

        return true;
    }

    bool find_in_set(std::vector<size_t> idxs, size_t idx) const {
        for (size_t i = 0; i < idx; ++i) {
            if (idxs[i] == idx) {
                return true;
            }
        }

        return false;
    }

    void merge_idx_set(std::vector<size_t> &idxs, std::vector<size_t> merge_idxs) {
        for (size_t i = 0; i < merge_idxs.size(); ++i) {
            idxs.push_back(merge_idxs[i]);
        }
    }

    const size_t m_max_size;
    M_E_T *m_matrix_ptr;

    graph_vertex<V_T> *m_vertex_ptr;
    size_t m_vertex_num;

    graph_edge<M_E_T> *m_edge_ptr;
    size_t m_edge_num;
};

#endif  // __DATA_STRUCTURE_GRAPH_ADJACENCY_MATRIX_H__
