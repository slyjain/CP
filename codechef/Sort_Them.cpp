#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s,p;
vector<vector<int>>dp;
int ctn(char x){
    return (int)(x-'a');
}

map<int,int>mp;
//char to num
int rec(int ind,char prev){
    if(ind==n){
        return 0;
    }
    // cout<<"here";
    // cout<<prev<<"\n";
    //cache check
    if(dp[ind][ctn(prev)]!=-1){
        return dp[ind][ctn(prev)];
    }
    //compute
    int ans=1e9;
    // cout<<s[ind]<<" "<<p[26-mp[ctn(s[ind])]]<<"\n";
    if(ctn(s[ind])>=ctn(prev)){
        ans=min(ans,rec(ind+1,s[ind]));
    }
    if(ctn(p[26-mp[ctn(s[ind])]])>=ctn(prev)){
        ans=min(ans,rec(ind+1,p[26-mp[ctn(s[ind])]])+1);
    }
    
    //save and return 
    return dp[ind][ctn(prev)]=ans;

}
void solve(){
    cin>>n>>s>>p;
    dp.clear();
    dp.resize(n,vector<int>(26,-1));
    mp.clear();
    int i=1;
    for(auto x:p){
        mp[ctn(x)]=i;
        i++;
    }
    cout<<((rec(0,'a')>n)?-1:rec(0,'a'))<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}