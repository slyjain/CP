#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
int f[1010][1010];
int p[1010][1010];
void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char x;
            cin>>x;
            // cout<<x<<" ";
            if(x=='.'){
                f[i][j]=0;
            }
            else{
                f[i][j]=1;
            }
            // cout<<f[i][j]<<" ";
        }
        // cout<<"\n";
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            p[i][j]=f[i][j];
            if(i>1){
                p[i][j]+=p[i-1][j];
            }
            if(j>1){
                p[i][j]+=p[i][j-1];
            }   
            if(i>1&&j>1){
                p[i][j]-=p[i-1][j-1];
            }
            // cout<<p[i][j]<<" ";
        }
        // cout<<"\n";
    }
    while(q--){
        int x1,x2,y1,y2;
        cin>>y1>>x1>>y2>>x2;
        // cout<<y1<<" "<<x1<<" "<<y2<<" "<<x2<<"\n";
        int ans=p[y2][x2];
        if(x1>1)ans-=p[y2][x1-1];
        if(y1>1)ans-=p[y1-1][x2];
        if(x1>1&&y1>1)ans+=p[y1-1][x1-1];
        cout<<ans<<"\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}