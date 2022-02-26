/*
  if there exist path between src and dst in given bidirectional graph
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <queue>

using namespace std;

void
dfs(vector<vector<int>> graph, int size, bool *visited, int i) {
  // traverse each column
  visited[i] = true;
  for (int j = 0; j < size; j++) {
    if (graph[i][j] == 1 && visited[j] == false) {
      // go to corrosponding row and traverse recursively
      dfs(graph, size, visited, j);
    }
  }
}

bool
findPathSrcDst(vector<vector<int>> graph, int src, int dst) {
  int size = graph[0].size();
  bool visited[size];
  
  // init visited array
  for (int i = 0; i < size; i++) {
    visited[i] = false;
  }

  // traverse graph in DFS, row by row
  dfs(graph, size, visited, src);

  if (visited[dst] == true) {
    return true;
  } else {
    return false;
  }
}

int
main() {
  vector<vector<int>> graph = {{1, 1, 0, 0},  // 0 -->0 1
															 {0, 1, 0, 0},  // 1 -->1 
															 {0, 0, 1, 1},  // 2 -->2 3
															 {1, 1, 1, 1}}; // 3 -->0 1 3
  int src = 3;
  int dst = 2;
  printf("Src %d to dst %d path %s\n", src, dst, findPathSrcDst(graph, src, dst) == true ? "exit" : "doesnt exit");
  return 0;
}
