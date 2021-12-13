/**
 * @file graph.cc
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-12
 * 
 * @copyright Copyright (c) 2021
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

Graph::Graph(int nodes) {
    this->nodes = nodes;
    adjacency_list = new std::vector<int>[nodes];
    predecessor.resize(nodes);
    distance.resize(nodes);
    source_ = 0;
}

Graph::~Graph() {
    delete[] adjacency_list;
    adjacency_list = nullptr;
}

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
std::vector<int> Graph::BFS(int source) {
    std::vector<int> to_return;
    source_ = source;

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

// This function can ONLY be called after BFS is called.
// Uses the predecessor and distance vectors populated by BFS to show the shortest path 
// from the source passed into BFS to the destination vertex passed into this function
std::vector<int> Graph::getShortestPath(int dest) {
    std::vector<int> backwards_path;
    int node = dest;
    while (node != -1) {
        backwards_path.push_back(node);
        node = predecessor[node];
    }

    std::vector<int> to_return;
    for (int i = backwards_path.size() - 1; i >= 0; --i) {
        to_return.push_back(backwards_path[i]);
    }

    return to_return;
}

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

std::vector<std::vector<double>> Graph::getMatrix() {
    return matrix;
}

// Populates matrix private variable using adjacency list. Adj list must be already populated.
// This constructs a COLUMN-based matrix.
void Graph::makeMatrix() {
    matrix.resize(nodes);
    for (int i = 0; i < (int) matrix.size(); ++i) {
        matrix[i].resize(nodes);
    }

    for (int i = 0; i < nodes; ++i) {
        for (int j = 0; j < (int) adjacency_list[i].size(); ++j) {
            matrix[adjacency_list[i][j]][i] = 1.0;
            //matrix[i][adjacency_list[i][j]] = 1.0;
        }
    }
}

// Changes the populated matrix into a Markov matrix where the entries represent probabilities and the sum of each column = 1
void Graph::makeMarkov() {
    double column_sum = 0.0;
    for (int col = 0; col < nodes; ++col) {
        column_sum = 0.0;
        for (int row = 0; row < nodes; ++row) {
            column_sum += matrix[row][col];
        }
        // We want to divide every entry in each column by the column sum, but we can't if the sum is 0. So instead we assign equal probability to each entry.
        if (column_sum == 0.0) {
            for (int row = 0; row < nodes; ++row) {
                matrix[row][col] = 1.0 / ((double) nodes);
            }
        } else {
            for (int row = 0; row < nodes; ++row) {
                matrix[row][col] /= column_sum;
            }
        }
    }
}

void Graph::printMatrix() {
    for (int row = 0; row < nodes; ++row) {
        for (int col = 0; col < nodes; ++col) {
            if (col == 0) {
                std::cout << "| " << matrix[row][col];
            } else if (col == nodes - 1) {
                std::cout << " " << matrix[row][col] << " |" << std::endl;
            } else {
                std::cout << " " << matrix[row][col];
            }
        }
    }
}

std::vector<double> Graph::matrixVectorMultiply(vector<double>& x) {
    std::vector<double> result;
    result.resize(nodes);
    if ((int) x.size() != nodes) {
        std::cout << "Argument vector does not have valid shape" << std::endl;
        return result;
    }
    double dot_product = 0.0;
    for (int row = 0; row < nodes; ++row) {
        dot_product = 0.0;
        for (int col = 0; col < nodes; ++col) {
            dot_product += matrix[row][col] * x[col];
        }
        result[row] = dot_product;
    }
    return result;
}

// Input is an arbitrary starting vector whose sum is 1
std::vector<double> Graph::pagerank() {
    std::vector<double> steady_state_vector;

    // Initialize vector arbitrarily (but it's sum must be 1)
    for (int i = 0; i < nodes; ++i) {
        steady_state_vector[i] = 1.0 / ((double) nodes);
    }

    // Pre-mulipty vector by Markov matrix many times until vector converges
    for (int i = 0; i < 1000; ++i) {
        steady_state_vector = matrixVectorMultiply(steady_state_vector);
    }

    return steady_state_vector;
}

}
