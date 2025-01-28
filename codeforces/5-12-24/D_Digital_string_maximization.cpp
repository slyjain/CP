#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    string s;
    cin>>s;
    int n=s.length();
    int i=n-2;
    while(i!=-1){
        if(s[i]-'0'<s[i+1]-'0'-1){
           int s1=s[i]-'0';
           int s2=s[i+1]-'0'-1;
           s[i]=(char)(s2+'0');
           s[i+1]=(char)(s1+'0');
            if(i<=n-4){
                i+=2;
            }else if(i==n-3){
                i+=1;
            }
        }else{
            i--;
        }
    }
    cout<<s<<"\n";
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