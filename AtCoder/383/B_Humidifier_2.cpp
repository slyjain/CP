#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
int h,w,d;
cin>>h>>w>>d;
vector<vector<char>>g;
g.assign(h,vector<char>(w));
for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
        cin>>g[i][j];
    }
}
int ans=0;
for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
        for(int k=0;k<h;k++){
            for(int l=0;l<w;l++){
                int cnt=0;
                if(g[i][j]!='#'&&g[k][l]!='#'){
                    for(int n=0;n<h;n++){
                    for(int m=0;m<w;m++){
                        
                        if(min((abs(n-i)+abs(m-j)),abs(k-n)+abs(m-l))<=d&&g[n][m]!='#'){
                            cnt++;
                        }
                    }
                }
                }
                
                ans=max(ans,cnt);
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