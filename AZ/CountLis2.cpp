#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1000000007;
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
vector<int>dp,cnt,a;
int rec(int level){
    //base case;
    if(level==-1){
        return 0;
    }
    //cache check
    if(dp[level]!=-1){
        return dp[level];
    }
    //transitions
    int ans=1;
    for(int i=level-1;i>=0;i--){
        if(a[level]>a[i]){
            ans=max(ans,(rec(i)+1)%mod);
        }
    }
    //save and return
    return dp[level]=ans;
}
void solve(){
     int n;
    //  vector<int>a;
     cin>>n;
     a.clear();
     dp.clear();
     cnt.clear();
     a.resize(n);
     dp.assign(n,-1);
     cnt.assign(n,0);
     for(int i=0;i<n;i++){
        cin>>a[i];
     }
     cnt[0]=1;
     rec(0);
     bool firstEle=true;
     for(int i=0;i<n;i++){
        // rec(i);
        firstEle=true;
        for(int j=0;j<i;j++){
            if(a[i]>a[j]&&(rec(j)+1)==rec(i)){
                cnt[i]=(cnt[i]+cnt[j])%mod;
                firstEle=false;
            }
        }
        if(firstEle){
            cnt[i]=1;
        }
        // cout<<rec(i)<<" "<<cnt[i]<<"\n";
     }
    //  cout<<"\n";
     int mxLis=0;
     for(int i=0;i<n;i++){
        mxLis=max(mxLis,rec(i));
     }
     int ans=0;
     for(int i=0;i<n;i++){
        if(mxLis==rec(i)){
            ans=(ans+cnt[i])%mod;
        }
     }
     cout<<ans<<"\n";
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