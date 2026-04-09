#include "graph.h"

// Count the number of isolated nodes in the graph
int count_isolated(Graph* g) {
    int count = 0;

    for (int u = 0; u < MAX_NODES; u++) {
        int isolated = 1;  // assume node u is isolated
        for (int v = 0; v < MAX_NODES; v++) {
            if (g->adj[u][v] == 1) {
                isolated = 0; // node u has an edge
                break;
            }
        }
        if (isolated) count++;
    }

    return count;
}
