/*
 * main.c
 *
 *  Created on: 2015. 5. 4.
 *      Author: Administrator
 */

#include "graph.h"

int main() {
	Graph graph;
	int start_num;

	read_graph(&graph, FALSE);

	printf("\tGraph Allocation\n");
	print_graph(&graph);

	printf("\nstart vertex : ");
	scanf("%d", &start_num);
	printf("\tBFS\n");
	bfs(&graph, start_num);
	printf("\tDFS\n");
	dfs(&graph, start_num);

	return 0;
}

/* QUEUE */
void init_queue(Queue *q) {
	q->first = 0;
	q->last = QUEUE_SIZE - 1;
	q->count = 0;
}

void enqueue(Queue *q, int x) {
	if (q->count >= QUEUE_SIZE)
		printf("queue overflow!\n");
	else {
		q->last = (q->last + 1) % QUEUE_SIZE;
		q->q[q->last] = x;
		q->count = q->count + 1;
	}
}

int dequeue(Queue *q) {
	int x;

	if (q->count <= 0)
		printf("queue empty!\n");
	else {
		x = q->q[q->first];
		q->first = (q->first + 1) % QUEUE_SIZE;
		q->count = q->count - 1;
	}
	return (x);
}

int empty(Queue *q) {
	if (q->count <= 0)
		return (TRUE);
	else
		return (FALSE);
}
/* QUEUE END */

/* GRAPH */
void read_graph(Graph *g, BOOL directed) {
	int i, m, x, y;

	initialize_graph(g);

	printf("Input Graph. ex) vertex_num edge_num\n");
	scanf("%d %d", &(g->nvertices), &m);
	printf("Input Edges. ex) vertex_num vertex_num\n");

	for (i = 1; i <= m; i++) {
		scanf("%d %d", &x, &y);
		insert_edge(g, x, y, directed);
	}
}

void initialize_graph(Graph *g) {
	int i = 0;
	g->nvertices = 0;
	g->nedges = 0;
	for (i = 1; i <= MAX_VERTEX; i++)
		g->degree[i] = 0;
}

void insert_edge(Graph *g, int x, int y, BOOL directed) {
	if (g->degree[x] > MAX_DEGREE)
		printf("Insertion exceeds max degree!\n");
	g->edges[x][g->degree[x]] = y;
	g->degree[x]++;

	if (directed == FALSE)
		insert_edge(g, y, x, TRUE);
	else
		g->nedges++;
}

void print_graph(Graph *g) {
	int i, j;

	for (i = 1; i <= g->nvertices; i++) {
		printf("%d: ", i);
		for (j = 0; j < g->degree[i]; j++)
			printf(" %d", g->edges[i][j]);
		printf("\n");
	}
}
/* GRAPH END */

