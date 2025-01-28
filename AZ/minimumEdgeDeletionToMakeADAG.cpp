#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
int n;
vector<vector<int>>g;
//vector<vector<int>> g; // adjacency list
//int n; // number of vertices
vector<int> vis;
int ans=0;
void dfs(int v){
    vis[v] = 1;
    for(int u : g[v]){
        if(vis[u]==0){
            dfs(u);
        }else if(vis[u]==1){
            ans++;
        }
    }
    vis[v]=2;
}
void solve(){
    ans=0;
    cin>>n;
    g.resize(n+1);
    vis.resize(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
            if(x==1){
                g[i].push_back(j);
            }
        }
    }     
    for(int i=1;i<=n;i++){
        if(vis[i]==false){
            dfs(i);
        }
    }
    cout<<ans<<"\n";
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