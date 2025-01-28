#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
 int a[1000100],b[1000100];
void solve(){
    const int mod=1e9+7;

 a[1]=1,b[1]=1;   
 for(int i=2;i<1000100;i++){
    a[i]=(2*a[i-1]+b[i-1])%mod;
    b[i]=(4*b[i-1]+a[i-1])%mod;
 } 
 int t;
 cin>>t;
 while(t--){
    int n;
    cin>>n;
    cout<<a[n]+b[n]<<"\n";
 }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
        solve();
    return 0;
}