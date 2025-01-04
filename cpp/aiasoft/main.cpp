//
// Created by gukan on 12/15/2024.
//
#include <bits/stdc++.h>

using namespace std;
// https://www.aiasoft.ge/problem/299
void ladder_and_ball() {
    int n;

    cin >> n;

    int d[n + 1];

    d[1] = 1;
    d[2] = 2;
    d[3] = 4;

    for (int i = 4; i <= n; i++) d[i] = d[i - 1] + d[i - 2] + d[i - 3];

    cout << d[n];
}

// https://www.aiasoft.ge/problem/225
void xaliso_isle() {
    int n, m;
    cin >> n >> m;
    vector a(n + 2, vector(m + 2, 0));
    vector dp(n + 2, vector(m + 2, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = a[i][j] + max(max(dp[i - 1][j], dp[i - 1][j - 1]), dp[i - 1][j + 1]);
        }
    }


    // READ
    // for (int i = 0; i < n + 2; i++) {
    //     for (int j = 0; j < m + 2; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl << endl;
    // READ
    int res = 0;
    for (int j = 1; j < m + 1; j++) {
        res = max(res, dp[n][j]);
    }
    cout << res;
}

// https://www.aiasoft.ge/problem/204
void locust_grasi() {
    int n;
    cin >> n;
    int d[n + 1];
    d[1] = 0;
    for (int i = 2; i <= n; i++) {
        d[i] = d[i - 1];
        if (i % 2 == 0) d[i] = min(d[i], d[i / 2]);
        if (i % 3 == 0) d[i] = min(d[i], d[i / 3]);
        d[i]++;
    }
    cout << d[n];
}


// https://www.aiasoft.ge/problem/202
void strange_ladder() {
    int n;

    cin >> n;

    long long a[n + 1], d[n + 1];

    for (int i = 1; i <= n; i++) cin >> a[i];


    d[1] = a[1];
    d[2] = a[2];

    for (int i = 3; i <= n; i++) d[i] = min(d[i - 1], d[i - 2]) + a[i];

    cout << d[n];
}


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

    return (path[N - 1] == -1 ? 0 : path[N - 1]);
}

int broken_ladder_1() {
    int N, K;

    cin >> N >> K;
    vector<long long> F(N + 1, 0);
    vector<bool> check(N + 1, true);
    F[0] = 1;
    F[1] = 1;


    for (int i = 0; i < K; i++) {
        int j;
        cin >> j;
        F[j] = 0;
        check[j] = false;
    }


    for (int i = 2; i <= N; i++) {
        if (check[i] == false) {
            continue;
        }


        F[i] = F[i - 1] + F[i - 2];
    }


    cout << F[N];
    return 0;
}

int main() {
    ladder_and_ball();
    cout << "endl" << endl;

    return 0;
}
