using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class TaskScheduling {
 public:
  static bool isSchedulingPossible(int tasks, const vector<vector<int>>& prerequisites) {
    vector<int> sortedOrder;
    if (tasks <= 0) {
      return false;
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
    queue<int> sources;
    for (auto entry : inDegree) {
      if (entry.second == 0) {
        sources.push(entry.first);
      }
    }

    // d. For each source, add it to the sortedOrder and subtract one from all of its children's
    // in-degrees if a child's in-degree becomes zero, add it to the sources queue
    while (!sources.empty()) {
      int vertex = sources.front(); sources.pop();
      sortedOrder.push_back(vertex);
      vector<int> children = graph[vertex]; // get the node's children to decrement their in-degrees
      for (auto child : children) {
        inDegree[child]--;
        if (inDegree[child] == 0) {
          sources.push(child);
        }
      }
    }

    // if sortedOrder doesn't contain all tasks, there is a cyclic dependency between tasks,
    // therefore, we will not be able to schedule all tasks
    return sortedOrder.size() == tasks;
  }
};

int 
main(int argc, char* argv[]) {
  bool result = TaskScheduling::isSchedulingPossible(3, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2}});
  cout << "Tasks execution possible: " << result << endl;

  result = TaskScheduling::isSchedulingPossible(3, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2}, vector<int>{2, 0}});
  cout << "Tasks execution possible: " << result << endl;

  result = TaskScheduling::isSchedulingPossible(6, vector<vector<int>>{vector<int>{2, 5}, vector<int>{0, 5}, vector<int>{0, 4},
																								vector<int>{1, 4}, vector<int>{3, 2}, vector<int>{1, 3}});
  cout << "Tasks execution possible: " << result << endl;
}
