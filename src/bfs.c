/*
 * bfs.c
 *
 *  Created on: 2015. 5. 6.
 *      Author: Administrator
 */

#include "graph.h"

BOOL bfs_discovered[MAX_VERTEX];      // bfs_discovered vertex
BOOL bfs_processed[MAX_VERTEX];       // bfs_processed vertex
int bfs_parent[MAX_VERTEX];          // relation between bfs_parent and children

void bfs(Graph *g, int start) {
	Queue q;
	int i, v;

	init_queue(&q);
	enqueue(&q, start);
	bfs_discovered[start] = TRUE;

	while (empty(&q) == FALSE) {
		v = dequeue(&q); // bfs_parent
		process_vertex(v); // process
		bfs_processed[v] = TRUE;
		for (i = 0; i < g->degree[v]; i++) {
			if (valid_edge(g->edges[v][i]) == TRUE) {
				if (bfs_discovered[g->edges[v][i]] == FALSE) {
					enqueue(&q, g->edges[v][i]);
					bfs_discovered[g->edges[v][i]] = TRUE;
					bfs_parent[g->edges[v][i]] = v;
				}
//				if (bfs_processed[g->edges[v][i]] == FALSE)
//					process_edge(v, g->edges[v][i]);
			}
		}
	}
}

BOOL valid_edge(int edge) {
	return (edge == 0) ? FALSE : TRUE;
}

void initialize_search(Graph *g) {
	int i;

	for (i = 1; i < g->nvertices; i++) {
		bfs_discovered[i] = bfs_processed[i] = FALSE;
		bfs_parent[i] = -1;
	}
}

void process_vertex(int v) {
	printf("processed vertex %d\n", v);
}

void process_edge(int x, int y) {
	printf("processed edge (%d, %d)\n", x, y);
}

void find_path(int start, int end, int bfs_parents[]) {
	if ((start == end) || (end == -1))
		printf("\n%d", start);
	else {
		find_path(start, bfs_parents[end], bfs_parents);
		printf(" %d", end);
	}
}

