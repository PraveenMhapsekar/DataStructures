// Check if Graph is Bipartite – Adjacency Matrix using Depth-First Search (DFS)
// A bipartite graph : A graph whose vertices can be divided into two disjoint & independent sets
// https://algorithms.tutorialhorizon.com/check-if-graph-is-bipartite-adjacency-matrix-using-depth-first-searchdfs/

#include <vector>
#include <iostream>

using namespace std;

#define WHITE 0
#define RED   1
#define GREEN 2

bool
isBipartiteUtil(int u, int *colors, vector<vector<int>> graph) {
  int size = graph[0].size();
	// If is it first vertex, mark it RED
	if (u == 0) {
		colors[u] = RED;
  }

	// Travel all adjacent vertices
	for (int v = 0; v < size; v++) {
		// If u-v exist and v is color with white
		if (graph[u][v] == 1 && colors[v] == WHITE) {
			// Color is with the alternate color of vertex v
			if (colors[u] == RED) {
				colors[v] = GREEN;
			} else if (colors[u] == GREEN) {
				colors[v] = RED;
			}
			// Recursive call
			return isBipartiteUtil(v, colors, graph);
		} else if (graph[u][v] == 1 && colors[u] == colors[v]) {
			return false;
		}
	}

	// Graph is successfully colored in 2 color, red and green
	// Graph is bipartite
	return true;
}

bool 
isBipartite(vector<vector<int>> graph) {
	// Check if graph is empty
	int size = graph[0].size();

	// Initialize colors for all vertices
  int	 colors[size];

	// Color all the vertices with white color
	for (int i = 0; i < size; i++) {
		colors[i] = WHITE;
	}

	// Start coloring vertices
  // this code will handle the disconnected graph as well
	// Color the first vertex with RED
	for (int i = 0; i < size; i++) {
		if (colors[i]== WHITE) {
			bool result = isBipartiteUtil(i, colors, graph);
			if (result == false)
				return false;
		}
	}

	return true;
}

/*
		0-----1
		|   / |
		|  /  |
		| /   |
		2     3-----4
		|           |
		|-----------|
*/
int
main() {
  vector<vector<int>> 
  graph = {{0, 1, 1, 0, 0},  // 0 --> 1, 2
					 {0, 0, 2, 3, 0},  // 1 --> 2
					 {0, 0, 0, 0, 3},  // 2 --> 4
					 {0, 0, 0, 0, 2},  // 3 --> 4
					 {0, 0, 0, 0, 0}}; // 
  printf("Is bipartite: %s\n", isBipartite(graph) == true ? "yes" : "no");

	graph = {{0, 1, 1, 1},
					 {1, 0, 0, 1},
					 {0, 0, 0, 1},
					 {1, 1, 1, 0}};
  printf("Is bipartite: %s\n", isBipartite(graph) == true ? "yes" : "no");

  return 0;
}
