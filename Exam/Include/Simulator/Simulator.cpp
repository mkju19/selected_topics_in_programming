//
// Created by marco on 08-08-2023.
//

#include <random>
#include <float.h>
#include "Simulator.h"
#include "../Reaction/Reaction.h"
#include "../SymbolTable.h"
#include "../Reaction/Agent.h"

double Simulator::calculateDelay(const Reaction &reaction, std::mt19937& gen) {
    double lambdaK = reaction.getRate();

    for(auto const& inputId : reaction.getInputIds()){
        lambdaK *= agents->getElement(inputId).getValue();
    }

    std::exponential_distribution<double> d(lambdaK);
    return d(gen);
}

void Simulator::addAgent(const Agent &agent) {
    agents->addElement(agent.getId(), agent);
}

void Simulator::addReaction(Reaction &reaction) {
    for(auto agent : reaction.getInputIds()){
        if (!agents->contains(agent)){
            throw IDNotFoundException(agent);
        }
    }
    reactions.push_back(reaction);
}

void Simulator::updateAgent(const std::string &id, int value) {
    auto agent = agents->getElement(id);
    auto newVal = agent.getValue() + value;
    agent.setValue(newVal);
    agents->updateElement(id, agent);
}

void Simulator::increment(const std::string& id, int amount) {
    updateAgent(id, amount);
}

void Simulator::decrement(const std::string &id, int amount) {
    updateAgent(id, -amount);
}

void Simulator::react(Reaction &reaction, std::mt19937 gen) {
    for(auto reactantId : reaction.getInputIds()){
        decrement(reactantId, 1);
    }
    for(auto productId : reaction.getproductIds()){
        increment(productId, 1);
    }

    elapsedTime = elapsedTime + reaction.getDelay();
    calculateDelay(reaction, gen);
}

Reaction &Simulator::minDelay() {
    auto minVal = DBL_MAX;
    int minIndex = 0;
    for(auto i = 0; i<reactions.size(); i++){
        if (reactions.at(i).getDelay() <= minVal)
            minIndex = i;
    }
    return reactions.at(minIndex);
}

void Simulator::run(const double& endTime) {
    std::random_device rd;
    std::mt19937 gen(rd());

    while(elapsedTime < endTime){
        for(auto reaction : reactions){
            reaction.setDelay(calculateDelay(reaction, gen));
        }
        auto minDelayReaction = minDelay();
        react(minDelayReaction, gen);
    }
}






