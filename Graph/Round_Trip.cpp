#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<vector<int>>g;
vector<int>vis;
vector<int>par;
bool cyc;
vector<int>cycPath;
// vector<int>col;
void dfs(int i,int parent){
    vis[i]=1;
    
    for(auto v:g[i]){
        if(vis[v]==0){
            par[v]=i;
            dfs(v,i);
            if(cyc==true)return;
            
        }
        else if(vis[v]==1&&v!=parent){
            int p=v;
            cycPath.push_back(p);
            // cout<<p<<" ";
            p=i;
            while(p!=v){
                cycPath.push_back(p);
                // cout<<p<<" ";
                p=par[p];
                
                
            }
            cycPath.push_back(v);
            // cout<<v<<" ";
            cyc=true;
            return;
        }
    }
}
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    vis.resize(n+1,0);
    par.resize(n+1,-1);
    // col.resize(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // vector<int>nv;
    cyc=false;
    for(int i=1;i<=n;i++){
        if(vis[i]==0&&cyc==false){
            // nv.push_back(i);
            dfs(i,-1);
        }
    }
    if(cycPath.size()>0){
        cout<<cycPath.size()<<"\n";
    for(auto v:cycPath){
        cout<<v<<" ";
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