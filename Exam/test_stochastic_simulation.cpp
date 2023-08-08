#include "vessel_t.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <iostream>

#include "Include/Reaction/Agent.h"
#include "Include/Reaction/ReactionComponent.h"
#include "Include/Reaction/Rule.h"
#include "Include/Reaction/Reaction.h"
#include "Include/SymbolTable.h"
TEST_CASE("Test reactions")
{
    auto a = Agent("a", 1);
    auto b = Agent("b", 2);
    auto c = Agent("c", 3);
    auto lambda = 0.5f;
    SUBCASE("Test that reactions can be generated using overloaded operators"){
        auto reaction1 = Reaction(a + b >>= c, lambda);
        auto reaction2 = Reaction(a >>= b, lambda);
        auto reaction3 = Reaction(a >>= b + c, lambda);
        auto reaction4 = Reaction(a + b >>= b + c, lambda);
    }
    SUBCASE("Test pretty printer does not crash"){
        auto reaction1 = Reaction(a + b >>= c, lambda);
        auto reaction2 = Reaction(a >>= b, lambda);
        auto reaction3 = Reaction(a >>= b + c, lambda);
        auto reaction4 = Reaction(a + b >>= b + c, lambda);
        std::cout <<    reaction1 << std::endl <<
                        reaction2 << std::endl <<
                        reaction3 << std::endl <<
                        reaction4 << std::endl;
    }

}
TEST_CASE("Test Symbol table"){
    auto a = Agent("a", 1);

    auto symbolTable = SymbolTable<std::string, Agent>{};

    SUBCASE("Test that the symbol table can add an object and retrieve it"){
        auto id1 = "a";
        auto id2 = "b";

        symbolTable.addElement(id1, a);
        symbolTable.addElement(id2, a);
        auto obj = symbolTable.getElement(id1);

        CHECK(obj.getId() == id1);
        CHECK(obj.getValue() == a.getValue());

    }
    SUBCASE("Test that Symbol table can update a value"){
        int newValue = 3;

        symbolTable.addElement(a.getId(), a);
        a.setValue(newValue);
        symbolTable.updateElement(a.getId(), a);

        auto obj = symbolTable.getElement(a.getId());
        CHECK(obj.getValue() == newValue);
    }
    SUBCASE("Test that symbol table throws an exception when the same ID is added twice"){
        auto id = "a";

        symbolTable.addElement(id, a);
        CHECK_THROWS(
                symbolTable.addElement("a", a)
        );
    }
    SUBCASE("Test that symbol table Throws an exception when getElement is called on an id that does not exist"){
        CHECK_THROWS(symbolTable.getElement("a"));
    }
    SUBCASE("Test that symbol table throws an exception when trying to update an element the does not exist"){
        CHECK_THROWS(symbolTable.updateElement("a", a));
    }

}