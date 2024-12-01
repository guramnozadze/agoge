//
// Created by hebontes on 11/30/24.
//
#include <iostream>
#include <vector>
using namespace std;

// Alternatively C guide is better than this freeCodeCamps
void merge_sorted_arrays(vector<int> &a, int l, int m, int r) {
	int temp[r - l + 1];
	int i = l, j = m+1, k = 0;
	while (i <= m  && j <= r) {
		if (a[i] <= a[j]){
			temp[k] = a[i];
			k++;

			i++;
		}else {
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	while (i <= m) {
		temp[k] = a[i];
		k++;

		i++;
	}
	while (j <= r) {
		temp[k] = a[j];
		k++;
		j++;
	}

	for (i=l; i <= r; i++) {
		a[i] = temp[i-l];
	}

}

void merge_sort_recursion(vector<int> &a, int l, int r) {
	// l = 0 r = 1
	if (l < r) {
		int m = l + (r - l) / 2;
		merge_sort_recursion(a, l, m);
		merge_sort_recursion(a, m + 1, r);
		merge_sorted_arrays(a, l, m, r);
	}
}

void merge_sort(vector<int> &a, int length) {
	merge_sort_recursion(a, 0, length - 1);
}

int main() {
	vector<int> arr = {9, 4, 8, 1, 7, 0, 3, 2, 5, 6};
	int length = 10;
	merge_sort(arr, length);
	// output arr
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
