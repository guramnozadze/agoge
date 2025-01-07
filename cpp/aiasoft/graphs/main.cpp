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

void adjency_matrix() {
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

int main() {
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
}
