//
// Created by marco on 05-08-2023.
//
#include "ReactionComponent.h"
#include "Agent.h"

void ReactionComponent::addAgent(Agent &a) {
    agents.push_back(std::make_shared<Agent>(a));
}

Agents& ReactionComponent::getAgents() {
    return this->agents;
}

// REQUIREMENT 1 - overload operators to support reaction rule typesetting in code
ReactionComponent operator+(Agent &lhs, Agent &rhs) {
    auto p_lhs = std::make_shared<Agent>(lhs);
    auto p_rhs = std::make_shared<Agent>(rhs);
    return ReactionComponent(std::vector{std::move(p_lhs), std::move(p_rhs)});
}
ReactionComponent operator+(ReactionComponent &lhs, Agent &rhs) {
    lhs.addAgent(rhs);
    return lhs;
}

