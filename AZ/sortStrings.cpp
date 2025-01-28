#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<string>a,r;
vector<int>c;
vector<vector<int>>dp;
vector<vector<bool>>done;
int n;
const int INF=1e18;
int rec(int level,bool rev){
    //base case
    if(level==n){
        return 0;
    }
    //cache check
    if(done[level][rev]!=false){
        return dp[level][rev];
    }
    //transitions
    int ans=INF;
    string prev=(rev==true)?r[level-1]:a[level-1];
    if(a[level]>prev){
            ans=min(ans,rec(level+1,false));
    }
    if(r[level]>prev){
            ans=min(ans,rec(level+1,true)+c[level]);
    }
    //save and return
    done[level][rev]=true;
    return dp[level][rev]=ans;
}
void solve(){
    
    cin>>n;
    a.resize(n);
    r.resize(n);
    c.resize(n);
    dp.clear();
    done.clear();
    dp.assign(n+1,vector<int>(2,0));
    done.assign(n+1,vector<bool>(2,false));
    for(int i=0;i<n;i++){
        cin>>c[i];
        // cout<<c[i]<<" ";
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
        r[i]=a[i];
        reverse(r[i].begin(),r[i].end());
        // cout<<a[i]<<" "<<r[i]<<"\n";
    }
    // cout<<rec(1,0);
    int ans=min(rec(1,0),rec(1,1)+c[0]);
    if(ans>=INF){cout<<-1<<"\n";return;}
    cout<<ans<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}