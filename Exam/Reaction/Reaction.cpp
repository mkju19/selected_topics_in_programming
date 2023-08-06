
#include "Reaction.h"
#include "Rule.h"
#include "Agent.h"
Reaction::Reaction(Rule rule, double lambda) : input(rule.getInputAgents()), product(rule.getOutputAgents()), lambda(lambda){}

//REQUIREMENT 2a - Pretty printer in human readable format
std::ostream &operator<<(std::ostream &out, const Reaction &reaction) {
    auto input = &reaction.input;
    auto product = &reaction.product;

    for (auto i = 0; i < input->size(); i++){
        out << "(" << input->at(i)->getId() << ":" << input->at(i)->getValue() << ") ";

        if (i < input->size()-1){ out << "+ "; }
        else{ out << ">>= "; }
    }
    for (auto i = 0; i < product->size(); i++){
        out << "(" << product->at(i)->getId() << ":" << product->at(i)->getValue() << ") ";

        if (i < product->size()-1) { out << "+ ";}
    }

    out << "(rate: " << reaction.lambda << ")";
    return out;
}
