#include "graph.h"

// Check whether the graph contains a triangle
int has_triangle(Graph* g) {
    for (int u = 0; u < MAX_NODES; u++) {
        for (int v = u + 1; v < MAX_NODES; v++) {
            if (g->adj[u][v] == 0) continue; // no edge between u and v
            for (int w = v + 1; w < MAX_NODES; w++) {
                if (g->adj[u][w] && g->adj[v][w]) {
                    // edges exist between u-v, u-w, and v-w → triangle found
                    return 1;
                }
            }
        }
    }
    // no triangle found
    return 0;
}
