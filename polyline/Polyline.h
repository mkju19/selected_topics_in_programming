#include <string>
#include <memory>
#include "vector"

#ifndef POLYLINE_POLYLINE_H
#define POLYLINE_POLYLINE_H

struct Point {
    int x;
    int y;
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

class Polyline {
//    std::vector<Point> points;
    std::shared_ptr<std::vector<Point>> m_points;

public:
    auto get_points(){return *m_points;}

    Polyline():m_points(std::make_shared<std::vector<Point>>()){}
    explicit Polyline(const std::vector<Point> &points) : m_points(std::make_shared<std::vector<Point>>(points)){}
    Polyline& operator+=(const Point& p);

    Polyline& operator=(const Polyline &p);
};


#endif //POLYLINE_POLYLINE_H
