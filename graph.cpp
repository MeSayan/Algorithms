#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using vertex = int;
using edge = pair<int, int>;
using edgelist = vector<edge>;


class Graph {
  
  public:
  int N;
  vector< vector<vertex> > graph;
  vector<int> v;
  
  Graph(int n): N(n), graph(n,vector<int>(0)) {};

  void addEdge(edge e) {
    graph[e.first].push_back(e.second);
    graph[e.second].push_back(e.first);
  }

  void buildGraph(edgelist A) {
    for(edge e: A ) {
      addEdge(e);
    }
  }

  void BFS(vertex source) {
    queue<vertex> Q;
    Q.push(source);
    
    // visited array tacks wether vertex is
    // visited or not
    bool visited[N] = {false};

    while(!Q.empty()) {
      vertex v = Q.front();
      Q.pop();
      visited[v] = true;
      
      cout << v << " ";
      for (vertex u: graph[v]) {
	if( !visited[u] )
	  Q.push(u);
      }
    }
  }

  vector<int> BFSwithLevels(vertex source) {

    queue<vertex> Q;
    Q.push(source);
    
    // visited array tacks wether vertex is
    // visited or not
    bool visited[N] = {false};
    vector<int> level(N);
    level[source] = 0;

    
    while(!Q.empty()) {
      vertex v = Q.front();
      Q.pop();
      visited[v] = true;
      
      cout << v << " ";
      for (vertex u: graph[v]) {
	if( !visited[u] )
	  Q.push(u), level[u] = level[v]+1;
      }
    }

    return level;
  }


  void DFS(vertex source) {
    bool visited[N] = {false};
    DFSutil(source, visited);
  }
   
  void DFSutil(vertex source,bool visited[]){
    
    visited[source] = true;
    cout << source << " ";

    for(auto dest: graph[source]){
      if ( !visited[dest] ){
	DFSutil(dest, visited);
      }
    }
  }
  
  void printMatrix() {
    for(auto  i : graph ){
      for(auto  j: i){
	cout << j ;
      }
      cout << endl;
    }
  }
  
};

int main() {
  Graph G(4);
  edgelist  e = {{0,1}, {0,2}, {1,2}, {2,0}, {2,3}, {3,3}};

  G.buildGraph(e);
  G.DFS(2);

  return 0;
}
