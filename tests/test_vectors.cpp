#include <catch.hpp>

#include "vectors.hpp"

using namespace std;

cppNN::vec<int> a = {0,2,1};
cppNN::vec<double> b = {6,7,11};
cppNN::vec<double> c = {6,9,12};
cppNN::vec<double> d = {};
cppNN::vec<double> e = {6,11,7};

TEST_CASE("Vector to string conversion")
{
    REQUIRE(a.toString() == "{0,2,1}");
    REQUIRE(d.toString() == "{}");
}

TEST_CASE("Addition and subtraction")
{
    REQUIRE(a + b == c);
    REQUIRE(c - b == a);
}

TEST_CASE("Dot product")
{
    REQUIRE(a.dot(b) == 25.0);
    REQUIRE(b.dot(a) == 25.0);
}

TEST_CASE("Equality")
{
    REQUIRE(a == a);
    REQUIRE(!(a == b));
}

TEST_CASE("Indexing")
{
    REQUIRE(b.idx(a) == e);
}
