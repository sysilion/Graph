/*
 * Graph.h
 *
 *  Created on: 2015. 5. 6.
 *      Author: Administrator
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <stdio.h>
#include <windows.h>

#define MAX_VERTEX	100                // maximum number of vertices
#define MAX_DEGREE	50                // maximum degree of a vertex
#define QUEUE_SIZE	10                // QUEUE SIZE

typedef struct {
	int edges[MAX_VERTEX + 1][MAX_DEGREE];		// adjacency list through array
	int degree[MAX_VERTEX + 1];						// degree of each vertex
	int nvertices;                                // number of vertices in Graph
	int nedges;                                      // number of edges in Graph
} Graph;

typedef struct {
	int q[QUEUE_SIZE];       // queue body
	int first;                           // location of first element in queue
	int last;                           // location of last element in queue
	int count;                        // number of elements in queue
} Queue;

void init_queue(Queue *q);
void enqueue(Queue *q, int x);
int dequeue(Queue *q);
int empty(Queue *q);

void read_graph(Graph *g, BOOL directed);
void initialize_graph(Graph *g);
void insert_edge(Graph *g, int x, int y, BOOL directed);
void insert_edge(Graph *g, int x, int y, BOOL directed);
void print_graph(Graph *g);

void bfs(Graph *g, int start);
BOOL valid_edge(int edge);
void initialize_search(Graph *g);
void process_vertex(int v);
void process_edge(int x, int y);
void find_path(int start, int end, int parents[]);

void dfs(Graph *g, int v);

#endif /* GRAPH_H_ */
