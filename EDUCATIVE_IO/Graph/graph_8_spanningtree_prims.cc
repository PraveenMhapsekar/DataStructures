#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

class vertex {
private:
  int id;
  bool visited;

public:
  vertex(int id, bool visited) {
    this->id = id;
    this->visited = visited;
  }

  int getId() {
    return id;
  }
  void setId(int id) {
    this->id = id;
  }
  bool isVisited() {
    return visited;
  }
  void setVisited(bool visited) {
    this->visited = visited;
  }
};

class edge {
private:
  int weight;
  bool visited;
  vertex* src;
  vertex* dest;

public:
  edge(int weight, bool visited, vertex* src, vertex* dest){
    this->weight = weight;
    this->visited = visited;
    this->src = src;
    this->dest = dest;
  }

  int getWeight() const {
    return weight;
  }

  void setWeight(int weight) {
    this->weight = weight;
  }

  bool isVisited() const {
    return visited;
  }

  void setVisited(bool visited) {
    this->visited = visited;
  }

  vertex* getSrc() const {
    return src;
  }

  void setSrc(vertex* src) {
    this->src = src;
  }

  vertex* getDest() const {
    return dest;
  }

  void setDest(vertex* dest) {
    this->dest = dest;
  }
};

class graph {
private:
  vector<vertex*> g;    //vertices
  vector<edge*> e;      //edges

public:
  const vector<vertex*>& getG() const {
    return g;
  }

  void setG(const vector<vertex*>& g) {
    this->g = g;
  }

  const vector<edge*>& getE() const {
    return e;
  }

  void setE(const vector<edge*>& e) {
    this->e = e;
  }

  // This method returns the vertex with a given id if it
  // already exists in the graph, returns NULL otherwise
  vertex* vertex_exists(int id) {
    for (int i = 0; i < this->g.size(); i++) {
      if (g[i]->getId() == id) {
        return g[i];
      }
    }
    return nullptr;
  }

	// This method generates the graph with v vertices
	// and e edges
	void
	generate_graph(int vertices, vector< vector<int> > edges) {
    // create vertices
    for (int i = 0; i < vertices; i++) {
      vertex* v = new vertex(i + 1, false);
      this->g.push_back(v);
    }

    // create edges
    for (int i = 0; i < edges.size(); i++) {
      vertex* src = vertex_exists(edges[i][1]);
      vertex* dest = vertex_exists(edges[i][2]);
      edge* e = new edge(edges[i][0], false, src, dest);
      this->e.push_back(e);
    }
  }

	// This method finds the MST of a graph using
	// Prim's Algorithm
	// returns the weight of the MST
	int find_min_spanning_tree(){
    int vertex_count = 0;
    int weight = 0;

    // Add first vertex to the MST
    vertex* current = g[0];
    current->setVisited(true);
    vertex_count++;

    // Construct the remaining MST using the
    // smallest weight edge
    while (vertex_count < g.size()) {
      edge* smallest = NULL;

      for(int i = 0; i < e.size(); i++){
        if(e[i]->isVisited() == false) {
          if ((e[i]->getSrc()->isVisited() == true) && 
              (e[i]->getDest()->isVisited() == false)) {
            if (smallest == NULL ||
                e[i]->getWeight() < smallest->getWeight()) {
               smallest = e[i];
            }
          }
        }
      }

      smallest->setVisited(true);
      smallest->getDest()->setVisited(true);
      weight += smallest->getWeight();
      vertex_count++;
    }
    return weight;
  }

  string print_graph() {
    string result = "";
    cout << "visited" << endl;
    for (int i = 0; i < g.size(); i++) {
       cout<<g[i]->getId()<< ' ' <<g[i]->isVisited()<< endl;
    }
    cout << endl << "Graph" << endl;
    cout << "src->dst[wht, vsted]" << endl;
	for (int i = 0; i < e.size(); i++) {
      result += "[" + std::to_string(e[i]->getSrc()->getId()) + "->" + std::to_string(e[i]->getDest()->getId()) + "],";
       cout << e[i]->getSrc()->getId() << "->"
           << e[i]->getDest()->getId() << "["
           << e[i]->getWeight() << ", "
           << e[i]->isVisited() << "]  " << endl;
    }
    return result;
  }

  void print_mst(int w){
    cout << "MST\n";
    for(int i=0; i<e.size(); i++){
      if(e[i]->isVisited() == true){
        cout << e[i]->getSrc()->getId() << "->"
          << e[i]->getDest()->getId() << endl;
      }
    }
    cout << "weight: " << w << endl;
    cout << endl;
  }
};

void test_graph1() {
  graph g;
  int v = 5;

  // each edge contains the following: weight, src, dest
  vector<vector<int> > e = {{ 1, 1, 2 }, { 1, 1, 3 }, 
                            { 2, 2, 3 }, { 3, 2, 4 }, 
                            { 3, 3, 5 }, { 2, 4, 5 }};

  g.generate_graph(v, e);
  g.print_graph();
  cout << "Testing graph 1...\n";
  //g.print_graph();
  int w = g.find_min_spanning_tree();
  g.print_mst(w);
}

void test_graph2() {
  graph g;
  int v = 7;

  // each edge contains the following: weight, src, dest
  vector<vector<int> > e = { { 2, 1, 4 }, 
                        { 1, 1, 3 }, { 2, 1, 2 }, 
                        { 1, 3, 4 }, { 3, 2, 4 }, 
                        { 2, 3, 5 }, { 2, 4, 7 },
                        { 1, 5, 6 }, { 2, 5, 7 } };

  g.generate_graph(v, e);

  cout << "Testing graph 2...\n";
  g.print_graph();
  int w = g.find_min_spanning_tree();
  g.print_mst(w);
}

int main() {
  test_graph1();
  test_graph2();
  return 0;
}
