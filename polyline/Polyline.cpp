#include <iostream>
#include "Polyline.h"

Polyline& Polyline::operator+=(const Point &p){
    if(m_points.use_count() > 1){
        std::cout << "Performed copy-on-write\n";
        m_points = std::make_shared<std::vector<Point>>(*m_points);
    }
    m_points->push_back(p);
    return *this;
}

Polyline& Polyline::operator=(const Polyline &p) {
    if (this == &p)
        return *this;
    m_points = p.m_points;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Point& p){
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}
