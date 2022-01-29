/*
Mother vertex:
A mother vertex in a Graph G = (V, E) is a vertex v such that all other vertices in G can be reached by a path from v.
There can be zero, one, or more than one mother vertices in a graph. 
We need to find all the mother vertices in the given graph.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <queue>

using namespace std;

#define NUM 4

void
dfs(int isConnected[NUM][NUM], int size, int *visited, int i) {
  // traverse each column
  visited[i] = 1;
  for (int j = 0; j < size; j++) {
    if (isConnected[i][j] == 1 && visited[j] == 0) {
      // go to corrosponding row and traverse recursively
      dfs(isConnected, size, visited, j );
    }
  }
}

bool
findMotherVertex(int isConnected[NUM][NUM], int isConnectedSize, int isConnectedColSize) {
  int count = 0; 
  int visited[isConnectedSize];
  
  if (isConnectedSize != isConnectedColSize) 
    return count;
  
  // init visited array
  for (int i = 0; i < isConnectedSize; i++) {
    visited[i] = 0;
  }

  int last_i; 

  // traverse graph in DFS, row by row
  for (int i = 0; i < isConnectedSize; i++) {
    if (visited[i] == 0) {
      dfs(isConnected, isConnectedSize, visited, i);
      last_i = i; // last visited vertex
      count++;
    }
  }

  // Clear visited array
  for (int i = 0; i < isConnectedSize; i++) {
    visited[i] = 0;
  }

  // DFS from last vertex
  dfs(isConnected, isConnectedSize, visited, last_i);

  // Verify if all nodes are visited, if yes last vertext is mother vertex
  bool flag = true;
  for (int i = 0; i < isConnectedSize; i++) {
		if (visited[i] != 1) {
		  flag = false;
		}
  } 

  return flag;
}

int
main() {
  // 0->1->2 3->4 5 
  int graph[NUM][NUM] = {{1, 1, 0, 0},  // 0 -->0 1
											   {0, 1, 1, 0},  // 1 -->1 2
											   {0, 0, 1, 0},  // 2 -->2
											   {1, 1, 0, 1}}; // 3 -->0 1 3
  printf("Mother Vertex? %s\n", findMotherVertex(graph, NUM, NUM) == true ? "yes" : "no");
  return 0;
}
