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
    void runPageRank();
    long double columnSum(int col);
    long double initSum();
    unsigned int getNumOfNodes();
    SparseMatrix<long double> getTransMatrix();
    Vector<long double, Dynamic> getInitVec();
    void top10Nodes();
<<<<<<< HEAD

=======
>>>>>>> 8c4f9c189b8c342f57241e29139baa3f3df3d01c


    private:
    unsigned int num_of_nodes;
    SparseMatrix<long double> transition_matrix;
    Vector<long double, Dynamic> init_pr_vec;
    vector<int>* comp;
    bool track;
    int num_iterations;
};

}
