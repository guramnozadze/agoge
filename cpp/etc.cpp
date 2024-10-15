#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  int a[N];
  int x;

  for(int i=0; i<N; i++){
    //cin >> x;
    //a[i] = x;
    cin >> a[i];
    a[i] = rand()%201; // [0. 200]
  }

  for(int i=0; i<N; i++){
    cout << a[i] << " ";
  }
}
