//
// Created by marco on 05-08-2023.
//

#ifndef EXAM_REACTION_H
#define EXAM_REACTION_H

#include <vector>
#include <memory>
class Agent;
class Rule;

class Reaction {
    std::vector<std::shared_ptr<Agent>> input;
    std::vector<std::shared_ptr<Agent>> product;
    double lambda;
public:
    Reaction(int in, int out, int lambda): input(in), product(out), lambda(lambda){};
    Reaction(Rule rule, double lambda);

    //REQUIREMENT 2a - Pretty printer in human readable format
    friend std::ostream& operator<< (std::ostream &out, Reaction const& reaction);
};




#endif //EXAM_REACTION_H
