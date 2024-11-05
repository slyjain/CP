#include<bits/stdc++.h>
using namespace std;
#define int long long
string s1,s2;

void solve(){
    cin>>s1>>s2;
    string temp=s1;
    while(temp.length()<s2.length()){
        temp+=s1;
    }
    bool milgaya=false;
    int l=-1,r=-1;
 
    for(int i=0;i<=(temp.length()-s2.length());i++){

        if(temp.substr(i,s2.length())==s2){
            milgaya=true;
            l=i,r=i+s2.length();
        }
    }
    if(milgaya){
        for(int i=0;i<l;i++){
            cout<<temp[i];
        }
        for(int i=r;i<temp.size();i++){
            cout<<temp[i];
        }
    }
    else{
        cout<<-1;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}