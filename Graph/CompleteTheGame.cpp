#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<vector<int>>g;
vector<int>ways;
vector<int>vis;
int bfs(int start,int way){
    ways[start]=way;
    vis[start]=1;
    queue<int>q;
    q.push(start);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto v:g[curr]){
            ways[v]+=ways[curr];
            if(vis[v]==0){
                q.push(v);
            }
            
        }
    }
    return ways[n];
}
void solve(){
cin>>n>>m;
g.resize(n+1);
ways.resize(n+1,0);
vis.resize(n+1,0);
for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    g[x].push_back(y);


}
int ans=bfs(1,1);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}