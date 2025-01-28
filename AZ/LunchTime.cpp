#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
void solve(){
     int n;
     cin>>n;
     int a,b;
     cin>>a>>b;
     int cnt=0;
     while(a!=b){
        if(a>b){
            a/=2;
            // cnt++;
        }else{
            b/=2;
            
        }
        cnt++;
     }
    //  cout<<cnt;
     cout<<2*cnt-1<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}