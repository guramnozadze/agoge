#include <iostream>
#include <vector>
using namespace std;

// Bottom-up Approach
int fibFaster(int n) {
  vector<int> memo(n + 1, 0);

  for (int i = 0; i <= n; i++) {
    if (i <= 1) {
      memo[i] = 1;
    } else {
      memo[i] = memo[i - 1] + memo[i - 2];
    }
  }

  return memo[n];
}

// Memoized Fibonacci
int fibSlowMemo(int n, vector<int> &memo) {
  if (memo[n] != 0) {
    return memo[n];
  }

  if (n <= 1) {
    return 1;
  }


  memo[n] = fibSlowMemo(n-1, memo) + fibSlowMemo(n-2, memo);

  return memo[n];
}

// Slowest Fibonacci
int fibSlow(int n) {
  if (n <= 1) {
    return 1;
  }

  return fibSlow(n-1) + fibSlow(n-2);
}

// Tabluation
// 0 1 2 3 4 5 6
// 0 1 1 2 3
int fib_dynamic(int n) {
  vector<int> table(n+1, 0);
  table[1]= 1;
  for (int i = 0 ; i <= n; i++) {
    table[i+1] += table[i];
    table[i+2] += table[i];

  }
  for (int i = 0 ; i <= n; i++) {
   cout << table[n] << " ";
  }

  return 1;
}

int main() {

  int n = 41;
  vector<int> memo(n+1, 0);
  fib_dynamic(6);
  // cout << "fibFaster: " << fibFaster(n) << endl;
  // cout << "fibSlowMemo: " << fibSlowMemo(n,memo) << endl;
  // cout << "fibSlow: " << fibSlow(n) << endl;

  return 0;
}
