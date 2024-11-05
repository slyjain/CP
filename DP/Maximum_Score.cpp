#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
vector<string>cb;
int dp[101][101][11];
int dx[]={-1,1};
void solve(){
    cin>>n>>m>>k;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        cb.push_back(s);
    }
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int l=0;l<k;l++){
                if(i==0){
                    dp[i][j][(cb[i][j]-'0')%k]=cb[i][j]-'0';
                }
                else if(i-1>=0){
                    if(j==0){
                        if(dp[i-1][j+1][(l-cb[i][j]-'0'+k)%k]!=-1){
                            
                            dp[i][j][l]=dp[i-1][j+1][(l-(cb[i][j]-'0')+k)]+(cb[i][j]-'0');
                        } 
                    }
                    else if(j==m-1){
                        if(dp[i-1][j-1][(l-cb[i][j]-'0'+k)%k]!=-1){
                            
                            dp[i][j][l]=dp[i-1][j-1][(l-(cb[i][j]-'0')+k)%k]+(cb[i][j]-'0');
                        }
                    }
                    else if(j>0&&j<m-1){
                        int ans=-1;
                        if(dp[i-1][j+1][(l-cb[i][j]-'0'+k)%k]!=-1){
                            
                            ans=dp[i-1][j+1][(l-(cb[i][j]-'0')+k)]+(cb[i][j]-'0');
                        } 
                        if(dp[i-1][j-1][(l-cb[i][j]-'0'+k)%k]!=-1){
                            
                            ans=max(ans,dp[i-1][j-1][(l-(cb[i][j]-'0')+k)%k]+(cb[i][j]-'0'));
                        }
                        dp[i][j][l]=ans;
                    }
                }
            }
            
        }
    }
    for(int j=0;j<m;j++){
        cout<<j<<"\n";
        for(int i=0;i<n;i++){
            for(int l=k-1;l>=0;l--){
                cout<<dp[i][j][l]<<" ";
            }
            cout<<"\n";
        }
        cout<<"---------------------------\n";
    }
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