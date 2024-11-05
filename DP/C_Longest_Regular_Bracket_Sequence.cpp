#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int n;
int dp[1000001];
vector<int>closing;
int rec(int level){
    //base case
    if(closing[level]==-1){
        return 0;
    }
    if(level==-1){
        return 0;
    }
    //cache check
    if(dp[level]!=-1){
        return dp[level];
    }
    //transition
    int ans=0;
    if(closing[level]!=-1){
        
        ans=level-closing[level]+1;
        ans+=rec(closing[level]-1);
    }
    return dp[level]=ans;


}
void solve(){
    cin>>s;
    n=s.length();
    stack<int>st;
    closing.resize(n,-1);
    
    for (int i = 0; i < n; i++)
    {
     if(s[i]=='('){
        st.push(i);
     }   
     else{
        if(st.empty()){
            closing[i]=-1;
        }else{
            int tp=st.top();
            st.pop();
            closing[i]=tp;
            // closing[tp]=i;
        }
     }
    }
    // for(int i=0;i<n;i++){
    //     cout<<closing[i]<<" ";
    // }
    cout<<"\n";
   memset(dp,-1,sizeof(dp));
   int mx=0;
   int cnt=1;
    for(int i=0;i<n;i++){
        // cout<<rec(i)<<" ";
        if(s[i]==')'&&rec(i)>mx){
            mx=rec(i);
            cnt=1;
        }
        else if(rec(i)==mx){
            cnt++;
        }
    }
    if(mx==0){
        cout<<0<<" 1";
    }
    else{
         cout<<mx<<" "<<cnt;
    }
   
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}