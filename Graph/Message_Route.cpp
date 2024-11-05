#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<vector<int>>g;
vector<int>dis;
vector<int>parent;
// void dfs(int i){
//     vis[i]=1;
//     for(auto v:g[i]){
//         if(dis[v]==0){
//             dfs(v);
//         }
//     }
// }
void bfs(int st){
    queue<int>q;
    q.push(st);
    dis[st]=1;
    while(!q.empty()){
        int f=q.front();
        q.pop();
        for(auto v:g[f]){
            if(dis[v]==1e18){
                dis[v]=1+dis[f];
                q.push(v);
                parent[v]=f;
            }
        }
    }
}
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    dis.resize(n+1,1e18);
    parent.resize(n+1,-1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

   bfs(1);
    if(dis[n]==1e18){
        cout<<"IMPOSSIBLE";
    }
    else{
        vector<int>path;
        cout<<dis[n]<<"\n";
        int p=n;
        while(p!=-1){
            path.push_back(p);
            p=parent[p];
        }
        reverse(path.begin(),path.end());
        for(auto p:path){
            cout<<p<<" ";
        }
    }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}