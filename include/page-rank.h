#pragma once

#include "graph.h"
#include <iostream>
#include <vector>
#include <cmath>
#include "../eigen-3.4.0/Eigen/Sparse"

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

    /**
     * @brief Runs the main Page Rank algorithm.
     * 
     */
    void runPageRank();

    long double columnSum(int col);
    long double initSum();
    unsigned int getNumOfNodes();
    SparseMatrix<long double> getTransMatrix();
    Vector<long double, Dynamic> getInitVec();

    /**
     * @brief Prints the top 10 most popular web pages. These are the 10 biggest entries in the steady-state vector.
     * 
     */
    void top10Nodes();


    private:
    unsigned int num_of_nodes;

    /**
     * @brief The transition matrix used to perform power iteration. Each column sums to 1.
     * 
     */
    SparseMatrix<long double> transition_matrix;
    
    Vector<long double, Dynamic> init_pr_vec;
    vector<int>* comp;
    bool track;
    int num_iterations;
};

}
