#ifndef EXAM_SIMULATOR_H
#define EXAM_SIMULATOR_H

#include <memory>
#include <vector>
#include <random>
#include <functional>
#include "../SymbolTable.h"
//#include "../Reaction/Agent.h"

class StateObserver;
class Reaction;
class Agent;

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
    bool canReact(const Reaction& reaction) const;
    std::vector<std::string> vectorizeReaction (const Reaction& reaction) const;

public:
    Simulator()=default;
    Simulator(const Simulator& other){
        *this = other;
    };
    Simulator& operator=(const Simulator& other);
    ~Simulator()=default;
    void addReaction(const Reaction& reaction);
    void addAgent(const Agent& agent);

    void run(const double& endTime, StateObserver &observer);

};


#endif //EXAM_SIMULATOR_H
