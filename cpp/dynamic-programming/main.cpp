#include <iostream>
using namespace std;

// https://www.aiasoft.ge/problem/307
int matrix_sum() {
    int N, M;
    cin >> N >> M;
    int a[N][M];

    // Without writing to matric
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }

    int count;
    cin >> count;
    while (count > 0) {
        int x, y;
        cin >> x >> y;

        int sum = 0;
        for (int i = 0; i < x - 1; i++) {
            for (int j = 0; j < y - 1; y++) {
                sum += a[i][j];
            }
        }

        cout << sum << endl;
        count--;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    int n;
    cin >> n;

    long long d[n + 1];

    d[1] = 0;
    d[2] = 1;
    d[3] = 1;

    for (int i = 4; i <= n; i++) {
        d[i] = d[i - 3] + d[i - 2];
    }

    for (int i = 1; i <= n; i++) {
        cout << i << " - " << d[i] << endl;
    }
    cout << d[n] ;

    return 0;
}

/*
int main(int argc, char *argv[]) {
  int n, e;
  cin >> n >> e;
  int a[n][n];

  // Without writing to matric
  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        cin >> x;
        if (i + j == n - 1 || i == j) {
            sum += x;
      }
    }
  }


  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i <= j) {
        a[i][j] = e;
      } else {
        a[i][j] = 0;
      }
    }
  }

  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}*/
// g++  7.4.0

#include <iostream>

using namespace std;

void dynamic_matrix_sum() {
    int N;

    cin >> N;

    int C[N + 1][N + 1];

    C[0][0] = 1;
    C[1][0] = C[1][1] = 1;

    for (int n = 2; n <= N; n++) {
        C[n][0] = C[n][n] = 1;
        for (int k = 1; k < n; k++) {
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
        }
    }

    for (int n = 0; n <= N; n++) {
        for (int k = 0; k <= n; k++) {
            cout << C[n][k] << " ";
        }
        cout << "\n";
    }
}
