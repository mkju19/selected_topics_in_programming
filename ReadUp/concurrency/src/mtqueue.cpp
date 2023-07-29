#include "mtqueue.hpp"
#include "iostream"

void produce(mtqueue<int>&)
{
	// TODO: create producer routine: put random numbers into queue
}

void consume(mtqueue<int>&)
{
	// TODO: create consumer routine: fetch and print values
}

int main(){

    auto q = mtqueue<int>{};
    std::cout << "is empty: " << (q.isEmpty() ? "true" : "false") << std::endl;
    q.put(1);
    std::cout << "is empty: " << (q.isEmpty() ? "true" : "false") << std::endl;
    auto res = q.get();
    std::cout << "is empty: " << (q.isEmpty() ? "true" : "false") << std::endl;

    q.put(2);

    int a = 4;
    int& b = a;

    q.put(b);
    res = q.get();

    if(res.has_value())
        std::cout << "The first is: " << (res.value()) << std::endl;
    else
        std::cout << "The queue was empty" << std::endl;

    res = q.get();
    if(res.has_value())
        std::cout << "The second is: " << (res.value()) << std::endl;
    else
        std::cout << "The queue was empty" << std::endl;
	// TODO: create an instance of a queue
	// TODO: spawn multiple threads for producer and consumer using the queue
    // NOTE: producer and consumer expect to bind to the queue by reference:
    // 1) STL uses values, therefore plain queue argument might not work: wrap the queue into std::ref instead.
    // 2) Using std::ref is not normal: it is a red-flag that we are doing something wrong.
    //    In this case we are sharing the queue between threads -- dangerous design!
    //    But in this exercise this is how we stress-test our queue in multi-threaded (MT) environment.
    // NOTE: many successful test runs do not guarantee that the queue is MT-safe.
    // You may make your producers to work longer, try running optimized builds hoping to trigger an error,
    // or enable option(TSAN "Thread Sanitizer" ON) in the CMakeLists.txt
    // (remember to regenerate the cmake build by deleting the build directories).
    // Limitations:
    //  - clang++-13 does not ship std::jthread.
    //  - thread sanitizer is supported only on Linux and MacOS.
}