
#include <cmath>
#include "Reaction.h"
#include "Rule.h"
#include "Agent.h"
Reaction::Reaction(const Rule& rule, double lambda) : input(), product(), lambda(lambda){
    auto inputAgents = rule.getInputAgents();
    auto productAgents = rule.getOutputAgents();
    for(auto agent : inputAgents){
        input.push_back(agent->getId());
    }
    for(auto agent : productAgents){
        product.push_back(agent->getId());
    }
}

//REQUIREMENT 2a - Pretty printer in human readable format
std::string Reaction::toString() const {
    std::string str = "";

    for (auto i = 0; i < input.size(); i++){
        str += input.at(i) + " ";

        if (i < input.size()-1){ str += "+ "; }
        else{ str += ">>= "; }
    }
    for (auto i = 0; i < product.size(); i++){
        str += product.at(i) + " ";

        if (i < product.size()-1) { str += "+ ";}
    }
    auto rate = std::floor(lambda * 1000)/1000;
    str += "(rate: " + std::to_string(rate).substr(0, 5) + ")";
    return str;
}
std::ostream &operator<<(std::ostream &out, const Reaction &reaction) {
    out << reaction.toString();
    return out;
}



