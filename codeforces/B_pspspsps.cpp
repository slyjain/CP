#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    string s;
    cin>>n>>s;
    if(s[0]=='s'){
        s[0]='.';
    }if(s[n-1]=='p'){
        s[n-1]='.';
    }
    char prev='.';
    for(auto x:s){
        if(x!='.'){
        if(x!=prev&&prev!='.'){
            cout<<"NO\n";
            return;
        }
        else if(x!=prev){
            prev=x;
        }}
    }
    cout<<"YES\n";
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