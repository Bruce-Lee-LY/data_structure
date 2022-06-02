// Copyright 2022. All Rights Reserved.
// Author: Bruce-Lee-LY
// Date: 22:51:45 on Tue, May 24, 2022
//
// Description: coordinate

#ifndef __DATA_STRUCTURE_COORDINATE_H__
#define __DATA_STRUCTURE_COORDINATE_H__

#include <ostream>

class coordinate {
    friend std::ostream &operator<<(std::ostream &out, const coordinate &coor) {
        out << "(" << coor.m_x << ", " << coor.m_y << ")";
        return out;
    }

public:
    coordinate(const int x = 0, const int y = 0) {
        m_x = x;
        m_y = y;
    }

    ~coordinate() = default;

    coordinate &operator=(const coordinate &coor) {
        m_x = coor.m_x;
        m_y = coor.m_y;

        return *this;
    }

    coordinate &operator=(const int &value) {
        m_x = value;
        m_y = value;

        return *this;
    }

    bool operator==(const coordinate &coor) const {
        return m_x == coor.m_x && m_y == coor.m_y;
    }

    bool operator==(const int &value) const {
        return m_x == value && m_y == value;
    }

    bool operator!=(const coordinate &coor) const {
        return m_x != coor.m_x || m_y != coor.m_y;
    }

    bool operator!=(const int &value) const {
        return m_x != value || m_y != value;
    }

    bool operator>(const coordinate &coor) const {
        return m_x + m_y > coor.m_x + coor.m_y;
    }

    bool operator>(const int &value) const {
        return m_x + m_y > value;
    }

    bool operator>=(const coordinate &coor) const {
        return m_x + m_y >= coor.m_x + coor.m_y;
    }

    bool operator>=(const int &value) const {
        return m_x + m_y >= value;
    }

    bool operator<(const coordinate &coor) const {
        return m_x + m_y < coor.m_x + coor.m_y;
    }

    bool operator<(const int &value) const {
        return m_x + m_y < value;
    }

    bool operator<=(const coordinate &coor) const {
        return m_x + m_y <= coor.m_x + coor.m_y;
    }

    bool operator<=(const int &value) const {
        return m_x + m_y <= value;
    }

private:
    int m_x;
    int m_y;
};

#endif  // __DATA_STRUCTURE_COORDINATE_H__
