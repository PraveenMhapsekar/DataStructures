/*
Topological Sort: A topological sort or topological ordering of a directed graph is a linear ordering of its vertices such that for every directed edge uv from vertex u to vertex v, u comes before v in the ordering. A topological ordering is possible if and only if the graph has no directed cycles, that is, if it is a directed acyclic graph (DAG). 

Modified DFS:
	Use temporary stack to store the vertex.
	Maintain a visited [] to keep track of already visited vertices.
	In DFS we print the vertex and make recursive call to the adjacent vertices but here we will make the recursive call to the adjacent vertices and then push the vertex to stack.
	Observe closely the previous step, it will ensure that vertex will be pushed to stack only when all of its adjacent vertices (descendants) are pushed into stack.
	Finally print the stack.
	For disconnected graph, Iterate through all the vertices, during iteration, at a time consider each vertex as source (if not already visited).

Time Complexity:
	 O(V+E)
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

#define SIZE 8

void
dfs(int graph[SIZE][SIZE], int size, int *visited, int i, stack<int> &s) {
  // traverse each column
  visited[i] = 1;
  for (int j = 0; j < size; j++) {
    if (graph[i][j] == 1 && visited[j] == 0) {
      // go to corrosponding row and traverse recursively
      dfs(graph, size, visited, j, s);
    }
  }
  s.push(i);
}

int
topologicalSortDfs(int graph[SIZE][SIZE], int size) {
  int count = 0; 
  int visited[size];
  stack<int> s;
  
  
  // init visited array
  for (int i = 0; i < size; i++) {
    visited[i] = 0;
  }
 
  // traverse graph in DFS, row by row
  for (int i = 0; i < size; i++) {
    if (visited[i] == 0) {
      dfs(graph, size, visited, i, s);
      count++;
    }
  }

  // Print stack
  int s_size = s.size();
  cout << "size " << s_size << endl;
  for (int i = 0; i < s_size; i++) {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
  return count;
}

int
main() {
  int graph[SIZE][SIZE] = {{0, 0, 0, 0, 0, 0, 0, 0},  // 0 --> 
													 {1, 0, 0, 0, 0, 0, 0, 0},  // 1 --> 0
													 {0, 1, 0, 0, 0, 0, 0, 0},  // 2 --> 1
													 {0, 1, 0, 0, 0, 0, 0, 0},  // 3 --> 1
													 {0, 0, 0, 0, 0, 0, 0, 0},  // 4 --> 
													 {0, 0, 1, 0, 1, 0, 0, 0},  // 5 --> 2, 4
													 {0, 0, 0, 1, 1, 0, 0, 0},  // 6 --> 3, 4
													 {0, 0, 0, 0, 0, 1, 1, 0}}; // 7 --> 5, 6
  int size = SIZE;
  topologicalSortDfs(graph, size);
  return 0;
}
