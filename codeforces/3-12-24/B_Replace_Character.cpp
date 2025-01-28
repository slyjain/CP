#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>mp(26);
    for(auto x:s){
        mp[x-'a']++;
    }
    // char change=(mp.begin())->first;
    // char changeTo=(mp.rbegin())->first;
    vector<pair<int,int>>mp2;
    for(int i=0;i<26;i++){
        if(mp[i]>0){
            mp2.push_back({mp[i],i});
        }
    }
    sort(mp2.begin(),mp2.end());
    char change=(mp2.begin())->second+'a';
    char changeTo=(mp2.rbegin())->second+'a';
    bool hap=true;
    for(auto x:s){
        // char curr=x;
        // cout<<curr;
        if(x==change&&hap==true){
            cout<<changeTo;
            hap=false;

        }else{
            cout<<x;
        }

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