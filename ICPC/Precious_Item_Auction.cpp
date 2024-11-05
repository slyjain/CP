#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
void solve(){
    cin>>n>>k;
    vector<int>mp;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mp.push_back(x);
    }
    sort(mp.begin(),mp.end());
    int mx,mn;
    /*bool lele=false;
    int p=k;
    for(int i=n-1;i>=0;i--){
        if(lele&&p>=0){
            mx+=mp[i];
            p--;
        }
        else{
            lele=true;
        }
    }
     mn=mp[n-k-1];
    for(int i=0;i<k-1;i++){
        mn+=mp[i];
    }*/
//    1 1 2 3 3
    int idx=n-2;
    int sum=0;
    int p=k;
    while(k){
        sum+=mp[idx];
        idx-=2;
        k--;
    }
    mn=0;
    // k largest skip
    k=p;
    idx=n-1-k;
    mn=mp[idx++];
    k--;
    idx=0;
    while(k){
        mn+=mp[idx++];
        k--;
    }
    cout<<mn<<" "<<sum<<"\n";

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