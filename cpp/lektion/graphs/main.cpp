//
// Created by gukan on 12/17/2024.
// Mathematician eileri
#include <iostream>
#include <vector>

using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

int main(){

  int n, m;
  int u, v;

  cin >> n >> m;

  vector<int> adj[n+1];

  for(int i=0; i<m; i++){
    cin >> u >> v;
    addEdge(adj, u, v);
  }

  for(int i=1; i<n+1; i++){
    cout << i << " - ";
    for(int j=0; j<adj[i].size(); j++){
      cout << adj[i][j] << " ";
    }
    cout << "\n";
  }

}