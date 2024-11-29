#include <iostream>
#include <vector>
using namespace std;

int minimum_coins(int amount, vector<int> &coins) {

  vector<int> dp(amount + 1, amount + 1);
  dp[0] = 0;

  for (int i = 1; i <= amount; i++) {
    for (int coin : coins) {
      if (coin <= i) {
        dp[i] = min(dp[i], dp[i - coin] + 1);
      }
    }
  }

  return (dp[amount] > amount) ? -1 : dp[amount];
}


int coin_change(int amount, vector<int> &coins) {

  vector<vector<int>> dp;

  for (int coin : coins) {
    amount -= coin;
    if (amount >= 0) {
      coin_change(amount-coin, coins);
    }
  }
}

int main() {

  vector<int> coins = {1,2};
  int amount = 2;
  // int count = minimum_coins(13, coins);

  coin_change(amount, coins);

  return 0;
}
