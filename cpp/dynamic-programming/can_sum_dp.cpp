//
// Created by gukan on 12/3/2024.
//
#include <iostream>
using namespace std;


bool canSumTabulation(int targetSum, int a[], int n){ // n -length
  bool tab[targetSum+1];
  for (int i = 0; i <= targetSum;i++){
    tab[i] = false;
  }
  tab[0] = true;

  for (int i = 0; i <= targetSum;i++){
    if(tab[i]){
      for (int j = 0; j < n;j++){
        if(tab[i+a[j]] == false){
          tab[i+a[j]] = true;
        }
      }
    }
  }

  return tab[n];
}

int main(){
  int n = 3;
  int targetSum = 7;
  int a[3] = {5,3,4};
  cout << canSumTabulation(targetSum, a, n) << endl;

  return 0;
}