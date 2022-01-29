#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <queue>

using namespace std;

#define NUM 6

bool
dfs(int isConnected[NUM][NUM], int size, int *visited, int i) {
  visited[i] = 1;
  // traverse each column
  for (int j = 0; j < size; j++) {
    // find if circle is detected ?
    if (isConnected[i][j] == 1) {
      if (visited[j] == 1) { 
        return true;
			} else {
        // go to corrosponding row and traverse recursively
        return dfs(isConnected, size, visited, j);
      }
    }
  }

  return false;
}

bool
findLoop(int isConnected[NUM][NUM], int isConnectedSize, int isConnectedColSize){
  int count = 0; 
  int visited[isConnectedSize];
  
  if (isConnectedSize != isConnectedColSize) 
    return count;
  
  // init visited array
  for (int i = 0; i < isConnectedSize; i++) {
    visited[i] = 0;
  }
 
   // traverse graph in DFS, row by row
  for (int i = 0; i < isConnectedSize; i++) {
    if (visited[i] == 0) {
      if (dfs(isConnected, isConnectedSize, visited, i) == true) {
         return true;
      }
      count++;
    }
  }
  return false;
}

int
main() {
  int graph[NUM][NUM] = {{0, 1, 0, 0, 0, 0},
											   {0, 0, 1, 0, 0, 0},
											   {0, 0, 0, 1, 0, 0},
											   {0, 0, 0, 0, 1, 0},
											   {0, 0, 0, 0, 0, 1},
											   {1, 0, 0, 0, 0, 0}};
  printf("Loop %s\n", findLoop(graph, NUM, NUM) == true ? "detected" : "not detected");
  return 0;
}
