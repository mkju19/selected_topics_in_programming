#include <iostream>
#include "Include/Reaction/Agent.h"
#include "Include/Reaction/Reaction.h"
#include "Include/Reaction/Rule.h"
#include "Include/Reaction/ReactionComponent.h"
//#include "Include/SymbolTable.h"
#include "Include/Simulator/Simulator.h"
#include "Include/Simulator/StateObserver.h"
#include "Examples/SimpleExample.h"
#include "Examples/CircadianRythmExample.h"

//#include <graphviz/gvc.h>
//#include "graphviz/cgraph.h"


class ObserverPrinter : public StateObserver{
    std::vector<std::vector<std::string>> lines;

    void printVector(const std::vector<std::string>& vec){
//        std::cout<< "| ";
        for (const auto& item: vec){
            std::cout << item << " ; ";
        }
        std::cout<< std::endl;
    }
public:
    void observe(std::vector<std::string> vec) override{
        lines.push_back(vec);
    };
    void stop() override {
        std::cout<< "STARTS PRINTING" << std::endl;
        for (auto &line : lines){
            printVector(line);
        }
        std::cout << "STOP PRINTING" << std::endl;
    }
};


int main() {
    auto obs = ObserverPrinter{};
    SimpleExample::run(obs);

//    obs = ObserverPrinter{};
//    CircadianRythmExample::run(obs);

//    auto a = Agent("a", 1);
//    auto b = Agent("b", 60);
//    auto c = Agent("c", 50);
//    auto rule1 = Rule(a >>=  a + c);
//    auto reaction1 = Reaction(a + b >>= c + b, 10);
//    auto reaction2 = Reaction(b + c >>= a + c, 5);
//
//    auto sim = Simulator{};
//    sim.addAgent(a);
//    sim.addAgent(b);
//    sim.addAgent(c);
//    sim.addReaction(reaction1);
//    sim.addReaction(reaction2);
//    auto observer = ObserverPrinter{};
//    sim.run(100, observer);

    return 0;
}

