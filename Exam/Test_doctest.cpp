#include "FunctionToTest.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("TEST TESTING")
{
    auto a = func(1);
    CHECK(a == 1);
}