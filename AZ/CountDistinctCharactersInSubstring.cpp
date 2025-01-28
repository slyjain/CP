#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
void solve(){
     int n;
     cin>>n;
     string s;
     cin>>s;vector<int> alpha[26];
     for(int i=0;i<26;i++){
        alpha[i].push_back(-1);
     }
     for(int i=0;i<n;i++){
        alpha[s[i]-'a'].push_back(i);
     }
     for(int i=0;i<26;i++){
        alpha[i].push_back(n);
     }int ans=0;
     for(int i=0;i<26;i++){
        int sz=alpha[i].size();
        for(int j=1;j<sz-1;j++){
            // cout<<(char)('a'+i)<<" "<<(alpha[i][j+1]-alpha[i][j])*(alpha[i][j]+1)<<"\n";
            ans+=(alpha[i][j+1]-alpha[i][j])*(alpha[i][j]+1);
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