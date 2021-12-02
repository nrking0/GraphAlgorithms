#include "../include/graph.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <regex>

namespace finalproject {

Graph::Graph(int nodes) {
    this->nodes = nodes;
    adjacency_list = new std::vector<int>[nodes];
}

Graph::~Graph() {
    delete[] adjacency_list;
    adjacency_list = nullptr;
}

void Graph::addEdge(int a, int b) {
    this->adjacency_list[a].push_back(b);
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

std::istream& operator>>(istream& is, Graph& g) {
    std::string curr_line;
    while (std::getline(is, curr_line)) {
        std::vector<int> nodes;

        std::string num = "";
        for (char c : curr_line) {
            if (std::isdigit(c)) {
                num += c;
            } else if (num.size() > 0) {
                nodes.push_back(stoi(num));
                num = "";
            } else {
                num = "";
            }
        }

        if (num.size() > 0) {
            nodes.push_back(stoi(num));
            num = "";
        }

        g.addEdge(nodes[0], nodes[1]);
    }

    return is;
}


void Graph::print() {
    for (int i = 0; i < nodes; i++) {
        std::vector<int> temp = adjacency_list[i];
        for (int j : temp) {
            std::cout << "(" << i << ", " << j << ")" << std::endl;
        }
    }
}


bool Graph::isNode(int a, int b) const {
    if (a > nodes || b > nodes) return false;

    for (int i : adjacency_list[a]) {
        if (i == b) return true;
    }

    return false;
}

std::vector<int>* Graph::getList() const {
    return adjacency_list;
}

int Graph::getNodes() const {
    return nodes;
}

}
