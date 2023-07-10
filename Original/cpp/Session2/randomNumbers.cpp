#include <iostream>
#include <random>
std::vector<int> genMt();

void generateNumbers(){
    std::vector<int> vals = genMt();
    for (auto v: vals)
        std::cout<< v << ", ";
}

std::vector<int> genMt(){
    auto mt = std::mt19937();
    int size = 10'000'000;
    std::vector<int> vals(size, 0);

    for (int i = 0; i < size; i++)
        vals[i] = (mt.operator()() % 1001) - 1;
//    for (auto v : vals)
//        std::cout<< v << "\n";
    return vals;
}