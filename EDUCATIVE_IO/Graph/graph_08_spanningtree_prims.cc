#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <queue>
// Prims Algorithm
// 1. Initialize the MST with an arbitrary vertex from the graph
// 2. Find the minimum weight edge from the constructed graph to the vertices not yet added in the graph
// 3. Add that edge and vertex to the MST
// 4. Repeat steps 2-3 until all the vertices have been added to the MST

using namespace std;

#define NUM 5

typedef struct resultSet {
 int src;
 int dst;
 int weight;
} result_set_t;

// Get the vertex with min key and not included in MST
int
getMinimumVertex(bool *mst, int *key, int size) {
  int minKey = INT_MAX;
  int vertex = -1;

  for (int j  = 0; j < size; j++) {
	  if (mst[j] == false && minKey > key[j]) {
			minKey = key[j];
			vertex = j;
	  }
	}
  return vertex;
}

int 
find_min_spanning_tree(int graph[NUM][NUM], int size) {
  result_set_t result[size];
  bool mst[size];
  int key[size];

  // init
	for (int i = 0; i < size; i++) {
    mst[i] = false;
    key[i] = INT_MAX;
    result[i].src = -1;
    result[i].weight = 0;
  }

  key[0] = 0;
  int weight = 0;

	for (int i = 0; i < size; i++) {
		// Get the vertex with the min key
		int vertex = getMinimumVertex(mst, key, size);

		// Include vertex in MST
		mst[vertex] = true;

		// Iterate through all the adj vertices of above vertex and update the keys
		for (int j = 0; j < size; j++) {
		  if (graph[vertex][j] > 0) {
				// Check if 'j' not in MST and
				// if key needs an update or not
			  if (mst[j] == false && graph[vertex][j] < key[j]) {
					// update the key
					key[j] = graph[vertex][j];
					// add this edge to MST result
					result[j].src = vertex;
					result[j].dst = j;
					result[j].weight = key[j];
			  }
		  }
	  }
  }

  // Done. Print result
  for (int i = 0; i < size; i++) {
    if (result[i].src != -1) {
			cout << "src[" << result[i].src << "]->dst[" << result[i].dst << "] Weight: " << result[i].weight << endl;
      weight+= result[i].weight;
    }
  }

	return weight;// result;
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
  int graph[NUM][NUM] = {{0, 1, 1, 0, 0},  // 0 --> 1, 2
											   {0, 0, 2, 3, 0},  // 1 --> 2
											   {0, 0, 0, 0, 3},  // 2 --> 4
											   {0, 0, 0, 0, 2},  // 3 --> 4
											   {0, 0, 0, 0, 0}}; // 
  int size = 5;

  printf("min spanning tree weight : %d\n", find_min_spanning_tree(graph, size));
  return 0;
}