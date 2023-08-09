#ifndef EXAM_SIMULATOR_H
#define EXAM_SIMULATOR_H

#include <memory>
#include <vector>
#include <random>
#include <functional>
#include "../SymbolTable.h"

class Agent;
class Reaction;

// THIS SHOULD WORK BUT IT DOESN'T
// probably linking errors
// The idea working on godbolt: https://godbolt.org/z/E5P5s5MEY
//template <typename T>
//concept Observable = requires(T obj, std::vector<std::string> vec) {
//    { obj.observe(vec) } -> std::same_as<void>;
//    { obj.stop() } -> std::same_as<void>;
//};

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

    void run(const double& endTime, const std::function<void(std::vector<std::string>)> &observer);

};


#endif //EXAM_SIMULATOR_H
