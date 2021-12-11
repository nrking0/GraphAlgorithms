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

        long double init_val = (long double) 1/num_of_nodes;
        init_pr_vec.resize(num_of_nodes, init_val);
    }

    void PageRank::printInitialValues() {
        int count = 0; 
        cout << "[";
        for (long double val : init_pr_vec) {
            if (count == 5) {
                cout << "......]" << endl;
                return;
            }
            cout << val << ", ";
            count++;
        }
    }
}