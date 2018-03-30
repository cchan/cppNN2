#include <catch.hpp>

#include "vectors.hpp"

using namespace std;

vec<double> a = {1,2,3};
vec<double> b = {5,7,9};
vec<double> c = {6,9,12};
vec<double> d = {};

TEST_CASE("Addition and subtraction")
{
    REQUIRE(a + b == c);
    REQUIRE(c - b == a);
}

TEST_CASE("Vector to string conversion")
{
    REQUIRE(a.toString() == "{1,2,3}");
    REQUIRE(d.toString() == "{}");
}
