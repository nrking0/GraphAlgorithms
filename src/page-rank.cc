#include "../include/connected-component.h"
#include "../include/graph.h"
#include "../include/page-rank.h"
#include <vector>
#include <iostream>

using namespace std;

namespace finalproject {

    PageRank::PageRank() {}

    // PageRank::~PageRank() { 
    //     delete[] comp;
    //     comp = nullptr;
    // }

    PageRank::PageRank(const Graph g, bool log, int numIter) {
        comp = g.getList();
        num_of_nodes = g.getNodes();
        track = log;
        num_iterations = numIter;
        bool shift = false;

        for (unsigned i = 0; i < num_of_nodes; i++) {
            for (unsigned j = 0; j < comp[i].size(); ++j) {
                if ((unsigned int)comp[i][j] == num_of_nodes) {
                    shift = true;
                }
            }
        }
        if (shift == true) {
            for (unsigned i = 0; i < num_of_nodes; i++) {
                for (unsigned j = 0; j < comp[i].size(); ++j) {
                    comp[i][j]--;
                }
            }
        }

        transition_matrix.resize(num_of_nodes, num_of_nodes);
        init_pr_vec.resize(num_of_nodes);

        for (unsigned i = 0; i < init_pr_vec.size(); i++) {
            init_pr_vec[i] = (long double) 1/num_of_nodes;
        }

        for (unsigned i = 0; i < num_of_nodes; i++) {
            long double val = (long double) 1/comp[i].size();
            for (unsigned j = 0; j < comp[i].size(); ++j) {
                transition_matrix.coeffRef(comp[i][j], i) = val;
            }
        }
    }

    
    
    void PageRank::runPageRank() {
        // if (num_of_nodes > 10) {
        //     cout << "Initial Vector: " << init_pr_vec.head(10).transpose() << endl;
        // }
        Vector<long double, Dynamic> tempVec;
        for (int i = 0; i < num_iterations; i++) {
            tempVec = init_pr_vec;
            init_pr_vec = transition_matrix * init_pr_vec;
            if ((i % 10 == 0 || i == 1) && track) {
                long double sum = 0;
                for (unsigned j = 0; j < num_of_nodes; j++) {
                    sum += init_pr_vec[j];
                }
                Vector<long double, Dynamic> error = init_pr_vec - tempVec;
                cout << "Iteration: " << i << endl;
                // cout << "                Error: " << error.cwiseAbs().transpose() << endl;
                cout << "                Vector: ";
                printInitialValues();
                cout << "                Sum: " << sum << endl;
                cout << "                Average Error: " << error.cwiseAbs().sum()/num_of_nodes << endl;
            }
        }
    }

    void PageRank::top10Nodes() {
        vector<pair<double long, int>> vec;
        for (unsigned int i = 0; i < num_of_nodes; i++) {
            vec.push_back(make_pair(init_pr_vec[i],i));
        }
        sort(vec.begin(), vec.end());
        vector<pair<double long, int>> topTen(vec.end() - 10, vec.end());
        reverse(topTen.begin(), topTen.end());
        cout << "Node       Probability" << endl;
        for (auto val : topTen) {
            cout << val.second << "       " << val.first << endl;
        }
    }

    long double PageRank::columnSum(int col) {
        long double sum = 0;
        for (unsigned i = 0; i < init_pr_vec.size(); i++) {
            sum += init_pr_vec[i];
        }
        return sum;
    }

    long double PageRank::initSum() {
        long double sum = 0;
        for (unsigned i = 0; i < init_pr_vec.size(); i++) {
            sum += init_pr_vec[i];
        }
        return sum;
    }

    unsigned int PageRank::getNumOfNodes() {
        return num_of_nodes;
    }

    void PageRank::printTransMatrix() {
        if (num_of_nodes > 30) {
            cout << transition_matrix.topLeftCorner(30, 30);
        } else {
            cout << transition_matrix << endl;
        }
    }

    void PageRank::printInitialValues() {
        if (num_of_nodes > 10) {
            cout << init_pr_vec.head(10).transpose() << endl;
        } else {
            cout << init_pr_vec.transpose() << endl;
        }
    }

    SparseMatrix<long double> PageRank::getTransMatrix() {
        return transition_matrix;
    }

    Vector<long double, Dynamic> PageRank::getInitVec() {
        return init_pr_vec;
    }
}