#include "../include/graph.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include <queue>

namespace finalproject {

Graph::Graph(int nodes) {
    this->nodes = nodes;
    adjacency_list = new std::vector<int>[nodes];
    predecessor.resize(nodes);
    distance.resize(nodes);
    source = 0;
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

// Performs BFS starting from whatever source vertex is passed in as a parameter.
// This function populates the predecessor and distance vectors given the source vertex.
void Graph::BFS(int source) {
    // Set up data structures. 
    // We will also be using the predecessor and distance vectors, but those have already been resized in the constructor.
    std::queue<int> queue_;
    std::vector<bool> visited;
    visited.resize(nodes);

    // Visit source node. It doesn't really have a predecessor so just make it -1.
    visited[source] = true;
    queue_.push(source);
    predecessor[source] = -1;
    distance[source] = 0;

    // Perform traversal while populating our predecessor and distance vectors
    int curr = 0;
    int neighbor = 0;
    while (!queue_.empty()) {
        curr = queue_.front();
        queue_.pop();
        // We can process the node "curr" right here if we want (like printing it out)
        // std::cout << curr << std::endl;
        
        for (int i = 0; i < adjacency_list[curr].size(); ++i) {
            neighbor = adjacency_list[curr][i];
            if (visited[neighbor] == false) {
                visited[neighbor] = true;
                queue_.push(neighbor);
                predecessor[neighbor] = curr;
                distance[neighbor] = distance[curr] + 1;
            }
        }
    }
}

// This function can ONLY be called after BFS is called.
// Uses the predecessor and distance vectors populated by BFS to show the shortest path 
// from the source passed into BFS to the destination vertex passed into this function
void Graph::printShortestPath(int dest) {
    std::cout << "Distance from " << source << " to " << dest << " is: " << distance[dest] << std::endl;
    std::vector<int> backwards_path;
    int node = dest;
    while (node != -1) {
        backwards_path.push_back(node);
        node = predecessor[node];
    }

    std::cout << "\nShortest path from " << source << " to " << dest << " is: " << std::endl;
    for (int i = backwards_path.size() - 1; i >= 0; --i) {
        std::cout << backwards_path[i] << std::endl;
    }
}

}
