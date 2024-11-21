#include <iostream>
using namespace std;

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
  cout << d[n];

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
