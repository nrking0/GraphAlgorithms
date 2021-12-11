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
    void printInitialValues();


    private:
    vector<vector<long double>> transition_matrix;
    vector<long double> init_pr_vec;
    vector<int>* comp;
    int num_of_nodes;
};

}