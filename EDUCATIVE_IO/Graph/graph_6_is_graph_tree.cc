// is unidirected graph is tree or not?
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <queue>

using namespace std;

#define NUM 4

bool
dfs(int isConnected[NUM][NUM], int size, int *visited, int i) {

  // traverse each column
  visited[i] = 1;
  for (int j = 0; j < size; j++) {
    if (isConnected[i][j]) {
      if (visited[j] == 1) {
        printf("returning false i %d j %d\n", i, j);
        return false;
      }
      if (visited[j] == 0) {
			  if (dfs(isConnected, size, visited, j ) == false) {
           return false;
        }
			}
    }
	}
 
  return true;
}

bool
isTree(int isConnected[NUM][NUM], int isConnectedSize, int isConnectedColSize) {
  int count = 0; 
  int visited[isConnectedSize];
  
  if (isConnectedSize != isConnectedColSize) 
    return count;
  
  // init visited array
  for (int i = 0; i < isConnectedSize; i++) {
    visited[i] = 0;
  }

	// traverse graph in DFS, starting at vertex 0
  // if dfs finds any vertx already visited it is not a tree
  if (dfs(isConnected, isConnectedSize, visited, 0) == false) {
    return false;
  }

  // after DFS if any vertx is not visited, its not tree
  for (int i = 0; i < isConnectedSize; i++) {
    if (visited[i] == 0) {
      printf("returning false for not visited %d\n", i);
      return false;
    }
  }

  // checked all conditions, Graph is a tree
  return true;
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
  int graph[NUM][NUM] = {{0, 0, 0, 0},  // 0 -->1, 2
											   {0, 0, 0, 0},  // 1 --> 
											   {0, 0, 0, 0},  // 2 -->3
											   {0, 0, 0, 0}}; // 3 -->
  printf("graph is %s\n", isTree(graph, NUM, NUM) == true? "tree" : "not a tree");
  return 0;
}
