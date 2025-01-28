#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>dis;
vector<vector<char>>g;
#define F first 
#define S second
using node=pair<pair<int,int>,int>;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int h, w,d;
vector<pair<int,int>> neigh(pair<int,int>v){
    vector<pair<int,int>>ne;
    int x=v.first;
    int y=v.second;
    for(int i=0;i<4;i++){
        if(x+dx[i]>=0&&x+dx[i]<h&&y+dy[i]>=0&&y+dy[i]<w){
            ne.push_back({x+dx[i],y+dy[i]});
        }
    }
    return ne;
}
void bfs(pair<int,int> init){
    queue<node>q;
    q.push({init,0});
    dis[init.F][init.S]=0;
    while(!q.empty()){
        pair<int,int> v=q.front().F;
        int dist=q.front().S;
        q.pop();
        for(auto x:neigh(v)){
            if(dis[x.first][x.second]>(dist+1)&&g[x.first][x.second]=='.'&&dist<d){
                dis[x.first][x.second]=dist+1;
                q.push({{x.first,x.second},dist+1});
            }
        }
    }
}
void solve(){
    
    cin>>h>>w>>d;
    
    g.assign(h,vector<char>(w,0));
    vector<pair<int,int>>initialisers;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>g[i][j];
            if(g[i][j]=='H'){
                initialisers.push_back({i,j});
            }
        }
    }
    dis.assign(h,vector<int>(w,1e18));
    for(auto x:initialisers){
        bfs(x);
    }
    int ans=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            // if(dis[i][j]==1e18){
            //     cout<<"inf"<<"\t";
            // }else{
            //     cout<<dis[i][j]<<"\t";
            // }
            if(dis[i][j]<=d){
                
                ans++;
            }
        }
        // cout<<"\n";
    }
    cout<<ans;

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}