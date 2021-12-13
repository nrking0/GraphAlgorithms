#include <catch2/catch.hpp>
#include "../include/graph.h"
#include "../include/connected-component.h"
#include <fstream>
#include <vector>

using namespace finalproject;

TEST_CASE("Small graph test") {
    Graph g(5);

    std::ifstream input_file("../data/component-test.txt");
    if (input_file.is_open()) {
        input_file >> g;
        input_file.close();
    }

    ConnectedComponent c;
    std::vector<std::vector<int>> vec = c.kosaraju(g);
    
    REQUIRE(vec.size() == 2);
    REQUIRE(vec[0][0] == 2);
    REQUIRE(vec[0][1] == 3);
    REQUIRE(vec[0][2] == 4);
    REQUIRE(vec[1][0] == 0);
    REQUIRE(vec[1][1] == 1);
}

TEST_CASE("Test Full Graph") {
    Graph g(281903);

    std::ifstream input_file("../data/web-stanford.txt");
    if (input_file.is_open()) {
        input_file >> g;
        input_file.close();
    }

    ConnectedComponent c;
    std::vector<std::vector<int>> vec = c.kosaraju(g);
    
    REQUIRE(vec.size() == 29916);

}