// is unidirected find min distance between two vertices
// Algo
//  - do bfs traverse from src
//  - increment distance at every level
//  - continue till dst is reached.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <vector>
#include <queue>

using namespace std;

int 
findMin(vector<vector<int>> graph, int src, int dst) {

	if (src == dst){
		return 0;
	}

  int size = graph[0].size();
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
          // distance[j] is guaranteed to be minimum. 
          // Visited vertex will not be visited again ad it is marked.
          // since this is level order traversal shortest path dest will be visited first.
					return distance[dst];
				}
      }
			j++;
		} // end of while loop
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
  vector<vector<int>> graph = {{0, 1, 1, 0},  // 0 -->1, 2
															 {1, 0, 0, 0},  // 1 --> 
															 {0, 0, 0, 1},  // 2 -->3
															 {0, 0, 0, 0}}; // 3 -->

  printf("graph min between 1, 3 is %d\n", findMin(graph, 1, 3));
  return 0;
}
