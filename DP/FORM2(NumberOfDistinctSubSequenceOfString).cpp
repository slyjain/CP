#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int dp[1001];
int prefixSum[1001];
int previousOcc[26];
int rec(int n){
    dp[0]=1;
    prefixSum[0]=1;
    memset(previousOcc,-1,sizeof(previousOcc));
    for(int i=1;i<=n;i++){
        prefixSum[i]+=(2*prefixSum[i-1]);
        if(previousOcc[s[i-1]-'a']!=-1){
            prefixSum[i]-=(prefixSum[previousOcc[s[i-1]-'a']]);
        }
        previousOcc[s[i-1]-'a']=i-1;
    }

    return prefixSum[n]-1;
}
void solve(){
    cin>>s;
    int n=s.size();
    cout<<rec(n);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}