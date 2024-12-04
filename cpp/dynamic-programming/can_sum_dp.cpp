//
// Created by gukan on 12/3/2024.
//
#include <iostream>
#include <vector>
using namespace std;


vector<int> howSumTabulation(int targetSum, int a[], int n) {// n -length
  vector table(targetSum+1, vector<int>(0, {}));

  for (int i = 0; i < targetSum+1; i++) {
    if (i == 0 || !table[i].empty()) {
      for (int j = 0; j < n; j++) {
        int num = a[j];
        if (i+num < targetSum+1) {
          vector<int> combination = table[i];
          combination.push_back(num);
          if (table[i+num].size() > combination.size() || table[i+num].size() == 0) {
            table[i+num] = combination;
          }
        }
      }
    }
  }

  vector<int> result = table[targetSum];
  for (int num: result) {
    cout << num << " ";
  }

  return {};
}


bool canSumTabulation(int targetSum, int a[], int n){ // n -length
  bool tab[targetSum+1];
  for (int i = 0; i <= targetSum;i++){
    tab[i] = false;
  }
  tab[0] = true;

  for (int i = 0; i <= targetSum;i++){
    if(tab[i]){
      for (int j = 0; j < n; j++){
        int num = a[j];
        if(tab[i+num] == false){
          tab[i+num] = true;
        }
      }
    }
  }

  return tab[n];
}

int main(){
  int n = 3;
  int targetSum = 8;
  int a[n] = {2,3,5};
  howSumTabulation(targetSum,a,n);

  return 0;
}