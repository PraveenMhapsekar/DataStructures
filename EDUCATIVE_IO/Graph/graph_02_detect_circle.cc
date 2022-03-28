#include <stdio.h>
#include <vector>

using namespace std;

bool
dfs(vector<vector<int>> &graph, int size, bool *visited, int i) {
  visited[i] = true;
  // traverse each column
  for (int j = 0; j < size; j++) {
    // find if circle is detected ?
    if (graph[i][j] == 1) {  // there exist path between i and j vertices
      if (visited[j] == true) { // vertex j is already visited
        return true;
			} else {
        // go to corrosponding row and traverse recursively
        return dfs(graph, size, visited, j);
      }
    }
  }
  return false;
}

bool
findLoop(vector<vector<int>> &graph) {
  int graphSize = graph[0].size();  
  bool visited[graphSize];

  // init visited array
  for (int i = 0; i < graphSize; i++) {
    visited[i] = false;
  }
 
  // traverse graph in DFS, row by row
  for (int i = 0; i < graphSize; i++) {
    if (visited[i] == false) {
      if (dfs(graph, graphSize, visited, i) == true) {
        return true; // Found loop return true
      }
    }
  }
  return false;
}

int
main() {
  vector<vector<int>> graph = {{0, 1, 0, 0, 0, 0}, // vertex 0 -> 1
															 {0, 0, 1, 0, 0, 0}, // vertex 1 -> 2
															 {0, 0, 0, 1, 0, 0}, // vertex 2 -> 3
															 {0, 0, 0, 0, 1, 0}, // vertex 3 -> 4
															 {0, 0, 0, 0, 0, 1}, // vertex 4 -> 5
															 {1, 0, 0, 0, 0, 0}};// vertex 5 -> 0 // loop

  printf("Loop %s\n", findLoop(graph) == true ? "detected" : "not detected");

											graph = {{0, 1, 0, 0, 0, 0}, // vertex 0 -> 1
															 {0, 0, 1, 0, 0, 0}, // vertex 1 -> 2
															 {0, 0, 0, 1, 0, 0}, // vertex 2 -> 3
															 {0, 0, 0, 0, 1, 0}, // vertex 3 -> 4
															 {0, 0, 0, 0, 0, 1}, // vertex 4 -> 5
															 {0, 0, 0, 0, 0, 0}};// vertex 5 ->  // no loop

  printf("Loop %s\n", findLoop(graph) == true ? "detected" : "not detected");
 
  return 0;
}
