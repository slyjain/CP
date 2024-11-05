#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
void solve(){
    cin>>s;
    int cha[26]={0};
    if(s.length()>3){
        cout<<"No";
    }
    else{
    for(auto c:s){
        if(c-'A'>=0){
            cha[c-'A']++;
        }

        }
        bool p=true;
    for(int i=0;i<3;i++){
        if(cha[i]==1){
            continue;
        }
        else{
            p=false;
        }
    }
    if(p){
        cout<<"Yes";
    }
    else{
        cout<<"No";
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