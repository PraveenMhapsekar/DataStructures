// Check if Graph is Bipartite – Adjacency Matrix using Depth-First Search(DFS)
// https://algorithms.tutorialhorizon.com/check-if-graph-is-bipartite-adjacency-matrix-using-depth-first-searchdfs/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>

using namespace std;

#define SIZE 4

#define WHITE 0
#define RED   1
#define GREEN 2

bool
isBipartiteUtil(int u, int size, int *colors, int graph[SIZE][SIZE]){
	// If is it first vertex, mark it RED
	if (u == 0)
		colors[u] = RED;

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
			return isBipartiteUtil(v, size, colors, graph);
		} else if (graph[u][v] == 1 && colors[u] == colors[v]) {
			return false;
		}
	}

	// Graph is successfully colored in 2 color, red and green
	// Graph is bipartite
	return true;
}

bool 
isBipartite(int graph[SIZE][SIZE], int size) {
	// Check if graph is empty
	if (size == 0)
		return true;

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
			bool result = isBipartiteUtil(i, size, colors, graph);
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
  /*
  int graph[SIZE][SIZE] = {{0, 1, 1, 0, 0},  // 0 --> 1, 2
											   {0, 0, 2, 3, 0},  // 1 --> 2
											   {0, 0, 0, 0, 3},  // 2 --> 4
											   {0, 0, 0, 0, 2},  // 3 --> 4
											   {0, 0, 0, 0, 0}}; // 
  int size = 5;
  printf("Is bipartite: %s\n", isBipartite(graph, size) == true? "yes" : "no");
  */

  int size = SIZE;
  int graph[SIZE][SIZE] =  { {0, 1, 1, 1},
                            {1, 0, 0, 1},
                            {0, 0, 0, 1},
                            {1, 1, 1, 0}
                          };

  printf("Is bipartite: %s\n", isBipartite(graph, size) == true? "yes" : "no");
  return 0;
}
