#include "../include/graph.h"
#include <vector>
#include <iostream>


Graph::Graph(int nodes) {
    this->nodes = nodes;
    adjacency_list = new std::vector<int>[nodes];
}

Graph::~Graph() {
    delete[] adjacency_list;
    adjacency_list = nullptr;
}

void Graph::addEdge(int a, int b) {
    adjacency_list[a].push_back(b);
}

Graph Graph::getTranspose() {
    Graph transpose(nodes);
    for (int i = 0; i < nodes; i++) {
        std::vector<int> temp = adjacency_list[i];
        for (int j : temp) {
            transpose.addEdge(j, i);
        }
    }

    return transpose;
}


void Graph::print() {
    for (int i = 0; i < nodes; i++) {
        std::vector<int> temp = adjacency_list[i];
        for (int j : temp) {
            std::cout << "(" << i << ", " << j << ")" << std::endl;
        }
    }
}