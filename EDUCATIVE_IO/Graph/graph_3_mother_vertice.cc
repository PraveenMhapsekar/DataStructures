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

int
findCircleNum(int isConnected[NUM][NUM], int isConnectedSize, int isConnectedColSize) {
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

  // verify if all nodes are visited, if yes last vertext is mother vertex
  bool flag = true;
  for (int i = 0; i < isConnectedSize; i++) {
		printf(" V[%d] count is %d\n", i, visited[i]);
		if (visited[i] != 1) {
		  flag = false;
		}
  } 

  if (flag == true) {
		printf("mother is %d\n", last_i);
  } else {
    printf("mother vertices not found \n");
  }

  return count;
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
  // 0->1->2 3->4 5 
  int graph[NUM][NUM] = {{1, 1, 0, 0},  // 0 -->0 1
											   {0, 1, 1, 0},  // 1 -->1 2
											   {0, 0, 1, 0},  // 2 -->2
											   {1, 1, 0, 1}}; // 3 -->0 1 3
  printf("Number of islands %d\n", findCircleNum(graph, NUM, NUM));
  return 0;
}
