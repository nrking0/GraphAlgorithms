#include <catch2/catch.hpp>
#include "../include/graph.h"
#include <fstream>

using namespace finalproject;

TEST_CASE("Input Operator Test") {
    Graph g(5);

    std::ifstream input_file("data/test.txt");
    if (input_file.is_open()) {
        input_file >> g;
        input_file.close();
    }

    REQUIRE(g.isNode(0,1));
}
