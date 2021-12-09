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

    visited.clear();
    visited = vector<bool>(g.getNodes(), false);
    Graph transpose = g.getTranspose();

    while(!st.empty()) {
        int n = st.top();
        st.pop();

        if (!visited[n]) {
            vector<int> component;
            assign(n, transpose, component);
            components.push_back(component);
        }

    }

    return components;
    
}

void ConnectedComponent::visit(int node, const Graph& g) {
    if (!visited[node]) {
        visited[node] = true;
        vector<int> list = g.getList()[node];
        for (int i = 1; i < list.size(); i++) {
            visit(list[i], g);
        }
        st.push(node);
    }
}

void ConnectedComponent::assign(int node, const Graph& g, vector<int> component) {
    if (!visited[node]) {
        visited[node] = true;
        component.push_back(node);
        for (int i : g.getList()[node]) {
            if (!visited[i]) {
                assign(i, g, component);
            }
        }
    }
}

}