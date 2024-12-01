//
// Created by gukan on 12/1/2024.
//
#include <iostream>
#include <vector>
#include <cstddef>  // For NULL

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

vector<int>* how_sum(int targetSum, vector<int> &a) {
	if (targetSum == 0) return new vector<int>();
	if (targetSum < 0 ) return nullptr;
	for (int num : a) {
		vector<int>* curr = how_sum(targetSum - num, a);
		if (curr != nullptr) {
			curr->push_back(num);
			return curr;
		}
	}
	return nullptr;
}


int main() {
	int m = 33, n = 35;
	// vector<vector<int>> memo(m+1, vector<int>(n+1, -1));

	// vector<int> memo(targetSum+1, -1);
	// cout << how_sum(targetSum,a) << endl;
	int targetSum = 11;
	vector<int> a = {5,3,4,7};

	vector<int>* sums = how_sum(targetSum, a);
	if (sums != nullptr) {
		for (int n : *sums) {  // Note the * to dereference
			cout << n << endl;
		}
	}
	return 0;
}
