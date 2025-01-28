#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int k;
    cin>>k;
    vector<int>v={2,3,5};
    set<int>s;
    s.insert(1);
    vector<int>ans;
    while(ans.size()<k){
        ans.push_back(*s.begin());
        cout<<ans.back()<<" ";
        for(auto x:v){
            s.insert(*s.begin()*x);
        }
        s.erase(s.begin());
    }
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    return 0;
}