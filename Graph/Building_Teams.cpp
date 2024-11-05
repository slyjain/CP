#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<vector<int>>g;
vector<int>vis;
vector<int>col;
bool dfs(int i,int c){
    vis[i]=1;
    col[i]=c;
    bool ans=true;
    for(auto v:g[i]){
        if(vis[v]==0){
            ans=dfs(v,1-c);
            if(ans==false){
                return false;
            }
        }
        if(vis[v]!=0&&col[v]==c){
            return false;
        }

    }
    return ans;
}
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    vis.resize(n+1,0);
    col.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int>nv;
    bool ans=true;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            // nv.push_back(i);
            ans=dfs(i,0);
        }
    }
    if(ans){
        for(int i=1;i<=n;i++){
            cout<<col[i]+1<<" ";
        }
    }
    else{
        cout<<"IMPOSSIBLE";
    }
    // cout<<nv.size()-1<<"\n";
    // for(int i=1;i<nv.size();i++){
    //     cout<<nv[0]<<" "<<nv[i]<<"\n";
    // }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}