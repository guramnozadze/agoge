//
// Created by gukan on 12/17/2024.
// Mathematician eileri
#include <iostream>
#include <vector>

using namespace std;

//
void binary_search() {

}

// https://www.aiasoft.ge/problem/306
void mariams_birthday() {
    int N; // mariams firends
    int M; // conflicted friends count
    cin >> k >> n;
    if (n % 2) {
        cout << 0;
    }else {
        cout << 1;
    }
}


// https://www.aiasoft.ge/problem/857
void binary_tree() {
    int N; // count of leaves // leaf is a vertex that has only one edge
    cin >> k >> n;
    if (n % 2) {
        cout << 0;
    }else {
        cout << 1;
    }
}

// https://www.aiasoft.ge/problem/649
void check_the_graph() {
    int k, n;
    cin >> k >> n;
    if (n % 2) {
        cout << 0;
    }else {
        cout << 1;
    }
}

// https://www.aiasoft.ge/problem/903
void city_baias_mayor() {
    int N, M;// Verticies, Edges
    cin >> N >> M;
    vector<int> adj[N+1];

    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int max_edges =0;
    int vertice =0;
    for (int i = 1; i <= N; i++) {
        cout << i << " - ";
        if (adj[i].size() >= max_edges) {
            vertice = i;
            max_edges =adj[i].size();
        }
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j]<<" ";
        }
        cout << endl;
    }
    cout << vertice;

}

void edge_count() {
    int N; // N - Vertex - წიბო
    cin >> N;

    int adj[N+1][N+1] = { 0 };
    string answer = "yes";
    int edge_count = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int a;
            cin >> a;
            adj[i][j] = a;
            if (adj[j][i] == 1 && adj[i][j] == 1) {
                edge_count++;
            }
        }
    }

    cout << edge_count << endl;
}

void edge_count_answer() {
    int N;
    int x, m = 0, k = 0;

    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> x;
            if(i==j) m += x; // Diagonal (LOOP)
            else k += x; // Off-diagonal
        }
    }

    cout << k/2 + m;
}

int main() {
    city_baias_mayor();

    return 0;
}
