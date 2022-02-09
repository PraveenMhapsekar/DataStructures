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
#include <vector>
#include <iostream>
using namespace std;

#define SIZE 8
int indegree[8];

void
allTopoSortUtil(int graph[SIZE][SIZE], int size, int *visited, vector<int> &s) {
  // traverse each column
  bool flag = false;

  for (int i = 0; i < size; i++) {
    if (indegree[i] == 0 && visited[i] == 0) {
      visited[i] = 1;
      s.push_back(i);

      for (int j = 0; j < size; j++) {
        if (graph[i][j] == 1) {
          if (indegree[j]) {
			      indegree[j]--;
          }
        }
      }

      allTopoSortUtil(graph, size, visited, s);
  
      visited[i] = 0;
      s.erase(s.end() - 1);
        
      for (int j = 0; j < size; j ++) {
        if (graph[i][j] == 1) {
			  	indegree[j]++;
        }
      }
      flag = true;
    }
  }  // end of outr for loop

	if (!flag) {
		int s_size = s.size();
		cout << "size " << s_size << " : ";
		for (int i = 0; i < s_size; i++) {
			cout << s[i] << " ";
		}
		cout << endl;
	}
}

void
allTopoSort(int graph[SIZE][SIZE], int size) {
  int visited[size];
  vector<int> s;
  
  // init visited array
  for (int i = 0; i < size; i++) {
    visited[i] = 0;
  }
 
  allTopoSortUtil(graph, size, visited, s);
}

int
main() 
{
  int graph[SIZE][SIZE] = {{0, 0, 0, 0, 0, 0, 0, 0},  // 0 --> 
													 {1, 0, 0, 0, 0, 0, 0, 0},  // 1 --> 0
													 {0, 1, 0, 0, 0, 0, 0, 0},  // 2 --> 1
													 {0, 1, 0, 0, 0, 0, 0, 0},  // 3 --> 1
													 {0, 0, 0, 0, 0, 0, 0, 0},  // 4 --> 
													 {0, 0, 1, 0, 1, 0, 0, 0},  // 5 --> 2, 4
													 {0, 0, 0, 1, 1, 0, 0, 0},  // 6 --> 3, 4
													 {0, 0, 0, 0, 0, 1, 1, 0}}; // 7 --> 5, 6
  int size = SIZE;

  for (int i = 0; i < size; i++) {
    int cnt = 0;
    for (int j = 0; j < size; j++) {
			if (graph[j][i] == 1) {
			  cnt++;
			}
    }
    indegree[i] = cnt;
  }

  for (int i = 0; i < size; i++) {
    cout << i << " degree : " << indegree[i] << endl;
  }
  cout << endl;

  allTopoSort(graph, size);

  return 0;
}
