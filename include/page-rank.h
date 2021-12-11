#pragma once

#include "graph.h"
#include <iostream>
#include <vector>

using namespace std;

namespace finalproject {

class PageRank {

    public:
    PageRank();
    ~PageRank();
    PageRank(const Graph g);

    private:
    vector<vector<double>> transition_matrix;
    vector<double> init_pr_vec;
    vector<int>* comp;
    int num_of_nodes
};

}