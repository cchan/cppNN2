#include <catch.hpp>

#include "vectors.hpp"

using namespace std;

cppNN::vec<double> a = {1,2,3};
cppNN::vec<double> b = {5,7,9};
cppNN::vec<double> c = {6,9,12};
cppNN::vec<double> d = {};

TEST_CASE("Vector to string conversion")
{
    REQUIRE(a.toString() == "{1,2,3}");
    REQUIRE(d.toString() == "{}");
}

TEST_CASE("Addition and subtraction")
{
    //REQUIRE(a + b == c);
    //REQUIRE(c - b == a);
}

TEST_CASE("Dot product")
{
    //REQUIRE(a.dot(b) == 46.0);
    //REQUIRE(b.dot(a) == 46.0);
}
