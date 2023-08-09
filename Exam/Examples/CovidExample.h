//
// Created by marco on 09-08-2023.
//

#ifndef EXAM_COVIDEXAMPLE_H
#define EXAM_COVIDEXAMPLE_H

#include "../Include/Reaction/Agent.h"
#include "../Include/Reaction/ReactionComponent.h"
#include "../Include/Reaction/Rule.h"
#include "../Include/Reaction/Reaction.h"
#include "../Include/Simulator/Simulator.h"
#include "../Include/Simulator/StateObserver.h"

struct CovidExample {
    static void run(StateObserver& observer, int N) {
        auto sim = Simulator{};


        const auto eps = 0.0009; // initial fraction of infectious
        const auto I0 = size_t(std::round(eps*N)); // initial infectious
        const auto E0 = size_t(std::round(eps*N*15)); // initial exposed
        const auto S0 = N-I0-E0; // initial susceptible
        const auto R0 = 2.4; // basic reproductive number (initial, without lockdown etc)
        const auto alpha = 1.0 / 5.1; // incubation rate (E -> I) ~5.1 days
        const auto gamma = 1.0 / 3.1; // recovery rate (I -> R) ~3.1 days
        const auto beta = R0 * gamma; // infection/generation rate (S+I -> E+I)
        const auto P_H = 0.9e-3; // probability of hospitalization
        const auto kappa = gamma * P_H*(1.0-P_H); // hospitalization rate (I -> H)
        const auto tau = 1.0/10.12; // recovery/death rate in hospital (H -> R) ~10.12 days
        auto S = Agent{"S", S0}; // susceptible
        auto E = Agent{"E", E0}; // exposed
        auto I = Agent{"I", I0}; // infectious
        auto H = Agent{"H", 0}; // hospitalized
        auto R = Agent{"R", 0}; // removed/immune (recovered + dead)
        sim.addAgent(S);
        sim.addAgent(E);
        sim.addAgent(I);
        sim.addAgent(H);
        sim.addAgent(R);

        sim.addReaction(Reaction{S+I >>= E+I, beta/N}); // susceptible becomes exposed through infectious
        sim.addReaction(Reaction{E >>= I, alpha}); // exposed becomes infectious
        sim.addReaction(Reaction{I >>= R, gamma}); // infectious becomes removed

        sim.addReaction(Reaction{I >>= H, kappa}); // infectious becomes hospitalized
        sim.addReaction(Reaction{H >>= R, tau}); // hospitalized becomes removed

        sim.run(100, observer);
    }
};


#endif //EXAM_COVIDEXAMPLE_H
