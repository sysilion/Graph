/*
 * dfs.c
 *
 *  Created on: 2015. 5. 7.
 *      Author: Administrator
 */

#include "graph.h"

BOOL dfs_discovered[MAX_VERTEX];	// dfs_discovered vertex
BOOL dfs_processed[MAX_VERTEX];		// dfs_processed vertex
int dfs_parent[MAX_VERTEX];			// relation between dfs_parent and children

void dfs(Graph *g, int v) {
	int i;
	if (dfs_discovered[v])
		return;
	dfs_discovered[v] = TRUE;
	process_vertex(v); // process
	dfs_processed[v] = TRUE;

	for (i = 0; i < g->degree[v]; i++) {
		if (valid_edge(g->edges[v][i]) == TRUE) {
			if (dfs_discovered[g->edges[v][i]] == FALSE) {
				dfs_parent[g->edges[v][i]] = v;
				dfs(g, g->edges[v][i]);
			}
//			if (dfs_processed[g->edges[v][i]] == TRUE)
//				process_edge(v, g->edges[v][i]);
		}
	}
}
