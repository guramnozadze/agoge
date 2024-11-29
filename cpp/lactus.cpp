#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K, L; // N - Leaf count, L - stones count
    cin >> N >> K >> L;


    int leafs[N];
    for (int i = 0; i < N; i++) {
        leafs[i] = 1;
    }

    for (int i = 0; i < L; i++) {
      int index;
      cin >> index;
      leafs[index] = 0;
    }

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;










    // Optional: Print the array to verify
    for (int i = 0; i < N; i++) {
        cout << leafs[i] << " ";
    }
    cout << endl;
}







//int N, K, L;
//int x;
//
//cin >> N >> K >> L;
//
//int d[N + 1];
//for (int i = 0; i <= N; i++)
//    d[i] = 1;
//
//for (int i = 0; i < L; i++) {
//    cin >> x;
//    d[x] = 0;
//}
//
//for (int i = 2; i <= K; i++) {
//    if (d[i]) {
//        d[i] = 0;
//        for (int j = 1; j < i; j++)
//            d[i] += d[j];
//    }
//}