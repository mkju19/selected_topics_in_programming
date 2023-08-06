#include "vessel_t.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <iostream>

#include "Reaction/Agent.h"
#include "Reaction/ReactionComponent.h"
#include "Reaction/Rule.h"
#include "Reaction/Reaction.h"
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