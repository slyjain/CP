#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    bool temp=false;
    if(a==b+c||b==a+c||c==a+b||(a==b&&b==c)){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}