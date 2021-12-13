/**
 * @file connected-component.h
 * @author Nick King (nrking2), Jimmy Huang (jhuan35), Eduardo Palmares (ep7), Abhyudhaya Venkatasubramanian (av13)
 * @brief This class is used to perform Kosaraju's algorithm on the graph.
 * This algorithm finds all the strongly connected components of the graph.
 * 
 * @date 2021-12-12
 * 
 */

#pragma once

#include <vector>
#include "graph.h"
#include <stack>

using namespace std;

namespace finalproject {

class ConnectedComponent {
    public:
        /**
         * @brief Construct a new Connected Component object with empty components 2D vector and empty stack.
         * 
         */
        ConnectedComponent();

        /**
         * @brief Run's Kosaraju's algorithm and returns the SCCs.
         * 
         * @param g 
         * @return vector<vector<int>> SCCs
         */
        vector<vector<int>> kosaraju(const Graph& g);

        /**
         * @brief Get the Components object
         * 
         * @return vector<vector<int>> components 2D vector
         */
        vector<vector<int>> getComponents();

        /**
         * @brief Prints components in 2D vector.
         * 
         */
        void print();

        /**
         * @brief Prints the biggest SCC.
         * 
         */
        void printLargest();

        /**
         * @brief Free memory allocated for the 2D vector and stack.
         * 
         */
        ~ConnectedComponent();

    private:
        // Pointer to 2D vector
        vector<vector<int>>* components;

        vector<bool> visited;

        // Pointer to stack
        stack<int>* st;

        /* helper functions */
        void visit(int node, const Graph& g);
        void assign(int node, const Graph& g, vector<int>& component);
};

}