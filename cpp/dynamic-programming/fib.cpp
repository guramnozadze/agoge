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

// Memoized Fib
int fib(int n, vector<int> &memo) {
  if (memo[n] != 0) {
    return memo[n];
  }

  if (n <= 2) {
    return 1;
  }

  memo[n] = fib(n - 1, memo) + fib(n - 2, memo);

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

int fibMemo(int n, vector<int> &memo) {
  if(memo[n] != 0){
    return memo[n];
  }
  if (n <= 2) {
    return 1;
  }

  memo[n] = fibSlow(n-1) + fibSlow(n-2);
  return memo[n];
}

int main() {

  int n = 41;
  vector<int> memo(n+1, 0);

  cout << "fibFaster: " << fibFaster(n) << endl;
  cout << "fibSlowMemo: " << fibSlowMemo(n,memo) << endl;
  cout << "fibSlow: " << fibSlow(n) << endl;

  return 0;
}

// OOP
class Solution {
public:
  int fib(int n) {
    vector<int> memo(n, 0);

    return fibMemo(n, memo);
  }

private:
  int fibMemo(int n, vector<int> &memo) {
    // Check if we've already computed this Fibonacci number
    if (memo[n] != 0) {
      return memo[n];
    }

    // Base cases
    if (n <= 1) {
      return n;
    }

    // Recursive computation and memoization
    memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
    return memo[n];
  }
};
