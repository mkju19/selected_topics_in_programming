#include <iostream>
#include <memory>
#include "Include/Reaction/Agent.h"
#include "Include/Reaction/Reaction.h"
#include "Include/Reaction/Rule.h"
#include "Include/Reaction/ReactionComponent.h"
#include "Include/SymbolTable.h"
#include "Include/Simulator/Simulator.h"
#include "Include/Simulator/StateObserver.h"

//#include <graphviz/gvc.h>
//#include "graphviz/cgraph.h"


class Obs : public StateObserver{
    std::vector<std::vector<std::string>> lines;

    void printVector(std::vector<std::string> vec){
        std::cout<< "| ";
        for (const auto& item: vec){
            std::cout << item << " | ";
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

//void createNode(Agraph_t *g, std::string &name, std::string &fillColor, const std::string &shape){
//    auto node = agnode(g, (char *) name.c_str(), 1);
//    agsafeset(node, (char *) "style", (char *) "filled", (char *) "");
//    agsafeset(node, (char *) "fillcolor", (char *) fillColor.c_str(), (char *) "");
//    agsafeset(node, (char *) "shape", (char *) shape.c_str(), (char *) "");
//}





int main() {
    auto a = Agent("a", 1);
    auto b = Agent("b", 60);
    auto c = Agent("c", 50);
    auto rule1 = Rule(a >>=  a + c);
    auto reaction1 = Reaction(a + b >>= c + b, 10);
    auto reaction2 = Reaction(b + c >>= a + c, 5);
//    auto observer = DerivedObserver();
//    auto vec = std::vector<std::string>{};
//    vec.push_back("aa");
//    vec.push_back("bb");
//    observer.observe(vec);
//    observer.stop();

    auto sim = Simulator{};
    sim.addAgent(a);
    sim.addAgent(b);
    sim.addAgent(c);
    sim.addReaction(reaction1);
    sim.addReaction(reaction2);
    auto observer = Obs{};
    sim.run(100, observer);



//    GVC_t *gvc = gvContext();
//    Agraph_t *g = agopen((char*)"g", Agdirected, nullptr);
//
//    // createNode
//    auto name = std::string{"node"};
//    auto fillColor = std::string{"lightgreen"};
//    auto shape = std::string{"box"};
//
//    createNode(g, name, fillColor, shape);
//
//
//    gvLayout(gvc, g, "dot");
//    gvRenderFilename(gvc, g, "png", (char*)("test.png"));
//    gvFreeLayout(gvc, g);
//    agclose(g);
//    gvFreeContext(gvc);

    return 0;


 //   return 0;
}

