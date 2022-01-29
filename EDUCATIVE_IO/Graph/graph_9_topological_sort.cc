// Topological sort

using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class TopologicalSort {
public:
  static vector<int> sort(int vertices, const vector<vector<int>>& edges) {
    vector<int> sortedOrder;
    if (vertices <= 0) {
      return sortedOrder;
    }

    // a. Initialize the graph
    unordered_map<int, int> inDegree;       // count of incoming edges for every vertex
    unordered_map<int, vector<int>> graph;  // adjacency list graph
    for (int i = 0; i < vertices; i++) {
      inDegree[i] = 0;
      graph[i] = vector<int>();
    }

    // b. Build the graph
    for (int i = 0; i < edges.size(); i++) {
      int parent = edges[i][0];
      int child = edges[i][1];
      graph[parent].push_back(child);  // put the child into it's parent's list
      inDegree[child]++;               // increment child's inDegree
    }

    // c. Find all sources i.e., all vertices with 0 in-degrees
    queue<int> sources;
    for (auto entry : inDegree) {
      if (entry.second == 0) {
        sources.push(entry.first);
      }
    }

    // BFS
    // d. For each source, add it to the sortedOrder and subtract one from all of its children's
    // in-degrees if a child's in-degree becomes zero, add it to the sources queue
    while (!sources.empty()) {
      int vertex = sources.front();
      sources.pop();
      sortedOrder.push_back(vertex);
      vector<int> children = graph[vertex];  // get the node's children to decrement their in-degrees
      for (auto child : children) {
        inDegree[child]--;
        if (inDegree[child] == 0) {
          sources.push(child);
        }
      }
    }

    if (sortedOrder.size() != vertices) {
      // topological sort is not possible as the graph has a cycle
      return vector<int>();
    }

    return sortedOrder;
  }
};

int main(int argc, char* argv[]) {
  // #1
  vector<int> result =
      TopologicalSort::sort(4, vector<vector<int>>{vector<int>{3, 2}, vector<int>{3, 0},
                                                   vector<int>{2, 0}, vector<int>{2, 1}});

  cout << "Topological sort:" << endl;
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
  // #2
	result = TopologicalSort::sort(5, vector<vector<int>>{vector<int>{4, 2},
                                                        vector<int>{4, 3}, 
                                                        vector<int>{2, 0},
																  					            vector<int>{2, 1},
                                                        vector<int>{3, 1}});
  cout << "Topological sort:" << endl;
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
  // #3
  result = TopologicalSort::sort(7, vector<vector<int>>{vector<int>{6, 4},
																											 	vector<int>{6, 2}, 
																												vector<int>{5, 3},
																												vector<int>{5, 4},
																												vector<int>{3, 0}, 
																												vector<int>{3, 1},
																												vector<int>{3, 2},
																												vector<int>{4, 1}});

  cout << "Topological sort:" << endl;
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
