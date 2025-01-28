#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> g; // adjacency list
int n; // number of vertices
vector<int>parent;
vector<bool> vis;
int mxCyc=1e9;
void dfs(int v,int par){
    // vis[v] = true;
    parent[v]=par;
    for(int u : g[v]){
        if(vis[u]==1){
            dfs(u,v);
        }else if(vis[u]==2&&u!=par){
            int curr=v;
            int cycSize=1;
            while(curr!=u){
                v=parent[v];
                cycSize++;
            }
            if(cycSize<mxCyc){
                mxCyc=cycSize;
            }
        }
    }
    // vis[v]=3;
}
void solve(){
    int m;
    cin>>n>>m;
    g.resize(n+1);
    vis.resize(n+1,1);
    parent.resize(n+1,0);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        vis.assign(n+1,0);
            // parent[i]=-1;
            dfs(i,-1);
        
    }
    cout<<mxCyc;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}