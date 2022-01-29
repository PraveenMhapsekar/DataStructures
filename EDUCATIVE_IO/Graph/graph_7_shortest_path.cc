// is unidirected find min distance between two vertices
// Algo
//  - do bfs traverse from src
//  - increment distance at every level
//  - continue till dst is reached.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <queue>

using namespace std;
#define NUM 4
int 
findMin(int graph[NUM][NUM], int size, int src, int dst) {
	if (src == dst){
		return 0;
	}

	bool *visited = new bool[size];
	int *distance = new int[size];
	queue<int> q;
	int i;

  // push src and mark it visited
	q.push(src);
	visited[src] = true;

	// BFS Traverse while queue is not empty
	while (!q.empty()) {
		//Dequeue a vertex from queue
		i = q.front(); q.pop();
		// Get adjacent vertices to the vertex
		// if vertex is not visited then enqueue it in the Queue
		// Increment distance from the src
    int j = 0;
		while (j < size) {
      if (graph[i][j] == 1) {
				if (!visited[j]) {
					q.push(j);
					visited[j] = true;
					distance[j] = distance[i] + 1;
				}
				if (j == dst) {
          // dst is reached, return distance
					return distance[dst];
				}
      }
			j++;
		}
	}

  // Cleanup
	delete[] distance;
  delete[] visited;
	return -1;
}

/*
     0
    / \
   1   2
        \     =>  
         3
     1
      \
       0
        \
         2
          \
           3
*/
int
main() {
  int graph[NUM][NUM] = {{0, 1, 1, 0},  // 0 -->1, 2
											   {1, 0, 0, 0},  // 1 --> 
											   {0, 0, 0, 1},  // 2 -->3
											   {0, 0, 0, 0}}; // 3 -->

  printf("graph min betwen 1, 3 is %d\n", findMin(graph, NUM, 1, 3));
  return 0;
}
