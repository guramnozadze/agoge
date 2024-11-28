#include <bits/stdc++.h>

using namespace std;

int main() {

    int N, K, L;
    int x;

    cin >> N >> K >> L;

    int d[N + 1];
    for (int i = 0; i <= N; i++)
        d[i] = 1;

    for (int i = 0; i < L; i++) {
        cin >> x;
        d[x] = 0;
    }

    for (int i = 2; i <= K; i++) {
        if (d[i]) {
            d[i] = 0;
            for (int j = 1; j < i; j++)
                d[i] += d[j];
        }
    }
}
