#ifndef EXAM_SIMULATOR_H
#define EXAM_SIMULATOR_H

#include <memory>
#include <vector>

template <typename TKey, typename T>
class SymbolTable;
class Agent;
class Reaction;

using AgentSymbolTable = std::unique_ptr<SymbolTable<std::string, Agent>>;

class Simulator {
AgentSymbolTable agents;
std::vector<Reaction> reactions;
double elapsedTime = 0;


double calculateDelay(const Reaction& reaction, std::mt19937& gen);
void react(Reaction& reaction, std::mt19937 gen);
void increment(const std::string& id, int amount);
void decrement(const std::string& id, int amount);
void updateAgent(const std::string& id, int value);
Reaction& minDelay();

void addReaction(Reaction& reaction);
void addAgent(const Agent& agent);

void run(const double& endTime);

};


#endif //EXAM_SIMULATOR_H
