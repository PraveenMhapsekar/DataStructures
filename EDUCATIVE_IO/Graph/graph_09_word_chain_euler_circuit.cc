/*
To find the Euler circuit of the graph, we must ensure that these two conditions are satisfied:

The in-degree of every vertex is equal to its out-degree.
A cycle exists connecting all the vertices of the graph that starts and ends at the same vertex.

Time Complexity:
	 O(V+E)

 +---------------+     +-----------------+----------+---+---+---+
 +  vertexchain  + --> + value + visited + adjVertx +   +   +   /
 +---------------+     +-----------------+----------+---+---+---+
 +  vertexchain  +                       + inVertex +   +   +   /
 +---------------+                       +----------+---+---+---+
 +  vertexchain  + 
 +---------------+
 +  vertexchain  + 
 +---------------+
*/

#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class VertexChain {
  public:
	char value;
	bool visited;
	vector<VertexChain*> adj_vertices;
	vector<VertexChain*> in_vertices;

	VertexChain(char value, bool visited) {
		this->value = value;
		this->visited = visited;
	}
};

class graph {
  public:
	vector<VertexChain*> g;

	// This method returns TRUE if the graph has a cycle containing
	// all the nodes, returns FALSE otherwise
	bool CanChainWordsRec(VertexChain* node, VertexChain* starting_node) {
		node->visited = true;

		// Base case
		// return TRUE if all nodes have been visited and there
		// exists an edge from the last node being visited to
		// the starting node
		vector<VertexChain*> adj = node->adj_vertices;
		if (AllVisited()) {
			for (int i = 0; i < adj.size(); i++) {
				if (adj[i] == starting_node) {
					return true;
				}
			}
		}

		// Recursive case
		for (int i = 0; i < adj.size(); i++) {
			if (adj[i]->visited == false) {
				node = adj[i];
				if (CanChainWordsRec(node, starting_node)) {
					return true;
				}
			}
		}
		return false;
	}

	// Challenge function
	bool CanChainWords(int list_size) {
		// Empty list and single word cannot form a chain
		if (list_size < 2) {
			return false;
		}

		if (g.size() > 0) {
			if (OutEqualsIn()) {
				return CanChainWordsRec(g[0], g[0]);
			}
		}

		return false;
	}

	// This method creates a graph from a list of words. A node of
	// the graph contains a character representing the start or end
	// character of a word.
	void CreateGraph(vector<string> words_list) {
		for (int i = 0; i < words_list.size(); i++) {
			string word = words_list[i];
			char start_char = word[0];
			char end_char = word[word.length() - 1];

			VertexChain* start = VertexChainExists(start_char);
			if (start == nullptr) {
				start = new VertexChain(start_char, false);
				g.push_back(start);
			}

			VertexChain* end = VertexChainExists(end_char);
			if (end == nullptr) {
				end = new VertexChain(end_char, false);
				g.push_back(end);
			}

			// Add an edge from start vertex to end vertex
			AddEdge(start, end);
		}
	}

	// This method returns the VertexChain with a given value if it
	// already exists in the graph, returns NULL otherwise
	VertexChain* VertexChainExists(char value) {
		for (int i = 0; i < this->g.size(); i++) {
			if (g[i]->value == value) {
				return g[i];
			}
		}
		return nullptr;
	}

	// This method returns TRUE if all nodes of the graph have
	// been visited
	bool AllVisited() {
		for (int i = 0; i < g.size(); i++) {
			if (g[i]->visited == false) {
				return false;
			}
		}
		return true;
	}

	// This method adds an edge from start VertexChain to end VertexChain by
	// adding the end VertexChain in the adjacency list of start VertexChain
	// It also adds the start VertexChain to the in_vertices of end VertexChain
	void AddEdge(VertexChain* start, VertexChain* end) {
		start->adj_vertices.push_back(end);
		end->in_vertices.push_back(start);
	}

	// This method returns TRUE if out degree of each vertex is equal
	// to its in degree, returns FALSE otherwise
	bool OutEqualsIn() {
		for (int i = 0; i < g.size(); i++) {
			int out = g[i]->adj_vertices.size();
			int inn = g[i]->in_vertices.size();
			if (out != inn) {
				return false;
			}
		}
		return true;
	}

	void PrintGraph() {
		for (int i = 0; i < g.size(); i++) {
			cout << g[i] << ' ' << g[i]->visited << endl;
			vector<VertexChain*> adj = g[i]->adj_vertices;
			for (int j = 0; j < adj.size(); j++) {
				cout << adj[j] << ' ';
			}
			cout << endl;
		}
	}
};

int main() {
	vector<vector<string>> list = {{"eve", "eat", "ripe", "tear"},
																 {"hit", "hot", "dot", "dog", "cog"},
																 {"aa", "ba", "ab"},
																 {"apple", "juice"}};
	cout << boolalpha;
	for (int i = 0; i < list.size(); i++) {
		graph g;
		g.CreateGraph(list[i]);
		bool result = g.CanChainWords(list[i].size());
		cout << i + 1 << ". List of words: ";
		//PrintList(list[i]);
		cout << "   Is word chaining possible?: " << result << endl;
		cout << "----------------------------------------------------------------------------------------" << endl;
	}
}
