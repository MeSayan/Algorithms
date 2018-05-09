/*Directed and Weighted Grapgh*/

#include <iostream>
#include <vector>

using namespace std;
using vertex = int;
using edge = pair<int, pair <int, int>>; // (weight,source,dest)
using edgelist = vector<edge>;


class DGraph{

#define start(u) u.second.first
#define end(u) u.second.second 
#define weight(u) u.first
  
public:
  int N;
  vector<vector<pair<int,int>>> dgraph;
  
  DGraph(int n): N(n), dgraph(n,vector<pair<int,int>>(0)) {};

  void addEdge(edge e) {
    dgraph[start(e)].push_back({end(e),weight(e)});
    //cout << dgraph[start(e)] << "  ";
  }

  void buildGraph(edgelist el) {
    for(edge e: el) {
      addEdge(e);
    }
  }

  void BFS(vertex source) {

    
  }

  void printMatrix() {
    for(auto i: dgraph) {
      for(auto j: i) {
	cout << j.first << " " << j.second;
      }
    }
  }
};
  

int main() {
  DGraph G(3);
  edgelist el = { {0,{0,1}}, {1,{1,2}}};
  G.buildGraph(el);
  G.printMatrix();

  return 0;

  
}
