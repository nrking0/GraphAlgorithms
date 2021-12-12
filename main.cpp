#include <iostream>
#include "include/graph.h"
#include "include/connected-component.h"
#include <fstream>
#include <vector>

using namespace finalproject;

int main() {
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
    // g.print();

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

    std::cout << "\nSo, the shortest path from 0 to 13102 should have a distance of 2, and the middle node in the path sequence should be through 15409:\n" << std::endl;

    g.BFS(1);
    g.printShortestPath(13102);

    std::cout << "\nLet's test out our shortest path function a bit more:\n" << std::endl;

    g.printShortestPath(6548);

    std::cout << "\nLet's do it again after changing the source vertex by calling BFS with a different parameter:\n" << std::endl;

    g.BFS(105318);
    g.printShortestPath(36606);

    std::cout << "\nPrint out all nodes in entire graph:\n" << std::endl;

    std::vector<int> traversal = g.bfsAll();
    // for (int node : traversal) {
    //     std::cout << node << ", ";
    // }
    std::cout << "\n\nWe traversed a total of " << traversal.size() << " nodes" << std::endl;

    std::cout << "\n\n\nTesting Kosaraju's:" << std::endl;


    ConnectedComponent c;
    std::vector<std::vector<int>> vec = c.kosaraju(g);
    // Uncomment to see all strongly connected components printed out
    // c.print();
    // Uncomment the line below to view the largest strongly connected component and its size
    // c.printLargest();
    std::cout << "Number of Strongly Connected Components: " << vec.size() << std::endl;
    




    // Test basic matrix functionality.
    std::cout << "\n\n\nTesting basic matrix functionality:\n\n\n";
    Graph g2(3);
    g2.addEdge(0,1);
    g2.addEdge(1,0);
    g2.addEdge(1,2);
    g2.addEdge(2,0);

    g2.makeMatrix();
    g2.printMatrix();
    
    std::cout << std::endl;

    g2.makeMarkov();
    g2.printMatrix();




    std::cout << "\n\n\nTesting basic matrix functionality with another small graph:\n\n\n";
    Graph g3(4);
    g3.addEdge(0,1);
    g3.addEdge(0,3);
    g3.addEdge(1,2);
    g3.addEdge(1,3);
    g3.addEdge(2,0);

    g3.makeMatrix();
    g3.printMatrix();

    std::cout << std::endl;

    g3.makeMarkov();
    g3.printMatrix();



    // Based on testing this out in Python, the final steady-state vector should be:
    // [0.23076923 0.15384615 0.30769231 0.30769231]
    std::cout << "\n\n\nTest pagerank on small 4x4 matrix:\n\n\n";
    Graph g4(4);
    g4.addEdge(0,1);
    g4.addEdge(0,2);
    g4.addEdge(0,3);
    g4.addEdge(1,3);
    g4.addEdge(3,0);
    g4.addEdge(3,2);

    g4.makeMatrix();
    g4.printMatrix();

    std::cout << std::endl;

    g4.makeMarkov();
    g4.printMatrix();

    std::cout << std::endl;

    std::vector<double> start_vector{0.25, 0.25, 0.25, 0.25};

    std::vector<double> steady_state_vector = g4.pagerank(start_vector);
    for (double d : steady_state_vector) {
        std::cout << d << ", ";
    }
    std::cout << "\n\n\n";



    // std::cout <<"\nFinally, let's run pagerank on the entire graph:\n" << std::endl;
    // g.makeMatrix();
    // g.makeMarkov();
    // std::vector<double> initial_vector(281903, 1.0 / 281903.0);
    // std::vector<double> final_vector = g.pagerank(initial_vector);
    // for (double d : final_vector) {
    //     std::cout << d << ", ";
    // }


    return 0;
}
