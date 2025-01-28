#include<bits/stdc++.h>
using namespace std;
#define int long long
int h,w;
 vector<vector<char>>g;
     vector<vector<bool>>vis;
     int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

bool valid(int x,int y){
    if(x>=0&&x<h&&y>=0&&y<w&&g[x][y]!='#'){
        return true;
    }
    return false;
}
void solve(){
    int x,y;
    cin>>h>>w>>x>>y;
   g.resize(h,vector<char>(w));
   vis.resize(h,vector<bool>(w,false));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>g[i][j];
        }
    }
    string s;
    cin>>s;
    int cnt=0;
    x--,y--;
    if(g[x][y]=='@'&&vis[x][y]==false){
            cnt++;
        }
        vis[x][y]=true;
    for(auto c:s){
        int nx,ny;
        if(c=='U'){
             nx=x+dx[2];
             ny=y+dy[2];
        }else if(c=='L'){
             nx=x+dx[0];
             ny=y+dy[0];
        }else if(c=='R'){
             nx=x+dx[1];
             ny=y+dy[1];
        }else if(c=='D'){
             nx=x+dx[3];
             ny=y+dy[3];
        }
        if(valid(nx,ny)){
                x=nx,y=ny;
            }
        if(g[x][y]=='@'&&vis[x][y]==false){
            cnt++;
        }
        vis[x][y]=true;
    }
    cout<<x+1<<" "<<y+1<<" "<<cnt;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}