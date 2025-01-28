#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
int sum(int a,int b){
    while(b){
        int temp=b&a;
        a=a^b;
        b=(temp<<1);
    }
    return a;
}
void solve(){
     int a,b;
     cin>>a>>b;
    cout<<sum(a,b)<<"\n";
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