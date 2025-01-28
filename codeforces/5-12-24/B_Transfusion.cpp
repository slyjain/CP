#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    bool e=true;
    int evenSum=0,oddSum=0,evenCount=0,oddCount=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(e){
            e=false;
            evenSum+=x;
            evenCount++;
        }
        else{
            e=true;
            oddSum+=x;
            oddCount++;
        }
    }
    if(oddSum%oddCount==0&&evenSum%evenCount==0&&(oddSum/oddCount)==(evenSum/evenCount)){
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