#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>pre(n);
    string s;
    cin>>s;
    pre[0]=s.length();
    for(int i=1;i<n;i++){
        cin>>s;
        pre[i]=s.length();
        pre[i]+=pre[i-1];
    }
    int ans=upper_bound(pre.begin(),pre.end(),m)-pre.begin();
    cout<<ans<<"\n";
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