#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,x;
int arr[101];
int dp[2000100];
int rec(int remSum){
    //prunnig
    if(remSum<0){
        return 1e9;
    }
    //base case
    if(remSum==0){
        return 0;
    }
    //cache check
    if(dp[remSum]!=-1){
        return dp[remSum];
    }
    //compute
    int ans=1e9;
    for(int i=0;i<n;i++){
        ans=min(ans,1+rec(remSum-arr[i]));
    }
    //save and return 
    return dp[remSum]=ans;

}
int iter(int remSum){
    if(remSum==0){
        return 0;
    }
    // cout<<remSum<<"\n";
    dp[0]=0;
    for(int j=0;j<=remSum;j++){
        if(dp[j]!=1e9){
            for(int i=0;i<n;i++){
                
                dp[arr[i]+j]=min(dp[arr[i]+j],1+dp[j]);
                // if((arr[i]+j)==remSum){
                //     break;
                // }
            }
            // if(dp[remSum]!=)
        }
        // cout<<"here";
        // cout<<dp[j]<<" ";
        
    }
    // cout<<dp[remSum]<<" ";
    return (dp[remSum]!=(int)1e9?dp[remSum]:(-1));
    
}
void solve(){
    cin>>n>>x;
    // cout<<n<<x;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        // cout<<arr[i];
    }
    for(int i=0;i<2000100;i++){
        dp[i]=1e9;
        // cout<<dp[i]<<" ";
    }
    cout<<iter(x);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}