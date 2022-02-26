// is unidirected graph is tree or not?
// Graph is tree if,
//   #1 there is no loop
//   #2 there is all nodes are connected (there is no forest or islands!)

#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

bool
dfs(vector<vector<int>> graph, int size, bool *visited, int i) {
  visited[i] = true;

  for (int j = 0; j < size; j++) {
    if (graph[i][j]) {
      if (visited[j] == true) {
        // loop detected, not a tree. return false
        return false;
      } else {      
        // if subsequent traverse detected loop, return false
			  if (dfs(graph, size, visited, j) == false) {
           return false;
        }
			}
    }
	}
  return true;
}

bool
isTree(vector<vector<int>> graph) {
  int count = 0; 
  int size = graph[0].size();
  bool visited[size];
  
  // init visited array
  for (int i = 0; i < size; i++) {
    visited[i] = 0;
  }

	// traverse graph in DFS, starting at vertex 0
  // if dfs finds any vertx already visited it is not a tree
  if (dfs(graph, size, visited, 0) == false) {
    return false;
  }

  // After DFS traverse if any vertex is not visited, its not tree
  // this means there are more than one disjoined graphs (aka forest or islands)
  for (int i = 0; i < size; i++) {
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
  vector<vector<int>> graph = {{0, 1, 1, 0},  // 0 -->1, 2
															 {0, 0, 0, 0},  // 1 --> 
															 {0, 0, 0, 1},  // 2 -->3
															 {0, 0, 0, 0}}; // 3 -->

  printf("graph is %s\n", isTree(graph) == true ? "a tree" : "not a tree");
  return 0;
}
