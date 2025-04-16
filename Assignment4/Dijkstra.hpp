#pragma once
#include <vector>
using namespace std;

class Dijkstra {
public:
    static vector<int> run(int V, const vector<vector<vector<int>>> &adj, int src);
};
