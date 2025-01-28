#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int m,a,b,c;
    cin>>m>>a>>b>>c;
    int ans=0;
    ans=min(m,a);
    int rem=m-min(m,a);
    ans+=min(m,b);
    rem+=(m-min(m,b));
    ans+=min(rem,c);
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