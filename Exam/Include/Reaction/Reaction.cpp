
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
std::ostream &operator<<(std::ostream &out, const Reaction &reaction) {
    auto input = &reaction.input;
    auto product = &reaction.product;

    for (auto i = 0; i < input->size(); i++){
        out << input->at(i) << " ";

        if (i < input->size()-1){ out << "+ "; }
        else{ out << ">>= "; }
    }
    for (auto i = 0; i < product->size(); i++){
        out << product->at(i) << " ";

        if (i < product->size()-1) { out << "+ ";}
    }

    out << "(rate: " << reaction.lambda << ")";
    return out;
}


