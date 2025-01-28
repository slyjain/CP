#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>col;
vector<bool>vis;
vector<vector<int>>g;
void bfs(int sc_node){
    // vis[sc_node]=false;
    queue<int>q;
    q.push(sc_node);
    while(q.empty()==false){
        int node=q.front();
        q.pop();
        vis[node]=true;
        for(int x:g[node]){
            if(vis[x]==false){
                if(col[x]==col[node]){
                    col[x]++;
                }
                q.push(x);
            }
        }
    }
    
    
}
int mex(int i){
    int mex[3]={0,0,0};
    for(auto x:g[i]){
        mex[x]++;
    }
    for(int i=0;i<=2;i++){
        if(mex[i]==0){
            return i;
        }
    }
    return -1;
}
void solve(){
     int n,x,y;
     cin>>n>>x>>y;
     vis.resize(n+1,0);
     col.resize(n+1,0);
     g.resize(n+1);
     g[x].push_back(y);
     g[y].push_back(x);
     g[1].push_back(2);
     g[1].push_back(n);
     g[n].push_back(1);
     g[n].push_back(n-1);
     for(int i=2;i<=n-1;i++){
        g[i].push_back(i-1);
        g[i].push_back(i+1);
     }
     bfs(x);
     for(int i=1;i<=n;i++){
        cout<<mex(i);
     }
cout<<"\n";
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