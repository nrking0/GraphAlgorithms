#include <catch2/catch.hpp>
#include "../include/page-rank.h"
#include <fstream>
#include <vector>

using namespace finalproject;

using namespace Eigen;

TEST_CASE("PageRank Small Test") {
    SECTION("Initial Vector Sum to 1") {
        Graph g(4);

        std::ifstream input_file("../data/test-small-pr.txt");
        if (input_file.is_open()) {
            input_file >> g;
            input_file.close();
        }

        PageRank r(g, false, 1000);
        REQUIRE(r.initSum() == 1);
    }

    SECTION("Transition Matrix Initial Columns Equal to 1") {
        Graph g(4);

        std::ifstream input_file("../data/test-small-pr.txt");
        if (input_file.is_open()) {
            input_file >> g;
            input_file.close();
        }

        PageRank r(g, false, 1000);
        for (unsigned int i = 0; i < r.getNumOfNodes(); i++) {
            REQUIRE(r.columnSum(i) == 1); 
        }
    }

    SECTION("Correct Number of Items in Each Transition Matrix Column") {
        Graph g(4);

        std::ifstream input_file("../data/test-small-pr.txt");
        if (input_file.is_open()) {
            input_file >> g;
            input_file.close();
        }

        PageRank r(g, false, 1000);
        SparseMatrix<long double> t_matrix = r.getTransMatrix();
        // Vector<long double, Dynamic> i_vec = r.getInitVec();
        std::vector<int>* adj_list = g.getList();
        
        for (unsigned int i = 0; i < r.getNumOfNodes(); i++) {
            REQUIRE(t_matrix.col(i).nonZeros() == (unsigned int)adj_list[i].size()); 
        }
    }

    SECTION("Correct Coverging Values") {
        Graph g(4);

        std::ifstream input_file("../data/test-small-pr.txt");
        if (input_file.is_open()) {
            input_file >> g;
            input_file.close();
        }

        PageRank r(g, false, 1000);
        r.runPageRank();
        Vector<long double, Dynamic> i_vec = r.getInitVec();
        
        REQUIRE((double)i_vec[0] == 0.12); 
        REQUIRE((double)i_vec[1] == 0.24); 
        REQUIRE((double)i_vec[2] == 0.24); 
        REQUIRE((double)i_vec[3] == 0.40); 

    }
}