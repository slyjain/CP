#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
string s;
int n;
void solve(){
     
     cin>>n;
     
     cin>>s;
     
     vector<int>mp[26];
     for(int i=0;i<26;i++){
        mp[i].push_back(-1);
     }
     for(int i=0;i<s.size();i++){
        mp[s[i]-'a'].push_back(i);
     }
     for(int i=0;i<26;i++){
        mp[i].push_back(n);
     }
     int ans=0;
     for(int i=0;i<26;i++){
        for(int j=1;j<mp[i].size()-1;j++){
            int t1=mp[i][j]-mp[i][j-1];
            int t2=mp[i][j+1]-mp[i][j];
            // cout<<t1<<" "<<t2<<"\n";
            ans+=t1*t2;
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