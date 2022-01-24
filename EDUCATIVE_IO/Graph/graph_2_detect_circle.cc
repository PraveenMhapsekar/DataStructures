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
    if (isConnected[i][j] == 1 && visited[j] == 1) { 
       return true;
    } else if (isConnected[i][j] == 1 && visited[j] == 0) {
       // go to corrosponding row and traverse recursively
       return dfs(isConnected, size, visited, j );
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
          printf("\n returning true\n");
         return true;
      }
      count++;
    }
  }
  return false;
}

/*
  int count = 0; 
/// Set Solution
int find(int *parent, int x) {
  if (parent[x] == x)  {
    return x;
  } 
  return find(parent, parent[x]);
}

void myUnion(int *parent,  int i, int j) {
  int x = find(parent, i);
  int y = find(parent, j);
  if (x != y) {
    parent[x] = y;
    // when joining cities reduce provice count
    count--;
  }
}

int findCircleNum(int isConnected[NUM][NUM], int isConnectedSize, int isConnectedColSize){
  if (isConnectedSize != isConnectedColSize) return count;
  /// init all cities are assumed to be province
  count = isConnectedSize;
  int parent[isConnectedSize];
  for (int i = 0; i < isConnectedSize; i++) {
    parent[i] = i;
  }
  
  for (int i = 0; i < isConnectedSize; i++) {
    for (int j = 0; j < isConnectedColSize; j++) {
      if ((isConnected[i][j] == 1) && (i != j)) {
        myUnion(parent, i, j);
      }
    }
  }
  
  return count; 
}
*/
/*
              0 --> 1 --> 2
              

*/
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
