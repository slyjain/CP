#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
string s;
int k;
int n;
vector<vector<int>>cst(27,vector<int>(27,0));
vector<vector<vector<int>>>dp;
vector<vector<vector<bool>>>done;
// int dp[110][110][27];
int rec(int level,int krem,char prev){
    //prunning
    if(krem<0){
        return -1e18;
    }
    //base case
    if(level==s.size()){
        return 0;
    }
    //cache check
    if(done[level][krem][prev-'a']){
        return dp[level][krem][prev-'a'];
    }
    int ans=-1e18;
    for(char i='a';i<='z';i++){
        if(s[level]==i){
            ans=max(ans,rec(level+1,krem,i)+cst[prev-'a'][i-'a']);
        }else if(krem>=1){
            ans=max(ans,rec(level+1,krem-1,i)+cst[prev-'a'][i-'a']);
        }
    }
    done[level][krem][prev-'a']=true;
    return dp[level][krem][prev-'a']=ans;
}
void solve(){
     
     cin>>s>>k;
     cin>>n;
    //  cst.clear();
     dp.assign(s.size()+1,vector<vector<int>>(k+1,vector<int>(27,-1)));
    //  done.clear();
     done.assign(s.size()+1,vector<vector<bool>>(k+1,vector<bool>(27,false)));
    //  memset(dp,-1,sizeof(dp));
    cst.assign(27,vector<int>(27,0));
    // memset(cst,0,sizeof(cst));
     for(int i=0;i<n;i++){
        char x,y;
        int cost;
        cin>>x>>y>>cost;
       cst[x-'a'][y-'a']=cost;
     }
    int ans=-1e18;
    for(char i='a';i<='z';i++){
        if(s[0]==i){
            ans=max(ans,rec(1,k,i));
        }else if(k>=1){
            ans=max(ans,rec(1,k-1,i));
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