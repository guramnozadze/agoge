//
// Created by gukan on 12/15/2024.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K, L; // leafs, jump distance, count of frogs
    cin >> N >> K >> L;

    vector<int> path(N, 0);
    path[0] = 1;  // Starting point always has 1 way to reach


    for (int i = 0; i < L; i++) {
        int j;
        cin >> j;
        path[j-1] = -1;
    }


    for (int i = 1; i < N; i++) {
        if (path[i] == -1) continue;  // Skip blocked stones
        for (int j = K; j > 0; j--) {
            int prev_leaf = i-j;
            if (prev_leaf < 0 || path[prev_leaf] == -1) continue;
            path[i] += path[prev_leaf];
        }
    }

    cout << path[N-1] << ' ';

    return 0;
}