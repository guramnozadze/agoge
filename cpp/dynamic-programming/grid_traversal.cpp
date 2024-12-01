//
// Created by gukan on 12/1/2024.
//
#include <iostream>
#include <vector>
using namespace std;

int grid_traversal(int m, int n, vector<vector<int>> &memo) {
	if (memo[m][n] != -1) {
		return memo[m][n];
	}
	if (m == 1 && n == 1) return 1;
	if (m == 0 || n == 0) return 0;
	memo[m][n] = grid_traversal(m -1,n,memo) + grid_traversal(m, n - 1,memo);
	return memo[m][n];
}

bool can_sum(int targetSum, vector<int> a, vector<int> &memo) {
	if (memo[targetSum] != -1) return memo[targetSum];
	if (targetSum == 0) return true;
	if (targetSum < 0) return false;

	for (int i = 0; i < a.size(); i++) {
		if (can_sum(targetSum-a[i], a,memo) == true) {
			memo[targetSum] = true;
			return true;
		}
	}

	memo[targetSum] = false;
	return false;
}

int main() {
	int m = 33, n = 35;
	// vector<vector<int>> memo(m+1, vector<int>(n+1, -1));
	vector<int> a = {5,3,4,7};

	int targetSum = 20000;
	vector<int> memo(targetSum+1, -1);
	cout << can_sum(targetSum,a, memo) << endl;

	return 0;
}
