#include <queue>
#include <thread>
#include <mutex>
#include "ParallelSimulator.h"
#include "Simulator.h"
#include "../Reaction/Reaction.h"
#include "../Reaction/Rule.h"
#include "../Reaction/Agent.h"

void ParallelSimulator::run(const double endTime, StateObserver& observer, int numberOfThreads) {
    auto threads = std::vector<std::jthread>{};
    for(auto i = 0; i < numberOfThreads; i++){
        auto handle = std::jthread{&ParallelSimulator::simulate, this, endTime, std::ref(observer), Simulator{sim}, i};
        threads.push_back(std::move(handle));
    }

    for(auto& thread : threads){
        thread.join();
    }
    observer.stopParallel();
}

void ParallelSimulator::simulate(const double endTime, StateObserver& observer, Simulator simulator, int id) {
    auto obs = SimulationObserver{};

    simulator.run(endTime, obs);

    while (!obs.queueEmpty()){
            std::scoped_lock lock(mut);
            observer.observeParallel(obs.popQueue(), id);
    }
}


