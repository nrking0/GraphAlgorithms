#include <iostream>
#include "include/graph.h"
#include "include/connected-component.h"
#include <fstream>
#include <vector>

using namespace finalproject;

int main() {
    Graph g(281903);


    // if compiling with CMake from the build directory, uncomment the line below:
    // std::ifstream input_file("../data/web-stanford.txt");

    // if compiling with the g++ command on the ReadMe, use the line below:
    std::ifstream input_file("./data/web-stanford.txt");


    if (input_file.is_open()) {
        input_file >> g;
        input_file.close();
    }

    // g.print();

    std::vector<int>* adj_list = g.getList();

    // Let's look at the neighbors of the first node, as well as the neighbors of the last neighbor of the first node,
    // to help us test our shortest path function
    std::cout << "\nNeighbors of node 0:" << std::endl;
    for (int i = 0; i < adj_list[0].size(); ++i) {
        std::cout << adj_list[0][i] << std::endl;
    }
    std::cout << "\nNeighbors of node 867923:" << std::endl;
    for (int i = 0; i < adj_list[867923].size(); ++i) {
        std::cout << adj_list[867923][i] << std::endl;
    }

    std::cout << "\nSo, the shortest path from 0 to 857527 should have a distance of 2, and the middle node in the path sequence should be 867923:\n" << std::endl;

    g.BFS(0);
    g.printShortestPath(857527);

    std::cout << "\nLet's test out our shortest path function a bit more:\n" << std::endl;

    g.printShortestPath(123782);

    std::cout << "\nLet's do it again after changing the source vertex by calling BFS with a different parameter:\n" << std::endl;

    g.BFS(573863);
    g.printShortestPath(777293);


    ConnectedComponent c;
    std::vector<std::vector<int>> vec = c.kosaraju(g);
    // c.print();
    std::cout << "Number of Connected Components: " << vec.size() << std::endl;
    

    return 0;
}
