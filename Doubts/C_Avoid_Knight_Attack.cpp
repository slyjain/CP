#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a,b;
int dx[]={1,-1,1,-1,2,-2,2,-2};
int dy[]={2,2,-2,-2,1,1,-1,-1};
bool isValid(int x,int y){
    if(x<n&&x>=0&&y<n&&y>=0){
        return true;
    }
    return false;
}
void solve(){
    cin>>n>>m;
    map<pair<int,int>,int>cb,at;
    for(int i=0;i<m;i++){
        
        cin>>a>>b;
        a--,b--;
        cb[{a,b}]++;
    }
    
    for(auto u:cb){
        int x=u.first.first;
            int y=u.first.second;
            at[{x,y}]++;
        for(int i=0;i<8;i++){
            
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(isValid(nx,ny)){
                at[{nx,ny}]++;
            }
        }
    }
    cout<<n*n-at.size();

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}