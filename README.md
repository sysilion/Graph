# Graph
Graph BFS, DFS Test

~~~
Input Graph. ex) vertex_num edge_num
8 10
Input Edges. ex) vertex_num vertex_num
1 2
1 3
2 4
2 5
4 8
5 8
6 8
7 8
3 6
3 7
        Graph Allocation
1:  2 3
2:  1 4 5
3:  1 6 7
4:  2 8
5:  2 8
6:  8 3
7:  8 3
8:  4 5 6 7

start vertex : 1
        BFS
processed vertex 1
processed vertex 2
processed vertex 3
processed vertex 4
processed vertex 5
processed vertex 6
processed vertex 7
processed vertex 8
        DFS
processed vertex 1
processed vertex 2
processed vertex 4
processed vertex 8
processed vertex 5
processed vertex 6
processed vertex 3
processed vertex 7
~~~