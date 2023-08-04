#ifndef CONCURRENCY_MTQUEUE_H
#define CONCURRENCY_MTQUEUE_H

#include <queue>
#include <optional>
#include <mutex>
#include <condition_variable>

template <typename T>
class mtqueue {
	std::queue<T> container; // TODO: benchmark other containers
    std::mutex mut;
    std::condition_variable cv;
	// TODO: add multi-threading safety (MT-safety)
public:
    bool isEmpty() {
        std::lock_guard<std::mutex> lock(mut);
        return container.empty();
    }

	void put(T&& item) {
        auto lock = std::lock_guard(mut);
        container.push(std::move(item));
        cv.notify_one();
	}
	void put(const T& item) {
        auto lock = std::lock_guard(mut);
        container.push(item);
        cv.notify_one();
	}
	T get(){
        auto lock = std::unique_lock(mut);
        cv.wait(lock, [c = &container] {return !(c->empty());});

        auto res = container.front();
        container.pop();
        return res;

	}
};

#endif	// CONCURRENCY_MTQUEUE_H
