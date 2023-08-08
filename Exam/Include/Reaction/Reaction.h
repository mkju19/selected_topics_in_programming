#ifndef EXAM_REACTION_H
#define EXAM_REACTION_H

#include <vector>
#include <memory>
class Agent;
class Rule;

class Reaction {
    std::vector<std::string> input;
    std::vector<std::string> product;
    double lambda;
    double delay = 0;
public:
    Reaction(int in, int out, int lambda): input(in), product(out), lambda(lambda){};
    Reaction(const Rule& rule, double lambda);
    Reaction() = default;

    double getDelay(){return delay;}
    void setDelay(double d){delay = d;};
    double getRate() const { return lambda;}
    std::vector<std::string> getInputIds() const{return input;}
    std::vector<std::string> getproductIds() const{return product;}
    std::string toString() const;
    //REQUIREMENT 2a - Pretty printer in human readable format
    friend std::ostream& operator<< (std::ostream &out, Reaction const& reaction);
};




#endif //EXAM_REACTION_H
