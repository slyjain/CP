#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
vector<vector<int>> g; // adjacency list
int n; // number of vertices
vector<int> vis;
bool isPossible=false;
bool check(){
    for(int i=1;i<=n;i++){
        if(vis[i]==2)return false;
    }
    return true;
}
void dfs(int v,int par){
    vis[v] = 2;
    for(int u : g[v]){
        if(vis[u]==1){
            dfs(u,v);
        }else if(vis[u]==2&&u!=par){
            isPossible=true;
        }
    }
}
void solve(){
    int m;
        cin>>n>>m;
        g.resize(n+1);
        vis.resize(n+1,1);
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
            if(vis[i]==1){
                dfs(i,0);
            }
        }  
        if(isPossible){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
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