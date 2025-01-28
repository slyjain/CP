#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    unordered_map<string,bool>mp;
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        mp[x]=true;
    }
    int sz=s.size();
    vector<vector<bool>>dp(sz+1,vector<bool>(sz+1,false));
    for(int i=0;i<sz;i++){
        for(int j=i;j<sz;j++){
            if(mp[s.substr(i,j-i+1)]==true){
                dp[i][j]=true;
            }
        }
    }
    for(int i=0;i<sz;i++){
        for(int j=i;j<sz;j++){
            if(mp[s.substr(i,j-i+1)]==true){
                dp[i][j]=true;
            }
            else{
                bool ans=false;
                for(int k=i;k<j;k++){
                    ans|=(dp[i][k]&dp[k+1][j]);
                }
                dp[i][j]=ans;
            }
            
        }
    }
    if(dp[0][sz-1]==true){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
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