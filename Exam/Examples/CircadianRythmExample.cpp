//
// Created by marco on 09-08-2023.
//

#include "CircadianRythmExample.h"
#include "../Include/Reaction/Agent.h"
#include "../Include/Reaction/ReactionComponent.h"
#include "../Include/Reaction/Rule.h"
#include "../Include/Reaction/Reaction.h"
#include "../Include/Simulator/Simulator.h"

void CircadianRythmExample::run(StateObserver& observer) {
    auto sim = Simulator{};

    auto alphaA = 50.0;
    auto alpha_A = 500.0;
    auto alphaR = 0.01;
    auto alpha_R = 50.0;
    auto betaA = 50.0;
    auto betaR = 5.0;
    auto gammaA = 1.0;
    auto gammaR = 1.0;
    auto gammaC = 2.0;
    auto deltaA = 1.0;
    auto deltaR = 0.2;
    auto deltaMA = 10.0;
    auto deltaMR = 0.5;
    auto thetaA = 50.0;
    auto thetaR = 100.0;

    auto DA = Agent{"DA", 1};
    auto D_A = Agent{"D_A", 0};
    auto DR = Agent{"DR", 1};
    auto D_R = Agent{"D_R", 0};
    auto MA = Agent{"MA", 0};
    auto MR = Agent{"MR", 0};
    auto A = Agent{"A", 0};
    auto R = Agent{"R", 0};
    auto C = Agent{"C", 0};
    auto env = Agent{"env", 0};

    sim.addAgent(DA);
    sim.addAgent(D_A);
    sim.addAgent(DR);
    sim.addAgent(D_R);
    sim.addAgent(MA);
    sim.addAgent(MR);
    sim.addAgent(A);
    sim.addAgent(R);
    sim.addAgent(C);
    sim.addAgent(env);

    sim.addReaction(Reaction{A + DA >>= D_A, gammaA});
    sim.addReaction(Reaction{D_A >>= DA + A, thetaA});
    sim.addReaction(Reaction{A + DR >>= D_R, gammaR});
    sim.addReaction(Reaction{D_R >>= DR + A, thetaR});
    sim.addReaction(Reaction{D_A >>= MA + D_A, alpha_A});
    sim.addReaction(Reaction{DA >>= MA + DA, alphaA});
    sim.addReaction(Reaction{D_R >>= MR + D_R, alpha_R});
    sim.addReaction(Reaction{DR >>= MR + DR, alphaR});
    sim.addReaction(Reaction{MA >>= MA + A, betaA});
    sim.addReaction(Reaction{MR >>= MR + R, betaR});
    sim.addReaction(Reaction{A + R >>= C, gammaC});
    sim.addReaction(Reaction{C >>= R, deltaA});
    sim.addReaction(Reaction{A >>= env, deltaA});
    sim.addReaction(Reaction{R >>= env, deltaR});
    sim.addReaction(Reaction{MA >>= env, deltaMA});
    sim.addReaction(Reaction{MR >>= env, deltaMR});

    sim.run(100, observer);
}
