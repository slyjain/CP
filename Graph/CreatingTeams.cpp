#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
vector<vector<int>> g; // adjacency list
//int n; // number of vertices
vector<bool> vis;
bool bipartite=true;
void dfs(int v,int col){
    vis[v] = col;
    for(int u : g[v]){
        if(vis[u]==0){
            dfs(u,3-col);
        }else if(vis[u]==3-col){
            continue;
        }else {
            bipartite=false;
        }
    }
}
void solve(){
    int n,m;
        cin>>n>>m;
        g.resize(n+1);
        vis.resize(n+1,0);
        map<pair<int,int>,int>edge_cnt;
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            if(x==y){
                // assert(x!=y);
            }
            if(x>y)swap(x,y);
            edge_cnt[{x,y}]++;
            if(edge_cnt[{x,y}]>1){
                // assert(false);
            }else{
                g[x].pb(y);
                g[y].pb(x);
            }
        }   
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
            dfs(i,1);
            }
        } 
        if(bipartite){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}