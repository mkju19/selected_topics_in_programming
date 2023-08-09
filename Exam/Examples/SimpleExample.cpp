//
// Created by marco on 09-08-2023.
//

#include "SimpleExample.h"
#include "../Include/Reaction/Agent.h"
#include "../Include/Reaction/ReactionComponent.h"
#include "../Include/Reaction/Rule.h"
#include "../Include/Reaction/Reaction.h"
#include "../Include/Simulator/Simulator.h"
void SimpleExample::run(StateObserver& observer) {
    auto sim = Simulator{};

    auto a = Agent{"a", 100};
    auto b = Agent{"b", 0};
    auto c = Agent{"c", 1};
    sim.addAgent(a);
    sim.addAgent(b);
    sim.addAgent(c);

    sim.addReaction(Reaction(a + c >>= b + c, 0.001));

    sim.run(2000, observer);
}

