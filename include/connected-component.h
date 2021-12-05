#pragma once

#include <vector>
#include "graph.h"
#include <stack>

using namespace std;

namespace finalproject {

class ConnectedComponent {
    public:
        ConnectedComponent();
        vector<vector<int>> kosaraju(const Graph& g);

    private:
        vector<vector<int>> components;
        vector<bool> visited;
        stack<int> stack_;

        void visit(int node, const Graph& g);
};

}