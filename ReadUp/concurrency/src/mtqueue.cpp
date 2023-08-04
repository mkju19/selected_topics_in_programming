#include "mtqueue.hpp"
#include "iostream"
#include <random>
#include <thread>

void produce(mtqueue<int>& q, int n)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);

    for (auto i = 0u; i < n ; i++){
        auto val = dist(gen);
        std::cout << "pushed: " + std::to_string(val) + "\n";
        q.put(std::move(val));
    }

    std::cout << "finished pushing: "+ std::to_string(n) + " elements\n";
	// TODO: create producer routine: put random numbers into queue
}

void consume(mtqueue<int>& q, int n)
{
    for (auto i = 0; i < n ; i++){
        auto val = q.get();
        std::cout << "POPed: " + std::to_string(val) + "\n";
    }
    std::cout << "Finished POPing " + std::to_string(n) + "elements.\n";
	// TODO: create consumer routine: fetch and print values
}

int main(){

	// TODO: create an instance of a queue
    auto q = mtqueue<int>{};

    auto produce_t1 = std::jthread(produce, std::ref(q), 1);
    auto produce_t2 = std::jthread(produce, std::ref(q), 2);
    auto produce_t3 = std::jthread(produce, std::ref(q), 3);

    auto consume_t1 = std::jthread(consume, std::ref(q), 1);
    auto consume_t2 = std::jthread(consume, std::ref(q), 2);
    auto consume_t3 = std::jthread(consume, std::ref(q), 3);


    produce_t1.join();
    produce_t2.join();
    produce_t3.join();

    consume_t1.join();
    consume_t2.join();
    consume_t3.join();
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