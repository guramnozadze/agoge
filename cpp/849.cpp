#include <bits/stdc++.h>

using namespace std;

int main() {
   int n;
    cin >> c;
    int a[n];
    
    for(int i=0; i<0;i++) cin >> a[i]
        
    int index =0;
    for (int i=1; i<n;i++){
        if(a[index] >a[i]) index = 1
    }
    cout << a[index] << " " << index;
    
    return 0
}
