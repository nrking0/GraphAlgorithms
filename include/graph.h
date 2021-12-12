#pragma once

#include <vector>
#include <iostream>

using namespace std;

namespace finalproject {

class Graph {
    public:
        Graph(int nodes);
        ~Graph();
        void addEdge(int a, int b);
        Graph getTranspose() const;
        friend istream& operator>>(istream& is, Graph& g);
        void print();
        bool isNode(int a, int b) const;
        vector<int>* getList() const;
        int getNodes() const;
        // General BFS function used to traverse from an arbitrary node
        void BFS(int source);
        void printShortestPath(int dest);
        // Complete BFS traversal of entire graph and returns vector of nodes in order of traversal
        vector<int> bfsAll();

        std::vector<std::vector<double>> getMatrix();
        void makeMatrix();
        void makeMarkov();
        void printMatrix();
        vector<double> matrixVectorMultiply(vector<double>& x);

        vector<double> pagerank(vector<double>& x);

    private:
        vector<int>* adjacency_list;  
        int nodes;  
        // Define a source node for the graph. This is changed when BFS is called.
        int source_;
        // Contains predecessor of every node. Only is populated after BFS is called with an arbitrary source node.
        vector<int> predecessor;
        // Contains distance from arbitrary source to any node. Only is populated after BFS is called with an arbitrary source node.
        vector<int> distance;

        // Matrix for use in pagerank. Store doubles since we will be converting this adjacency matrix into a Markov matrix
        // Note that this is a COLUMN-based matrix. (edge ij exists <==> a_ji == 1)
        vector<vector<double>> matrix;

        // Overloaded BFS function to be used for bfsAll function
        void BFS(int source, vector<bool>& visited, vector<int>& traversal);
};

}
