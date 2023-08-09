#include <iostream>
#include "Include/Reaction/Agent.h"
#include "Include/Reaction/Reaction.h"
#include "Include/Reaction/Rule.h"
#include "Include/Reaction/ReactionComponent.h"
#include "Include/SymbolTable.h"
#include "Include/Simulator/Simulator.h"
#include <graphviz/gvc.h>
#include "graphviz/cgraph.h"


void createNode(Agraph_t *g, std::string &name, std::string &fillColor, const std::string &shape){
    auto node = agnode(g, (char *) name.c_str(), 1);
    agsafeset(node, (char *) "style", (char *) "filled", (char *) "");
    agsafeset(node, (char *) "fillcolor", (char *) fillColor.c_str(), (char *) "");
    agsafeset(node, (char *) "shape", (char *) shape.c_str(), (char *) "");
}

void printVector(std::vector<std::string> vec){
    std::cout<< "| ";
    for (const auto& item: vec){
        std::cout << item << " | ";
    }
    std::cout<< std::endl;
}

int main() {
    auto a = Agent("a", 1);
    auto b = Agent("b", 60);
    auto c = Agent("c", 50);
    auto rule1 = Rule(a >>=  a + c);
    auto reaction1 = Reaction(a + b >>= c + b, 10);
    auto reaction2 = Reaction(b + c >>= a + c, 5);
    auto sim = Simulator{};
    sim.addAgent(a);
    sim.addAgent(b);
    sim.addAgent(c);
    sim.addReaction(reaction1);
    sim.addReaction(reaction2);
    sim.run(100, printVector);



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

