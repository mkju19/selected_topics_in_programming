#include <iostream>
#include "Include/Reaction/Agent.h"
#include "Include/Reaction/Reaction.h"
#include "Include/Reaction/Rule.h"
#include "Include/Reaction/ReactionComponent.h"
#include "Include/SymbolTable.h"
#include <graphviz/gvc.h>
#include "graphviz/cgraph.h"


void createNode(Agraph_t *g, std::string &name, std::string &fillColor, const std::string &shape){
    auto node = agnode(g, (char *) name.c_str(), 1);
    agsafeset(node, (char *) "style", (char *) "filled", (char *) "");
    agsafeset(node, (char *) "fillcolor", (char *) fillColor.c_str(), (char *) "");
    agsafeset(node, (char *) "shape", (char *) shape.c_str(), (char *) "");
}

int main() {
    auto a = Agent("aa", 1);
    auto b = Agent("b", 2);
    auto c = Agent("c", 3);
    auto rule1 = Rule(a >>=  a + c);
    auto reaction = Reaction(a + b >>= c + b, 0.4);
//    std::cout << "Rule1 input: " << rule1.getInputAgents().at(0).get()->getId() << std::endl;
//    std::cout << "Rule1 product: " << rule1.getOutputAgents().at(1).get()->getId() << std::endl;

    auto symbolTable = SymbolTable<std::string, Agent>{};
    auto symbolTableR = SymbolTable<std::string, Reaction>{};

    symbolTableR.addElement("reaction1", reaction);


    symbolTable.addElement(a.getId(), a);
    a.setValue(2);
//    symbolTable.updateElement(a.getId(), a);
    std::cout << symbolTable.getElement(a.getId()) << std::endl;
    std::cout << symbolTableR.getElement("reaction1") << std::endl;

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

