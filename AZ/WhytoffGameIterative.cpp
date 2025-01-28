 #include<bits/stdc++.h>
 using namespace std;
 #define int long long
 //do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
 void solve(){
      int n;
      cin>>n;
      int dp[n+1][n+1];
      for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=0;
            if(i==0||j==0||i==j){
                dp[i][j]=1;
                break;
            }
            for(int x=0;x<=i;x++){
                dp[i][j]|=dp[x][j];
            }
            for(int x=0;x<=j;x++){
                dp[i][j]|=dp[i][x];
            }
            for(int x=0;x<min(i,j);x++){
                dp[i][j]|=dp[i-x][j-x];
            }
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