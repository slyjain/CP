#include<bits/stdc++.h>
using namespace std;
#define int long long
char a[8][8];
bool r[8],c[8];
void solve(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin>>a[i][j];
            if(a[i][j]=='#'){
                r[i]=true;
                c[j]=true;
            }
        }
    }
    int ans=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(a[i][j]=='.'){
                if(r[i]==false&&c[j]==false){
                    ans++;
                }
            }
        }
    }
    cout<<ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}