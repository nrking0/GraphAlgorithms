#include "../include/connected-component.h"
#include "../include/graph.h"
#include "../include/page-rank.h"
#include <vector>
#include <iostream>

using namespace std;

namespace finalproject {

    PageRank::PageRank() {}

    PageRank::~PageRank() { }

    PageRank::PageRank(const Graph g) {
        comp = g.getList();
        num_of_nodes = g.getNodes();
    }

}