using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class AlienDictionary {
 public:
  static string findOrder(const vector<string> &words) {
    if (words.empty() || words.empty()) {
      return "";
    }

    // a. Initialize the graph
    unordered_map<char, int> inDegree;        // count of incoming edges for every vertex
    unordered_map<char, vector<char>> graph;  // adjacency list graph
    for (auto word : words) {
      for (char character : word) {
        inDegree[character] = 0;
        graph[character] = vector<char>();
      }
    }

    // b. Build the graph
    for (int i = 0; i < words.size() - 1; i++) {
      string w1 = words[i], w2 = words[i + 1];  // find ordering of characters from adjacent words
      for (int j = 0; j < min(w1.length(), w2.length()); j++) {
        char parent = w1[j], child = w2[j];
        if (parent != child) {             // if the two characters are different
          graph[parent].push_back(child);  // put the child into it's parent's list
          inDegree[child]++;               // increment child's inDegree
          break;  // only the first different character between the two words will help us find the
                  // order
        }
      }
    }

    // c. Find all sources i.e., all vertices with 0 in-degrees
    queue<char> sources;
    for (auto entry : inDegree) {
      if (entry.second == 0) {
        sources.push(entry.first);
      }
    }

    // d. For each source, add it to the sortedOrder and subtract one from all of its children's
    // in-degrees if a child's in-degree becomes zero, add it to the sources queue
    string sortedOrder;
    while (!sources.empty()) {
      char vertex = sources.front();
      sources.pop();
      sortedOrder += vertex;
      vector<char> children =
          graph[vertex];  // get the node's children to decrement their in-degrees
      for (char child : children) {
        inDegree[child]--;
        if (inDegree[child] == 0) {
          sources.push(child);
        }
      }
    }

    // if sortedOrder doesn't contain all characters, there is a cyclic dependency between
    // characters, therefore, we will not be able to find the correct ordering of the characters
    if (sortedOrder.length() != inDegree.size()) {
      return "";
    }

    return sortedOrder;
  }
};

int
main(int argc, char *argv[]) {
  string result = AlienDictionary::findOrder(vector<string>{"ba", "bc", "ac", "cab"});
  cout << "Character order: " << result << endl;

  result = AlienDictionary::findOrder(vector<string>{"cab", "aaa", "aab"});
  cout << "Character order: " << result << endl;

  result = AlienDictionary::findOrder(vector<string>{"ywx", "wz", "xww", "xz", "zyy", "zwz"});
  cout << "Character order: " << result << endl;
}
