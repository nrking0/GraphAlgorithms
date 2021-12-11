#include <catch2/catch.hpp>
#include "../include/graph.h"
#include <fstream>
#include <vector>

using namespace finalproject;


TEST_CASE("Basic graph test") {
    SECTION("Adding edges") {
        Graph g(5);

        g.addEdge(1,2);
        g.addEdge(0,1);

        REQUIRE(g.isNode(0,1));
        REQUIRE(g.isNode(1,2));
    }

    SECTION("Test getList") {
        Graph g(5);

        g.addEdge(1,2);
        g.addEdge(0,1);

        std::vector<int>* vec = g.getList();

        REQUIRE(vec[0][0] == 1);
        REQUIRE(vec[1][0] == 2);
    }

    SECTION("Test printing") {
        Graph g(5);

        g.addEdge(1,2);
        g.addEdge(0,1);

        g.print();
    }
}

TEST_CASE("Input Operator Test") {
    SECTION("Small list") {
        Graph g(5);

        std::ifstream input_file("../data/test.txt");
        if (input_file.is_open()) {
            input_file >> g;
            input_file.close();
        }

        REQUIRE(g.isNode(0,1));
        REQUIRE(g.isNode(1,2));
    }

    SECTION("Web data input test") {
        Graph g(281903);

        std::ifstream input_file("../data/web-stanford.txt");
        if (input_file.is_open()) {
            input_file >> g;
            input_file.close();
        }

        REQUIRE(g.isNode(6548,57031));
        REQUIRE(g.isNode(1,15409));
        REQUIRE(g.getNodes() == 281903);
    }
}

TEST_CASE("Ensure isNode is working") {
    Graph g(5);

    g.addEdge(1,2);
    g.addEdge(0,1);

    std::vector<int>* vec = g.getList();

    REQUIRE(vec[0][0] == 1);
    REQUIRE(vec[1][0] == 2);
    REQUIRE(g.isNode(0,1));
    REQUIRE(g.isNode(1,2));
    REQUIRE(!g.isNode(10,15));
    REQUIRE(!g.isNode(0,0));
}

TEST_CASE("Test getTranspose") {
    Graph g(5);

    g.addEdge(1,2);
    g.addEdge(0,1);

    Graph t = g.getTranspose();

    REQUIRE(t.isNode(2,1));
    REQUIRE(t.isNode(1,0));
}