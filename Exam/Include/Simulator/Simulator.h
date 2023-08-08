#ifndef EXAM_SIMULATOR_H
#define EXAM_SIMULATOR_H

#include <memory>
#include <vector>
#include <random>
#include "../SymbolTable.h"

class Agent;
class Reaction;

using AgentSymbolTable = std::unique_ptr<SymbolTable<std::string, Agent>>;

class Simulator {
    SymbolTable<std::string, Agent> agents;
    std::vector<Reaction> reactions;
    double elapsedTime = 0;
    int delta = 1;


    double calculateDelay(const Reaction& reaction, std::mt19937& gen);
    void react(const Reaction& reaction);
    void increment(const std::string& id, int amount);
    void decrement(const std::string& id, int amount);
    void updateAgent(const std::string& id, int value);
    Reaction& minDelayReaction();
    void ObserveState(const Reaction& reaction) const;
    bool canReact(const Reaction& reaction) const;
    std::vector<std::string> vectorizeReaction (const Reaction& reaction) const;

public:
    void addReaction(Reaction& reaction);
    void addAgent(const Agent& agent);

//    void run(const double& endTime);
    std::vector<std::vector<std::string>> run(const double& endTime);

};


#endif //EXAM_SIMULATOR_H
