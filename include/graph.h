/**
 * @file graph.h
 * @author Nick King (nrking2), Jimmy Huang (jhuan35), Eduardo Palmares (ep7), Abhyudhaya Venkatasubramanian (av13)
 * @brief This graph class represents the Stanford web dataset with an adjacency list.
 * Functionality for reading text files of a simple format is supported.
 * The graph can also be traversed with BFS.
 * @date 2021-12-12
 * 
 */

#pragma once

#include <vector>
#include <iostream>

using namespace std;

namespace finalproject {

class Graph {
    public:
        /**
         * @brief Construct a new Graph object with a specified number of nodes.
         * Adjacency list is initialized with specified number of internal vectors.
         * 
         * @param nodes 
         */
        Graph(int nodes);

        /**
         * @brief Destroy the Graph object. Frees memory allocated for the adjacency list.
         * 
         */
        ~Graph();

        /**
         * @brief Adds a directed edge from node a to node b.
         * 
         * @param a 
         * @param b 
         */
        void addEdge(int a, int b);

        /**
         * @brief Computes the transpose of the graph, which is useful for Kosaraju's algorithm.
         * 
         * @return Graph 
         */
        Graph getTranspose() const;

        /**
         * @brief Reads in entire graph from txt file and populates adjacency list accordingly.
         * 
         * @param is 
         * @param g 
         * @return istream& 
         */
        friend istream& operator>>(istream& is, Graph& g);

        void print();

        /**
         * @brief Checks if b is a node that a has a directed edge to.
         * 
         * @param a 
         * @param b 
         * @return true if edge ab exists
         * @return false if edge ab does not exist
         */
        bool isNode(int a, int b) const;

        /**
         * @brief Returns the adjacency list
         * 
         * @return vector<int>* 
         */
        vector<int>* getList() const;

        /**
         * @brief Returns the number of nodes in the graph.
         * 
         * @return int 
         */
        int getNodes() const;

        /**
         * @brief General BFS function used to traverse from an arbitrary source node.
         * 
         * @param source 
         * @return vector<int> of nodes in order of traversal
         */
        vector<int> BFS(int source);

        /**
         * @brief Returns a vector of the nodes in the shortest path from the source defined in BFS(int source)
         * to the provided dest. Returns an empty vector if there is no path from source to dest.
         * 
         * @param dest 
         * @return vector<int> of nodes in order of path
         */
        vector<int> getShortestPath(int dest);

        /**
         * @brief Completes BFS traversal of entire graph
         * 
         * @return vector<int> of nodes in order of traversal
         */
        vector<int> bfsAll();

        // (May or may not need...)
        std::vector<std::vector<double>> getMatrix();
        void makeMatrix();
        void makeMarkov();
        void printMatrix();
        vector<double> matrixVectorMultiply(vector<double>& x);
        vector<double> pagerank();

    private:
        // Array of vectors to store graph
        vector<int>* adjacency_list;  

        // Number of nodes in graph
        int nodes;

        // Define a source node for the graph. This is changed when BFS is called.
        int source_;

        // Contains predecessor of every node. Only is populated after BFS is called with an arbitrary source node.
        vector<int> predecessor;

        // Contains distance from arbitrary source to any node. Only is populated after BFS is called with an arbitrary source node.
        vector<int> distance;

        // (May or may not need...)
        // Matrix for use in pagerank. Store doubles since we will be converting this adjacency matrix into a Markov matrix
        // Note that this is a COLUMN-based matrix. (edge ij exists <==> a_ji == 1)
        vector<vector<double>> matrix;

        // Overloaded BFS helper function to be used in bfsAll function
        void BFS(int source, vector<bool>& visited, vector<int>& traversal);
};

}
