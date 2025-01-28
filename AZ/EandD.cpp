#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    string k,o;
    // cin>>k>>o
    k="PgEfTYaWGHjDAmxQqFLRpCJBownyUKZXkbvzIdshurMilNSVOtec#@_!=.+-*/";
    o="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string s;
    int c;
    cin>>c;
    cin>>s;
    map<char,char>mp;
    if(c==1){
        for(int i=0;i<o.length();i++){
            mp[o[i]]=k[i];
        }
        for(auto x:s){
            cout<<mp[x];
        }
    }else{
        for(int i=0;i<o.length();i++){
            mp[k[i]]=o[i];
        }
        for(auto x:s){
            cout<<mp[x];
        }
    }
    
    

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}