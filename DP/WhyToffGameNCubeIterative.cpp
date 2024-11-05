#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[101][101];
void solve(){
    int a,b;
    cin>>a>>b;
    for(int x=0;x<=a;x++){
        for(int y=0;y<=b;y++){
            int ans=0;
            if(x==0&&y==0){
                dp[x][y]=0;
                ans=0;
            }
           
            
            for(int z=0;z<x;z++){
                if(dp[z][y]==1){
                    ans=1;
                    break;
                }
            }   
            
            
                for(int z=0;z<y;z++){
                if(dp[x][z]==1){
                    ans=1;
                    break;
                }
            }    
            
            
                for(int z=1;z<=min(x,y);z++){
                    if(dp[x-z][y-z]==0){
                        ans=1;
                        break;
                    }
                
            }
            dp[x][y]=ans;
                    //  cout<<dp[x][y]<<" ";
        }
        // cout<<"\n";
    }
    cout<<dp[a][b]<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);int t;
    cin>>t;
    while(t--){
solve();
    }
    
    return 0;
}