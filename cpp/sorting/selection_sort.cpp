#include <iostream>
using namespace std;
int main(){
  int n;

  cin >> n;

  int a[n];

  for(int i=0; i<n;i++){
    a[i] = rand()%201-100;
    cout << a[i] << " ";
  }

  // Selection Sort
  int temp;    
  int index;

  for(int i=0; i<n; i++){
    index = i;
    for (int j=0; j<n; j++){
      if(a[j] < a[index]){
        index = j;
      }
    }
    temp = a[i];
    a[i] = a[index];
    a[index] = temp;
  }
  for(int i=0; i<n; i++) cout << a[i] << " ";
  cout << "\n";
}
