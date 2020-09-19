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

TEST_CASE("It checks near equality for floating point") {
    Vector<double, 3> testVec({1.23, 3.14, 5.6});
    const double epsilon = 0.001;

    REQUIRE(testVec.isApproximationOf(Vector<double, 3>({1.23, 3.14, 5.6}), epsilon));
    REQUIRE(!testVec.isApproximationOf(Vector<double, 3>({1.24, 3.2, 5.5}), epsilon));
    REQUIRE((testVec * 2).isApproximationOf(Vector<double, 3>({2.46, 6.28, 11.2}), epsilon));
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

TEST_CASE("It performs scalar multiplication") {
    Vector<int, 3> testVec({3, 9, -5});

    REQUIRE(testVec * 3 == Vector<int, 3>({9, 27, -15}));
    REQUIRE(testVec * -1 == Vector<int, 3>({-3, -9, 5}));

    testVec *= 2;
    REQUIRE(testVec == Vector<int, 3> ({6, 18, -10}));

    testVec *= -3;
    REQUIRE(testVec == Vector<int, 3> ({-18, -54, 30}));
}

TEST_CASE("It performs scalar division") {
    Vector<int, 2> intVec({24, 33});
    REQUIRE(intVec / 3 == Vector<int, 2>({8, 11}));
    intVec /= 3;
    REQUIRE(intVec == Vector<int, 2>({8, 11}));

    Vector<double, 2> doubleVec({3.2, 5.6});
    const double epsilon = 0.001;
    REQUIRE((doubleVec / 3).isApproximationOf(Vector<double, 2>({1.0666, 1.8666}), epsilon));
    doubleVec /= 3;
    REQUIRE(doubleVec.isApproximationOf(Vector<double, 2>({1.0666, 1.8666}), epsilon));
}

TEST_CASE("It computes dot products") {
    Vector<int, 3> one({-2, 3, -5});
    Vector<int, 3> two({6, 8, -8});
    Vector<int, 3> three({-1, 2, 3});

    REQUIRE(one * two == 52);
    REQUIRE(two * three == -14);
}

TEST_CASE("It computes unit vectors") {
    Vector<double, 2> testVec2({3, 4});
    const double epsilon = 0.001;
    REQUIRE(testVec2.unit().isApproximationOf(Vector<double, 2>({0.6, 0.8}), epsilon));

    Vector<double, 3> testVec3({4, 2, 9});
    REQUIRE(testVec3.unit().isApproximationOf(Vector<double, 3>({0.39801, 0.199, 0.8955}), epsilon));
}