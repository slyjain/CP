#include<bits/stdc++.h>
using namespace std;
#define int long long
int ar[100010],b[100010];
void solve(){
    // memset(ar,0,sizeof(ar));
    // memset(b,0,sizeof(b));
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>ar[i];
        b[i]=0;
    }
    for(int i=1;i<=m;i++){
        int l,r;
        cin>>l>>r;
        b[l]++;
        b[r+1]--;
    }
    map<int,int>f;
    for(int i=1;i<=n;i++){
        b[i]+=b[i-1];
        
    }
    for(int i=1;i<=n;i++){
        int x=b[i];
        // while(x>0){
        //     f[ar[i]]++;
        //     x--;
        // }
        if(x>0){
            f[ar[i]]=x;
        }
    }
    // sort(f.begin(),f.end());
    vector<pair<int,int>>lengths;
    for(auto v:f){
        lengths.push_back(make_pair(v.second,v.first));
    }
    int l=lengths.size();
    for(int i=1;i<l;i++){
        lengths[i].first+=lengths[i-1].first;
    }
    
    for(int i=1;i<=k;i++){
        int x;
        cin>>x;
        if(x>(lengths[l-1].first)){
            cout<<"-1";
        }
        else{
            auto lb=lower_bound(lengths.begin(),lengths.end(),make_pair(x,LONG_LONG_MIN))-lengths.begin();
            // cout<<lb;
            cout<<lengths[lb].second;
            
        }
        // x<=l?cout<<f[x-1]:cout<<-1;
        cout<<" ";
    }
    cout<<"\n";
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