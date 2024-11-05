#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,arr[101];
//0->nothing
//1->gym
//2->contest
int dp[101][3];
int rec(int day,int prev){
    //base case
    if(day==n){
        return 0;
    }
    //cache check
    if(dp[day][prev]!=-1){
        return dp[day][prev];
    }
    //compute
    int ans=0;
    // cout<<arr[day]<<" ";
    if(arr[day]==0){
        //only 0
        // cout<<0<<"\n";
        ans=1+rec(day+1,0);
    }
    else if(arr[day]==1){
        //0 2
        if(prev==0){
            // cout<<0<<"\n";
            ans=rec(day+1,2);
        }
        else if(prev==1){
            // cout<<0<<"\n";
            ans=rec(day+1,2);
        }
        else if(prev==2){
            // cout<<0<<"\n";
            ans=1+rec(day+1,0);
        }

    }
    else if(arr[day]==2){
        //0 or 1
        if(prev==0){
            ans=rec(day+1,1);
        }
        else if(prev==1){
            ans=1+rec(day+1,0);
        }
        else if(prev==2){
            ans=rec(day+1,1);
        }
    }
    else if(arr[day]==3){
        //1 or 2
        if(prev==0){
            ans=rec(day+1,1);
            ans=min(ans,rec(day+1,2));
        }
        else if(prev==1){
            ans=rec(day+1,2);
        }
        else if(prev==2){
            ans=rec(day+1,1);
        }
    }
    return dp[day][prev]=ans;

}
void solve(){
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}