//
// Created by marco on 09-08-2023.
//

#ifndef EXAM_SIMPLEEXAMPLE_H
#define EXAM_SIMPLEEXAMPLE_H
#include <utility>

#include "../Include/Reaction/Agent.h"
#include "../Include/Reaction/ReactionComponent.h"
#include "../Include/Reaction/Rule.h"
#include "../Include/Reaction/Reaction.h"
#include "../Include/Simulator/Simulator.h"
#include "../Include/Simulator/StateObserver.h"
#include "../Include/Simulator/ParallelSimulator.h"

struct SimpleExample {
private:
    static const int endTime = 2000;
public:
    static void run(StateObserver& observer){
        auto sim = Simulator{};

        auto a = Agent{"a", 100};
        auto b = Agent{"b", 0};
        auto c = Agent{"c", 1};
        sim.addAgent(a);
        sim.addAgent(b);
        sim.addAgent(c);

        sim.addReaction(Reaction(a + c >>= b + c, 0.001));

        sim.run(endTime, observer);
    };
    static void runParallel(StateObserver& observer, int numberOfThreads) {
        auto sim = Simulator{};

        auto a = Agent{"a", 100};
        auto b = Agent{"b", 0};
        auto c = Agent{"c", 1};
        sim.addAgent(a);
        sim.addAgent(b);
        sim.addAgent(c);

        sim.addReaction(Reaction(a + c >>= b + c, 0.001));

        auto parallelSim = ParallelSimulator{sim};
        parallelSim.run(endTime, observer, numberOfThreads);
    };
};


#endif //EXAM_SIMPLEEXAMPLE_H
