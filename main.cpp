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

    //**************************************************************

    Graph p(4);
    std::ifstream input("../data/test-small-pr.txt");
    if (input.is_open()) {
        input >> p;
        input.close();
    }

    PageRank r(p, false, 1000);
    r.runPageRank();
    r.printInitialValues();
    
    //**************************************************************

    Graph g(281903);
    std::ifstream input_file("../data/web-stanford.txt");
    if (input_file.is_open()) {
        input_file >> g;
        input_file.close();
    }

    PageRank stan(g, true, 1000);
    stan.runPageRank();
    stan.printInitialValues();


    return 0;
}
