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

TEST_CASE("Test BFS") {
    // We traversed these graphs by hand to figure out what 
    // the correct traversals (starting from node 0) should be:

    SECTION("5 nodes, WCC") {
        Graph g(5);
        g.addEdge(0,3);
        g.addEdge(1,0);
        g.addEdge(1,3);
        g.addEdge(1,4);
        g.addEdge(2,0);
        g.addEdge(3,2);
        g.addEdge(4,1);
        std::vector<int> correct_traversal{0, 3, 2};
        std::vector<int> our_traversal = g.BFS(0);
        for (int i = 0; i < (int) our_traversal.size(); ++i) {
            REQUIRE(our_traversal[i] == correct_traversal[i]);
        }
    }

    SECTION("5 nodes, SCC") {
        Graph g(5);
        g.addEdge(0,1);
        g.addEdge(0,3);
        g.addEdge(1,0);
        g.addEdge(1,3);
        g.addEdge(1,4);
        g.addEdge(2,0);
        g.addEdge(3,2);
        g.addEdge(4,1);
        std::vector<int> correct_traversal{0, 1, 3, 4, 2};
        std::vector<int> our_traversal = g.BFS(0);
        for (int i = 0; i < (int) our_traversal.size(); ++i) {
            REQUIRE(our_traversal[i] == correct_traversal[i]);
        }
    }

    SECTION("13 nodes, disconnected") {
        Graph g(13);
        g.addEdge(0,2);
        g.addEdge(0,3);
        g.addEdge(2,6);
        g.addEdge(3,2);
        g.addEdge(6,2);
        g.addEdge(6,11);
        g.addEdge(10,2);
        g.addEdge(10,3);
        g.addEdge(11,0);

        g.addEdge(1,5);
        g.addEdge(1,8);
        g.addEdge(4,7);
        g.addEdge(5,4);
        g.addEdge(8,9);
        g.addEdge(9,12);
        g.addEdge(12,1);
        g.addEdge(12,8);

        std::vector<int> correct_traversal_1{0, 2, 3, 6, 11};
        std::vector<int> our_traversal_1 = g.BFS(0);
        for (int i = 0; i < (int) our_traversal_1.size(); ++i) {
            REQUIRE(our_traversal_1[i] == correct_traversal_1[i]);
        }

        // Traverse the other component starting from node 1
        std::vector<int> correct_traversal_2{1, 5, 8, 4, 9, 7, 12};
        std::vector<int> our_traversal_2 = g.BFS(1);
        for (int i = 0; i < (int) our_traversal_2.size(); ++i) {
            REQUIRE(our_traversal_2[i] == correct_traversal_2[i]);
        }
    }
}

TEST_CASE("Test getShortestPath") {
    // Using the same graphs for the BFS test case

    SECTION("5 nodes, WCC") {
        Graph g(5);
        g.addEdge(0,3);
        g.addEdge(1,0);
        g.addEdge(1,3);
        g.addEdge(1,4);
        g.addEdge(2,0);
        g.addEdge(3,2);
        g.addEdge(4,1);

        std::vector<int> traversal = g.BFS(0);

        std::vector<int> our_path_1 = g.getShortestPath(1);
        REQUIRE(our_path_1.empty());

        std::vector<int> correct_path_2{0, 3, 2};
        std::vector<int> our_path_2 = g.getShortestPath(2);
        for (int i = 0; i < (int) our_path_2.size(); ++i) {
            REQUIRE(our_path_2[i] == correct_path_2[i]);
        }

        std::vector<int> correct_path_3{0, 3};
        std::vector<int> our_path_3 = g.getShortestPath(3);
        for (int i = 0; i < (int) our_path_3.size(); ++i) {
            REQUIRE(our_path_3[i] == correct_path_3[i]);
        }
    }

    SECTION("5 nodes, SCC") {
        Graph g(5);
        g.addEdge(0,1);
        g.addEdge(0,3);
        g.addEdge(1,0);
        g.addEdge(1,3);
        g.addEdge(1,4);
        g.addEdge(2,0);
        g.addEdge(3,2);
        g.addEdge(4,1);

        std::vector<int> traversal = g.BFS(0);

        std::vector<int> correct_path_1{0, 1, 4};
        std::vector<int> our_path_1 = g.getShortestPath(4);
        for (int i = 0; i < (int) our_path_1.size(); ++i) {
            REQUIRE(our_path_1[i] == correct_path_1[i]);
        }

        std::vector<int> correct_path_2{0, 3, 2};
        std::vector<int> our_path_2 = g.getShortestPath(2);
        for (int i = 0; i < (int) our_path_2.size(); ++i) {
            REQUIRE(our_path_2[i] == correct_path_2[i]);
        }

        std::vector<int> correct_path_3{0, 1};
        std::vector<int> our_path_3 = g.getShortestPath(1);
        for (int i = 0; i < (int) our_path_3.size(); ++i) {
            REQUIRE(our_path_3[i] == correct_path_3[i]);
        }
    }

    SECTION("13 nodes, disconnected") {
        Graph g(13);
        g.addEdge(0,2);
        g.addEdge(0,3);
        g.addEdge(2,6);
        g.addEdge(3,2);
        g.addEdge(6,2);
        g.addEdge(6,11);
        g.addEdge(10,2);
        g.addEdge(10,3);
        g.addEdge(11,0);

        g.addEdge(1,5);
        g.addEdge(1,8);
        g.addEdge(4,7);
        g.addEdge(5,4);
        g.addEdge(8,9);
        g.addEdge(9,12);
        g.addEdge(12,1);
        g.addEdge(12,8);

        // Traverse first component

        std::vector<int> traversal_from_0 = g.BFS(0);

        std::vector<int> our_empty_path_1 = g.getShortestPath(7);
        REQUIRE(our_empty_path_1.empty());

        std::vector<int> our_empty_path_2 = g.getShortestPath(12);
        REQUIRE(our_empty_path_2.empty());

        std::vector<int> our_empty_path_3 = g.getShortestPath(4);
        REQUIRE(our_empty_path_3.empty());

        std::vector<int> our_empty_path_4 = g.getShortestPath(10);
        REQUIRE(our_empty_path_4.empty());

        std::vector<int> correct_path_1{0, 2, 6, 11};
        std::vector<int> our_path_1 = g.getShortestPath(11);
        for (int i = 0; i < (int) our_path_1.size(); ++i) {
            REQUIRE(our_path_1[i] == correct_path_1[i]);
        }

        std::vector<int> correct_path_2{0, 3};
        std::vector<int> our_path_2 = g.getShortestPath(3);
        for (int i = 0; i < (int) our_path_2.size(); ++i) {
            REQUIRE(our_path_2[i] == correct_path_2[i]);
        }

        std::vector<int> correct_path_3{0, 2, 6};
        std::vector<int> our_path_3 = g.getShortestPath(6);
        for (int i = 0; i < (int) our_path_3.size(); ++i) {
            REQUIRE(our_path_3[i] == correct_path_3[i]);
        }

        // Traverse second component

        std::vector<int> traversal_from_1 = g.BFS(1);

        std::vector<int> our_empty_path_5 = g.getShortestPath(0);
        REQUIRE(our_empty_path_5.empty());

        std::vector<int> our_empty_path_6 = g.getShortestPath(6);
        REQUIRE(our_empty_path_6.empty());

        std::vector<int> our_empty_path_7 = g.getShortestPath(10);
        REQUIRE(our_empty_path_7.empty());

        std::vector<int> our_empty_path_8 = g.getShortestPath(11);
        REQUIRE(our_empty_path_8.empty());

        std::vector<int> correct_path_4{1, 8, 9, 12};
        std::vector<int> our_path_4 = g.getShortestPath(12);
        for (int i = 0; i < (int) our_path_4.size(); ++i) {
            REQUIRE(our_path_4[i] == correct_path_4[i]);
        }

        std::vector<int> correct_path_5{1, 5, 4, 7};
        std::vector<int> our_path_5 = g.getShortestPath(7);
        for (int i = 0; i < (int) our_path_5.size(); ++i) {
            REQUIRE(our_path_5[i] == correct_path_5[i]);
        }

        std::vector<int> correct_path_6{1, 5};
        std::vector<int> our_path_6 = g.getShortestPath(5);
        for (int i = 0; i < (int) our_path_6.size(); ++i) {
            REQUIRE(our_path_6[i] == correct_path_6[i]);
        }
    }
}

TEST_CASE("bfsAll") {
    // Uses 5-node WCC graph and 13-node disconnected graph from BFS test case

    SECTION("5 nodes, WCC") {
        Graph g(5);
        g.addEdge(0,3);
        g.addEdge(1,0);
        g.addEdge(1,3);
        g.addEdge(1,4);
        g.addEdge(2,0);
        g.addEdge(3,2);
        g.addEdge(4,1);
        std::vector<int> correct_traversal{0, 3, 2, 1, 4};
        std::vector<int> our_traversal = g.bfsAll();
        for (int i = 0; i < (int) our_traversal.size(); ++i) {
            REQUIRE(our_traversal[i] == correct_traversal[i]);
        }
    }

    SECTION("13 nodes, disconnected") {
        Graph g(13);
        g.addEdge(0,2);
        g.addEdge(0,3);
        g.addEdge(2,6);
        g.addEdge(3,2);
        g.addEdge(6,2);
        g.addEdge(6,11);
        g.addEdge(10,2);
        g.addEdge(10,3);
        g.addEdge(11,0);

        g.addEdge(1,5);
        g.addEdge(1,8);
        g.addEdge(4,7);
        g.addEdge(5,4);
        g.addEdge(8,9);
        g.addEdge(9,12);
        g.addEdge(12,1);
        g.addEdge(12,8);

        std::vector<int> correct_traversal_1{0, 2, 3, 6, 11, 1, 5, 8, 4, 9, 7, 12, 10};
        std::vector<int> our_traversal_1 = g.bfsAll();
        for (int i = 0; i < (int) our_traversal_1.size(); ++i) {
            REQUIRE(our_traversal_1[i] == correct_traversal_1[i]);
        }
    }
}