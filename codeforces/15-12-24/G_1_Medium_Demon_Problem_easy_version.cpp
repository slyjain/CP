#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
int n;
// vector<int>
// for(int i=1;i<=n;i++){
    
// }
vector<vector<int>>g(n+1);
vector<int>indegree(n+1,0);
for(int i=1;i<=n;i++){
    int x;
    cin>>x;
    g[i].push_back(x);
    indegree[x]++;
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