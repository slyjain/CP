#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m,sx,sy;
    cin>>n>>m>>sx>>sy;
    map<pair<int,int>,bool>mp;
    map<pair<int,int>,int>vis;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        mp[{x,y}]=true;
    }
    int cnt=0;
    if(mp[{sx,sy}]==true){
        cnt++;
    }
    vis[{sx,sy}]==1;
    for(int i=0;i<m;i++){
        char c;
        cin>>c;int d;
        cin>>d;
        // int nx,ny;
        if(c=='U'){
            //  nx=sx-1;
            //  ny=sy;
            sy+=d;
        }else if(c=='D' ){
            // nx=sx+1;
            // ny=sy;
            sy-=d;
        }else if(c=='L'){
            sx-=d;
        }else if(c=='R'){
            sx+=d;
        }
        if(mp[{sx,sy}]==true&&vis[{sx,sy}]==0){
            cnt++;
        }
        vis[{sx,sy}]=1;
    }
    cout<<sx<<" "<<sy<<" "<<cnt;

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}