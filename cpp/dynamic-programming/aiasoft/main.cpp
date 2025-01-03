//
// Created by gukan on 12/15/2024.
//
#include <bits/stdc++.h>

using namespace std;

int locust_and_frogs() {
    int N, K, L; // leafs, jump distance, count of frogs
    cin >> N >> K >> L;

    vector<int> path(N, 0);
    path[0] = 1; // Starting point always has 1 way to reach


    for (int i = 0; i < L; i++) {
        int j;
        cin >> j;
        path[j - 1] = -1;
    }


    for (int i = 1; i < N; i++) {
        if (path[i] == -1) continue; // Skip blocked stones
        for (int j = K; j > 0; j--) {
            int prev_leaf = i - j;
            if (prev_leaf < 0 || path[prev_leaf] == -1) continue;
            path[i] += path[prev_leaf];
        }
    }

    return (path[N - 1] == -1 ? 0 : path[N - 1]) ;
}

int broken_ladder_1() {
    int N, K;

    cin >> N >> K;
    vector<long long> F(N+1, 0);
    vector<bool> check(N+1, true);
    F[0]=1;
    F[1]=1;


    for (int i = 0; i < K; i++) {
        int j;
        cin >> j;
        F[j] = 0;
        check[j] = false;
    }



    for (int i = 2; i <= N; i++) {
        if(check[i] == false){
            continue;
        }


        F[i]=F[i-1]+F[i-2];
    }


    cout<< F[N];
    return 0;

int main() {
    int result =broken_ladder_1() ;
    cout << result;
    return 0;
}


