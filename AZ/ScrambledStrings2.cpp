#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
int n;
string s1,s2;
int dp[41][41][41];
int rec(int ptr1,int ptr2,int subStrLen){
    //base case
    if(subStrLen==1){
        return s1[ptr1]==s2[ptr2]; 
    }
    //cache check
    if(dp[ptr1][ptr2][subStrLen]!=-1){
        return dp[ptr1][ptr2][subStrLen];
    }
    //transitions
    bool ans=false;
    for(int len=1;len<subStrLen;len++){
        ans|=(rec(ptr1,ptr2,len)&rec(ptr1+len,ptr2+len,subStrLen-len));
        ans|=(rec(ptr1,ptr2+subStrLen-len,len)&rec(ptr1+len,ptr2,subStrLen-len));
    }
    return dp[ptr1][ptr2][subStrLen]=ans;
}
void solve(){
     
     cin>>s1>>s2;
        n=s1.size();
        memset(dp,-1,sizeof(dp));
     cout<<(rec(0,0,n)?"Yes\n":"No\n");
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