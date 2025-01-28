#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,q;
vector<vector<int>>g,vis;
int cnt;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int dfs(int x,int y){
    g[x][y]=0;
    int ans=1;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0&&nx<n&&ny>=0&&ny<m&&g[nx][ny]==1){
            ans+=dfs(nx,ny);
        }
    }
    return ans;

}
void solve(){
    cin>>n>>m>>q;
    g.resize(n,vector<int>(m));
    vis.resize(n,vector<int>(m,0));
    int total=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            if(g[i][j]==1)total++;
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        x--,y--;
        if(g[x][y]==0){
            cout<<total<<"\n";
        }else{
            total-=dfs(x,y);
           cout<<total<<"\n";
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