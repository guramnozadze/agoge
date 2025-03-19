#include <bits/stdc++.h>

using namespace std;

int G[21][21] = {0}, used[21]; // used[/] - 1

int n,m,x;

void DFS(int v) {

    used[v] = 1;

    for (int i = 1; i <=n ; i++)  // G[v]
        if ( G[v][i] == 1)
            if ( used[i] == 0 )
                DFS(i);
}



int main(){

    cin>> n >> m >> x;

    // Mezoblebis Matrica - Adjacency Matrix
    for (int i =1; i<=m; ++i) {
        int u, v; cin >> u >> v;
        G[u][v] = G[u][v] = 1;
    }



    return 0;
 }