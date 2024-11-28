#include <iostream>
#include <vector>
using namespace std;

// Bottom-up Approach
int fibBUA(int n) {
  vector<int> memo(n + 1, 0);

  for (int i = 0; i <= n; i++) {
    if (i < 2) {
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

int main() {

  int fibo = 5;

  cout << "answer" << fibBUA(fibo) << endl;
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
