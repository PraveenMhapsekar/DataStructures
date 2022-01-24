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
findPathSrcDst(int isConnected[NUM][NUM], int isConnectedSize, int isConnectedColSize, int src, int dst) {
  int count = 0; 
  int visited[isConnectedSize];
  
  if (isConnectedSize != isConnectedColSize) 
    return count;
  
  // init visited array
  for (int i = 0; i < isConnectedSize; i++) {
    visited[i] = 0;
  }

  // traverse graph in DFS, row by row
  dfs(isConnected, isConnectedSize, visited, src);

  if (visited[dst] == 1) {
    return true;
  } else {
    return false;
  }
}

int
main() {
  int graph[NUM][NUM] = {{1, 1, 0, 0},  // 0 -->0 1
											   {0, 1, 0, 0},  // 1 -->1 
											   {0, 0, 1, 1},  // 2 -->2 3
											   {1, 1, 0, 1}}; // 3 -->0 1 3
  int src = 3;
  int dst = 2;
  printf("Src %d to dst %d path %s\n", src, dst, findPathSrcDst(graph, NUM, NUM, src, dst) == true? "exit" : "doesnt exit");
  return 0;
}
