#include "Dijkstra.hpp"
#include <queue>
#include <climits>


vector<int> Dijkstra::run(int V, const vector<vector<vector<int>>> &adj, int src) {
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<int> dist(V, INT_MAX);

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top()[1];
        pq.pop();

        for (const auto &x : adj[u]) {
            int v = x[0];
            int weight = x[1];

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}
