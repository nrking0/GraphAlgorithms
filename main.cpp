#include <iostream>
#include "include/graph.h"


int main() {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,1);
    g.addEdge(2,1);
    g.addEdge(3,1);
    g.addEdge(4,1);
    g.print();
    return 0;
}
