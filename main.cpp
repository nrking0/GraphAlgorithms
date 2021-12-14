/**
 * @file main.cpp
 * @author Nick King (nrking2), Jimmy Huang (jhuan35), Eduardo Palmares (ep7), Abhyudhaya Venkatasubramanian (av13)
 * @brief Informally tests all the major functionalities of this project. These functionalities include:
 * - Creating a graph from the Stanford web dataset
 * - Finding the shortest path between any 2 nodes
 * - Traversing the whole graph with BFS
 * - Finding the strongly connected components with Kosaraju's algorithm
 * - Finding the most important nodes with the Page Rank algorithm
 * 
 * Feel free to comment out / uncomment different parts to see the output of the different functionalities.
 * Notably, if you want to run the entire BFS traversal, uncomment lines 93 through 95.
 * 
 * @date 2021-12-12
 * 
 */

#include <iostream>
#include "include/graph.h"
#include "include/connected-component.h"
#include "include/page-rank.h"
#include <fstream>
#include <vector>
#include <cmath>
#include "../eigen-3.4.0/Eigen/Sparse"

using namespace finalproject;

using namespace Eigen;

int main() {
    // Reading the text file into a graph

    Graph g(281903);

    // if compiling with CMake from the build directory, uncomment the line below:
    std::ifstream input_file("../data/web-stanford.txt");

    // if compiling with the g++ command on the ReadMe, use the line below:
    // std::ifstream input_file("./data/web-stanford.txt");

    if (input_file.is_open()) {
        input_file >> g;
        input_file.close();
    }

    // Uncomment to see printing of all nodes of graph
    // std::cout << g;

    //-----------------------------------------------------------------------------------------------------
    // BFS and Shortest Path
    std::cout << "\n\n\n\n\nBFS and Shortest Path Demo:\n\n" << std::endl;

    std::vector<int>* adj_list = g.getList();

    // Let's look at the neighbors of the first node, as well as the neighbors of the last neighbor of the first node,
    // to help us test our shortest path function
    std::cout << "\nNeighbors of node 1:" << std::endl;
    for (int i = 0; i < (int) adj_list[1].size(); ++i) {
        std::cout << adj_list[1][i] << std::endl;
    }
    std::cout << "\nNeighbors of node 15409:" << std::endl;
    for (int i = 0; i < (int) adj_list[15409].size(); ++i) {
        std::cout << adj_list[15409][i] << std::endl;
    }

    std::cout << "\nSo, the shortest path from 1 to 13102 should have a distance of 2,\nand the middle node in the path sequence should be through 15409:\n" << std::endl;

    std::vector<int> traversal_1 = g.BFS(1);
    std::vector<int> path_1 = g.getShortestPath(13102);
    for (int i : path_1) {
        std::cout << i << std::endl;
    }

    std::cout << "\nLet's test out our shortest path function a bit more\nby making sure that the shortest path from 1 to 6548 has length 1:\n" << std::endl;

    std::vector<int> path_2 = g.getShortestPath(6548);
    for (int i : path_2) {
        std::cout << i << std::endl;
    }

    std::cout << "\nLet's do it again after changing the source vertex \nby calling BFS with the start node as 105318,\nand then seeing what the shortest path to 36606 is:" << std::endl;

    std::vector<int> traversal_2 = g.BFS(105318);
    std::vector<int> path_3 = g.getShortestPath(36606);
    for (int i : path_3) {
        std::cout << i << std::endl;
    }

    std::cout << "\nPrint out all nodes in entire graph:\n" << std::endl;

    std::vector<int> traversal_all = g.bfsAll();
    // for (int node : traversal_all) {
    //     std::cout << node << ", ";
    // }
    std::cout << "\n\nWe traversed a total of " << traversal_all.size() << " nodes" << std::endl;


    //-----------------------------------------------------------------------------------------------------
    // Kosaraju's Algorithm for Strongly Connected Components
    std::cout << "\n\n\n\n\nKosaraju's Algorithm Demo:\n\n" << std::endl;

    std::cout << "\n\n\nTesting Kosaraju's:" << std::endl;


    ConnectedComponent c;
    std::vector<std::vector<int>> vec = c.kosaraju(g);

    // Uncomment to see all strongly connected components printed out
    // c.print();

    // Uncomment the line below to view the largest strongly connected component and its size
    // c.printLargest();

    std::cout << "Number of Connected Components: " << vec.size() << std::endl;

    std::cout << "Number of Nodes in Graph: " << g.getNodes() << std::endl;
    std::cout << "Number of Strongly Connected Components: " << vec.size() << std::endl;

    std::cout << std::endl;

    //-----------------------------------------------------------------------------------------------------
    // Page Rank
    std::cout << "\n\n\n\n\nPage Rank Demo:\n\n" << std::endl;

    std::cout << "\nTesting Page Rank on smaller dataset:\n" << std::endl;
    Graph p(4);
    std::ifstream input("../data/test-small-pr.txt");
    if (input.is_open()) {
        input >> p;
        input.close();
    }

    PageRank r(p, false, 1000);
    r.runPageRank();
    r.printInitialValues();
    
    

    Graph g2(281903);
    std::ifstream input_file2("../data/web-stanford.txt");
    if (input_file2.is_open()) {
        input_file2 >> g2;
        input_file2.close();
    }

    PageRank stan(g2, false, 100);
    stan.runPageRank();
    // stan.printInitialValues();
    std::cout << "\nHere are the top 10 web pages in the Stanford dataset:\n" << std::endl;
    stan.top10Nodes();


    return 0;
}
