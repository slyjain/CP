#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a+b+c>=90){
        cout<<"PASS\n";
    }
    else{
        cout<<"FAIL\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}