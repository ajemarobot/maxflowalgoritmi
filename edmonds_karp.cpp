/// edmonds_karp.cpp
#include "edmonds_karp.h"
#include "search_helpers.h" 

using namespace std;

int edmondsKarp(Graph& graph, int source, int sink) {
    vector<vector<int>> residualGraph = graph.adjMatrix;
    vector<int> parent(graph.V);
    int maxFlow = 0;

    while (bfs(graph, source, sink, parent, residualGraph)) {
        int pathFlow = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }
    return maxFlow;
}
