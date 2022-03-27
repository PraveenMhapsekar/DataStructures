/*
	Mother vertex:
	A mother vertex in a Graph G = (V, E) is a vertex v such that all other vertices in G can be reached by a path from v.
	There can be zero, one, or more than one mother vertices in a graph. 
	We need to find all the mother vertices in the given graph.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <vector>

using namespace std;

void
dfs(vector<vector<int>> graph, int size, bool *visited, int i) {
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
findMotherVertex(vector<vector<int>> graph) {
  int size = graph[0].size();
  bool visited[size];
  int last_i;

  // init visited array
  for (int i = 0; i < size; i++) {
    visited[i] = false;
  }

  // traverse graph in DFS, row by row
  for (int i = 0; i < size; i++) {
    if (visited[i] == false) {
      dfs(graph, size, visited, i);
      last_i = i; // last visited vertex
    }
  }

  // Clear visited array
  for (int i = 0; i < size; i++) {
    visited[i] = false;
  }

  // DFS from last vertex
  dfs(graph, size, visited, last_i);

  // Verify if all nodes are visited, if yes last vertext is mother vertex
  for (int i = 0; i < size; i++) {
		if (visited[i] == false) {
		  return -1;
		}
  } 

  // All nodes are visited from last_i, this is the mother
  return last_i;
}

int
main() {
  // 0->1->2 3->4 5 
  vector<vector<int>> graph = {{1, 1, 0, 0},  // 0 -->0 1
															 {0, 1, 1, 0},  // 1 -->1 2
															 {0, 0, 1, 0},  // 2 -->2
															 {1, 1, 0, 1}}; // 3 -->0 1 3
  printf("Mother Vertex : %d\n", findMotherVertex(graph) );
  return 0;
}
