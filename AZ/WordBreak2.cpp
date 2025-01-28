#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL 
//VARIABLES AFTER EACH TEST CASE
void solve(){
     int n;
     cin>>n;
     string s;
     cin>>s;
     unordered_set<string>us;
     for(int i=0;i<n;i++){
        string x;
        cin>>x;
        us.insert(x);
     }
     int sz=s.size();
     vector<int>dp(sz+1,false);
     dp[0]=true;
    for(int i=0;i<sz;i++){
        bool ans=false;
        for(int j=i;j>=0;j--){
            if(us.find(s.substr(j,i-j+1))!=us.end()){
                ans|=dp[j-1];
            }
        }
        dp[i]=ans;
    }
    if(dp[sz-1])cout<<"Yes\n";
    else{cout<<"No\n";}
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