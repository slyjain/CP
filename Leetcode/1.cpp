#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<vector<int>>st(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>st[i][j];
        }
    }
    int mx=0;
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            bool tr=true;
            int seq=0;
            if(i&(1<<j)){
                for(int k=0;k<n;k++){
                    if((st[j][k]==1 && ((i>>k)%2==1))||(st[j][k]==0&&((i>>k)%2==0))){
                        

                    }
                    else if(st[j][k]==2){
                        continue;
                    }
                    else{
                        tr=false;
                    }
            }
            if(tr){
                mx=max(mx,(int)__builtin_popcountll(i));
            }
            }
            
        }
    }
    cout<<mx;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}