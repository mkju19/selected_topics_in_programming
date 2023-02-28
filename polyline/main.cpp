#include <iostream>
#include "Polyline.h"


template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v);

int main() {
    std::vector<Point> p {
        {1,2},
        {1,2}
    };
    Polyline pl {p};

    pl += {1,3};

    std::cout << pl.get_points() << "\n\n";

    Polyline pl2 {};
    pl2 = pl;

    pl2 += {1,4};

    std::cout << pl2.get_points() << "\n\n";
    std::cout << pl.get_points() << "\n";
    return 0;

}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v){
    os << "[";
    for ( int i = 0; i < v.size(); i++) {
        if (i != v.size() - 1)
            os << v[i] << ", ";
        else
            os << v[i];
    }
    os << "]";
    return os;
}