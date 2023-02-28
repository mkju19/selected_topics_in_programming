#include <iostream>
#include <chrono>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;
using namespace std::chrono;

void swap_ends(int arr[], int size);
void swap_ends(vector<int>& arr);
void swap_ends_mem(int arr[], int size);
void printArr(int arr[], int size);
vector<int> sortCpy(vector<int>& arr);
int* sortCpy(const int arr[], int size);

int main(){
    // do some warm up work here
    cout << "hello \n";
    constexpr int arrSize = 100000;
    int cArr[arrSize] = {0};
    std::vector<int> vec(arrSize, 2);

    static int staticArr[arrSize] = {0};
    static std::vector<int> staticVec(arrSize, 2);

    auto t0 = high_resolution_clock::now();
    swap_ends(cArr, arrSize);
    auto t1 = high_resolution_clock::now();
    std::cout << "Stack allocated array: " << duration<double, std::milli>(t1-t0).count() << "ms\n";

    auto t2 = high_resolution_clock::now();
    swap_ends(vec);
    auto t3 = high_resolution_clock::now();
    std::cout << "stack allocated vector: " << duration<double, std::milli>(t3-t2).count() << "ms\n";

    auto t4 = high_resolution_clock::now();
    swap_ends(staticArr, arrSize);
    auto t5 = high_resolution_clock::now();
    std::cout << "Static c array: " << duration<double, std::milli>(t5-t4).count() << "ms\n";

    auto t6 = high_resolution_clock::now();
    swap_ends(staticVec);
    auto t7 = high_resolution_clock::now();
    std::cout << "Static vector: " << duration<double, std::milli>(t7-t6).count() << "ms\n";



    auto t8 = high_resolution_clock::now();
    swap_ends_mem(cArr, arrSize);
    auto t9 = high_resolution_clock::now();
    std::cout << "dynamic array with memcpy: " << duration<double, std::milli>(t9-t8).count() << "ms\n";

    auto t10 = high_resolution_clock::now();
    swap_ends_mem(staticArr, arrSize);
    auto t11 = high_resolution_clock::now();
    std::cout << "Static array with memcpy: " << duration<double, std::milli>(t11-t10).count() << "ms\n";


    vector<int> intVec = {1, 2, 3, 5, 2, 4};
    for (auto i : intVec) cout << i ;
    cout << "\n";
    vector<int> res = sortCpy(intVec);

    for (auto i : res) cout << i;
    cout << "\n";
    int intArr[] = {1,2,4,6,3,2,5};
    int length = 7;
    cout << "length: " << length << "\n";

    for (auto i : intArr) cout << i;
    cout << "\n";

    int * res2 = sortCpy(intArr, length);

    for (int i = 0; i < length; i++) cout << res2[i];

}

//void timeTest(char* message, function do_work){
//    auto t0 = high_resolution_clock::now();
//    do_work();
//    auto t1 = high_resolution_clock::now();
//    std::cout << duration<double, std::milli>(t1-t0).count() << "ms\n";
//}

void swap_ends(int arr[], int size) {
    for (int i = size/2 - 1, j = size - 1; i >= 0; --i, --j)
        swap(arr[i], arr[j]);
}

void swap_ends(vector<int>& arr) { // overloading the same fn-name
    for (int i = arr.size()/2 - 1, j = arr.size() - 1; i >= 0; --i, --j)
        swap(arr[i], arr[j]);
}

void swap_ends_mem(int arr[], int size) {
    int half = size/2;
    int buf[half];

    memcpy(buf, arr, sizeof buf);
    memcpy(arr, &arr[half], sizeof buf);
    memcpy(&arr[half], buf, sizeof buf);
}

vector<int> sortCpy(vector<int>& arr){
    vector<int> dest = *new vector<int>();
    copy(arr.begin(), arr.end(), back_inserter(dest));
    std::sort(dest.begin(), dest.end());
    return dest;
}

int* sortCpy(const int arr[], int size){
    int *dest = new int[size];
    for (int i = 0; i < size; ++i) {
        dest[i] = arr[i];
    }
    std::sort(dest, dest + size);
    return dest;
}

void printArr(int arr[], int size){
    cout << "[";
    for (int i = 0 ; i < size; i++)
        cout << arr[i] << ", ";
    cout << "] \n";
}