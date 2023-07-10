#ifndef CONCURRENCY_MTQUEUE_H
#define CONCURRENCY_MTQUEUE_H

#include <queue>
#include <condition_variable>

template <typename T>
class mtqueue {
	std::queue<T> container; // TODO: benchmark other containers
	// TODO: add multi-threading safety (MT-safety)
    std::mutex q_mutex;
    std::condition_variable cond;
public:
    bool empty() {
        return container.empty();
    }
	void put(T&& item) {
		// TODO: implement putting the element into container
        q_mutex.lock();
        container.push(item);
        q_mutex.unlock();
	}
	void put(const T& item) {
		// TODO: implement putting the element into container
        q_mutex.lock();
        container.push(item);
        q_mutex.unlock();
	}
	T get(){
        // TODO: implement fetching an element from front container
        std::unique_lock<std::mutex> lock{q_mutex};
        if (container.empty()){
            cond.wait(lock, [&container = container](){return container.empty();});
        }
        auto &&front = container.front();
        container.pop();
        return front;
	}
};

#endif	// CONCURRENCY_MTQUEUE_H
