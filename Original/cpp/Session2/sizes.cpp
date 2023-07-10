#include "sizes.h"
#include <iostream>
#include <limits>

template <typename T> void printSizeLimit(std::string const &type);

void allSizes(){
    printSizeLimit<bool>("bool");
    printSizeLimit<char>("char");
    printSizeLimit<int>("int");
    printSizeLimit<long>("long");
    printSizeLimit<float>("float");
    printSizeLimit<double>("double");


}

template <typename T> void printSizeLimit(std::string const &type) {
    std::cout << "size of " << type << ": " << sizeof(T) << " byte(s) \n"
              << "range: ["
              << std::numeric_limits<T>::min() << ", "
              << std::numeric_limits<T>::max() << "]\n\n";
}

