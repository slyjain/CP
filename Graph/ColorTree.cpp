#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>g;
//vector<vector<int>> g; // adjacency list
//int n; // number of vertices
vector<bool> vis;
void dfs(int v){
    vis[v] = true;
    for(int u : g[v]){
        if(!vis[u]){
            dfs(u);
        }
    }
}
void solve(){
    int n,m;
    
    cin>>n;
    m=n-1;
    g.resize(n+1),vis.resize(n+1);
    for(int i=0;i<m;i++){
      int a,b;
      cin>>a>>b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    int col=0;
    for(int i=1;i<=n;i++){
      col=max(col,((int)g[i].size()+1));
    } 
    cout<<col;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}