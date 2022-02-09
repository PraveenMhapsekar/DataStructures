// is unidirected graph is tree or not?
// Graph is tree if,
//   #1 there is no loop
//   #2 there is all nodes are connected (there is no forest or islands!)

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <queue>

using namespace std;

#define NUM 4

bool
dfs(int isConnected[NUM][NUM], int size, int *visited, int i) {
  visited[i] = 1;
  for (int j = 0; j < size; j++) {
    if (isConnected[i][j]) {
      if (visited[j] == 1) {
        // loop detected, not a tree. return false
        return false;
      } else {      
        // if subsequent traverse detected loop, return false
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

  // After DFS traverse if any vertex is not visited, its not tree
  // this means there are more than one disjoined graphs (aka forest or islands)
  for (int i = 0; i < isConnectedSize; i++) {
    if (visited[i] == 0) {
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
  int graph[NUM][NUM] = {{0, 1, 1, 0},  // 0 -->1, 2
											   {0, 0, 0, 0},  // 1 --> 
											   {0, 0, 0, 1},  // 2 -->3
											   {0, 0, 0, 0}}; // 3 -->
  printf("graph is %s\n", isTree(graph, NUM, NUM) == true? "tree" : "not a tree");
  return 0;
}
