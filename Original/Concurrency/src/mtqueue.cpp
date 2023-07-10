#include <random>
#include <iostream>
#include <thread>
#include "mtqueue.hpp"

static std::random_device dev;
static std::mt19937 rng(dev());
static std::uniform_int_distribution<std::mt19937::result_type> dist(1,10);

void produce(mtqueue<int>& q)
{
	// TODO: create producer routine: put random numbers into queue
    for (auto i = 0; i < 10; i++){
        q.put(dist(rng));
    }
}

void consume(mtqueue<int>& q)
{
	// TODO: create consumer routine: fetch and print values
    while (!q.empty()){
        std::cout<<"popped: " << q.get() << std::endl;
    }
}

int main(){
	// TODO: create an instance of a queue
    auto q = mtqueue<int>();
	// TODO: spawn multiple threads for producer and consumer using the queue
    auto num_of_producers = 5;
    std::vector<std::thread> producers;
    producers.reserve(num_of_producers);
    for (auto i = 0; i < num_of_producers; i++){
        producers.emplace_back(produce, std::ref(q));
    }

    auto num_of_consumers = 2;
    std::vector<std::thread> consumers;
    consumers.reserve(num_of_consumers);
    for (auto i = 0; i < num_of_consumers; i++){
        consumers.emplace_back(consume, std::ref(q));
    }


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