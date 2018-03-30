#include <catch.hpp>

#include "vectors.hpp"

using namespace std;

vector<double> a = {1,2,3};
vector<double> b = {5,7,9};
vector<double> c = {6,9,12};
vector<double> d = {};

TEST_CASE("Addition and subtraction")
{
    REQUIRE(a + b == c);
    REQUIRE(c - b == a);
}

TEST_CASE("Vector to string conversion")
{
    REQUIRE(vectorToString(a) == "{1,2,3}");
    REQUIRE(vectorToString(d) == "{}");
}
