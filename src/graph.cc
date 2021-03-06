/**
 * @file graph.cc
 * @author Nick King (nrking2), Jimmy Huang (jhuan35), Eduardo Palmares (ep7), Abhyudhaya Venkatasubramanian (av13)
 * @brief Implementation of all functions declared in graph.h.
 * @date 2021-12-12
 * 
 */

#include "../include/graph.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include <queue>

namespace finalproject {

// Initialize predecessor vector with -1 for every node.
// Initialize distance vector with 0 for every node.
// Set source_ as 0 by default
Graph::Graph(int nodes) {
    this->nodes = nodes;
    adjacency_list = new std::vector<int>[nodes];
    predecessor = std::vector<int>(nodes, -1);
    distance.resize(nodes);
    source_ = 0;
}

// Graph::~Graph() {
//     delete[] adjacency_list;
//     // adjacency_list = nullptr;
// }

void Graph::addEdge(int a, int b) {
    this->adjacency_list[a].push_back(b);
}

Graph Graph::getTranspose() const {
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

        // Read in digits one by one
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

        // Make edge from first number to second number
        g.addEdge(nodes[0], nodes[1]);
    }

    return is;
}


std::ostream& operator<<(ostream& os, Graph& g) {
    for (int i = 0; i < g.getNodes(); i++) {
        std::vector<int> temp = g.getList()[i];
        for (int j : temp) {
            os << "(" << i << ", " << j << ")" << std::endl;
        }
    }

    return os;
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
std::vector<int> Graph::BFS(int source) {
    std::vector<int> to_return;

    // Set source_ private variable and reset predecessor and distance vectors
    source_ = source;
    predecessor = std::vector<int>(nodes, -1);
    distance = std::vector<int>(nodes, 0);

    // Set up data structures. 
    // We will also be using the predecessor and distance vectors, but those have already been set.
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
    int count = 0;
    while (!queue_.empty()) {
        curr = queue_.front();
        queue_.pop();
        // We can process the node "curr" right here if we want (like printing it out)
        to_return.push_back(curr);
        for (int i = 0; i < (int) adjacency_list[curr].size(); ++i) {
            neighbor = adjacency_list[curr][i];
            if (visited[neighbor] == false) {
                visited[neighbor] = true;
                queue_.push(neighbor);
                predecessor[neighbor] = curr;
                distance[neighbor] = distance[curr] + 1;
                ++count;
            }
        }
    }

    return to_return;
}

// This function can ONLY be called after BFS or bfsAll is called.
// Uses the predecessor and distance vectors populated by BFS to get the shortest path 
// from the source passed into BFS to the destination vertex passed into this function
std::vector<int> Graph::getShortestPath(int dest) {
    std::vector<int> backwards_path;

    // Return empty vector if there is no path from source_ to dest
    if (predecessor[dest] == -1) {
        return backwards_path;
    }

    // Keep following the predecessor vector starting from the node dest
    int node = dest;
    while (node != -1) {
        backwards_path.push_back(node);
        node = predecessor[node];
    }

    // Reverse the backwards_path vector
    std::vector<int> to_return;
    for (int i = backwards_path.size() - 1; i >= 0; --i) {
        to_return.push_back(backwards_path[i]);
    }

    return to_return;
}

// Uses the private helper BFS function to run BFS on every single node. 
// In contrast, the BFS(int source) function only traverses one weakly connected component.
std::vector<int> Graph::bfsAll() {
    std::vector<int> traversal;

    std::vector<bool> visited;
    visited.resize(nodes);

    for (int i = 0; i < nodes; ++i) {
        if (visited[i] == false) {
            BFS(i, visited, traversal);
        }
    }

    return traversal;
}

// Overloaded private helper function only used for bfsAll
void Graph::BFS(int source, vector<bool>& visited, vector<int>& traversal) {
    source_ = source;
    std::queue<int> queue_;

    visited[source] = true;
    queue_.push(source);
    predecessor[source] = -1;
    distance[source] = 0;

    int curr = 0;
    int neighbor = 0;
    while (!queue_.empty()) {
        curr = queue_.front();
        queue_.pop();
        // Add node to "traversal" vector
        traversal.push_back(curr);
        for (int i = 0; i < (int) adjacency_list[curr].size(); ++i) {
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

}
