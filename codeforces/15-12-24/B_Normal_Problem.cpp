#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
string s;
cin>>s;
int n=s.length();
for(int c=n-1;c>=0;c--){
    if(s[c]=='p'){
        cout<<'q';
    }else if(s[c]=='q'){
        cout<<'p';
    }else{
        cout<<'w';
    }
}cout<<"\n";
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