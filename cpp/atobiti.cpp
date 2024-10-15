#include <iostream>
using namespace std;
int main(){   
    int n;        
    int d[10] = {0,0,0,0,0,0,0,0,0,0};    
    cin >> n;
    //
    while(n){
        d[n%10]++;
        n /= 10;
    }    
    //for(int i=0; i<10; i++) cout << i << " " << d[i] << "\n";    
    int m = d[0];
    for(int i=0; i<10; i++) if(d[i]>m) m = d[i];  // მასივის მაქსიმალურ ელემენტს
    for(int i=0; i<10; i++) if(d[i]==m) cout << i << " "; // მაქსმალური ლემენეტის ინდექს   
}
