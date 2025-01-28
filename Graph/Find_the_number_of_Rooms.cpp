#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<char>>g;
vector<vector<bool>>vis;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n,m;
void dfs(int r,int c){
    vis[r][c]=true;
    for(int i=0;i<4;i++){
        int nr=r+dy[i],nc=c+dx[i];
        if(nr>=0&&nr<n&&nc>=0&&nc<m){
            if(vis[nr][nc]==false&&g[nr][nc]=='.'){
            dfs(nr,nc);
        }
        }
        
    }
}
void solve(){
    
    cin>>n>>m;
    g.resize(n,vector<char>(m));
    vis.resize(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
    }
    int comp=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='.'&&vis[i][j]==false){
               comp++;
                dfs(i,j);
            }
        }
    }
    cout<<comp;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}