#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

class Graph {

public:
  vector<vector<int>> graph;
  // init 
  Graph(int n) : graph(n, vector<int>(n, 0)) {}

	bool  // return true if cycle false otherwise
	dfs(bool *visited, int src, int dst) {
    int size = graph[0].size();
		visited[src] = true;

		for (int j = 0; j < size; j++) {
			if (graph[src][j]) {
        if (j == dst) return true;
				if (visited[j] == false) {
					// if subsequent traverse detected loop, return false
					if (dfs(visited, j, dst)) {
						// loop detected, not a tree. return false
						return true;
					}
				}
			}
		}
		return false;
	}

	bool
	checkPath(int src, int dst) {
		int count = 0; 
		int size = graph[0].size();
		bool visited[size];
		
		// init visited array
		for (int i = 0; i < size; i++) {
			visited[i] = 0;
		}

		// traverse graph in DFS, starting at vertex 0
		// if dfs finds any vertx already visited it is not a tree
		if (dfs(visited, src, dst) == true) {
			return true;
		}

		// checked all conditions, Graph is a tree
		return false;
	}

	void
	addEdge(int i, int j) {
		graph[i][j] = 1;
//		graph[j][i] = 1; // undirected graph will have edge in both direction
	}

	void
	printGraph() {
		int size = graph[0].size();

		for (int i = 0; i < size; i++) {
			cout << "{";
			for (int j = 0; j < size; j++) {
				cout << graph[i][j] << ", ";
			}
			cout << "}" << endl;
	 }
	}
};


int main() {
	Graph g1(9);
	g1.addEdge(0,2);
	g1.addEdge(0,5);
	g1.addEdge(2,3);
	g1.addEdge(2,4);
	g1.addEdge(5,3);
	g1.addEdge(5,6);
	g1.addEdge(3,6);
	g1.addEdge(6,7);
	g1.addEdge(6,8);
	g1.addEdge(6,4);
	g1.addEdge(7,8);
	cout << g1.checkPath(0, 7) << endl;

	Graph g2(4);
	g2.addEdge(0,1);
	g2.addEdge(1,2);
	g2.addEdge(1,3);
	g2.addEdge(2,3);

	cout << g2.checkPath(3, 0) << endl;
}
