#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>g;
//vector<vector<int>> g; // adjacency list
//int n; // number of vertices
vector<int> vis;
void dfs(int v,int comp){
    vis[v] = comp;
    for(int u : g[v]){
        if(vis[u]==0){
            dfs(u,comp);
        }
    }
}
void solve(){
     int n,m,q;
     cin>>n>>m;
     g.resize(n+1);
     for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
     }
     vis.resize(n+1,0);
     int compNo=0;
     for(int i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i,++compNo);
        }
     }
     map<int,int>mp;
     for(int i=1;i<=n;i++){
        mp[vis[i]]++;
     }
     int sum=0;
     int sumSq=0;
    for(auto x:mp){
        sum+=x.second;
        sumSq+=(x.second*x.second);
    }
    int ans=sum*sum-sumSq;
    ans/=2;
    cout<<ans;
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}