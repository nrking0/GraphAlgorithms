#pragma once

#include "graph.h"
#include <iostream>
#include <vector>
#include <cmath>
#include "/home/ep7/cs225git/eigen-3.4.0/Eigen/Sparse"

using namespace std;

using namespace Eigen;

namespace finalproject {

class PageRank {

    public:
    PageRank();
    // ~PageRank();
    PageRank(const Graph g, bool log, int numIter);
    void printInitialValues();
    void printTransMatrix();
    void runPageRank();
    long double columnSum(int col);
    long double initSum();
    unsigned int getNumOfNodes();
    SparseMatrix<long double> getTransMatrix();
    Vector<long double, Dynamic> getInitVec();



    private:
    unsigned int num_of_nodes;
    SparseMatrix<long double> transition_matrix;
    Vector<long double, Dynamic> init_pr_vec;
    vector<int>* comp;
    bool track;
    int num_iterations;
};

}