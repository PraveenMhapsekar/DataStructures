using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class AllTaskSchedulingOrders {
 public:
  static void printOrders(int tasks, vector<vector<int>> &prerequisites) {
    vector<int> sortedOrder;
    if (tasks <= 0) {
      return;
    }

    // a. Initialize the graph
    unordered_map<int, int> inDegree;       // count of incoming edges for every vertex
    unordered_map<int, vector<int>> graph;  // adjacency list graph
    for (int i = 0; i < tasks; i++) {
      inDegree[i] = 0;
      graph[i] = vector<int>();
    }

    // b. Build the graph
    for (int i = 0; i < prerequisites.size(); i++) {
      int parent = prerequisites[i][0], child = prerequisites[i][1];
      graph[parent].push_back(child);  // put the child into it's parent's list
      inDegree[child]++;               // increment child's inDegree
    }

    // c. Find all sources i.e., all vertices with 0 in-degrees
    vector<int> sources;
    for (auto entry : inDegree) {
      if (entry.second == 0) {
        sources.push_back(entry.first);
      }
    }

    printAllTopologicalSorts(graph, inDegree, sources, sortedOrder);
  }

 private:
  static void printAllTopologicalSorts(unordered_map<int, vector<int>> &graph,
                                       unordered_map<int, int> &inDegree,
                                       const vector<int> &sources, vector<int> &sortedOrder) {
    if (!sources.empty()) {
      for (int vertex : sources) {
        sortedOrder.push_back(vertex);
        vector<int> sourcesForNextCall = sources;
        // only remove the current source, all other sources should remain in the queue for the next
        // call
        sourcesForNextCall.erase(
            find(sourcesForNextCall.begin(), sourcesForNextCall.end(), vertex));

        vector<int> children =
            graph[vertex];  // get the node's children to decrement their in-degrees
        for (auto child : children) {
          inDegree[child]--;
          if (inDegree[child] == 0) {
            sourcesForNextCall.push_back(child);  // save the new source for the next call
          }
        }

        // recursive call to print other orderings from the remaining (and new) sources
        printAllTopologicalSorts(graph, inDegree, sourcesForNextCall, sortedOrder);

        // backtrack, remove the vertex from the sorted order and put all of its
        // children back to consider the next source instead of the current vertex
        sortedOrder.erase(find(sortedOrder.begin(), sortedOrder.end(), vertex));
        for (auto child : children) {
          inDegree[child]++;
        }
      }
    }

    // if sortedOrder doesn't contain all tasks, either we've a cyclic dependency between tasks, or
    // we have not processed all the tasks in this recursive call
    if (sortedOrder.size() == inDegree.size()) {
      for (int num : sortedOrder) {
        cout << num << " ";
      }
      cout << endl;
    }
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> vec = {{0, 1}, {1, 2}};
  AllTaskSchedulingOrders::printOrders(3, vec);
  cout << endl;

  vec = {{3, 2}, {3, 0}, {2, 0}, {2, 1}};
  AllTaskSchedulingOrders::printOrders(4, vec);
  cout << endl;

  vec = {{2, 5}, {0, 5}, {0, 4}, {1, 4}, {3, 2}, {1, 3}};
  AllTaskSchedulingOrders::printOrders(6, vec);
  cout << endl;
}

