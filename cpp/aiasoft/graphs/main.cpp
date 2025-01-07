//
// Created by gukan on 12/17/2024.
// Mathematician eileri
#include <iostream>
#include <vector>

using namespace std;


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
    edge_count();


    return 0;
}
