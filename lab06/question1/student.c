#include "graph.h"

// Count the number of edges in an undirected graph
int count_edges(Graph* g) {
    int total = 0;

    for (int u = 0; u < MAX_NODES; u++) {
        for (int v = u + 1; v < MAX_NODES; v++) { // only upper triangle
            if (g->adj[u][v] == 1) total++;
        }
    }

    return total;
}
