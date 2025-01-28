#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
int n;
cin>>n;
int c1=__builtin_popcountll(n);
c1=1<<c1;
cout<<n+1-c1<<" "<<c1<<"\n";
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