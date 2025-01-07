//
// Created by gukan on 12/17/2024.
// Mathematician eileri
#include <iostream>
#include <vector>

using namespace std;

// Table shows which vertex is connected to which vertex
// Table is N X N (Vertex X Vertex)
void adjancency_matrix() { // მოსაზღვრეობის მატრიცით
    int N, M; // N - Vertex - წვერი ||||| M - Edge - წიბო
    cin >> N >> M;

    int adj[N + 1][N+1] = {0};


    for (int i = 1; i <= M; i++) {
        int v, u;
        cin >> v >> u;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    // Input
    // 3 2
    // 1 2
    // 1 3
}

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// adjancency-list representation მოსაზღვრე წვეროების სია
int main() {
    int n, m;
    int u, v;

    cin >> n >> m;

    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++) {
        cin >> u >> v;

        addEdge(adj, u, v);
    }

    for (int i = 1; i < n + 1; i++) {
        cout << i << " - ";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
}
