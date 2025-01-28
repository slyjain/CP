#include<bits/stdc++.h>
using namespace std;
#define int long long
//do not forget to reset the GLOBAL VARIABLES AFTER EACH TEST CASE
void solve(){
    string s;
    cin>>s;
    int n=s.size();
    vector<int>RLpair,LRpair;
    for(int i=0;i<n-1;i++){
        if(s[i]=='R'&&s[i+1]=='L'){
            RLpair.push_back(i);
            // cout<<i<<" ";
        }
    }
    // cout<<"\n";
    for(int j=n-1;j>0;j--){
        if(s[j]=='L'&&s[j-1]=='R'){
            LRpair.push_back(j);
            
        }
    }
    reverse(LRpair.begin(),LRpair.end());
    // for(auto v:LRpair){
        // cout<<v<<" ";
    // }
     cout<<"\n";
    vector<int>ans(n,0);
    for(int i=0;i<n;i++){
        // cout<<i<<" : "<<s[i]<<"\n";
        if(s[i]=='R'){
            int idx=*lower_bound(RLpair.begin(),RLpair.end(),i);
            ans[((100000-(idx-i))%2)+i]++;
            // cout<<idx<<" "<<i<<"\n";
        }
        else if(s[i]=='L'){
            int idx=lower_bound(LRpair.begin(),LRpair.end(),i)-LRpair.begin();
            
            if(idx!=LRpair.size()&&LRpair[idx]==i){
                // cout<<LRpair[idx]<<"\n";
                ans[i-((100000)%2)]++;
            }else{
                // cout<<"here";
                idx--;
                // cout<<LRpair[idx]<<"\n";
                // cout<<i-((100000-(i-idx))%2);
                ans[LRpair[idx]-((100000-(i-idx)+1)%2)]++;
            }
            
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i];
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