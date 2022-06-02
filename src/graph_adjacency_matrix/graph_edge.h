// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 22:54:23 on Tue, May 24, 2022
//
// Description: graph edge

#ifndef __DATA_STRUCTURE_GRAPH_EDGE_H__
#define __DATA_STRUCTURE_GRAPH_EDGE_H__

template <typename T>
class graph_edge {
public:
    graph_edge(const size_t in_head_idx = 0, const size_t in_tail_idx = 0, const T in_data = 0) : selected(false) {
        this->head_idx = in_head_idx;
        this->tail_idx = in_tail_idx;
        this->data = in_data;
    }

    ~graph_edge() = default;

    size_t head_idx;
    size_t tail_idx;
    T data;
    bool selected;
};

#endif  // __DATA_STRUCTURE_GRAPH_EDGE_H__
