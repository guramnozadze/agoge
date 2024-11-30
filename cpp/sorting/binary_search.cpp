//
// Created by hebontes on 11/30/24.
//
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int left, int right, int s) {
  if (left > right) {
    return -1;
  }
  int mid = (left + right) / 2;
  cout << mid << endl;
  if (s == arr[mid]) {
    return mid;
  }

  if (s < arr[mid]) {
    return binarySearch(arr, left, mid - 1, s);
  }

  if (s > arr[mid]) {
    return binarySearch(arr, mid+1, right, s);
  }

  return 0;
}

int main(){
  vector<int> arr = {45, 68, 99, 102, 123, 351};
  int search = 123;
  int value = binarySearch(arr, 0, 5, search);

  cout << value << " " << arr[value] << endl;
  return 0;
}

