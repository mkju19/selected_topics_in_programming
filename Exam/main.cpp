#include <iostream>
#include "Reaction/Agent.h"
#include "Reaction/Reaction.h"
#include "Reaction/Rule.h"
#include "Reaction/ReactionComponent.h"


int main() {
    auto a = Agent("aa", 1);
    auto b = Agent("b", 2);
    auto c = Agent("c", 3);
    auto rule1 = Rule(a >>=  a + c);

    auto reaction = Reaction(a + b >>= c + b, 0.4);
    std::cout << "Rule1 input: " << rule1.getInputAgents().at(0).get()->getId() << std::endl;
    std::cout << "Rule1 product: " << rule1.getOutputAgents().at(1).get()->getId() << std::endl;
    return 0;
}

