#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <queue>

using namespace std;

void
dfs(vector<vector<int>> &graph, int size, int *visited, int i) {
  // traverse each column
  visited[i] = 1;
  for (int j = 0; j < size; j++) {
    if (graph[i][j] == 1 && visited[j] == 0) {
      // go to corrosponding row and traverse recursively
      dfs(graph, size, visited, j);
    }
  }
}

int
findCircleNum(vector<vector<int>> &graph, int isConnectedSize) {
  int count = 0; 
  int visited[isConnectedSize];
  
  
  // init visited array
  for (int i = 0; i < isConnectedSize; i++) {
    visited[i] = 0;
  }
 
  // traverse graph in DFS, row by row
  for (int i = 0; i < isConnectedSize; i++) {
    if (visited[i] == 0) {
      dfs(graph, isConnectedSize, visited, i);
      count++;
    }
  }

  return count;
}

int
main() {
/*
  int graph[NUM][NUM] = {{0, 1, 0, 0, 0, 0},  // 0 --> 1
											   {0, 0, 1, 0, 0, 0},  // 1 --> 2
											   {0, 0, 0, 1, 0, 0},  // 2 --> 3
											   {0, 0, 0, 0, 1, 0},  // 3 --> 4
											   {0, 0, 0, 0, 0, 1},  // 4
											   {0, 0, 0, 0, 0, 0}}; // 5
*/
  /*
      0 -- 3
       \  /
        1 -- 2
  */
  vector<vector<int>> graph = {{1, 1, 0, 1},  // 0 -->0 1
															 {1, 1, 1, 1},  // 1 -->0 1 2
															 {0, 1, 1, 0},  // 2 -->1 2
															 {1, 1, 0, 1}}; // 3 -->0 1 3
  printf("Number of islands %d\n", findCircleNum(graph, graph.size()));
  return 0;
}
