#include <random>
#include <cfloat>
#include <iostream>
#include "Simulator.h"
#include "../Reaction/Reaction.h"
#include "../Reaction/Agent.h"
#include "StateObserver.h"

double Simulator::calculateDelay(const Reaction &reaction, std::mt19937& gen) {
    double lambdaK = reaction.getRate();

    for(auto const& inputId : reaction.getInputIds()){
        lambdaK *= agents.getElement(inputId).getValue();
    }

    std::exponential_distribution<double> d(lambdaK);
    auto res = d(gen);
    return res;
}

void Simulator::addAgent(const Agent &agent) {
    auto id = agent.getId();
    agents.addElement(id, agent);
}

void Simulator::addReaction(const Reaction &reaction) {
    for(auto agent : reaction.getInputIds()){
        if (!agents.contains(agent)){
            throw IDNotFoundException(agent);
        }
    }
    reactions.push_back(reaction);
}

void Simulator::updateAgent(const std::string &id, int value) {
    auto agent = agents.getElement(id);
    auto newVal = agent.getValue() + value;
    agent.setValue(newVal);
    agents.updateElement(id, agent);
}

void Simulator::increment(const std::string& id, int amount) {
    updateAgent(id, amount);
}

void Simulator::decrement(const std::string &id, int amount) {
    updateAgent(id, -amount);
}

void Simulator::react(const Reaction &reaction) {
    if (canReact(reaction)) {
        for (const auto &reactantId: reaction.getInputIds()) {
            decrement(reactantId, delta);
        }
        for (const auto &productId: reaction.getproductIds()) {
            increment(productId, delta);
        }
    }
}

Reaction &Simulator::minDelayReaction() {
    auto minVal = DBL_MAX;
    int minIndex = 0;
    for(auto i = 0; i<reactions.size(); i++){
        auto delayValue = reactions.at(i).getDelay();
        if ( delayValue <= minVal) {
            minVal = delayValue;
            minIndex = i;
        }
    }
    return reactions.at(minIndex);
}


void Simulator::run(const double &endTime, StateObserver &observer) {
    std::random_device rd;
    std::mt19937 gen(rd());

    while(elapsedTime < endTime){
        for(auto& reaction : reactions){
            reaction.setDelay(calculateDelay(reaction, gen));
        }

        auto nextReaction = minDelayReaction();
        elapsedTime += nextReaction.getDelay();
        react(nextReaction);
        auto vectorizedReaction =vectorizeReaction(nextReaction);

        observer.observe(vectorizedReaction);
    }
    observer.stop();
}

bool Simulator::canReact(const Reaction &reaction) const {

    for(const auto &agentId : reaction.getInputIds()){
        auto agentValue = agents.getElement(agentId).getValue();
        if (agentValue < delta){
            return false;
        }
    }
    return true;
}

std::vector<std::string> Simulator::vectorizeReaction(const Reaction& reaction) const {
    std::vector<std::string> vec;
    vec.push_back(std::to_string(elapsedTime));
    vec.push_back(reaction.toString());
    vec.push_back(std::to_string(reaction.getDelay()));
    for(const auto& [key, agent_ptr] : agents){
        vec.push_back(agent_ptr->toString());
    }
    return vec;
}

Simulator &Simulator::operator=(const Simulator &other) {
    for(const auto& reaction: other.reactions){
        reactions.push_back(reaction);
    }
    for(const auto& [id, agent]: other.agents){
        agents.addElement(id, *agent);
    }
    return *this;
}







