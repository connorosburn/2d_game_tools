#include "catch.hpp"
#include "../lib/Vector.hpp"

TEST_CASE("It initializes properly with the default constructor") {
    Vector<int, 4> testVec;
    REQUIRE(testVec.size() == 4);
}

TEST_CASE("It initialializes with a plain std::vector") {
    std::vector<int> initVec { {4, 2} };
    Vector<int, 2> testVec(initVec);
    REQUIRE(testVec[0] == 4);
    REQUIRE(testVec[1] == 2);

    std::vector<int> initVecTwo{ {3, 7} };
    Vector<int, 2> testVecTwo({3, 7});
    REQUIRE(testVecTwo[0] == 3);
    REQUIRE(testVecTwo[1] == 7);
}

TEST_CASE("It properly overloads the equality operator") {
    Vector<int, 2> one({3, 4});
    Vector<int, 2> two({3, 4});
    Vector<int, 2> three({6, 8});
    REQUIRE(one == two);
    REQUIRE(two == one);
    REQUIRE(!(one == three));
    REQUIRE(!(three == two));
    REQUIRE(one != three);
    REQUIRE(three != two);
}

TEST_CASE("It adds two vectors") {
    Vector<int, 2> one({4, 6});
    Vector<int, 2> two({2, 9});
    Vector<int, 3> three({2, 9, 8});
    Vector<int, 3> four({5, 2, 4});

    REQUIRE(one + two == Vector<int, 2>({6, 15}));
    REQUIRE(three + four == Vector<int, 3>({7, 11, 12}));

    one += Vector<int, 2>({3, 2});
    REQUIRE(one == Vector<int, 2>({7, 8}));

    two += one;
    REQUIRE(two == Vector<int, 2>({9, 17}));
}

TEST_CASE("It subtracts two vectors") {
    Vector<int, 2> one({4, 8});
    Vector<int, 2> two({2, 3});

    REQUIRE(one - two == Vector<int, 2>({2, 5}));
    REQUIRE(two - one == Vector<int, 2>({-2, -5}));

    one -= two;
    REQUIRE(one == Vector<int, 2>({2, 5}));

    one -= two;
    REQUIRE(one == Vector<int, 2>({0, 2}));
}