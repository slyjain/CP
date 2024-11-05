#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<vector<int>>g;
vector<int>vis;
void dfs(int i){
    vis[i]=1;
    for(auto v:g[i]){
        if(vis[v]==0){
            dfs(v);
        }
    }
}
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    vis.resize(n+1,0);
    
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int>nv;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            nv.push_back(i);
            dfs(i);
        }
    }
    cout<<nv.size()-1<<"\n";
    for(int i=1;i<nv.size();i++){
        cout<<nv[0]<<" "<<nv[i]<<"\n";
    }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}