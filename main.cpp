#include <iostream>
#include "include/graph.h"
#include "include/connected-component.h"
#include "include/page-rank.h"
#include <fstream>
#include <vector>
#include <cmath>
#include "/home/ep7/cs225git/eigen-3.4.0/Eigen/Sparse"

using namespace finalproject;

using namespace Eigen;

int main() {
    // Graph g(281903);


    // if compiling with CMake from the build directory, uncomment the line below:
    // std::ifstream input_file("../data/web-stanford.txt");

    // if compiling with the g++ command on the ReadMe, use the line below:
    //std::ifstream input_file("./data/web-stanford.txt");


    // if (input_file.is_open()) {
    //     input_file >> g;
    //     input_file.close();
    // }
    
    // Uncomment to see printing of all nodes of graph
    //g.print();

    //std::vector<int>* adj_list = g.getList();

    // Let's look at the neighbors of the first node, as well as the neighbors of the last neighbor of the first node,
    // to help us test our shortest path function
    // std::cout << "\nNeighbors of node 0:" << std::endl;
    // for (unsigned int i = 0; i < adj_list[0].size(); ++i) {
    //     std::cout << adj_list[0][i] << std::endl;
    // }
    // std::cout <<  g.getNodes() << endl;
    // std::cout << "\nNeighbors of node 44103:" << std::endl;
    // for (unsigned i = 0; i < adj_list[44103].size(); ++i) {
    //     std::cout << adj_list[44103][i] << std::endl;
    // }
    // std::cout << "\nNeighbors of node 15409:" << std::endl;
    // for (unsigned int i = 0; i < adj_list[15409].size(); ++i) {
    //     std::cout << adj_list[15409][i] << std::endl;
    // }

    //std::cout << "\nSo, the shortest path from 0 to 13102 should have a distance of 2, and the middle node in the path sequence should be through 15409:\n" << std::endl;

    //g.BFS(1);
    //g.printShortestPath(13102);

    //std::cout << "\nLet's test out our shortest path function a bit more:\n" << std::endl;

    //g.printShortestPath(6548);

    //std::cout << "\nLet's do it again after changing the source vertex by calling BFS with a different parameter:\n" << std::endl;

    //g.BFS(105318);
    //g.printShortestPath(36606);

    //std::cout <<std::endl;


    //ConnectedComponent c;
    //std::vector<std::vector<int>> vec = c.kosaraju(g);
    // Uncomment to see all connected components printed out
    // c.print();
    // Uncomment the line below to view the largest connected component and its size
    // c.printLargest();
    //std::cout << "Number of Connected Components: " << vec.size() << std::endl;

    // Vector<long double, Dynamic> v(4);
    // for (int i = 0; i < v.size(); i++) {
    //     v[i] = 0.25;
    // }
    //std::cout << v << std::endl;

    // SparseMatrix<long double> T(4, 4);

    // T.coeffRef(1, 0) = (long double) 1/3;
    // T.coeffRef(2, 0) = (long double) 1/3;
    // T.coeffRef(3, 0) = (long double) 1/3;
    // // T.coeffRef(0, 1) = 0.5;
    // T.coeffRef(3, 1) = 1;

    // T.coeffRef(0, 2) = 0.25;
    // T.coeffRef(1, 2) = 0.25;
    // T.coeffRef(2, 2) = 0.25;
    // T.coeffRef(3, 2) = 0.25;


    // T.coeffRef(0, 3) = 0.5;
    // T.coeffRef(2, 3) = 0.5;

    // std::cout << T << std::endl;
    // std::cout << v << std::endl;

    // long double error = 1;
    // long double tol = 1e-7;
    // unsigned count = 0;

    // while (error > tol) {
    //     long double temp1 = v[0]; long double temp2 = v[1]; long double temp3 = v[2]; long double temp4 = v[3];

    //     v = T * v;
    //     error = (std::abs(temp1 - v[0]) + std::abs(temp2 - v[1]) + std::abs(temp3 - v[2]) + std::abs(temp4 - v[3]))/4;

    //     std::cout << "Iteration " << count << ": \n" << std::endl;
    //     std::cout << "           Vector: [" << v.transpose() << "] \n" << std::endl;
    //     std::cout << "           Error v[0]: " << std::abs(temp1 - v[0]) << std::endl;
    //     std::cout << "           Error v[1]: " << std::abs(temp2 - v[1]) << std::endl;
    //     std::cout << "           Error v[2]: " << std::abs(temp3 - v[2]) << std::endl;
    //     std::cout << "           Error v[3]: " << std::abs(temp4 - v[3]) << std::endl << "\n";
    //     std::cout << "           Average Error: " <<  error << "\n" << std::endl; 

    //     count++;
    // }


    Graph p(4);
    std::ifstream input("../data/test-small-pr.txt");

    if (input.is_open()) {
        input >> p;
        input.close();
    }

    PageRank r(p, false, 1000);
    r.runPageRank();

    return 0;
}
