#include <iostream>
#include <memory>
#include <vector>
#include <chrono>
#include <functional>
#include "base.h"
#include "Derived.h"

using namespace std::chrono;
void measure(const std::string &message, std::function<void()> const &func);

int main() {
    unsigned long size = 10'000'000;
    std::vector<std::unique_ptr<base>> vec{size};
    std::vector<Derived> derived_vec {size};

    for (auto i = 0; i < size; i++)
        vec[i] = std::make_unique<Derived>();

    std::cout << derived_vec[1].i << "\n";

    measure("Calling increment on all elements of the smart pointer vector", [&vec,&size]() {
        for (int i = 0; i < size; i++)
            vec[i]->increment();
    });

    measure("Calling decrement on all elements of the smart pointer vector", [&vec,&size]() {
        for (int i = 0; i < size; i++)
            vec[i]->decrement();
    });

    measure("Calling increment on all elements of the vector", [&derived_vec,&size]() {
        for (int i = 0; i < size; i++)
            derived_vec[i].increment();
    });

    measure("Calling decrement on all elements of the vector", [&derived_vec,&size]() {
        for (int i = 0; i < size; i++)
            derived_vec[i].decrement();
    });

    return 0;
}

void measure(const std::string &message, std::function<void()> const &func){
    auto t0 = high_resolution_clock::now();
    func();
    auto t1 = high_resolution_clock::now();
    std::cout << message << ": " << duration<double, std::milli>(t1-t0).count() << "ms\n";
}
