#include<bits/stdc++.h>
using namespace std;
#define int long long
int cntA[1001],cntB[1001];
void solve(){
    int n;
    cin>>n;
    memset(cntA,0,sizeof(cntA));
    memset(cntB,0,sizeof(cntB));
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cntA[x]++;
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cntB[x]++;
    }
    bool ans=true;
    int cnt=0;
    for(int i=1000;i>=1;i--){
        
        cnt+=(cntB[i]-cntA[i]);
        if(cnt<0||(cntA[i]>((n+1)/2))){
            ans=false;
            break;
        }
    }
    if(ans){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }

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