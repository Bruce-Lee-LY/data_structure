// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 22:54:55 on Tue, May 24, 2022
//
// Description: graph vertex

#ifndef __DATA_STRUCTURE_GRAPH_VERTEX_H__
#define __DATA_STRUCTURE_GRAPH_VERTEX_H__

template <typename T>
class graph_vertex {
public:
    graph_vertex(const T in_data = 0) : visited(false) {
        this->data = in_data;
    }

    ~graph_vertex() = default;

    T data;
    bool visited;
};

#endif  // __DATA_STRUCTURE_GRAPH_VERTEX_H__
