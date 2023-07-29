#ifndef CONCURRENCY_MTQUEUE_H
#define CONCURRENCY_MTQUEUE_H

#include <queue>
#include <optional>

template <typename T>
class mtqueue {
	std::queue<T> container; // TODO: benchmark other containers
	// TODO: add multi-threading safety (MT-safety)
public:
    bool isEmpty() {
        return container.empty();
    }

	void put(T&& item) {
        container.push(item);
		// TODO: implement putting the element into container
	}
	void put(const T& item) {
        container.push(item);
		// TODO: implement putting the element into container
	}
	std::optional<T> get(){
        if (container.empty())
            return {};
        else {
            auto res = container.front();
            container.pop();
            return res;
        }
	}
};

#endif	// CONCURRENCY_MTQUEUE_H
