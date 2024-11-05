#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int prefix[10010];
int prevOcc[26];
void rec(int level){
    prefix[0]=1;
    prevOcc[s[0]-'a']=0;
    for(int i=1;i<s.size();i++){
            prefix[i]=2*prefix[i-1];
            if(prevOcc[s[i]-'a']!=-1){
                prefix[i]-=prefix[prevOcc[s[i]-'a']];
            }
            prevOcc[s[i]-'a']=i;
    }
    cout<<prefix[s.size()-1];
}
void solve(){
        cin>>s;
        memset(prefix,-1,sizeof(prefix));
        memset(prevOcc,-1,sizeof(prevOcc));
        rec(0);
        
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}