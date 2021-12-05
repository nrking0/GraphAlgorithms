#include "../include/connected-component.h"
#include "../include/graph.h"
#include <vector>
#include <stack>

using namespace std;

namespace finalproject {

ConnectedComponent::ConnectedComponent() { }

vector<vector<int>> ConnectedComponent::kosaraju(const Graph& g) {
    visited.clear();
    visited = vector<bool>(g.getNodes(), false);

    for (int i = 0; i < g.getNodes(); i++) {
        visit(i, g);
    }    

    
}

void ConnectedComponent::visit(int node, const Graph& g) {
    if (!visited[node]) {
        visited[node] = true;
        vector<int> list = g.getList()[node];
        for (int i = 1; i < list.size(); i++) {
            visit(list[i], g);
        }
        stack_.push(node);
    }
}

}