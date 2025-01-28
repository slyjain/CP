#include <bits/stdc++.h>
using namespace std;
#define int long long
// do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
int n;
vector<int> a;
vector<vector<int>>dp1;
bool rec1(int l,int r){
    //base case and prunning

    if(l>=r){
        return 1;
    }
    //cache ccheck
    if(dp1[l][r]!=-1){
        return dp1[l][r];
    }
    //transitions
    return dp1[l][r]=((a[l]==a[r])&&rec1(l+1,r-1));
}
vector<vector<int>>dp2;
int rec2(int l,int r){
    //base case
    if(l>r)return 0;
    //cache check
    if(dp2[l][r]!=-1){
        return dp2[l][r];
    }
    //transitions
    int ans=1e9;
    // if(rec1(l,r)){
    //     ans=1;
    // }
    ans=min(ans,1+rec2(l+1,r));
    if(a[l]==a[l+1]){
        ans=min(1+rec2(l+2,r),ans);
    }
    
    for(int x=l+2;x<=r;x++){
        if(a[l]==a[x]){
            ans=min(ans,rec2(l+1,x-1)+rec2(x+1,r));
        }
    }
    //save and return
    return dp2[l][r]=ans;
}
void solve()
{
    // int n;
    cin >> n;
    a.assign(n,0);
    dp1.assign(n,vector<int>(n,-1));
    dp2.assign(n,vector<int>(n,-1));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // for(int l=0;l<n;l++){
    //     for(int r=0;r<n;r++){
    //         rec1(l,r);
    //         // cout<<l<<" "<<r<<" "<<rec1(l,r)<<"\n";
    //     }
    // }
    cout<<rec2(0,n-1)<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}