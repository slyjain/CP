#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n+1,0);
    int x;
    vector<int>ord;
    for(int i=0;i<n;i++){
        cin>>x;
        ord.push_back(x);
        arr[x]+=1;
    }
    vector<int>rem;
    for(int i=1;i<=n;i++){
        if(arr[i]==0){
            rem.push_back(i);
        }
    }
    vector<int>ans;
    int j=0;
    vector<int>currFreq(n+1,0);
    for(int i=0;i<n;i++){
        if(currFreq[ord[i]]==0){
            ans.push_back(ord[i]);
            currFreq[ord[i]]++;
        }else{
            ans.push_back(rem[j++]);
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}