#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <chrono>

using namespace std;
using namespace std::chrono;

int c_arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
vector<int>* pvec = new std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

const int runs = 10'000'000;

void swap_ends(int arr[], int size) {
    for (int i = size/2 - 1, j = size - 1; i >= 0; --i, --j)
        swap(arr[i], arr[j]);
}

void swap_ends(std::vector<int>& arr) {
    for (int i = arr.size()/2 - 1, j = arr.size() - 1; i >= 0; --i, --j)
        swap(arr[i], arr[j]);
}

void printVecs(vector<int>& vec, vector<int>* pvec){
    for (auto i : c_arr) cout << i << " ";
    cout << endl;

    for (auto i : vec) cout << i << " ";
    cout << endl;

    for (auto i : *pvec) cout << i << " ";
    cout << endl;
}


void do_work(){
    for (int i = 0; i < runs; ++i) {
        swap_ends(c_arr, sizeof(c_arr)/sizeof(int));
    }
}

void do_work(vector<int>& vec){
    for (int i = 0; i < runs; ++i) {
        swap_ends(vec);
    }
}

void getTime(std::string str){
    auto t0 = high_resolution_clock::now();
    do_work();
    auto t1 = high_resolution_clock::now();
    std::cout << str << duration<double, std::milli>(t1-t0).count() << "ms\n";
}

void getTime(std::string str, vector<int>& vec){
    auto t0 = high_resolution_clock::now();
    do_work(vec);
    auto t1 = high_resolution_clock::now();
    std::cout << str << duration<double, std::milli>(t1-t0).count() << "ms\n";
}

int main(){
    // do some warm up work here
    do_work();

    getTime("C array: ");
    getTime("vector: ", vec);

    return 0;
}