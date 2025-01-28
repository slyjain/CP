#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
int n,m;
using ii=pair<int,int>;
const int inf=1e18;
vector<vector<char>>g;
vector<vector<int>>dis;
int dx[]={-1,-1,-1,0,0,+1,+1,+1};
int dy[]={0,-1,+1,-1,+1,-1,0,+1};
bool valid(int x,int y){
    return x>=0&&x<n&&y>=0&&y<m;
}
void bfs(int sx,int sy){
    queue<ii>q;
    dis[sx][sy]=0;
    q.push({sx,sy});
    while(!q.empty()){
        ii node=q.front();
        q.pop();
       for(int i=0;i<8;i++){
            int nx=node.first+dx[i];
            int ny=node.second+dy[i];
            if(valid(nx,ny)&&dis[nx][ny]==inf&&g[nx][ny]=='.'){
                dis[nx][ny]=dis[node.first][node.second]+1;
                q.push({nx,ny});
            }
        }
    }
}
void solve(){
     
    cin>>n>>m;
    g.clear();
    g.resize(n,vector<char>(m));
    dis.clear();
    dis.resize(n,vector<int>(m,inf));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
    }
    int sx,sy,ex,ey;
    cin>>sx>>sy>>ex>>ey;
    bfs(sx,sy);
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<(dis[i][j]==inf?-1:dis[i][j])<<"\t";
    //     }
    //     cout<<"\n";
    // }
    if(dis[ex][ey]!=inf){
        cout<<dis[ex][ey];
    }else{
        cout<<"-1";
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