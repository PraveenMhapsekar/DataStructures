// is unidirected find min distance between two vertices
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

	//Bool Array to hold the history of visited nodes (by default-false)
	//Make a node visited whenever you enqueue it into queue
	bool *visited = new bool[size];

	//For keeping track of distance of current_node from src
	int *distance = new int[size];

	//Create Queue for Breadth First Traversal and enqueue src in it
	queue<int> q;
	int i;
	q.push(src);
	visited[src] = true;

	// BFS Traverse while queue is not empty
	while (!q.empty()) {
		//Dequeue a vertex/node from queue and add it to result
		i = q.front(); q.pop();
		//Get adjacent vertices to the current_node from the array,
		//and if they are not already visited then enqueue them in the Queue
		//and also update their distance from src by adding 1 in current_nodes's distance
    int j = 0;
		while (j < size) {
      if (graph[i][j] == 1) {
				if (!visited[j]) {
					q.push(j);
					visited[j] = true;
					distance[j] = distance[i] + 1;
				}
				if (j == dst) {
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
        \
         3
*/
int
main() {
  int graph[NUM][NUM] = {{0, 1, 1, 0},  // 0 -->1, 2
											   {0, 0, 0, 0},  // 1 --> 
											   {0, 0, 0, 1},  // 2 -->3
											   {0, 0, 0, 0}}; // 3 -->

  printf("graph min betwen 0, 3 is %d\n", findMin(graph, NUM, 0, 3));
  return 0;
}
